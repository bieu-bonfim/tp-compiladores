%{
#include <stdio.h>
#include <stdlib.h>
#include "structures/SymbolTable.h"
#include "structures/Expression.h"
#include "structures/Operators.h"

extern int yyparse();
extern int invalid_found;
extern char invalid_chars[];
extern int line_number;

void yyerror(const char *s);

SymbolTable *current_table;
Expression evaluate_arithmetic(Expression left, Expression right, ArOp op);
Expression evaluate_relational(Expression left, Expression right, RelOp op);
Expression evaluate_and(Expression left, Expression right);
Expression evaluate_or(Expression left, Expression right);
Expression evaluate_not(Expression expr);
Expression id_to_expression(char *id);

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
    Type type;
    Param *param;
    Expression result;
    ArOp arOp;
    RelOp relOp;
    LogOp logOp;
    PassedParam *passedParam;
}



%token <ival> INT
%token <fval> FLOAT
%token <sval> ID
%token <sval> LITERALSTRING
%token <sval> LITERALCHAR
%token <ival> TRUE
%token <ival> FALSE
%token <relOp> RELOP
%token <logOp> AND OR NOT
%token <arOp> AROP

%token ASSIGN ENDLINE
%token COMMA REF DEREF DELIMCASE WHILE FOR IF ELSE SWITCH CASE DEFAULT TYPEDEF STRUCT UNION
%token PLUSONE MINUSONE OPENBLOCK CLOSEBLOCK OPENARRAY CLOSEARRAY NULLT
%token IMPORT OPENBRACK CLOSEBRACK BREAK CONTINUE 
%token ENUM CONJUNCTURE GOTO QUOTE
%token PARAMS CALLFUNC DECLFUNC RETURNT CONST VOLATILE
%token TYPEINT TYPEFLOAT TYPEBOOL TYPECHAR TYPEVOID TYPESHORT TYPEDOUBLE TYPELONG

%start begin

%right NOT         
%left RELOP       
%left AROP              
%left AND                 
%left OR    

%type <param> argument
%type <param> arguments
%type <param> params
%type <type> type
%type <result> assignment
%type <result> opt_assignment
%type <result> expr
%type <result> term
%type <result> literal
%type <result> variable
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
            if (symbol->type == TYPE_INT) {
              symbol->TypeVal.intVal = $3.Val.intVal;
            } else if (symbol->type == TYPE_FLOAT) {
              symbol->TypeVal.floatVal = $3.Val.floatVal;
            } else if (symbol->type == TYPE_DOUBLE) {
              symbol->TypeVal.doubleVal = $3.Val.doubleVal;
            } else if (symbol->type == TYPE_LONG) {
              symbol->TypeVal.longVal = $3.Val.longVal;
            } else if (symbol->type == TYPE_SHORT) {
              symbol->TypeVal.shortVal = $3.Val.shortVal;
            } else if (symbol->type == TYPE_BOOL) {
              symbol->TypeVal.boolVal = $3.Val.boolVal;
            }
           }
          ;

opt_assignment: /* empty */ 
               { 
                Expression expression; 
                expression.type = TYPE_VOID;
                $$ = expression; 
               }
              | ASSIGN expr { $$ = $2; }
              ;

decl_var: type type_qualifier ID opt_assignment
          { 
           if ($4.type != $1 && $4.type != TYPE_VOID) {
             yyerror("Variavel nao inicializada com o tipo correto...\n");
           }
           Symbol *new_symbol = insert_symbol(current_table, $3, $1); 
           if ($4.type != TYPE_VOID) {
             if (new_symbol->type == TYPE_INT) {
               new_symbol->TypeVal.intVal = $4.Val.intVal;
             } else if (new_symbol->type == TYPE_FLOAT) {
               new_symbol->TypeVal.floatVal = $4.Val.floatVal;
             } else if (new_symbol->type == TYPE_DOUBLE) {
               new_symbol->TypeVal.doubleVal = $4.Val.doubleVal;
             } else if (new_symbol->type == TYPE_LONG) {
               new_symbol->TypeVal.longVal = $4.Val.longVal;
             } else if (new_symbol->type == TYPE_SHORT) {
               new_symbol->TypeVal.shortVal = $4.Val.shortVal;
             } else if (new_symbol->type == TYPE_BOOL) {
               new_symbol->TypeVal.boolVal = $4.Val.boolVal;
             }
           }
          }
        | type ID opt_assignment 
          { 
           if ($3.type != $1 && $3.type != TYPE_VOID) {
             yyerror("Variavel nao inicializada com o tipo correto...\n");
           }
           Symbol *new_symbol = insert_symbol(current_table, $2, $1); 
           if ($3.type != TYPE_VOID) {
             if (new_symbol->type == TYPE_INT) {
               new_symbol->TypeVal.intVal = $3.Val.intVal;
             } else if (new_symbol->type == TYPE_FLOAT) {
               new_symbol->TypeVal.floatVal = $3.Val.floatVal;
             } else if (new_symbol->type == TYPE_DOUBLE) {
               new_symbol->TypeVal.doubleVal = $3.Val.doubleVal;
             } else if (new_symbol->type == TYPE_LONG) {
               new_symbol->TypeVal.longVal = $3.Val.longVal;
             } else if (new_symbol->type == TYPE_SHORT) {
               new_symbol->TypeVal.shortVal = $3.Val.shortVal;
             } else if (new_symbol->type == TYPE_BOOL) {
               new_symbol->TypeVal.boolVal = $3.Val.boolVal;
             }
           }
          }
        ;

