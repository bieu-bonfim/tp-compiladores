#ifndef TAC_H
#define TAC_H

#include "../AST/AST.h"

typedef enum {
    TAC_ASSIGN, 
    TAC_ADD,    
    TAC_SUB,    
    TAC_MUL,    
    TAC_DIV,    
    TAC_LABEL,  
    TAC_GOTO,   
    TAC_IFGOTO, 
    TAC_PARAM,  
    TAC_CALL,   
    TAC_RETURN, 
} TACOp;

typedef struct TAC {
    TACOp op;
    char *result;
    char *arg1;
    char *arg2;
    char *label;
    struct TAC *next;
} TAC;


char* create_temp_var();
TAC* create_tac(TACOp op, char *result, char *arg1, char *arg2);
TAC* generate_tac(ASTNode *node, SymbolTable *table);
TAC* combine_tac(TAC *first, TAC *second);
void print_tac(TAC *tac);


#endif