%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "structures/SymbolTable.h"
#include "structures/Expression.h"
#include "structures/Operators.h"
#include "structures/AST/AST.h"

extern int yyparse();
extern int invalid_found;
extern char invalid_chars[];
extern int line_number;
int error_found = 0;

void yyerror(const char *s);

SymbolTable *current_table;
ASTNode *ast;

int yylex(void);
void semantic_analisys(ASTNode *node, SymbolTable *table);

%}

%code requires {
#include "structures/SymbolTable.h"
#include "structures/Expression.h"
#include "structures/Operators.h"
}

%union {
    int ival;
    float fval;
    char *sval;
    char cval;
    Symbol *symbol;
    Type type;
    Param *param;
    Expression *result;
    ArOp arOp;
    RelOp relOp;
    LogOp logOp;
    struct ASTNodeList *node_list;
    struct ASTNode *node;
}



%token <ival> INT
%token <fval> FLOAT
%token <sval> ID
%token <sval> LITERALSTRING
%token <cval> LITERALCHAR
%token <ival> TRUE
%token <ival> FALSE
%token <relOp> RELOP
%token <logOp> LOGOP NOT
%token <arOp> AROP

%token ASSIGN ENDLINE
%token COMMA REF DEREF DELIMCASE WHILE FOR IF ELSE SWITCH CASE DEFAULT TYPEDEF STRUCT UNION
%token PLUSONE MINUSONE OPENBLOCK CLOSEBLOCK OPENARRAY CLOSEARRAY NULLT
%token IMPORT OPENBRACK CLOSEBRACK BREAK CONTINUE 
%token ENUM CONJUNCTURE GOTO QUOTE POINT DOT
%token PARAMS CALLFUNC DECLFUNC RETURNT CONST VOLATILE
%token TYPEINT TYPEFLOAT TYPEBOOL TYPECHAR TYPEVOID TYPESHORT TYPEDOUBLE TYPELONG

%start begin

%right NOT         
%left RELOP       
%left AROP              
%left AND                 
%left LOGOP                 
%left OR    
%left POINT DOT

%type <param> argument
%type <param> arguments
%type <type> type
%type <node> assignment
%type <node> opt_assignment
%type <node> expr
%type <node> term
%type <node> variable

%type <node_list> start stmts param params
%type <node> start_item decl_func stmt_block decl_import unnary_expr bool function_call literal stmt decl_var decl_stmt stmt_continue
%type <node> stmt_break stmt_return stmt_for stmt_while stmt_if stmt_switch stmt_else
%type <node> case_stmt default_case 
%type <node_list> case_list
%type sign_func type_def

%%

begin: start { ast = create_root_node($1); }
     ;

start: /* empty */ { $$ = NULL; }
      | start start_item { $$ = append_to_list($1, $2); }
      ;

start_item: decl_func { $$ = $1; }
          | decl_import { $$ = $1; }
          | stmt { $$ = $1; }
          | unnary_expr ENDLINE { $$ = $1; }
          ;

decl_import: IMPORT LITERALSTRING ENDLINE { $$ = create_import_node($2); }
           ;

decl_func: DECLFUNC type ID PARAMS OPENBRACK arguments CLOSEBRACK stmt_block
           {
            Function *func = create_function($2);
            Param *param = $6;
            add_parameter_list(func, &param);

            ASTNode *node = create_func_node($3, func, $2, $8);

            $$ = node;
           }
         ;

decl_stmt: assignment ENDLINE { $$ = $1; }
         | sign_func ENDLINE { $$ = NULL; }
         | type_def { $$ = NULL; }
         | decl_var ENDLINE { $$ = $1; }
         | function_call ENDLINE { $$ = $1; }
         ;

stmt_block: OPENBLOCK stmts CLOSEBLOCK
          {
           $$ = create_block_node($2);
          }
          ;

stmt_if: IF expr stmt_block stmt_else
       {
        $$ = create_if_node($2, $3, $4);
       }
       ;

stmt_else: ELSE stmt_block
         {
          $$ = $2;
         }
         | ELSE stmt_if
         {
          $$ = $2;
         }
         | /* empty */
         {
          $$ = NULL;
         }
         ;

stmt_switch: SWITCH expr OPENBLOCK case_list default_case CLOSEBLOCK
           {
            $$ = create_switch_node($2, $4, $5);
           }
           ;

case_list: /* empty */
         {
          $$ = NULL;
         }
         | case_list case_stmt
         {
          $$ = append_to_list($1, $2);
         }
         ;

case_stmt: CASE expr DELIMCASE stmts stmt_break
         {
          $$ = create_case_node($2, $4, 0); 
         }
         ;

default_case: /* empty */
            {
             $$ = NULL;
            }
            | DEFAULT DELIMCASE stmts stmt_break
            {
             $$ = create_case_node(NULL, $3, 1);
            }
            ;

stmt_return: RETURNT expr ENDLINE
           {
            $$ = create_return_node($2);
           }
           ;

stmt_for: FOR expr COMMA unnary_expr stmt_block
         {
          $$ = create_for_node($2, $4, $5);
         }
        ;

