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

ASTNode::ASTNode(ASTNodeType type) : type(type), data_type(Type()) {}

ASTNode* create_int_node(int val) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_INT);
    node->data.int_val = val;
    return node;
}

ASTNode* create_float_node(float val) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_FLOAT);
    node->data.float_val = val;
    return node;
}

ASTNode* create_bin_arop_node(ASTNode* left, ASTNode* right, ArOp op) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_BIN_AROP);
    node->data.bin_arop.left = std::shared_ptr<ASTNode>(left);
    node->data.bin_arop.right = std::shared_ptr<ASTNode>(right);
    node->data.bin_arop.op = op;
    return node;
}

ASTNode* create_bin_relop_node(ASTNode* left, ASTNode* right, RelOp op) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_BIN_RELOP);
    node->data.bin_relop.left = std::shared_ptr<ASTNode>(left);
    node->data.bin_relop.right = std::shared_ptr<ASTNode>(right);
    node->data.bin_relop.op = op;
    return node;
}

ASTNode* create_bin_logop_node(ASTNode* left, ASTNode* right, LogOp op) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_BIN_LOGOP);
    node->data.bin_logop.left = std::shared_ptr<ASTNode>(left);
    node->data.bin_logop.right = std::shared_ptr<ASTNode>(right);
    node->data.bin_logop.op = op;
    return node;
}

ASTNode* create_unop_node(ASTNode* expr, UnnOp op) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_UNOP);
    node->data.unnop.expr = std::shared_ptr<ASTNode>(expr);
    node->data.unnop.op = op;
    return node;
}


ASTNode* create_var_decl_node(Symbol* symbol, ASTNode* expr) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_VAR_DECL);
    node->data.var_decl.var_symbol = symbol;
    node->data.var_decl.expr = std::shared_ptr<ASTNode>(expr);
    return node;
}

ASTNode* create_var_ref_node(Symbol* symbol) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_VAR);
    node->data.symbol = symbol;
    return node;
}

ASTNode* create_assign_node(Symbol* symbol, ASTNode* expr) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_ASSIGN);
    node->data.assign.var_symbol = symbol;
    node->data.assign.expr = std::shared_ptr<ASTNode>(expr);
    return node;
}

ASTNode* create_func_call_node(Symbol* func_symbol, ASTNodeList* args) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_FUNC_CALL);
    node->data.func_call.func_symbol = func_symbol;
    node->data.func_call.args = std::shared_ptr<ASTNodeList>(args);
    return node;
}

ASTNode* create_long_node(long val) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_LONG);
    node->data.long_val = val;
    return node;
}

ASTNode* create_short_node(short val) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_SHORT);
    node->data.short_val = val;
    return node;
}

ASTNode* create_double_node(double val) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_DOUBLE);
    node->data.double_val = val;
    return node;
}

ASTNode* create_char_node(char val) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_CHAR);
    node->data.char_val = val;
    return node;
}

ASTNodeList* append_to_list(ASTNodeList* list, ASTNode* node) {
    if (list == nullptr) {
        list = new ASTNodeList{std::shared_ptr<ASTNode>(node), nullptr};
    } else {
        ASTNodeList* current = list;
        while (current->next != nullptr) {
            current = current->next.get();
        }
        current->next = std::make_shared<ASTNodeList>(node, nullptr);
    }
    return list;
}

ASTNode* create_root_node(ASTNodeList* children) {
    auto node = new ASTNode(ASTNodeType::AST_NODE_ROOT);
    node->children = std::shared_ptr<ASTNodeList>(children);
    return node;
}

ASTNode* create_func_node(Symbol* symbol, ASTNode* body) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_FUNC);
    node->data.func.symbol = symbol;
    node->data.func.body = std::shared_ptr<ASTNode>(body);
    return node;
}

ASTNode* create_import_node(const char* name) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_IMPORT);
    node->data.import.name = std::string(name);
    return node;
}

ASTNode* create_bool_node(int val) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_BOOL);
    node->data.int_val = val;
    return node;
}

ASTNode* create_null_node() {
    return new ASTNode(ASTNodeType::AST_TYPE_NULL);
}

ASTNode* create_string_node(const char* val) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_STRING);
    node->data.string_val = std::string(val);
    return node;
}

ASTNode* create_if_node(ASTNode* condition, ASTNode* body_branch, ASTNode* else_branch) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_IF);
    node->data.if_node.condition = std::shared_ptr<ASTNode>(condition);
    node->data.if_node.body_branch = std::shared_ptr<ASTNode>(body_branch);
    node->data.if_node.else_branch = std::shared_ptr<ASTNode>(else_branch);
    return node;
}

ASTNode* create_while_node(ASTNode* condition, ASTNode* body) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_WHILE);
    node->data.while_node.condition = std::shared_ptr<ASTNode>(condition);
    node->data.while_node.body = std::shared_ptr<ASTNode>(body);
    return node;
}

ASTNode* create_for_node(ASTNode* condition, ASTNode* update, ASTNode* body) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_FOR);
    node->data.for_node.condition = std::shared_ptr<ASTNode>(condition);
    node->data.for_node.update = std::shared_ptr<ASTNode>(update);
    node->data.for_node.body = std::shared_ptr<ASTNode>(body);
    return node;
}

ASTNode* create_break_node() {
    return new ASTNode(ASTNodeType::AST_TYPE_BREAK);
}

ASTNode* create_continue_node() {
    return new ASTNode(ASTNodeType::AST_TYPE_CONTINUE);
}

ASTNode* create_return_node(ASTNode* expr) {
    auto node = new ASTNode(ASTNodeType::AST_TYPE_RETURN);
    node->data.return_node.expr = std::shared_ptr<ASTNode>(expr);
    return node;
}

void traverse_ast(ASTNode* node, int level) {
    if (!node) return;

    print_node_type(node, level);

    auto child = node->children.get();
    while (child) {
        traverse_ast(child->node.get(), level + 1);
        child = child->next.get();
    }
}

void print_node_type(ASTNode* node, int level) {
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
