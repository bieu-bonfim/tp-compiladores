#include "AST.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NodeType.h"
#include "../Operators.h"

ASTNode* create_int_node(int val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_INT;
  node->data_type = TYPE_INT;
  node->data.int_val = val;
  return node;
}

ASTNode* create_float_node(float val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_FLOAT;
  node->data_type = TYPE_FLOAT;
  node->data.float_val = val;
  return node;
}

ASTNode* create_bin_arop_node(ASTNode *left, ASTNode *right, ArOp op) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_BIN_AROP;
  node->data_type = left->data_type;
  node->data.bin_arop.left = left;
  node->data.bin_arop.right = right;
  node->data.bin_arop.op = op;
  return node;
}

ASTNode* create_bin_relop_node(ASTNode *left, ASTNode *right, RelOp op) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_BIN_RELOP;
  node->data_type = TYPE_BOOL;
  node->data.bin_relop.left = left;
  node->data.bin_relop.right = right;
  node->data.bin_relop.op = op;
  return node;
}

ASTNode* create_bin_logop_node(ASTNode *left, ASTNode *right, LogOp op) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_BIN_LOGOP;
  node->data_type = TYPE_BOOL;
  node->data.bin_logop.left = left;
  node->data.bin_logop.right = right;
  node->data.bin_logop.op = op;
  return node;
}

ASTNode* create_unop_node(ASTNode *expr, UnnOp op) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_UNOP;
  node->data_type = expr->data_type;
  node->data.unnop.expr = expr;
  node->data.unnop.op = op;
  return node;
}

ASTNode* create_var_decl_node(char* var_name, ASTNode *expr) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_VAR_DECL;
  node->data.var_decl.var_name = var_name;
  node->data.var_decl.expr = expr;
  return node;
}

ASTNode* create_var_ref_node(char* var_name) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_VAR;
  node->data.var_name = var_name;
  return node;
}

ASTNode* create_assign_node(char* var_name, ASTNode *expr) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_ASSIGN;
  node->data.assign.var_name = var_name;
  node->data.assign.expr = expr;
  return node;
}

ASTNode* create_func_call_node(char *func_name, ASTNodeList *args) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_FUNC_CALL;
  node->data.func_call.func_name = func_name;
  node->data.func_call.args = args;
  return node;
}

ASTNode* create_long_node(long val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_INT;
  node->data_type = TYPE_LONG;
  node->data.long_val = val;
  return node;
}

ASTNode* create_short_node(short val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_INT;
  node->data_type = TYPE_SHORT;
  node->data.short_val = val;
  return node;
}

ASTNode* create_double_node(double val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_DOUBLE;
  node->data_type = TYPE_DOUBLE;
  node->data.double_val = val;
  return node;
}

ASTNode* create_char_node(char val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_CHAR;
  node->data_type = TYPE_CHAR;
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

ASTNode* create_func_node(char* func_name, Function* func, Type func_type, ASTNode *body) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_FUNC;
  node->data.func.func_name = func_name;
  node->data.func.func = func;
  node->data.func.func_type = func_type;
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
  node->data_type = TYPE_BOOL;
  node->data.int_val = val;
  return node;
}

ASTNode* create_null_node() {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_NULL;
  node->data_type = TYPE_NULL;
  return node;
}

ASTNode* create_string_node(char *val) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = AST_TYPE_STRING;
  node->data_type = TYPE_STRING;
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

ASTNode* create_switch_node(ASTNode *condition, ASTNodeList *cases, ASTNode *default_case) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_TYPE_SWITCH;
    node->data_type = TYPE_VOID; 
    node->data.switch_node.condition = condition;
    node->data.switch_node.cases = cases;

    if (default_case) {
        node->data.switch_node.cases = append_to_list(node->data.switch_node.cases, default_case);
    }

    node->children = NULL;
    return node;
}

ASTNode* create_case_node(ASTNode *case_expr, ASTNodeList *stmts, int is_default) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_TYPE_CASE;
    node->data_type = TYPE_VOID;
    node->data.case_node.case_expr = case_expr;
    node->data.case_node.stmts = stmts;
    node->data.case_node.is_default = is_default;
    node->children = NULL;
    return node;
}

