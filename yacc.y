%{
#include <stdio.h>
#include <stdlib.h>
#include "structures/SymbolTable.h"
#include "structures/Expression.h"

extern int yyparse();
extern int invalid_found;
extern char invalid_chars[];
extern int line_number;

void yyerror(const char *s);

SymbolTable *current_table;

int yylex(void);

%}

%code requires {
#include "structures/SymbolTable.h"
#include "structures/Expression.h"
}

%union {
    int ival;
    float fval;
    char *sval;
    Type type;
    Param *param;
    Expression result;
}

%token <ival> INT
%token <fval> FLOAT
%token <sval> ID
%token <sval> LITERALSTRING
%token <sval> LITERALCHAR
%token <ival> TRUE
%token <ival> FALSE

%token PLUS MINUS MULT DIV MOD ASSIGN ENDLINE
%token COMMA REF DEREF DELIMCASE WHILE FOR IF ELSE SWITCH CASE DEFAULT TYPEDEF STRUCT UNION
%token PLUSONE MINUSONE OPENBLOCK CLOSEBLOCK OPENARRAY CLOSEARRAY NULLT
%token IMPORT OPENBRACK CLOSEBRACK BREAK CONTINUE 
%token OR AND NOT ENUM CONJUNCTURE GOTO QUOTE
%token GT LT GE LE EQ NE PARAMS CALLFUNC DECLFUNC RETURNT CONST VOLATILE
%token TYPEINT TYPEFLOAT TYPEBOOL TYPECHAR TYPEVOID TYPESHORT TYPEDOUBLE TYPELONG

%start begin

%right NOT                
%left MULT DIV MOD        
%left PLUS MINUS          
%left LT GT LE GE         
%left EQ NE               
%left AND                 
%left OR    

%type <param> argument
%type <param> arguments
%type <type> type
%type <result> assignment
%type <result> expr
%type <result> term


%%

begin: start
     ;

start: /* empty */
      | start start_item
      ;

start_item: decl_stmt
          | decl_func
          | decl_import
          ;

decl_import: IMPORT LITERALSTRING ENDLINE
           ;

decl_func: DECLFUNC type ID PARAMS OPENBRACK arguments CLOSEBRACK stmt_block
           {
            Function *func = create_function($2);
            Param *param = $6;
            add_parameter_list(func, &param);
            Symbol *new_symbol = insert_symbol(current_table, $3, TYPE_FUNC);
            new_symbol->TypeVal.funcVal = func;
           }
         ;

decl_stmt: assignment ENDLINE
         | sign_func ENDLINE
         | type_def
         | decl_var ENDLINE
         ;

stmt_block: OPENBLOCK 
            { 
              SymbolTable *new_table = create_symbol_table(current_table); 
              current_table = new_table; 
            }
            stmts 
            CLOSEBLOCK
            {
              SymbolTable *old_table = current_table;
              current_table = current_table->parent;
            }
          ;

stmt_if: IF expr stmt_block stmt_else
       ;

stmt_else: ELSE stmt_block
         | ELSE stmt_if
         | /* empty */
         ;

stmt_switch: SWITCH expr 
             OPENBLOCK 
             {
               SymbolTable *new_table = create_symbol_table(current_table);
               current_table = new_table;

             }
             case_list default_case 
             CLOSEBLOCK
             {
               SymbolTable *old_table = current_table;
               print_table(current_table);
               current_table = current_table->parent;
             }
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
           {
            Symbol *symbol = lookup_symbol(current_table, $1);
            if (symbol == NULL) {
              yyerror("Variavel nao encontrada...\n");
            } else {
              if (symbol->type != $3.type) {
                yyerror("Tipos incompativeis...\n");
              }
            }
           }
          ;

opt_assignment: /* empty */
              | ASSIGN expr
              ;

decl_var: type type_qualifier ID opt_assignment
          { 
           insert_symbol(current_table, $3, $1); 
          }
        | type ID opt_assignment 
          { 
           insert_symbol(current_table, $2, $1); 
          }
        ;

type_qualifier: CONST
              | VOLATILE
              | VOLATILE CONST
              ;

sign_func: type ID PARAMS 
         ;

expr: expr PLUS term
     {
      if ($1.type != $3.type) {
        yyerror("Tipos incompativeis...\n");
      } else {
        $$ = (Expression){.type = $1.type};
        // Pensar em como realizar as operações de forma a não poluir o código,
        // talvez seja interessante criar uma função que faça isso em Expressions.
        // Pode ser que seja uma função que resolva de forma genérica para todos os
        // tipos de operações.
      } 
     }
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

term: literal
    | INT { printf("INT %d\n", yylval.ival); }
    | FLOAT
    | variable
    | bool
    | function_call
    | unary_expr
    | OPENBRACK expr CLOSEBRACK
    ;

variable: ID accesses
        ;

bool: TRUE
    | FALSE
    ;

function_call: CALLFUNC ID PARAMS OPENBRACK params CLOSEBRACK
             ;

unary_expr: MINUSONE variable
          | PLUSONE variable
          | DEREF variable
          | REF variable
          ;

arguments: /* empty */ { $$ = NULL; }
         | argument { $$ = $1; }
         ;

argument: type ID 
         {
          Param *param = create_param($2, $1);
          $$ = param;
         }
        | type ID COMMA argument 
         {
          Param *param = create_param($2, $1);
          link_params(param, $4);
          $$ = param;
         }

params: /* empty */
      | expr
      | params COMMA expr
      ;

type: TYPEINT { $$ = TYPE_INT; } 
    | TYPEFLOAT { $$ = TYPE_FLOAT; }
    | TYPEBOOL { $$ = TYPE_BOOL; }
    | TYPECHAR { $$ = TYPE_CHAR; }
    | TYPEVOID { $$ = TYPE_VOID; }
    | TYPEDOUBLE { $$ = TYPE_DOUBLE; }
    | TYPELONG { $$ = TYPE_LONG; }
    | TYPESHORT { $$ = TYPE_SHORT; }
    | type_enum { $$ = TYPE_ENUM; }
    | type_struct { $$ = TYPE_STRUCT; }
    | type_union { $$ = TYPE_UNION; }
    ;

enum_def: ENUM CONJUNCTURE ID OPENBLOCK enum_list CLOSEBLOCK
        ;

enum_list: ID
         | enum_list COMMA ID
         ;

struct_def: STRUCT CONJUNCTURE ID OPENBLOCK struct_list CLOSEBLOCK
          ;

struct_list: type ID ENDLINE
           | struct_list type ID ENDLINE
           ;

union_def: UNION CONJUNCTURE ID OPENBLOCK union_list CLOSEBLOCK
         ;

union_list: type ID ENDLINE
          | union_list type ID ENDLINE
          ;

type_def: TYPEDEF type ID
        | TYPEDEF enum_def
        | TYPEDEF struct_def
        | TYPEDEF union_def
        ;

type_enum: ENUM ID
         ;

type_struct: STRUCT ID
           ;

type_union: UNION ID
          ;

accesses: /* empty */
        | accesses access
        ;

access: OPENARRAY expr CLOSEARRAY
      ;

literal: LITERALSTRING
       | LITERALCHAR
       | NULLT
       ;

%%

/* Error reporting function */
void yyerror(const char *s) {
    fprintf(stderr, "\033[0;31mErro Arcano...\033[0m A linha %d do grimório contém problemas.\n", line_number);
}

int main() {
    current_table = create_symbol_table(NULL);
    yyparse();
    printf("Parsing complete\n");
    print_table(current_table);
    return 0; 
}
