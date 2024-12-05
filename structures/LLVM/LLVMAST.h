#ifndef AST_H
#define AST_H

#include "NodeTypeAST.h"
#include "../SymbolTable.h"
#include "../Operators.h"
#include "../Types.h"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/Constant.h>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>
#include <cstddef>

// Definição da estrutura ASTNode e ASTNodeList
struct ASTNode;
using ASTNodePtr = std::shared_ptr<ASTNode>;

struct ASTNodeList {
    ASTNodePtr node;
    std::shared_ptr<ASTNodeList> next;

    ASTNodeList(ASTNodePtr node, std::shared_ptr<ASTNodeList> next)
        : node(node), next(next) {}
};

struct ASTNode {
    ASTNodeType type;
    Type data_type;

    union ASTNodeData {
        int int_val;
        long long_val;
        short short_val;
        double double_val;
        char char_val;
        float float_val;
        std::string string_val;
        Symbol* symbol;

        struct VarDecl {
            Symbol* var_symbol;
            ASTNodePtr expr;
        } var_decl;

        struct Func {
            Symbol* symbol;
            ASTNodePtr body;
        } func;

        struct Import {
            std::string name;
        } import;

        struct BinArOp {
            ASTNodePtr left;
            ASTNodePtr right;
            ArOp op;
        } bin_arop;

        struct BinRelOp {
            ASTNodePtr left;
            ASTNodePtr right;
            RelOp op;
        } bin_relop;

        struct BinLogOp {
            ASTNodePtr left;
            ASTNodePtr right;
            LogOp op;
        } bin_logop;

        struct UnOp {
            ASTNodePtr expr;
            UnnOp op;
        } unnop;

        struct Assign {
            Symbol* var_symbol;
            ASTNodePtr expr;
        } assign;

        struct FuncCall {
            Symbol* func_symbol;
            std::shared_ptr<ASTNodeList> args;
        } func_call;

        struct IfNode {
            ASTNodePtr condition;
            ASTNodePtr body_branch;
            ASTNodePtr else_branch;
        } if_node;

        struct WhileNode {
            ASTNodePtr condition;
            ASTNodePtr body;
        } while_node;

        struct ForNode {
            ASTNodePtr condition;
            ASTNodePtr update;
            ASTNodePtr body;
        } for_node;

        struct ReturnNode {
            ASTNodePtr expr;
        } return_node;

        ASTNodeData() {}
        ~ASTNodeData() {}
    } data;

    std::shared_ptr<ASTNodeList> children;

    // Construtor para inicializar o tipo do nó
    ASTNode(ASTNodeType type) : type(type), data_type(Type()) {}
};

// Declarações de funções para manipulação da AST
std::shared_ptr<ASTNodeList> append_to_list(std::shared_ptr<ASTNodeList> list, std::shared_ptr<ASTNode> node);
std::shared_ptr<ASTNode> create_root_node(std::shared_ptr<ASTNodeList> children);  // Declaração da função create_root_node
std::shared_ptr<ASTNode> create_int_node(int val);
std::shared_ptr<ASTNode> create_float_node(float val);
std::shared_ptr<ASTNode> create_var_decl_node(Symbol* symbol, std::shared_ptr<ASTNode> expr);
std::shared_ptr<ASTNode> create_var_ref_node(Symbol* symbol);
std::shared_ptr<ASTNode> create_func_call_node(Symbol* func_symbol, std::shared_ptr<ASTNodeList> args);
std::shared_ptr<ASTNode> create_bin_arop_node(std::shared_ptr<ASTNode> left, std::shared_ptr<ASTNode> right, ArOp op);
std::shared_ptr<ASTNode> create_bin_relop_node(std::shared_ptr<ASTNode> left, std::shared_ptr<ASTNode> right, RelOp op);
std::shared_ptr<ASTNode> create_bin_logop_node(std::shared_ptr<ASTNode> left, std::shared_ptr<ASTNode> right, LogOp op);
std::shared_ptr<ASTNode> create_unop_node(std::shared_ptr<ASTNode> expr, UnnOp op);
std::shared_ptr<ASTNode> create_assign_node(Symbol* symbol, std::shared_ptr<ASTNode> expr);
std::shared_ptr<ASTNode> create_long_node(long val);
std::shared_ptr<ASTNode> create_short_node(short val);
std::shared_ptr<ASTNode> create_double_node(double val);
std::shared_ptr<ASTNode> create_char_node(char val);
std::shared_ptr<ASTNode> create_import_node(const std::string& name);
std::shared_ptr<ASTNode> create_bool_node(int val);
std::shared_ptr<ASTNode> create_null_node();
std::shared_ptr<ASTNode> create_string_node(const std::string& val);
std::shared_ptr<ASTNode> create_return_node(std::shared_ptr<ASTNode> expr);
std::shared_ptr<ASTNode> create_if_node(std::shared_ptr<ASTNode> condition, std::shared_ptr<ASTNode> body_branch, std::shared_ptr<ASTNode> else_branch);
std::shared_ptr<ASTNode> create_while_node(std::shared_ptr<ASTNode> condition, std::shared_ptr<ASTNode> body);
std::shared_ptr<ASTNode> create_for_node(std::shared_ptr<ASTNode> condition, std::shared_ptr<ASTNode> update, std::shared_ptr<ASTNode> body);
std::shared_ptr<ASTNode> create_break_node();
std::shared_ptr<ASTNode> create_continue_node();

void traverse_ast(std::shared_ptr<ASTNode> node, int level);
void print_node_type(std::shared_ptr<ASTNode> node, int level);
void print_indentation(int level);

#endif
