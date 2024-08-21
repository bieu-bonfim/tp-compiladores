%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "structures/SymbolTable.h"
#include "structures/Expression.h"
#include "structures/Operators.h"

extern int yyparse();
extern int invalid_found;
extern char invalid_chars[];
extern int line_number;

void yyerror(const char *s);

SymbolTable *current_table;
Expression *evaluate_arithmetic(Expression left, Expression right, ArOp op);
Expression *evaluate_relational(Expression left, Expression right, RelOp op);
Expression *evaluate_and(Expression left, Expression right);
Expression *evaluate_or(Expression left, Expression right);
Expression *evaluate_not(Expression expr);
Expression *id_to_expression(char *id);
void* perform_arithmetic(Expression left, Expression right, ArOp op);
void* perform_int_arithmetic(void *left, void *right, ArOp op);
void* perform_float_arithmetic(void *left, void *right, ArOp op);
void* perform_double_arithmetic(void *left, void *right, ArOp op);
void* perform_long_arithmetic(void *left, void *right, ArOp op);
void* perform_short_arithmetic(void *left, void *right, ArOp op);
Expression* create_expression(Type type, void *value);
void assign_value_to_symbol(Symbol *symbol, Expression *expr);
void assign_value_to_expression(Symbol *symbol, Expression *expr);
void apply_unary_operation(Expression *result, Expression *operand, int operation);

int yylex(void);

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
}



%token <ival> INT
%token <fval> FLOAT
%token <sval> ID
%token <sval> LITERALSTRING
%token <cval> LITERALCHAR
%token <ival> TRUE
%token <ival> FALSE
%token <relOp> RELOP
%token <logOp> AND OR NOT
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
%left OR    
%left POINT DOT

%type <param> argument
%type <param> arguments
%type <param> params
%type <param> param
%type <type> type
%type <result> assignment
%type <result> opt_assignment
%type <result> expr
%type <result> term
%type <result> literal
%type <symbol> variable
%type <result> bool
%type <result> function_call
%type <result> unary_expr


%%

begin: start
     ;

start: /* empty */
      | start start_item
      ;

start_item: decl_stmt
          | decl_func
          | decl_import
          | unary_expr ENDLINE
          ;

decl_import: IMPORT LITERALSTRING ENDLINE
           ;