stmt_while: WHILE expr stmt_block
          {
            $$ = create_while_node($2, $3);
          }
          ;

stmt_break: BREAK ENDLINE
          {
            $$ = create_break_node();
          }
          ;

stmt_continue: CONTINUE ENDLINE
             {
              $$ = create_continue_node();
             }
             ;

stmts: /* empty */ { $$ = NULL; }
     | stmts stmt { $$ = append_to_list($1, $2); }
     ;

stmt: decl_stmt { $$ = $1; }
    | stmt_if { $$ = $1; }
    | stmt_switch { $$ = $1; }
    | stmt_while { $$ = $1; }
    | stmt_for { $$ = $1; }
    | stmt_return { $$ = $1; }
    | stmt_break { $$ = $1; }
    | stmt_continue { $$ = $1; }
    ;

assignment: variable ASSIGN expr
          {
           $$ = create_assign_node($1->data.var_name, $3);
          }
          ;

opt_assignment: /* empty */ 
              { 
               $$ = NULL; 
              }
              | ASSIGN expr 
              { 
               $$ = $2; 
              }
              ;

decl_var: type type_qualifier ID opt_assignment
        {
          $$ = create_var_decl_node($3, $4);
        }
        | type ID opt_assignment 
        {
          $$ = create_var_decl_node($2, $3);
        }
        ;

type_qualifier: CONST
              | VOLATILE
              | VOLATILE CONST
              ;

sign_func: type ID PARAMS arguments
         ;

expr: expr AROP term 
    { 
     $$ = create_bin_arop_node($1, $3, $2); 
    }
    | expr RELOP term 
    { 
     $$ = create_bin_relop_node($1, $3, $2); 
    }
    | expr LOGOP term 
    { 
     $$ = create_bin_logop_node($1, $3, $2); 
    }
    | NOT expr 
    { 
     $$ = create_unop_node($2, NOTOP); 
    }
    | term { $$ = $1; }
    ;

term: literal { $$ = $1; }
    | INT { $$ = create_int_node($1); }
    | FLOAT { $$ = create_float_node($1); }
    | variable { $$ = $1; }
    | bool { $$ = $1; }
    | function_call { $$ = $1; }
    | unnary_expr { $$ = $1; }
    | OPENBRACK expr CLOSEBRACK { $$ = $2; }
    ;

variable: ID accesses attributes
         {
          $$ = create_var_ref_node($1);
         }
        ;

attributes: /* empty */
          | attributes DOT ID accesses
          | attributes POINT ID accesses
          ;

bool: TRUE 
     {  
      $$ = create_bool_node(1);
     }
    | FALSE
     {
      $$ = create_bool_node(0);
     }
    ;

function_call: CALLFUNC ID PARAMS OPENBRACK params CLOSEBRACK
             {
              $$ = create_func_call_node($2, $5);
             }
             ;

unnary_expr: MINUSONE variable 
          { 
            $$ = create_unop_node($2, MINUSONEOP);
          }
          | PLUSONE variable 
          { 
            $$ = create_unop_node($2, PLUSONEOP);
          }
          | DEREF variable 
          { 
            $$ = create_unop_node($2, DEREFOP);
          }
          | REF variable 
          { 
            $$ = create_unop_node($2, REFOP);
          }
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

params: /* empty */ { $$ = NULL; }
      | param { $$ = $1; }
      ;

param: expr 
     { 
      $$ = append_to_list(NULL, $1); 
     }
     | expr COMMA param 
     { 
      $$ = append_to_list($3, $1); 
     }
     ;

type: TYPEINT { $$ = TYPE_INT; } 
    | TYPEFLOAT { $$ = TYPE_FLOAT; }
    | TYPEBOOL { $$ = TYPE_BOOL; }
    | TYPECHAR { $$ = TYPE_CHAR; }
    | TYPEVOID { $$ = TYPE_VOID; }
    | TYPEDOUBLE { $$ = TYPE_FLOAT; }
    | TYPELONG { $$ = TYPE_INT; }
    | TYPESHORT { $$ = TYPE_INT; }
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
       { 
        $$ = create_string_node($1);
       }
       | LITERALCHAR 
       { 
        $$ = create_char_node($1);
       }
       | NULLT 
       { 
        $$ = create_null_node(); 
       }
       ;

%%

/* Error reporting function */
void yyerror(const char *s) {
    fprintf(stderr, "\033[0;31mErro Arcano...\033[0m A linha %d do grimório contém problemas.\n", line_number);
    fprintf(stderr, "%s\n", s);
    error_found = 1;
}

int main() {
    printf("\n| %d | ", line_number);
    current_table = create_symbol_table(NULL);
    yyparse();
    if (error_found) {
        printf("\nCodigo sintaticamente incorreto.\n");
    } else {
        printf("\nCodigo sintaticamente correto.\n");
    }
    traverse_ast(ast, 0);
    print_table(current_table);
    return 0; 
}

void semantic_analisys(ASTNode *node, SymbolTable *table) {

}