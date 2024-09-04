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


void generateTAC(ASTNode *node);
char* generateTempVar();
char* generateLabel();
const char* getArOpString(ArOp op);



#endif