#include "AST.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NodeType.h"
#include "../Operators.h"

ASTNode* create_int_node(int val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_INT;
  node->data.int_val = val;
  return node;
}

ASTNode* create_float_node(float val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_FLOAT;
  node->data.float_val = val;
  return node;
}

ASTNode* create_bin_arop_node(ASTNode *left, ASTNode *right, ArOp op) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_BIN_AROP;
  node->data.bin_arop.left = left;
  node->data.bin_arop.right = right;
  node->data.bin_arop.op = op;
  return node;
}

ASTNode* create_bin_relop_node(ASTNode *left, ASTNode *right, RelOp op) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_BIN_RELOP;
  node->data.bin_relop.left = left;
  node->data.bin_relop.right = right;
  node->data.bin_relop.op = op;
  return node;
}

ASTNode* create_bin_logop_node(ASTNode *left, ASTNode *right, LogOp op) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_BIN_LOGOP;
  node->data.bin_logop.left = left;
  node->data.bin_logop.right = right;
  node->data.bin_logop.op = op;
  return node;
}

ASTNode* create_unop_node(ASTNode *expr, UnnOp op) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_UNOP;
  node->data.unnop.expr = expr;
  node->data.unnop.op = op;
  return node;
}

ASTNode* create_var_decl_node(Symbol* symbol, ASTNode *expr) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_VAR_DECL;
  node->data.var_decl.var_symbol = symbol;
  node->data.var_decl.expr = expr;
  return node;
}

ASTNode* create_var_ref_node(Symbol* symbol) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_VAR;
  node->data.symbol = symbol;
  return node;
}

ASTNode* create_assign_node(Symbol* symbol, ASTNode *expr) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_ASSIGN;
  node->data.assign.var_symbol = symbol;
  node->data.assign.expr = expr;
  return node;
}

ASTNode* create_func_call_node(Symbol *func_symbol, ASTNodeList *args) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_FUNC_CALL;
  node->data.func_call.func_symbol = func_symbol;
  node->data.func_call.args = args;
  return node;
}

ASTNode* create_long_node(long val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_INT;
  node->data.long_val = val;
  return node;
}

ASTNode* create_short_node(short val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_INT;
  node->data.short_val = val;
  return node;
}

ASTNode* create_double_node(double val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_FLOAT;
  node->data.double_val = val;
  return node;
}

ASTNode* create_char_node(char val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_INT;
  node->data.char_val = val;
  return node;
}

ASTNodeList* append_to_list(ASTNodeList *list, ASTNode *node) {
  if (list == NULL) {
    list = (ASTNodeList *)malloc(sizeof(ASTNodeList));
    list->node = node;
    list->next = NULL;
  } else {
    ASTNodeList *current = list;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = (ASTNodeList *)malloc(sizeof(ASTNodeList));
    current->next->node = node;
    current->next->next = NULL;
  }
  return list;
}

ASTNode* create_root_node(ASTNodeList *children) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_NODE_ROOT;
  node->children = children;
  return node;
}

ASTNode* create_func_node(Symbol* symbol, ASTNode *body) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_FUNC;
  node->data.func.symbol = symbol;
  node->data.func.body = body;
  return node;
}

ASTNode* create_import_node(char *name) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_IMPORT;
  node->data.import.name = strdup(name);
  return node;
}

ASTNode* create_bool_node(int val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_BOOL;
  node->data.int_val = val;
  return node;
}

ASTNode* create_null_node() {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_NULL;
  return node;
}

ASTNode* create_string_node(char *val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_STRING;
  node->data.string_val = strdup(val);
  return node;
}

ASTNode* create_if_node(ASTNode *condition, ASTNode *body_branch, ASTNode *else_branch) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_IF;
  node->data.if_node.condition = condition;
  node->data.if_node.body_branch = body_branch;
  node->data.if_node.else_branch = else_branch;
  return node;
}

ASTNode* create_while_node(ASTNode *condition, ASTNode *body) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_WHILE;
  node->data.while_node.condition = condition;
  node->data.while_node.body = body;
  return node;
}

