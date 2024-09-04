#include "codeGen.h"
#include "LLVMAST.h"
#include "NodeTypeLLVM.h"
#include "../Operators.h"
#include "../SymbolTable.h"
#include "../Types.h"

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <vector>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/FileSystem.h>

llvm::LLVMContext TheContext;
std::unique_ptr<llvm::Module> TheModule;
std::unique_ptr<llvm::IRBuilder<>> Builder;

void initLLVM() {
    TheModule = std::make_unique<llvm::Module>("my_module", TheContext);
    Builder = std::make_unique<llvm::IRBuilder<>>(TheContext);
}

llvm::Value* codegen(ASTNode* node) {
    switch (node->type) {
        case ASTNodeType::AST_TYPE_INT:
            return llvm::ConstantInt::get(TheContext, llvm::APInt(32, node->data.int_val));
        case ASTNodeType::AST_TYPE_FLOAT:
            return llvm::ConstantFP::get(TheContext, llvm::APFloat(node->data.float_val));
        case ASTNodeType::AST_TYPE_LONG:
            return llvm::ConstantInt::get(TheContext, llvm::APInt(64, node->data.long_val));
        case ASTNodeType::AST_TYPE_SHORT:
            return llvm::ConstantInt::get(TheContext, llvm::APInt(16, node->data.short_val));
        case ASTNodeType::AST_TYPE_DOUBLE:
            return llvm::ConstantFP::get(TheContext, llvm::APFloat(node->data.double_val));
        case ASTNodeType::AST_TYPE_CHAR:
            return llvm::ConstantInt::get(TheContext, llvm::APInt(8, node->data.char_val));
        case ASTNodeType::AST_TYPE_BOOL:
            return llvm::ConstantInt::get(TheContext, llvm::APInt(1, node->data.int_val));
        case ASTNodeType::AST_TYPE_BIN_AROP: {
            llvm::Value* left = codegen(node->data.bin_arop.left.get());
            llvm::Value* right = codegen(node->data.bin_arop.right.get());
            switch (node->data.bin_arop.op) {
                case PLUS:
                    return Builder->CreateAdd(left, right, "addtmp");
                case MINUS:
                    return Builder->CreateSub(left, right, "subtmp");
                case MULT:
                    return Builder->CreateMul(left, right, "multmp");
                case DIV:
                    return Builder->CreateSDiv(left, right, "divtmp");
                case MOD:
                    return Builder->CreateSRem(left, right, "modtmp");
                default:
                    return nullptr;
            }
        }
        case ASTNodeType::AST_TYPE_BIN_RELOP: {
            llvm::Value* left = codegen(node->data.bin_relop.left.get());
            llvm::Value* right = codegen(node->data.bin_relop.right.get());
            switch (node->data.bin_relop.op) {
                case LT:
                    return Builder->CreateICmpSLT(left, right, "lttmp");
                case GT:
                    return Builder->CreateICmpSGT(left, right, "gttmp");
                case LE:
                    return Builder->CreateICmpSLE(left, right, "letmp");
                case GE:
                    return Builder->CreateICmpSGE(left, right, "getmp");
                case EQ:
                    return Builder->CreateICmpEQ(left, right, "eqtmp");
                case NE:
                    return Builder->CreateICmpNE(left, right, "netmp");
                default:
                    return nullptr;
            }
        }
        case ASTNodeType::AST_TYPE_BIN_LOGOP: {
            llvm::Value* left = codegen(node->data.bin_logop.left.get());
            llvm::Value* right = codegen(node->data.bin_logop.right.get());
            switch (node->data.bin_logop.op) {
                case ANDOP:
                    return Builder->CreateAnd(left, right, "andtmp");
                case OROP:
                    return Builder->CreateOr(left, right, "ortmp");
                default:
                    return nullptr;
            }
        }
        case ASTNodeType::AST_TYPE_UNOP: {
            llvm::Value* expr = codegen(node->data.unnop.expr.get());
            switch (node->data.unnop.op) {
                case NOTOP:
                    return Builder->CreateNot(expr, "nottmp");
                case MINUSONEOP:
                    return Builder->CreateSub(expr, llvm::ConstantInt::get(TheContext, llvm::APInt(32, 1)), "minusone");
                case PLUSONEOP:
                    return Builder->CreateAdd(expr, llvm::ConstantInt::get(TheContext, llvm::APInt(32, 1)), "plusone");
                case REFOP:
                    return expr;
                default:
                    return nullptr;
            }
        }
        default:
            return nullptr;
    }
}

llvm::Function* createFunction(ASTNode* func_node) {
    llvm::FunctionType* funcType = llvm::FunctionType::get(llvm::Type::getVoidTy(TheContext), false);
    llvm::Function* func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "func_name", TheModule.get());

    llvm::BasicBlock* entry = llvm::BasicBlock::Create(TheContext, "entry", func);
    Builder->SetInsertPoint(entry);

    codegen(func_node->data.func.body.get());

    Builder->CreateRetVoid();

    llvm::verifyFunction(*func);

    return func;
}

void generateLLVMIR() {
    TheModule->print(llvm::outs(), nullptr);

    //Salvar a árvore em um arquivo
    std::error_code EC;
    llvm::raw_fd_ostream OS("output.ll", EC);
    TheModule->print(OS, nullptr);
}