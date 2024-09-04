%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "structures/SymbolTable.h"
#include "structures/Expression.h"
#include "structures/Operators.h"
#include "structures/AST/AST.h"
#include "structures/Types.h"
#include "structures/TAC/TAC.h"
#include "structures/AST/Colors.h"

extern int yyparse();
extern int invalid_found;
extern char invalid_chars[];
extern int line_number;
int error_found = 0;

void yyerror(const char *s);

SymbolTable *current_table;
SymbolTable *global_table;
ASTNode *ast;

int yylex(void);
void semantic_analysis(ASTNode *node, SymbolTable *table);

%}

%code requires {
#include "structures/AST/AST.h"
#include "structures/SymbolTable.h"
#include "structures/Expression.h"
#include "structures/Operators.h"
#include "structures/Types.h"
#include "structures/TAC/TAC.h"
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

decl_import: IMPORT LITERALSTRING ENDLINE 
           { 
            $$ = create_import_node($2); 
            $$->line = line_number;
           }
           ;

decl_func: DECLFUNC type ID PARAMS OPENBRACK arguments CLOSEBRACK stmt_block
           {
            Function *func = create_function($2);
            Param *param = $6;
            add_parameter_list(func, &param);

            ASTNode *node = create_func_node($3, func, $2, $8);

            $$ = node;
            $$->line = line_number;
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
           $$->line = line_number;
          }
          ;

stmt_if: IF expr stmt_block stmt_else
       {
        $$ = create_if_node($2, $3, $4);
        $$->line = line_number;
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
            $$->line = line_number;
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
          $$->line = line_number;
         }
         ;

default_case: /* empty */
            {
             $$ = NULL;
            }
            | DEFAULT DELIMCASE stmts stmt_break
            {
             $$ = create_case_node(NULL, $3, 1);
             $$->line = line_number;
            }
            ;

stmt_return: RETURNT expr ENDLINE
           {
            $$ = create_return_node($2);
            $$->line = line_number;
           }
           ;

stmt_for: FOR expr COMMA unnary_expr stmt_block
         {
          $$ = create_for_node($2, $4, $5);
          $$->line = line_number;
         }
        ;

stmt_while: WHILE expr stmt_block
          {
            $$ = create_while_node($2, $3);
            $$->line = line_number;
          }
          ;

stmt_break: BREAK ENDLINE
          {
            $$ = create_break_node();
            $$->line = line_number;
          }
          ;

stmt_continue: CONTINUE ENDLINE
             {
              $$ = create_continue_node();
              $$->line = line_number;
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
           $$->line = line_number;
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
          $$ = create_var_decl_node($3, $1, $4);
          $$->line = line_number;
        }
        | type ID opt_assignment 
        {
          $$ = create_var_decl_node($2, $1, $3);
          $$->line = line_number;
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
     $$->line = line_number;
    }
    | expr RELOP term 
    { 
     $$ = create_bin_relop_node($1, $3, $2); 
     $$->line = line_number;
    }
    | expr LOGOP term 
    { 
     $$ = create_bin_logop_node($1, $3, $2); 
     $$->line = line_number;
    }
    | NOT expr 
    { 
     $$ = create_unop_node($2, NOTOP); 
     $$->line = line_number;
    }
    | term { $$ = $1; }
    ;

term: literal { $$ = $1; }
    | INT 
    { 
     $$ = create_int_node($1); 
     $$->line = line_number;
    }
    | FLOAT 
    { 
     $$ = create_float_node($1); 
     $$->line = line_number;
    }
    | variable { $$ = $1; }
    | bool { $$ = $1; }
    | function_call { $$ = $1; }
    | unnary_expr { $$ = $1; }
    | OPENBRACK expr CLOSEBRACK { $$ = $2; }
    ;

variable: ID accesses attributes
         {
          $$ = create_var_ref_node($1);
          $$->line = line_number;
         }
        ;

attributes: /* empty */
          | attributes DOT ID accesses
          | attributes POINT ID accesses
          ;

bool: TRUE 
     {  
      $$ = create_bool_node(1);
      $$->line = line_number;
     }
    | FALSE
     {
      $$ = create_bool_node(0);
      $$->line = line_number;
     }
    ;

function_call: CALLFUNC ID PARAMS OPENBRACK params CLOSEBRACK
             {
              $$ = create_func_call_node($2, $5);
              $$->line = line_number;
             }
             ;

unnary_expr: MINUSONE variable 
          { 
            $$ = create_unop_node($2, MINUSONEOP);
            $$->line = line_number;
          }
          | PLUSONE variable 
          { 
            $$ = create_unop_node($2, PLUSONEOP);
            $$->line = line_number;
          }
          | DEREF variable 
          { 
            $$ = create_unop_node($2, DEREFOP);
            $$->line = line_number;
          }
          | REF variable 
          { 
            $$ = create_unop_node($2, REFOP);
            $$->line = line_number;
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
    global_table = create_symbol_table(NULL);
    current_table = global_table;
    yyparse();
    if (error_found) {
        printf("\n\n"RED_TEXT"-- Codigo sintaticamente incorreto.--"RESET"\n");
    } else {
        printf("\n\n"GREEN_TEXT"--Codigo sintaticamente correto.--"RESET"\n");
    }
    printf("\n");
    semantic_analysis(ast, current_table);
    traverse_ast(ast, 0);
    print_table(current_table);
    return 0; 
}

void semantic_analysis(ASTNode *node, SymbolTable *table) {
 if (node == NULL) return;

  switch (node->type) {
    case AST_TYPE_VAR_DECL:
      if (lookup_symbol(current_table, node->data.var_decl.var_name)) {
        printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" Essencia "PINK_TEXT"'%s'"RESET" ja usada no escopo atual.\n\n", node->line, node->data.var_decl.var_name);
      }

      insert_symbol(current_table, node->data.var_decl.var_name, node->data.var_decl.var_type, NULL);

      if (node->data.var_decl.expr != NULL) {
        semantic_analysis(node->data.var_decl.expr, current_table);

        if (node->data.var_decl.var_type != node->data.var_decl.expr->data_type) {
          printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" Tipo incompativel com a essencia "PINK_TEXT"'%s'"RESET" para inicializacao.\n", node->line, node->data.var_decl.var_name);
        }
      }
      break;
    case AST_TYPE_ASSIGN:
      Symbol *sym = lookup_symbol(table, node->data.assign.var_name);
      if (sym == NULL) {
        // nao declarada
      }

      semantic_analysis(node->data.assign.expr, table);
      if (node->data.assign.expr->data_type != sym->type) {
        printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" Tipo incompativel com a essencia " PINK_TEXT "'%s'" RESET".\n", node->line, node->data.assign.var_name);
      }

      break;
    case AST_TYPE_FUNC:
      if (lookup_symbol(current_table, node->data.func.func_name)) {
        printf("(Line %d) "PINK_TEXT"Erro Mistico:"RESET" Magia "GREEN_TEXT"'%s'"RESET" ja preparada neste escopo.\n", node->line, node->data.func.func_name);
      }
      insert_symbol(current_table, node->data.func.func_name, TYPE_FUNC, (void*)node->data.func.func);
      break;
    case AST_TYPE_FUNC_CALL:
      Symbol *func = lookup_symbol(current_table, node->data.func_call.func_name);
      if (func == NULL) {
        printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" Magia "GREEN_TEXT"'%s'"RESET" nao declarada nesse escopo.\n", node->line, node->data.func_call.func_name);
      } else if (func->type != TYPE_FUNC) {
        printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" "GREEN_TEXT"'%s'"RESET" nao e uma magia conhecida.\n", node->line, node->data.func_call.func_name);
      } else {
        Function *function = (Function*)func->value;
        Param *param = function->params;
        ASTNodeList *arg = node->data.func_call.args;
        while (param != NULL && arg != NULL) {
          semantic_analysis(arg->node, current_table);
          if (param->type != arg->node->data_type) {
            printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" Tipos de ingredientes incompativeis na conjuracao da magia.\n", node->line);
          }
          param = param->next;
          arg = arg->next;
        }
        if (param != NULL || arg != NULL) {
          printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" Numero de ingredientes incompativel.\n", node->line);
        }
      }
      break;
    case AST_TYPE_BIN_AROP:
      semantic_analysis(node->data.bin_arop.left, current_table);
      semantic_analysis(node->data.bin_arop.right, current_table);
      if (node->data.bin_arop.left->data_type != node->data.bin_arop.right->data_type) {
        printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" Tipos incompativeis na manipulacao aritmetica.\n", node->line);
      }
      if ((node->data.bin_arop.left->data_type != TYPE_INT || node->data.bin_arop.right->data_type != TYPE_INT) && node->data.bin_arop.op == MOD) {
        printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" Tipo invalido para operacao aritmetica.\n", node->line);
      }
      node->data_type = node->data.bin_arop.left->data_type;
      break;
    case AST_TYPE_BIN_RELOP:
      semantic_analysis(node->data.bin_relop.left, current_table);
      semantic_analysis(node->data.bin_relop.right, current_table);
      if (node->data.bin_relop.left->data_type != node->data.bin_relop.right->data_type) {
        printf("(Line %d) "PINK_TEXT"Erro Mistico:"RESET" Tipos incompativeis na manipulacao relacional.\n", node->line);
      }
      node->data_type = TYPE_BOOL;
      break;
    case AST_TYPE_BIN_LOGOP:
      semantic_analysis(node->data.bin_logop.left, current_table);
      semantic_analysis(node->data.bin_logop.right, current_table);
      if (node->data.bin_logop.left->data_type != node->data.bin_logop.right->data_type) {
        printf("(Line %d) "PINK_TEXT"Erro Mistico:"RESET" Tipos incompativeis na manipulacao logica.\n", node->line);
      }
      node->data_type = TYPE_BOOL;
      break;
    case AST_TYPE_UNOP_NOT:
      semantic_analysis(node->data.unnop.expr, current_table);
      if (node->data.unnop.expr->data_type != TYPE_BOOL) {
        printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" Tipo nao permitido para operador de negacao unario.\n", node->line);
      }
      break;
    case AST_TYPE_UNOP:
      semantic_analysis(node->data.unnop.expr, current_table);
      if (node->data.unnop.expr->data_type != TYPE_INT) {
        printf("(Line %d) "PINK_TEXT"Erro Mistico:"RESET" Tipos incompativeis na manipulacao de atualizao unaria.\n", node->line);
      }
      break;
    case AST_TYPE_VAR:
      Symbol *var = lookup_symbol(current_table, node->data.var_name);
      if (var == NULL) {
        printf("(Line %d) "PINK_TEXT"Erro Mistico:"RESET" Essencia "PINK_TEXT"'%s'"RESET" nao infundida neste escopo.\n", node->line, node->data.var_name);
      } else {
        node->data_type = var->type;
      }
      break;
    case AST_TYPE_INT:
      node->data_type = TYPE_INT;
      break;
    case AST_TYPE_FLOAT:
      node->data_type = TYPE_FLOAT;
      break;
    case AST_TYPE_BOOL:
      node->data_type = TYPE_BOOL;
      break;
    case AST_TYPE_CHAR:
      node->data_type = TYPE_CHAR;
      break;
    case AST_TYPE_STRING:
      node->data_type = TYPE_STRING;
      break;
    case AST_TYPE_NULL:
      node->data_type = TYPE_NULL;
      break;
    case AST_TYPE_BLOCK:
      current_table = create_symbol_table(current_table);
      ASTNodeList *stmt = node->children;
      while (stmt != NULL) {
        semantic_analysis(stmt->node, current_table);
        stmt = stmt->next;
      }
      current_table = current_table->parent;
      break;
    case AST_TYPE_IF:
      semantic_analysis(node->data.if_node.condition, current_table);
      if (node->data.if_node.condition->data_type != TYPE_BOOL) {
        printf("(Line %d) "PINK_TEXT"Erro Mistico:"RESET" Erro de tipos durante ponderamento.\n", node->line);
      }
      semantic_analysis(node->data.if_node.body_branch, current_table);
      if (node->data.if_node.else_branch != NULL) {
        semantic_analysis(node->data.if_node.else_branch, current_table);
      }
      break;
    case AST_TYPE_SWITCH:
      semantic_analysis(node->data.switch_node.condition, current_table);
      ASTNodeList *case_stmt = node->data.switch_node.cases;
      while (case_stmt != NULL) {
        semantic_analysis(case_stmt->node, current_table);
        case_stmt = case_stmt->next;
      }
      break;
    case AST_TYPE_CASE:
      if (node->data.case_node.case_expr != NULL) {
        semantic_analysis(node->data.case_node.case_expr, current_table);
      }
      current_table = create_symbol_table(current_table);
      ASTNodeList *stmts = node->data.case_node.stmts;
      while (stmts != NULL) {
        semantic_analysis(stmts->node, current_table);
        stmts = stmts->next;
      }
      current_table = current_table->parent;
      break;
    case AST_TYPE_FOR:
      semantic_analysis(node->data.for_node.condition, current_table);
      if (node->data.for_node.condition->data_type != TYPE_BOOL) {
        printf("(Line %d) "PINK_TEXT"Erro Mistico:"RESET" Erro de tipos na fratura temporal.\n", node->line);
      }
      semantic_analysis(node->data.for_node.update, current_table);
      semantic_analysis(node->data.for_node.body, current_table);
      break;
    case AST_TYPE_WHILE:
      semantic_analysis(node->data.while_node.condition, current_table);
      if (node->data.while_node.condition->data_type != TYPE_BOOL) {
        printf("(Linha %d) "PINK_TEXT"Erro Mistico:"RESET" Tipos incompativeis na dilatacao temporal.\n", node->line);
      }
      semantic_analysis(node->data.while_node.body, current_table);
      break;
    case AST_TYPE_BREAK:
      break;
    case AST_TYPE_CONTINUE:
      break;
    case AST_TYPE_RETURN:
      semantic_analysis(node->data.return_node.expr, current_table);
      break;
    default:
      break;
  }

  ASTNodeList *child = node->children;
  while (child != NULL) {
      semantic_analysis(child->node, current_table);
      child = child->next;
  }
}