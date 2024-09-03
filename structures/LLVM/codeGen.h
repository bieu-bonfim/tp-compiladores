// codegen.h
#include "LLVMAST.h"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>

// Declaração das funções de inicialização e geração de código
void initLLVM();
llvm::Value* codegen(ASTNode* node);
llvm::Function* createFunction(ASTNode* func_node);
void generateLLVMIR();
