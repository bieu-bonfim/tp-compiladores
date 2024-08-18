%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
%}

%token PLUS MINUS MULT DIV MOD ASSIGN ENDLINE
%token INT FLOAT TRUE FALSE ID
%token LITERAL
%token IMPORT
%token PREPARE

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

decl_func: PREPARE tipo ID COMPONENTS arguments stmt_block
         ;

decl_stmt: assignment ENDLINE
         // | def_type ENDLINE
         // | sign_func ENDLINE
         ;

stmt_block: OPENBLOCK stmts CLOSEBLOCK
          ;

stmts: /* empty */

arguments: /* empty */
         | OPENBRACK params CLOSEBRACK
         ;

assignment: ID ASSIGN expr
          ;

expr: term
    | expr PLUS term
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
    | expr NOT term
    ;

term: LITERAL
    | variable
    | bool
    | function_call
    // | ternary_expr
    | unary_expr
    | '[' expr ']'
    ;

variable: ID 
        ;

bool: TRUE
    | FALSE
    ;

function_call: CONJURE ID OPENBRACK params CLOSEBRACK
             ;

unary_expr: MINUSONE variable
          | PLUSONE variable
          | DEREF variable
          | REF variable
          ;

params: /* empty */
      | expr
      | params ', ' expr
      ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    return yyparse();
}
