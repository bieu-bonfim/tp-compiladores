#include "LLVMAST.h"
#include "NodeTypeAST.h"
#include "../Operators.h"
#include "../SymbolTable.h"
#include "../Types.h"

#include <iostream>
#include <memory>
#include <cstring>
#include <string>

using namespace std;

ASTNodePtr create_int_node(int val) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_INT);
    node->data.int_val = val;
    return node;
}

ASTNodePtr create_float_node(float val) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_FLOAT);
    node->data.float_val = val;
    return node;
}

ASTNodePtr create_bin_arop_node(ASTNodePtr left, ASTNodePtr right, ArOp op) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_BIN_AROP);
    node->data.bin_arop.left = left;
    node->data.bin_arop.right = right;
    node->data.bin_arop.op = op;
    return node;
}

ASTNodePtr create_bin_relop_node(ASTNodePtr left, ASTNodePtr right, RelOp op) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_BIN_RELOP);
    node->data.bin_relop.left = left;
    node->data.bin_relop.right = right;
    node->data.bin_relop.op = op;
    return node;
}

ASTNodePtr create_bin_logop_node(ASTNodePtr left, ASTNodePtr right, LogOp op) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_BIN_LOGOP);
    node->data.bin_logop.left = left;
    node->data.bin_logop.right = right;
    node->data.bin_logop.op = op;
    return node;
}

ASTNodePtr create_unop_node(ASTNodePtr expr, UnnOp op) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_UNOP);
    node->data.unnop.expr = expr;
    node->data.unnop.op = op;
    return node;
}

ASTNodePtr create_var_decl_node(Symbol* symbol, ASTNodePtr expr) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_VAR_DECL);
    node->data.var_decl.var_symbol = symbol;
    node->data.var_decl.expr = expr;
    return node;
}

ASTNodePtr create_var_ref_node(Symbol* symbol) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_VAR);
    node->data.symbol = symbol;
    return node;
}

ASTNodePtr create_assign_node(Symbol* symbol, ASTNodePtr expr) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_ASSIGN);
    node->data.assign.var_symbol = symbol;
    node->data.assign.expr = expr;
    return node;
}

ASTNodePtr create_func_call_node(Symbol* func_symbol, shared_ptr<ASTNodeList> args) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_FUNC_CALL);
    node->data.func_call.func_symbol = func_symbol;
    node->data.func_call.args = args;
    return node;
}

ASTNodePtr create_long_node(long val) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_LONG);
    node->data.long_val = val;
    return node;
}

ASTNodePtr create_short_node(short val) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_SHORT);
    node->data.short_val = val;
    return node;
}

ASTNodePtr create_double_node(double val) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_DOUBLE);
    node->data.double_val = val;
    return node;
}

ASTNodePtr create_char_node(char val) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_CHAR);
    node->data.char_val = val;
    return node;
}

shared_ptr<ASTNodeList> append_to_list(shared_ptr<ASTNodeList> list, ASTNodePtr node) {
    if (!list) {
        list = make_shared<ASTNodeList>(node, nullptr);
    } else {
        auto current = list;
        while (current->next) {
            current = current->next;
        }
        current->next = make_shared<ASTNodeList>(node, nullptr);
    }
    return list;
}

ASTNodePtr create_root_node(shared_ptr<ASTNodeList> children) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_NODE_ROOT);
    node->children = children;
    return node;
}

ASTNodePtr create_func_node(Symbol* symbol, ASTNodePtr body) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_FUNC);
    node->data.func.symbol = symbol;
    node->data.func.body = body;
    return node;
}

ASTNodePtr create_import_node(const string& name) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_IMPORT);
    node->data.import.name = name;
    return node;
}

ASTNodePtr create_bool_node(int val) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_BOOL);
    node->data.int_val = val;
    return node;
}

ASTNodePtr create_null_node() {
    return make_shared<ASTNode>(ASTNodeType::AST_TYPE_NULL);
}

ASTNodePtr create_string_node(const string& val) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_STRING);
    node->data.string_val = val;
    return node;
}

ASTNodePtr create_if_node(ASTNodePtr condition, ASTNodePtr body_branch, ASTNodePtr else_branch) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_IF);
    node->data.if_node.condition = condition;
    node->data.if_node.body_branch = body_branch;
    node->data.if_node.else_branch = else_branch;
    return node;
}

ASTNodePtr create_while_node(ASTNodePtr condition, ASTNodePtr body) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_WHILE);
    node->data.while_node.condition = condition;
    node->data.while_node.body = body;
    return node;
}

ASTNodePtr create_for_node(ASTNodePtr condition, ASTNodePtr update, ASTNodePtr body) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_FOR);
    node->data.for_node.condition = condition;
    node->data.for_node.update = update;
    node->data.for_node.body = body;
    return node;
}

ASTNodePtr create_break_node() {
    return make_shared<ASTNode>(ASTNodeType::AST_TYPE_BREAK);
}

