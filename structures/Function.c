#include "Function.h"
#include "./AST/Colors.h"

Function *create_function(Type type) {
    Function *func = (Function *)malloc(sizeof(Function));
    func->type = type;
    func->num_params = 0;
    func->params = NULL;
    return func;
}

void add_parameter_list(Function *func, Param **param) {
    if (param == NULL || *param == NULL) {
        func->params = NULL;
    } else {
        func->params = *param;
    }
    func->num_params = param_list_length(func->params);
}

int param_list_length(Param *param) {
    int count = 0;
    Param *current = param;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

Param *create_param(char *name, Type type) {
    Param *param = (Param *)malloc(sizeof(Param));
    param->name = strdup(name);
    param->type = type;
    param->next = NULL;
    return param;
}

void link_params(Param *param, Param *next) {
    param->next = next;
}

void free_function(Function *func) {
    Param *current = func->params;
    while (current != NULL) {
        Param *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
    free(func);
}

void print_function(Function func) {
    Param *current = func.params;
    while (current != NULL) {
        printf("│"BLACK_BG GREEN_TEXT" %-14s "RESET BLACK_BG"│"GREEN_TEXT" %-14s "RESET BLACK_BG "│"GREEN_TEXT" %-14s "RESET"│\n", current->name,type_to_string(current->type),  "");
        current = current->next;
    }
}