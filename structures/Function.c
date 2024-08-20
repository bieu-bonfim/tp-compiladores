#include "Function.h"

Function *create_function(Type type) {
    Function *func = (Function *)malloc(sizeof(Function));
    func->type = type;
    func->num_params = 0;
    func->params = NULL;
    return func;
}

void add_parameter(Function *func, char *name, Type type) {
    Param *newParam = (Param *)malloc(sizeof(Param));
    newParam->name = strdup(name);
    newParam->type = type;
    newParam->next = func->params;
    func->params = newParam;
    func->num_params++;
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

void print_function(Function *func) {
    printf("Function: ");
    type_to_string(func->type);
    printf("params: ");
    Param *current = func->params;
    while (current != NULL) {
        type_to_string(current->type);
        printf("%s, ", current->name);
        current = current->next;
    }
    printf("\n");
}