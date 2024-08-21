#ifndef OPERATORS_H
#define OPERATORS_H

typedef enum ArOp {
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD
} ArOp;

typedef enum RelOp {
    EQ,
    NE,
    LT,
    GT,
    LE,
    GE
} RelOp;

typedef enum LogOp {
    ANDOP,
    OROP,
    NOTOP
} LogOp;

typedef enum UnnOp {
    MINUSONEOP,
    PLUSONEOP,
    REFOP,
    DEREFOP,
} UnnOp;

#endif