type_qualifier: CONST
              | VOLATILE
              | VOLATILE CONST
              ;

sign_func: type ID PARAMS 
         ;

expr: expr AROP term { $$ = evaluate_arithmetic($1, $3, $2); }
    | expr RELOP term { $$ = evaluate_relational($1, $3, $2); }
    | expr AND term { $$ = evaluate_and($1, $3); }
    | expr OR term { $$ = evaluate_or($1, $3); }
    | NOT expr { $$ = evaluate_not($2); }
    | term { $$ = $1; }
    ;

term: literal { $$ = $1; }
    | INT { Expression result; result.type = TYPE_INT; result.Val.intVal = $1; $$ = result; }
    | FLOAT { Expression result; result.type = TYPE_FLOAT; result.Val.floatVal = $1; $$ = result; }
    | variable { $$ = $1; }
    | bool { $$ = $1; }
    | function_call { $$ = $1; }
    | unary_expr { $$ = $1; }
    | OPENBRACK expr CLOSEBRACK { $$ = $2; }
    ;

variable: ID accesses
         {
          Expression result = id_to_expression($1);
          $$ = result;
         }
        ;

bool: TRUE 
     {  
      Expression result;
      result.type = TYPE_BOOL;
      result.Val.boolVal = 1;
      $$ = result;
     }
    | FALSE
     {
      Expression result;
      result.type = TYPE_BOOL;
      result.Val.boolVal = 0;
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
                Function *func = symbol->TypeVal.funcVal;
                Param *param = $5;
                if (func->params != NULL) {
                  if (param_list_length(param) != param_list_length(func->params)) {
                    yyerror("Numero de parametros incorreto...\n");
                  }
                  Param *current = func->params;
                  while (current != NULL) {
                    if (current->type != param->type) {
                      yyerror("Tipo de parametro incorreto...\n");
                    }
                    current = current->next;
                    param = param->next;
                  }
                }
                Expression result;
                result.type = func->type;
                if (func->type == TYPE_INT) {
                  result.Val.intVal = 0;
                } else if (func->type == TYPE_FLOAT) {
                  result.Val.floatVal = 0.0;
                } else if (func->type == TYPE_DOUBLE) {
                  result.Val.doubleVal = 0.0;
                } else if (func->type == TYPE_LONG) {
                  result.Val.longVal = 0;
                } else if (func->type == TYPE_SHORT) {
                  result.Val.shortVal = 0;
                } else if (func->type == TYPE_BOOL) {
                  result.Val.boolVal = 0;
                } else if (func->type == TYPE_VOID) {
                  result.Val.intVal = 0;
                } else if (func->type == TYPE_CHAR) {
                  result.Val.charVal = '\0';
                } else if (func->type == TYPE_ENUM) {
                  result.Val.intVal = 0;
                } else if (func->type == TYPE_STRUCT) {
                  result.Val.intVal = 0;
                } else if (func->type == TYPE_UNION) {
                  result.Val.intVal = 0;
                }
              }
             ;

unary_expr: MINUSONE variable { $$ = $2; }
          | PLUSONE variable { $$ = $2; }
          | DEREF variable { $$ = $2; }
          | REF variable { $$ = $2; }
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
      | expr { $$ = NULL; }
      | params COMMA expr { $$ = NULL; } 
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

literal: LITERALSTRING { Expression result; result.type = TYPE_STRING; strcpy(result.Val.stringVal, $1); $$ = result; }
       | LITERALCHAR { Expression result; result.type = TYPE_CHAR; result.Val.charVal = *$1; $$ = result; }
       | NULLT { Expression result; result.type = TYPE_VOID; $$ = result; }
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

