%{
#include <stdio.h>
#include <stdlib.h>
#include "structures/SymbolTable.h"

extern int line_number;

SymbolTable *symbol_table = NULL;

void yyerror(const char *s);
int yylex(void);

%}

%union {
    int ival;
    float fval;
    char *sval;
}

%token <ival> INT
%token <fval> FLOAT
%token <sval> ID
%token <sval> LITERAL
%token <ival> TRUE
%token <ival> FALSE

%token PLUS MINUS MULT DIV MOD ASSIGN ENDLINE
%token COMMA REF DEREF QUOTE DELIMCASE WHILE FOR IF ELSE ELSEIF SWITCH CASE DEFAULT GOTO TYPEDEF STRUCT UNION
%token PLUSONE MINUSONE OPENBLOCK CLOSEBLOCK
%token IMPORT OPENBRACK CLOSEBRACK BREAK CONTINUE
%token PREPARE CONJURE OR AND NOT 
%token GT LT GE LE EQ NE PARAMS CALLFUNC DECLFUNC RETURNT CONST VOLATILE
%token TYPEINT TYPEFLOAT TYPEBOOL TYPECHAR TYPEVOID TYPESHORT TYPEDOUBLE TYPELONG

%right NOT                
%left MULT DIV MOD        
%left PLUS MINUS          
%left LT GT LE GE         
%left EQ NE               
%left AND                 
%left OR    

%%

start: /* empty */
      | start start_item
      ;

start_item: decl_stmt
          | decl_func
          | decl_import
          ;

decl_import: IMPORT LITERAL ENDLINE
           ;

decl_func: DECLFUNC tipo ID PARAMS OPENBRACK arguments CLOSEBRACK stmt_block
         ;

decl_stmt: assignment ENDLINE
         | decl_var ENDLINE
         | def_type ENDLINE
         | sign_func ENDLINE
         ;

stmt_block: OPENBLOCK stmts CLOSEBLOCK
         ;

stmt_if: IF expr stmt_block stmt_else
       ;

stmt_else: ELSE stmt_block
         | ELSE stmt_if
         | /* empty */
         ;

stmt_switch: SWITCH expr OPENBLOCK case_list default_case CLOSEBLOCK
           ;

case_list: /* empty */
         | case_list case_stmt
         ;

case_stmt: CASE expr DELIMCASE stmts stmt_break
          ;

default_case: /* empty */
            | DEFAULT DELIMCASE stmts stmt_break
            ;

stmt_return: RETURNT expr ENDLINE
           ;

stmt_for: FOR expr COMMA unary_expr stmt_block
        ;

stmt_while: WHILE expr stmt_block
          ;

stmt_break: BREAK ENDLINE
          ;

stmt_continue: CONTINUE ENDLINE
             ;

stmts: /* empty */
      | stmts stmt
      ;

stmt: decl_stmt
    | stmt_if
    | stmt_switch
    | stmt_while
    | stmt_for
    | stmt_return
    | stmt_break
    | stmt_continue
    ;

assignment: ID ASSIGN expr
          ;

opt_assignment: /* empty */
              | ASSIGN expr
              ;

decl_var: tipo ID opt_assignment
        | tipo CONST ID opt_assignment
        | tipo VOLATILE ID opt_assignment
        | tipo VOLATILE CONST ID opt_assignment
        ;

def_type: TYPEDEF tipo ID ENDLINE
        | TYPEDEF STRUCT ID 
        | TYPEDEF UNION ID 
        ;

sign_func: tipo ID PARAMS
         ;

expr: expr PLUS term
    | expr MINUS term
    | expr MULT term
    | expr DIV term
    | expr MOD term
    | expr GT term
    | expr LT term
    | expr GE term
    | expr LE term
    | expr EQ term
    | expr NE term
    | expr AND term
    | expr OR term
    | NOT expr
    | term
    ;

term: LITERAL
    | INT
    | FLOAT
    | variable
    | bool
    | function_call
    | unary_expr
    | OPENBRACK expr CLOSEBRACK
    ;


variable: ID 
        ;

bool: TRUE
    | FALSE
    ;

function_call: CALLFUNC ID OPENBRACK params CLOSEBRACK
             ;

unary_expr: MINUSONE variable
          | PLUSONE variable
          | DEREF variable
          | REF variable
          ;

arguments: /* empty */
         | argument
         ;

argument: tipo ID
        | tipo ID COMMA argument 

params: /* empty */
      | expr
      | params COMMA expr
      ;

tipo: TYPEINT
    | TYPEFLOAT
    | TYPEBOOL
    | TYPECHAR
    | TYPEVOID
    | TYPEDOUBLE
    | TYPELONG
    | TYPESHORT
    ;

%%

/* Error reporting function */
void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", line_number, s);
}

int main() {
    current_table = create_symbol_table(NULL);
    yyparse();
    return 0; 
}