decl_func: DECLFUNC type ID PARAMS OPENBRACK arguments CLOSEBRACK stmt_block
           {
            Function *func = create_function($2);
            Param *param = $6;
            add_parameter_list(func, &param);
            Symbol *new_symbol = insert_symbol(current_table, $3, TYPE_FUNC, (void*)func);
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

assignment: variable ASSIGN expr
           {
            Symbol *symbol = lookup_symbol(current_table, $1->name);
            if (symbol == NULL) {
                yyerror("Variable not found...\n");
            } else {
                assign_value_to_symbol(symbol, $3);
            }
           }
          ;

opt_assignment: /* empty */ 
               { 
                Expression *expression = (Expression*)malloc(sizeof(Expression)); 
                expression->type = TYPE_VOID;
                expression->value = NULL;
                $$ = expression; 
               }
              | ASSIGN expr 
              { 
               $$ = $2; 
              }
              ;

decl_var: type type_qualifier ID opt_assignment
          { 
           if ($4->type != $1 && $4->type != TYPE_VOID) {
             yyerror("Variavel nao inicializada com o tipo correto...\n");
           }
           Symbol *new_symbol = insert_symbol(current_table, $3, $1, $4->value); 
          }
        | type ID opt_assignment 
          { 
           if ($3->type != $1 && $3->type != TYPE_VOID) {
             yyerror("Variavel nao inicializada com o tipo correto...\n");
           }
           Symbol *new_symbol = insert_symbol(current_table, $2, $1, $3->value); 
          }
        ;

type_qualifier: CONST
              | VOLATILE
              | VOLATILE CONST
              ;

sign_func: type ID PARAMS 
         ;

expr: expr AROP term { $$ = evaluate_arithmetic(*$1, *$3, $2); }
    | expr RELOP term { $$ = evaluate_relational(*$1, *$3, $2); }
    | expr AND term { $$ = evaluate_and(*$1, *$3); }
    | expr OR term { $$ = evaluate_or(*$1, *$3); }
    | NOT expr { $$ = evaluate_not(*$2); }
    | term { $$ = $1; }
    ;

term: literal { $$ = $1; }
    | INT 
    { 
     Expression *result = create_expression(TYPE_INT, NULL);
     result->value = malloc(sizeof(int));
     *(int*)result->value = $1;
     $$ = result; 
    }
    | FLOAT 
    {
     Expression *result = create_expression(TYPE_FLOAT, NULL);
     result->value = malloc(sizeof(float));
     *(float*)result->value = $1;
     $$ = result; 
    }
    | variable 
    { 
     Expression *result = create_expression($1->type, NULL);
     assign_value_to_expression($1, result);
     $$ = result; 
    }
    | bool { $$ = $1; }
    | function_call { $$ = $1; }
    | unary_expr { $$ = $1; }
    | OPENBRACK expr CLOSEBRACK { $$ = $2; }
    ;

variable: ID accesses attributes
         {
          Symbol *symbol = lookup_symbol(current_table, $1);
          if (symbol == NULL) {
            yyerror("Variavel nao encontrada...\n");
          }
          $$ = symbol;
         }
        ;

attributes: /* empty */
          | attributes DOT ID accesses
          | attributes POINT ID accesses
          ;

bool: TRUE 
     {  
      Expression *result = (Expression*)malloc(sizeof(Expression));
      result->type = TYPE_BOOL;
      int *value = (int*)malloc(sizeof(int));
      *value = 1;
      result->value = (void*)value;
      $$ = result;
     }
    | FALSE
     {
      Expression *result = (Expression*)malloc(sizeof(Expression));
      result->type = TYPE_BOOL;
      int *value = (int*)malloc(sizeof(int));
      *value = 0;
      result->value = (void*)value;
      $$ = result;
     }
    ;

function_call: CALLFUNC ID PARAMS OPENBRACK params CLOSEBRACK
              {
                Symbol *symbol = lookup_symbol(current_table, $2);
                if (symbol == NULL) {
                  yyerror("Funcao nao encontrada...\n");
                }
                if (symbol->type != TYPE_FUNC) {
                  yyerror("Simbolo nao e uma funcao...\n");
                }
                Function *func = (Function *)symbol->value;
                Param *param = $5;
                if (func->params != NULL) {
                  if (param_list_length(param) != param_list_length(func->params)) {
                    yyerror("Numero de parametros incorreto...\n");
                  }
                  print_function(*func);
                  Param *current = func->params;
                  while (current != NULL) {
                    if (current->type != param->type) {
                      yyerror("Tipo de parametro incorreto...\n");
                    }
                    current = current->next;
                    param = param->next;
                  }
                }
                printf("Calling function %s\n", $2);
                Expression *result = create_expression(func->type, NULL);
                // TODO: Call function
                result->value = allocate_and_initialize(result->type);
                $$ = result;
              }
             ;

unary_expr: MINUSONE variable 
          { 
           Expression *result = create_expression($2->type, NULL);
           assign_value_to_expression($2, result);
           $$ = result; 
          }
          | PLUSONE variable 
          { 
           Expression *result = create_expression($2->type, NULL);
           assign_value_to_expression($2, result);
           $$ = result; 
          }
          | DEREF variable 
          { 
           Expression *result = create_expression($2->type, NULL);
           assign_value_to_expression($2, result);
           $$ = result; 
          }
          | REF variable 
          { 
           Expression *result = create_expression($2->type, NULL);
           assign_value_to_expression($2, result);
           $$ = result; 
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
      Param *param = create_param("", $1->type);
      $$ = param; 
     }
     | expr COMMA param 
     { 
      Param *param = create_param("", $1->type);
      link_params(param, $3);
      $$ = param; 
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
        Expression *result = create_expression(TYPE_STRING, NULL);        
        result->value = malloc(sizeof(char) * (strlen($1) + 1));
        strcpy((char*)result->value, $1);
        $$ = result;
       }
       | LITERALCHAR 
       { 
        Expression *result = create_expression(TYPE_CHAR, NULL);
        result->value = malloc(sizeof(char));
        *(char*)result->value = $1;
        $$ = result;
       }
       | NULLT 
       { 
        Expression *result = create_expression(TYPE_VOID, NULL);
        $$ = result; 
       }
       ;

%%

/* Error reporting function */
void yyerror(const char *s) {
    fprintf(stderr, "\033[0;31mErro Arcano...\033[0m A linha %d do grimório contém problemas.\n", line_number);
    fprintf(stderr, "%s\n", s);
}

int main() {
    current_table = create_symbol_table(NULL);
    yyparse();
    printf("Parsing complete\n");
    print_table(current_table);
    return 0; 
}

Expression* evaluate_arithmetic(Expression left, Expression right, ArOp op) {
    Expression *result = (Expression*)malloc(sizeof(Expression));
    
    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    result->value = perform_arithmetic(left, right, op);
    result->type = left.type;
    return result;
}

void* perform_arithmetic(Expression left, Expression right, ArOp op) {
    switch (left.type) {
        case TYPE_INT:
            return perform_int_arithmetic(left.value, right.value, op);
        case TYPE_FLOAT:
            return perform_float_arithmetic(left.value, right.value, op);
        case TYPE_DOUBLE:
            return perform_double_arithmetic(left.value, right.value, op);
        case TYPE_LONG:
            return perform_long_arithmetic(left.value, right.value, op);
        case TYPE_SHORT:
            return perform_short_arithmetic(left.value, right.value, op);
        default:
            yyerror("Tipo de variavel nao suportado...\n");
    }
}

void* perform_int_arithmetic(void *left, void *right, ArOp op) {
    int *l = (int*)left;
    int *r = (int*)right;
    int *result = (int*)malloc(sizeof(int));
    switch (op) {
        case PLUS:
            *result = *l + *r;
            break;
        case MINUS:
            *result = *l - *r;
            break;
        case MULT:
            *result = *l * *r;
            break;
        case DIV:
            *result = *l / *r;
            break;
        case MOD:
            *result = *l % *r;
            break;
    }
    return (void*)result;
}

void *perform_float_arithmetic(void *left, void *right, ArOp op) {
    float *l = (float*)left;
    float *r = (float*)right;
    float *result = (float*)malloc(sizeof(float));
    switch (op) {
        case PLUS:
            *result = *l + *r;
            break;
        case MINUS:
            *result = *l - *r;
            break;
        case MULT:
            *result = *l * *r;
            break;
        case DIV:
            *result = *l / *r;
            break;
        case MOD:
            yyerror("Operacao nao suportada para floats...\n");
            break;
    }
    return (void*)result;
}

void *perform_double_arithmetic(void *left, void *right, ArOp op) {
    double *l = (double*)left;
    double *r = (double*)right;
    double *result = (double*)malloc(sizeof(double));
    switch (op) {
        case PLUS:
            *result = *l + *r;
            break;
        case MINUS:
            *result = *l - *r;
            break;
        case MULT:
            *result = *l * *r;
            break;
        case DIV:
            *result = *l / *r;
            break;
        case MOD:
            yyerror("Operacao nao suportada para doubles...\n");
            break;
    }
    return (void*)result;
}

void *perform_long_arithmetic(void *left, void *right, ArOp op) {
    long *l = (long*)left;
    long *r = (long*)right;
    long *result = (long*)malloc(sizeof(long));
    switch (op) {
        case PLUS:
            *result = *l + *r;
            break;
        case MINUS:
            *result = *l - *r;
            break;
        case MULT:
            *result = *l * *r;
            break;
        case DIV:
            *result = *l / *r;
            break;
        case MOD:
            *result = *l % *r;
            break;
    }
    return (void*)result;
}

void *perform_short_arithmetic(void *left, void *right, ArOp op) {
    short *l = (short*)left;
    short *r = (short*)right;
    short *result = (short*)malloc(sizeof(short));
    switch (op) {
        case PLUS:
            *result = *l + *r;
            break;
        case MINUS:
            *result = *l - *r;
            break;
        case MULT:
            *result = *l * *r;
            break;
        case DIV:
            *result = *l / *r;
            break;
        case MOD:
            *result = *l % *r;
            break;
    }
    return (void*)result;
}

Expression* evaluate_relational(Expression left, Expression right, RelOp op) {
    Expression *result = (Expression*)malloc(sizeof(Expression));
    result->type = TYPE_BOOL;
    int* value = (int*)malloc(sizeof(int));

    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    switch (op) {
        case GT:
            *value = (int*)left.value > (int*)right.value;
            break;
        case LT:
            *value = (int*)left.value < (int*)right.value;
            break;
        case GE:
            *value = (int*)left.value >= (int*)right.value;
            break;
        case LE:
            *value = (int*)left.value <= (int*)right.value;
            break;
        case EQ:
            *value = (int*)left.value == (int*)right.value;
            break;
        case NE:
            *value = (int*)left.value != (int*)right.value;
            break;
    }
    result->value = (void*)value;
    return result;
}

Expression *evaluate_and(Expression left, Expression right) {
    Expression *result = (Expression*)malloc(sizeof(Expression));
    result->type = TYPE_BOOL;
    int* value = (int*)malloc(sizeof(int));

    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    *value = (int*)left.value && (int*)right.value;
    result->value = (void*)value;
    return result;
}

Expression* evaluate_or(Expression left, Expression right) {
    Expression* result = (Expression*)malloc(sizeof(Expression));
    result->type = TYPE_BOOL;
    int* value = (int*)malloc(sizeof(int));

    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    *value = (int*)left.value || (int*)right.value;
    result->value = (void*)value;
    return result;
}

Expression* evaluate_not(Expression expr) {
    Expression *result = (Expression*)malloc(sizeof(Expression));
    if (expr.type != TYPE_BOOL) {
        yyerror("Tipos incompativeis...\n");
    }
    int* value = (int*)malloc(sizeof(int));

    result->type = TYPE_BOOL;
    *value = (!(int*)expr.value);
    result->value = (void*)value;
    return result;
}

Expression* id_to_expression(char *id) {
    Symbol *symbol = lookup_symbol(current_table, id);
    if (symbol == NULL) {
        yyerror("Variavel nao encontrada...\n");
    }
    Expression *result = (Expression*)malloc(sizeof(Expression));
    result->type = symbol->type;
    result->value = symbol->value;
    return result;
}

Expression* create_expression(Type type, void *value) {
    Expression *expression = (Expression*)malloc(sizeof(Expression));
    expression->type = type;
    expression->value = value;
    return expression;
}

void assign_value_to_symbol(Symbol *symbol, Expression *expr) {
    if (symbol == NULL || expr == NULL) {
        yyerror("Invalid symbol or expression...\n");
        return;
    }

    if (symbol->type != expr->type) {
        yyerror("Incompatible types...\n");
        return;
    }

    if (symbol->value != NULL) {
        free(symbol->value);
    }

    switch (expr->type) {
        case TYPE_INT:
            symbol->value = malloc(sizeof(int));
            if (symbol->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(int*)symbol->value = *(int*)expr->value;
            break;

        case TYPE_FLOAT:
            symbol->value = malloc(sizeof(float));
            if (symbol->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(float*)symbol->value = *(float*)expr->value;
            break;

        case TYPE_DOUBLE:
            symbol->value = malloc(sizeof(double));
            if (symbol->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(double*)symbol->value = *(double*)expr->value;
            break;

        case TYPE_LONG:
            symbol->value = malloc(sizeof(long));
            if (symbol->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(long*)symbol->value = *(long*)expr->value;
            break;

        case TYPE_SHORT:
            symbol->value = malloc(sizeof(short));
            if (symbol->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(short*)symbol->value = *(short*)expr->value;
            break;

        case TYPE_BOOL:
            symbol->value = malloc(sizeof(_Bool));
            if (symbol->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(_Bool*)symbol->value = *(_Bool*)expr->value;
            break;

        case TYPE_CHAR:
            symbol->value = malloc(sizeof(char));
            if (symbol->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(char*)symbol->value = *(char*)expr->value;
            break;
        default:
            yyerror("Unknown data type...\n");
            return;
    }
}


void assign_value_to_expression(Symbol *symbol, Expression *expr) {
    if (symbol == NULL || expr == NULL) {
        yyerror("Invalid symbol or expression...\n");
        return;
    }

    if (symbol->type != expr->type) {
        yyerror("Incompatible types...\n");
        return;
    }

    switch (symbol->type) {
        case TYPE_INT:
            expr->value = malloc(sizeof(int));
            if (expr->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(int*)expr->value = *(int*)symbol->value;
            break;

        case TYPE_FLOAT:
            expr->value = malloc(sizeof(float));
            if (expr->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(float*)expr->value = *(float*)symbol->value;
            break;

        case TYPE_DOUBLE:
            expr->value = malloc(sizeof(double));
            if (expr->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(double*)expr->value = *(double*)symbol->value;
            break;

        case TYPE_LONG:
            expr->value = malloc(sizeof(long));
            if (expr->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(long*)expr->value = *(long*)symbol->value;
            break;

        case TYPE_SHORT:
            expr->value = malloc(sizeof(short));
            if (expr->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(short*)expr->value = *(short*)symbol->value;
            break;

        case TYPE_BOOL:
            expr->value = malloc(sizeof(_Bool));
            if (expr->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(_Bool*)expr->value = *(_Bool*)symbol->value;
            break;

        case TYPE_CHAR:
            expr->value = malloc(sizeof(char));
            if (expr->value == NULL) {
                yyerror("Memory allocation error...\n");
                return;
            }
            *(char*)expr->value = *(char*)symbol->value;
            break;
        default:
            yyerror("Unknown data type...\n");
            return;
    }
}

void apply_unary_operation(Expression *result, Expression *operand, int operation) {
    switch (operation) {
        case MINUSONE:
            if (operand->type == TYPE_INT) {
                int value = *(int*)operand->value;
                value--;
                result->value = malloc(sizeof(int));
                *(int*)result->value = value;
            } else if (operand->type == TYPE_FLOAT) {
                float value = *(float*)operand->value;
                value--;
                result->value = malloc(sizeof(float));
                *(float*)result->value = value;
            }
            // Handle other types...
            break;

        case PLUSONE:
            if (operand->type == TYPE_INT) {
                int value = *(int*)operand->value;
                value++;
                result->value = malloc(sizeof(int));
                *(int*)result->value = value;
            } else if (operand->type == TYPE_FLOAT) {
                float value = *(float*)operand->value;
                value++;
                result->value = malloc(sizeof(float));
                *(float*)result->value = value;
            }
            // Handle other types...
            break;

        case DEREF:
            // Assuming operand->value holds a pointer:
            result->value = *(void**)operand->value;
            break;

        case REF:
            // Assuming operand->value is a regular value:
            result->value = &operand->value;
            break;

        default:
            yyerror("Invalid unary operation.");
    }
    result->type = operand->type;
}
