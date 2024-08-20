#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"

typedef struct Param {
    Type type;
    char *name;
    struct Param *next;
} Param;

typedef struct Function {
    Type type;
    int num_params;
    Param *params;
} Function;

Function *create_function(Type returnType);
void add_parameter(Function *func, char *name, Type paramType);
void print_function(Function *func); 

#endif