ASTNode* create_for_node(ASTNode *condition, ASTNode *update, ASTNode *body) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_FOR;
  node->data.for_node.condition = condition;
  node->data.for_node.update = update;
  node->data.for_node.body = body;
  return node;
}

ASTNode* create_break_node() {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_BREAK;
  return node;
}

ASTNode* create_continue_node() {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_CONTINUE;
  return node;
}

ASTNode* create_return_node(ASTNode *expr) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_RETURN;
  node->data.return_node.expr = expr;
  return node;
}

void traverse_ast(ASTNode *node, int level) {
    if (node == NULL) return;

    print_node_type(node, level);

    ASTNodeList *child = node->children;
    while (child != NULL) {
        traverse_ast(child->node, level + 1);
        child = child->next;
    }
}

void print_node_type(ASTNode *node, int level) {
  print_indentation(level);
  switch (node->type) {
    case AST_TYPE_INT:
      printf("└─ Integer Literal: %d\n", node->data.int_val);
      break;
    case AST_TYPE_FLOAT:
      printf("└─ Float Literal: %f\n", node->data.float_val);
      break;
    case AST_TYPE_BIN_AROP:
      printf("└─ Binary Arithmetic Operation\n");
      break;
    case AST_TYPE_BIN_RELOP:
      printf("└─ Binary Relational Operation\n");
      break;
    case AST_TYPE_BIN_LOGOP:
      printf("└─ Binary Logical Operation\n");
      break;
    case AST_TYPE_UNOP:
      printf("└─ Unary Operation\n");
      if (node->data.unnop.expr != NULL)
      {
        traverse_ast(node->data.unnop.expr, level + 1);
      }
      break;
    case AST_TYPE_VAR:
      printf("└─ Variable Reference: %s\n", node->data.symbol->name);
      break;
    case AST_TYPE_ASSIGN:
      printf("└─ Assignment\n");
      if (node->data.assign.expr != NULL)
      {
        traverse_ast(node->data.assign.expr, level + 1);
      }
      break;
    case AST_TYPE_FUNC_CALL:
      printf("└─ Function Call\n");
      break;
    case AST_NODE_ROOT:
      printf("└─ Root\n");
      break;
    case AST_TYPE_LONG:
      printf("└─ Long Literal: %ld\n", node->data.long_val);
      break;
    case AST_TYPE_SHORT:
      printf("└─ Short Literal: %d\n", node->data.short_val);
      break;
    case AST_TYPE_DOUBLE:
      printf("└─ Double Literal: %f\n", node->data.double_val);
      break;
    case AST_TYPE_CHAR:
      printf("└─ Char Literal: %c\n", node->data.char_val);
      break;
    case AST_TYPE_FUNC:
      printf("└─ Function\n");
      if (node->data.func.body != NULL)
      {
        traverse_ast(node->data.func.body, level + 1);
      }
      break;
    case AST_TYPE_IMPORT:
      printf("└─ Import: %s\n", node->data.import.name);
      break;
    case AST_TYPE_RETURN:
      printf("└─ Return\n");
      break;
    case AST_TYPE_IF:
      printf("└─ If\n");
      break;
    case AST_TYPE_WHILE:
      printf("└─ While\n");
      break;
    case AST_TYPE_FOR:
      printf("└─ For\n");
      break;
    case AST_TYPE_BREAK:
      printf("└─ Break\n");
      break;
    case AST_TYPE_CONTINUE:
      printf("└─ Continue\n");
      break;
    case AST_TYPE_VAR_DECL:
      printf("└─ Variable Declaration\n");
      if (node->data.var_decl.expr != NULL)
      {
        traverse_ast(node->data.var_decl.expr, level + 1);
      }
      break;
    case AST_TYPE_BLOCK:
      printf("└─ Block\n");
      break;
    case AST_TYPE_BOOL:
      printf("└─ Boolean Literal: %s\n", node->data.int_val ? "veritas" : "falsum");
      break;
  }
}

void print_indentation(int level) {
    for (int i = 0; i < level; i++) {
        printf("  "); 
    }
}