ASTNodePtr create_continue_node() {
    return make_shared<ASTNode>(ASTNodeType::AST_TYPE_CONTINUE);
}

ASTNodePtr create_return_node(ASTNodePtr expr) {
    auto node = make_shared<ASTNode>(ASTNodeType::AST_TYPE_RETURN);
    node->data.return_node.expr = expr;
    return node;
}

void traverse_ast(ASTNodePtr node, int level) {
    if (!node) return;

    print_node_type(node, level);

    auto child = node->children;
    while (child) {
        traverse_ast(child->node, level + 1);
        child = child->next;
    }
}

void print_node_type(ASTNodePtr node, int level) {
    print_indentation(level);
    switch (node->type) {
        case ASTNodeType::AST_TYPE_INT:
            cout << "└─ Integer Literal: " << node->data.int_val << endl;
            break;
        case ASTNodeType::AST_TYPE_FLOAT:
            cout << "└─ Float Literal: " << node->data.float_val << endl;
            break;
        case ASTNodeType::AST_TYPE_BIN_AROP:
            cout << "└─ Binary Arithmetic Operation" << endl;
            break;
        case ASTNodeType::AST_TYPE_BIN_RELOP:
            cout << "└─ Binary Relational Operation" << endl;
            break;
        case ASTNodeType::AST_TYPE_BIN_LOGOP:
            cout << "└─ Binary Logical Operation" << endl;
            break;
        case ASTNodeType::AST_TYPE_UNOP:
            cout << "└─ Unary Operation" << endl;
            if (node->data.unnop.expr) {
                traverse_ast(node->data.unnop.expr, level + 1);
            }
            break;
        case ASTNodeType::AST_TYPE_VAR:
            cout << "└─ Variable Reference: " << node->data.symbol->name << endl;
            break;
        case ASTNodeType::AST_TYPE_ASSIGN:
            cout << "└─ Assignment" << endl;
            if (node->data.assign.expr) {
                traverse_ast(node->data.assign.expr, level + 1);
            }
            break;
        case ASTNodeType::AST_TYPE_FUNC_CALL:
            cout << "└─ Function Call" << endl;
            break;
        case ASTNodeType::AST_NODE_ROOT:
            cout << "└─ Root" << endl;
            break;
        case ASTNodeType::AST_TYPE_LONG:
            cout << "└─ Long Literal: " << node->data.long_val << endl;
            break;
        case ASTNodeType::AST_TYPE_SHORT:
            cout << "└─ Short Literal: " << node->data.short_val << endl;
            break;
        case ASTNodeType::AST_TYPE_DOUBLE:
            cout << "└─ Double Literal: " << node->data.double_val << endl;
            break;
        case ASTNodeType::AST_TYPE_CHAR:
            cout << "└─ Char Literal: " << node->data.char_val << endl;
            break;
        case ASTNodeType::AST_TYPE_FUNC:
            cout << "└─ Function" << endl;
            if (node->data.func.body) {
                traverse_ast(node->data.func.body, level + 1);
            }
            break;
        case ASTNodeType::AST_TYPE_IMPORT:
            cout << "└─ Import: " << node->data.import.name << endl;
            break;
        case ASTNodeType::AST_TYPE_BOOL:
            cout << "└─ Boolean Literal: " << (node->data.int_val ? "true" : "false") << endl;
            break;
        case ASTNodeType::AST_TYPE_NULL:
            cout << "└─ Null" << endl;
            break;
        case ASTNodeType::AST_TYPE_STRING:
            cout << "└─ String Literal: " << node->data.string_val << endl;
            break;
        case ASTNodeType::AST_TYPE_IF:
            cout << "└─ If Statement" << endl;
            break;
        case ASTNodeType::AST_TYPE_WHILE:
            cout << "└─ While Loop" << endl;
            break;
        case ASTNodeType::AST_TYPE_FOR:
            cout << "└─ For Loop" << endl;
            break;
        case ASTNodeType::AST_TYPE_BREAK:
            cout << "└─ Break Statement" << endl;
            break;
        case ASTNodeType::AST_TYPE_CONTINUE:
            cout << "└─ Continue Statement" << endl;
            break;
        case ASTNodeType::AST_TYPE_RETURN:
            cout << "└─ Return Statement" << endl;
            if (node->data.return_node.expr) {
                traverse_ast(node->data.return_node.expr, level + 1);
            }
            break;
        case ASTNodeType::AST_TYPE_VAR_DECL:
            cout << "└─ Variable Declaration" << endl;
            if (node->data.var_decl.expr) {
                traverse_ast(node->data.var_decl.expr, level + 1);
            }
            break;
        default:
            cout << "└─ Unknown Node Type" << endl;
            break;
    }
}

void print_indentation(int level) {
    for (int i = 0; i < level; ++i) {
        cout << "  ";
    }
}