ASTNode* create_block_node(ASTNodeList *stmts) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_TYPE_BLOCK;
    node->data_type = TYPE_VOID;
    node->children = stmts;
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
      if (node->data.bin_arop.left != NULL)
      {
        traverse_ast(node->data.bin_arop.left, level + 1);
      }
      print_ar_operators(node->data.bin_arop.op, level + 1);
      if (node->data.bin_arop.right != NULL)
      {
        traverse_ast(node->data.bin_arop.right, level + 1);
      }
      break;
    case AST_TYPE_BIN_RELOP:
      printf("└─ Binary Relational Operation\n");
      if (node->data.bin_relop.left != NULL)
      {
        traverse_ast(node->data.bin_relop.left, level + 1);
      }
      print_rel_operators(node->data.bin_relop.op, level + 1);
      if (node->data.bin_relop.right != NULL)
      {
        traverse_ast(node->data.bin_relop.right, level + 1);
      }
      break;
    case AST_TYPE_BIN_LOGOP:
      printf("└─ Binary Logical Operation\n");
      if (node->data.bin_logop.left != NULL)
      {
        traverse_ast(node->data.bin_logop.left, level + 1);
      }
      print_log_operators(node->data.bin_logop.op, level + 1);
      if (node->data.bin_logop.right != NULL)
      {
        traverse_ast(node->data.bin_logop.right, level + 1);
      }
      break;
    case AST_TYPE_UNOP:
      printf("└─ Unary Operation\n");
      if (node->data.unnop.expr != NULL)
      {
        traverse_ast(node->data.unnop.expr, level + 1);
      }
      break;
    case AST_TYPE_VAR:
      printf("└─ Variable Reference: %s\n", node->data.var_name);
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
      if (node->data.if_node.condition != NULL)
      {
        traverse_ast(node->data.if_node.condition, level + 1);
      }
      if (node->data.if_node.body_branch != NULL)
      {
        traverse_ast(node->data.if_node.body_branch, level + 1);
      }
      if (node->data.if_node.else_branch != NULL)
      {
        traverse_ast(node->data.if_node.else_branch, level + 1);
      }
      break;
    case AST_TYPE_WHILE:
      printf("└─ While\n");
      if (node->data.while_node.condition != NULL)
      {
        traverse_ast(node->data.while_node.condition, level + 1);
      }
      if (node->data.while_node.body != NULL)
      {
        traverse_ast(node->data.while_node.body, level + 1);
      }
      break;
    case AST_TYPE_FOR:
      printf("└─ For\n");
      if (node->data.for_node.condition != NULL)
      {
        traverse_ast(node->data.for_node.condition, level + 1);
      }
      if (node->data.for_node.update != NULL)
      {
        traverse_ast(node->data.for_node.update, level + 1);
      }
      if (node->data.for_node.body != NULL)
      {
        traverse_ast(node->data.for_node.body, level + 1);
      }
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
    case AST_TYPE_NULL:
      printf("└─ Null Literal\n");
      break;
    case AST_TYPE_STRING:
      printf("└─ String Literal: %s\n", node->data.string_val);
      break;
    case AST_TYPE_SWITCH:
      printf("└─ Switch\n");
      if (node->data.switch_node.condition != NULL)
      {
        traverse_ast(node->data.switch_node.condition, level + 1);
      }
      if (node->data.switch_node.cases != NULL)
      {
        ASTNodeList *current = node->data.switch_node.cases;
        while (current != NULL)
        {
          traverse_ast(current->node, level + 1);
          current = current->next;
        }
      }
      break;
    case AST_TYPE_CASE:
      printf("└─ Case\n");
      if (node->data.case_node.case_expr != NULL)
      {
        traverse_ast(node->data.case_node.case_expr, level + 1);
      }
      if (node->data.case_node.stmts != NULL)
      {
        ASTNodeList *current = node->data.case_node.stmts;
        while (current != NULL)
        {
          traverse_ast(current->node, level + 1);
          current = current->next;
        }
      }
      break;
    case AST_TYPE_DEFAULT:
      printf("└─ Default\n");
      break;

  }
}

void print_indentation(int level) {
    for (int i = 0; i < level; i++) {
        printf("  "); 
    }
}

void print_ar_operators(ArOp op, int level) {
    print_indentation(level);
    switch (op) {
        case PLUS:
            printf("└─ Add\n");
            break;
        case MINUS:
            printf("└─ Subtract\n");
            break;
        case MULT:
            printf("└─ Multiply\n");
            break;
        case DIV:
            printf("└─ Divide\n");
            break;
        case MOD:
            printf("└─ Modulus\n");
            break;
    }
}

void print_rel_operators(RelOp op, int level) {
    print_indentation(level);
    switch (op) {
        case EQ:
            printf("└─ Equal\n");
            break;
        case NE:
            printf("└─ Not Equal\n");
            break;
        case LT:
            printf("└─ Less Than\n");
            break;
        case GT:
            printf("└─ Greater Than\n");
            break;
        case LE:
            printf("└─ Less Than or Equal\n");
            break;
        case GE:
            printf("└─ Greater Than or Equal\n");
            break;
    }
}

void print_log_operators(LogOp op, int level) {
    print_indentation(level);
    switch (op) {
        case ANDOP:
            printf("└─ And\n");
            break;
        case OROP:
            printf("└─ Or\n");
            break;
    }
}