Expression evaluate_arithmetic(Expression left, Expression right, ArOp op) {
    Expression result;
    
    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    switch (op) {
        case PLUS:
            if (left.type == TYPE_INT) {
                result.Val.intVal = left.Val.intVal + right.Val.intVal;
            } else if (left.type == TYPE_FLOAT) {
                result.Val.floatVal = left.Val.floatVal + right.Val.floatVal;
            } else if (left.type == TYPE_DOUBLE) {
                result.Val.doubleVal = left.Val.doubleVal + right.Val.doubleVal;
            } else if (left.type == TYPE_LONG) {
                result.Val.longVal = left.Val.longVal + right.Val.longVal;
            } else if (left.type == TYPE_SHORT) {
                result.Val.shortVal = left.Val.shortVal + right.Val.shortVal;
            }
            break;
        case MINUS:
            if (left.type == TYPE_INT) {
                result.Val.intVal = left.Val.intVal - right.Val.intVal;
            } else if (left.type == TYPE_FLOAT) {
                result.Val.floatVal = left.Val.floatVal - right.Val.floatVal;
            } else if (left.type == TYPE_DOUBLE) {
                result.Val.doubleVal = left.Val.doubleVal - right.Val.doubleVal;
            } else if (left.type == TYPE_LONG) {
                result.Val.longVal = left.Val.longVal - right.Val.longVal;
            } else if (left.type == TYPE_SHORT) {
                result.Val.shortVal = left.Val.shortVal - right.Val.shortVal;
            }
            break;
        case MULT:
            if (left.type == TYPE_INT) {
                result.Val.intVal = left.Val.intVal * right.Val.intVal;
            } else if (left.type == TYPE_FLOAT) {
                result.Val.floatVal = left.Val.floatVal * right.Val.floatVal;
            } else if (left.type == TYPE_DOUBLE) {
                result.Val.doubleVal = left.Val.doubleVal * right.Val.doubleVal;
            } else if (left.type == TYPE_LONG) {
                result.Val.longVal = left.Val.longVal * right.Val.longVal;
            } else if (left.type == TYPE_SHORT) {
                result.Val.shortVal = left.Val.shortVal * right.Val.shortVal;
            }
            break;
        case DIV:
            if (left.type == TYPE_INT) {
                result.Val.intVal = left.Val.intVal / right.Val.intVal;
            } else if (left.type == TYPE_FLOAT) {
                result.Val.floatVal = left.Val.floatVal / right.Val.floatVal;
            } else if (left.type == TYPE_DOUBLE) {
                result.Val.doubleVal = left.Val.doubleVal / right.Val.doubleVal;
            } else if (left.type == TYPE_LONG) {
                result.Val.longVal = left.Val.longVal / right.Val.longVal;
            } else if (left.type == TYPE_SHORT) {
                result.Val.shortVal = left.Val.shortVal / right.Val.shortVal;
            }
            break;
        case MOD:
            if (left.type == TYPE_INT) {
                result.Val.intVal = left.Val.intVal % right.Val.intVal;
            } else if (left.type == TYPE_LONG) {
                result.Val.longVal = left.Val.longVal % right.Val.longVal;
            } else if (left.type == TYPE_SHORT) {
                result.Val.shortVal = left.Val.shortVal % right.Val.shortVal;
            }
            break;
    }

    result.type = left.type;
    return result;
}

Expression evaluate_relational(Expression left, Expression right, RelOp op) {
    Expression result;
    result.type = TYPE_BOOL;

    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    switch (op) {
        case GT:
            result.Val.boolVal = left.Val.boolVal > right.Val.boolVal;
            break;
        case LT:
            result.Val.boolVal = left.Val.boolVal < right.Val.boolVal;
            break;
        case GE:
            result.Val.boolVal = left.Val.boolVal >= right.Val.boolVal;
            break;
        case LE:
            result.Val.boolVal = left.Val.boolVal <= right.Val.boolVal;
            break;
        case EQ:
            result.Val.boolVal = left.Val.boolVal == right.Val.boolVal;
            break;
        case NE:
            result.Val.boolVal = left.Val.boolVal != right.Val.boolVal;
            break;
    }
    return result;
}

Expression evaluate_and(Expression left, Expression right) {
    Expression result;
    result.type = TYPE_BOOL;

    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    result.Val.boolVal = left.Val.boolVal && right.Val.boolVal;
    return result;
}

Expression evaluate_or(Expression left, Expression right) {
    Expression result;
    result.type = TYPE_BOOL;

    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    result.Val.boolVal = left.Val.boolVal || right.Val.boolVal;
    return result;
}

Expression evaluate_not(Expression expr) {
    Expression result;
    if (expr.type != TYPE_BOOL) {
        yyerror("Tipos incompativeis...\n");
    }
    result.type = TYPE_BOOL;
    result.Val.boolVal = !expr.Val.boolVal;
    return result;
}

Expression id_to_expression(char *id) {
    Symbol *symbol = lookup_symbol(current_table, id);
    if (symbol == NULL) {
        yyerror("Variavel nao encontrada...\n");
    }
    Expression result;
    result.type = symbol->type;
    if (symbol->type == TYPE_INT) {
        result.Val.intVal = symbol->TypeVal.intVal;
    } else if (symbol->type == TYPE_FLOAT) {
        result.Val.floatVal = symbol->TypeVal.floatVal;
    } else if (symbol->type == TYPE_DOUBLE) {
        result.Val.doubleVal = symbol->TypeVal.doubleVal;
    } else if (symbol->type == TYPE_LONG) {
        result.Val.longVal = symbol->TypeVal.longVal;
    } else if (symbol->type == TYPE_SHORT) {
        result.Val.shortVal = symbol->TypeVal.shortVal;
    } else if (symbol->type == TYPE_BOOL) {
        result.Val.boolVal = symbol->TypeVal.boolVal;
    }
    return result;
}