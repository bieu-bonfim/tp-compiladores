#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"

typedef struct Param {
    Type type;
    char *name;
    void* value;
    struct Param *next;
} Param;


typedef struct Function {
    Type type;
    int num_params;
    void *value;
    Param *params;
} Function;

Function *create_function(Type returnType);
void print_function(Function func); 
void add_parameter_list(Function *func, Param **param);
int param_list_length(Param *param);
Param *create_param(char *name, Type type);
void link_params(Param *param, Param *next);

#endif