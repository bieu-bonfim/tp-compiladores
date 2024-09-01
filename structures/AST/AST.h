#ifndef AST_H
#define AST_H

#include "NodeType.h"
#include "../SymbolTable.h"
#include "../Operators.h"
#include "../Types.h"

typedef struct ASTNode {
    ASTNodeType type;
    Type data_type; 
    
    union ASTNodeData {

      int int_val;
      long long_val;
      short short_val;
      double double_val;
      char char_val;
      char *string_val;
      float float_val;
      Symbol *symbol;
      struct {
        Symbol* var_symbol;
        struct ASTNode *expr;
      } var_decl;
      struct {
        Symbol *symbol;
        struct ASTNode *body;
      } func;
      struct {
        char *name;
      } import;
      struct {
        struct ASTNode *left;
        struct ASTNode *right;
        ArOp op;
      } bin_arop;
      struct {
        struct ASTNode *left;
        struct ASTNode *right;
        RelOp op;
      } bin_relop;
      struct {
        struct ASTNode *left;
        struct ASTNode *right;
        LogOp op;
      } bin_logop;
      struct {
        struct ASTNode *expr;
        UnnOp op;
      } unnop;
      struct {
        Symbol *var_symbol;
        struct ASTNode *expr;
      } assign;
      struct {
        Symbol *func_symbol;
        struct ASTNodeList *args;
      } func_call;
      struct {
        struct ASTNode *condition;
        struct ASTNode *body_branch;
        struct ASTNode *else_branch;
      } if_node;
      struct {
        struct ASTNode *condition;
        struct ASTNode *body;
      } while_node;
      struct {
        struct ASTNode *condition;
        struct ASTNode *update;
        struct ASTNode *body;
      } for_node;
      struct {
        struct ASTNode *expr;
      } return_node;

    } data;

    struct ASTNodeList *children;
} ASTNode;

typedef struct ASTNodeList {
    struct ASTNode *node;
    struct ASTNodeList *next;
} ASTNodeList;

ASTNodeList* append_to_list(ASTNodeList *list, ASTNode *node);
ASTNode* create_root_node(ASTNodeList *children);
ASTNode* create_int_node(int val);
ASTNode* create_float_node(float val);
ASTNode* create_var_decl_node(Symbol* symbol, ASTNode *expr);
ASTNode* create_var_ref_node(Symbol* symbol);
ASTNode* create_func_call_node(Symbol *func_symbol, ASTNodeList *args);
ASTNode* create_func_node(Symbol* symbol, ASTNode *body);
ASTNode* create_bin_arop_node(ASTNode *left, ASTNode *right, ArOp op);
ASTNode* create_bin_relop_node(ASTNode *left, ASTNode *right, RelOp op);
ASTNode* create_bin_logop_node(ASTNode *left, ASTNode *right, LogOp op);
ASTNode* create_unop_node(ASTNode *expr, UnnOp op);
ASTNode* create_assign_node(Symbol* symbol, ASTNode *expr);
ASTNode* create_long_node(long val);
ASTNode* create_short_node(short val);
ASTNode* create_double_node(double val);
ASTNode* create_char_node(char val);
ASTNode* create_import_node(char *name);
ASTNode* create_bool_node(int val);
ASTNode* create_null_node();
ASTNode* create_string_node(char *val);
ASTNode* create_return_node(ASTNode *expr);
ASTNode* create_if_node(ASTNode *condition, ASTNode *body_branch, ASTNode *else_branch);
ASTNode* create_while_node(ASTNode *condition, ASTNode *body);
ASTNode* create_for_node(ASTNode *condition, ASTNode *update, ASTNode *body);
ASTNode* create_break_node();
ASTNode* create_continue_node();

void traverse_ast(ASTNode *node, int level);
void print_node_type(ASTNode *node, int level);
void print_indentation(int level);


#endif  