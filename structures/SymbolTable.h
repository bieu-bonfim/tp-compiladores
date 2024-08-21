#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"
#include "Function.h"
#include "Expression.h"

#define HASH_SIZE 47
#define MAX_LEVEL 10

typedef struct Symbol {
    char *name;
    Type type;
    void *value;
    int volatile_flag;
    int constant_flag;
    struct Symbol *next;
} Symbol;

typedef struct SymbolTable {
    Symbol *table[HASH_SIZE];
    struct SymbolTable *parent;
} SymbolTable;


unsigned int hash(char *name);
SymbolTable *create_symbol_table(SymbolTable *parent);
Symbol* insert_symbol(SymbolTable *table, char *name, Type type, void* value);
Symbol *lookup_symbol(SymbolTable *table, char *name);
void print_table(SymbolTable *table);
void free_symbol_table(SymbolTable *table);
void* allocate_and_initialize(Type type);
char* bool_to_string(int value);


#endif