#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"

#define HASH_SIZE 47
#define MAX_LEVEL 10

typedef struct Symbol {
    char *name;
    Type type;
    union {
        int intVal;
        float floatVal;
        double doubleVal;
        char charVal;
        int boolVal;
    } TypeVal;
    int level;
    Symbol *next;
} Symbol;

typedef struct SymbolTable {
    Symbol *table[HASH_SIZE];
    SymbolTable *parent;
} SymbolTable;

#endif