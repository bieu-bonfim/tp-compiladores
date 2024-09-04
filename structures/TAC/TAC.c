#include "TAC.h"
#include <stdio.h>

int temp_count = 0;

char* create_temp_var() {
    char *temp_var = (char*)malloc(10 * sizeof(char));
    if (!temp_var) {
        fprintf(stderr, "Error: Unable to allocate memory for temporary variable.\n");
        exit(EXIT_FAILURE);
    }

    snprintf(temp_var, 10, "t%d", temp_count);

    temp_count++;

    return temp_var;
}

TAC* create_tac(TACOp op, char *result, char *arg1, char *arg2) {
    TAC *new_tac = (TAC*)malloc(sizeof(TAC));
    if (!new_tac) {
        fprintf(stderr, "Error: Unable to allocate memory for TAC.\n");
        exit(EXIT_FAILURE);
    }

    new_tac->op = op;
    new_tac->result = result ? strdup(result) : NULL;
    new_tac->arg1 = arg1 ? strdup(arg1) : NULL;
    new_tac->arg2 = arg2 ? strdup(arg2) : NULL;
    new_tac->label = NULL;  
    new_tac->next = NULL; 

    return new_tac;
}

TAC* generate_tac(ASTNode *node, SymbolTable *table) {
    if (node == NULL) return NULL;
    
    TAC *code = NULL;

    switch (node->type) {
        case AST_TYPE_BIN_AROP: 
            printf("Generating TAC for binary arithmetic operation...\n");
            TAC *left_code = generate_tac(node->data.bin_arop.left, table);
            TAC *right_code = generate_tac(node->data.bin_arop.right, table);
            
            // Create temporary variable for the result
            node->temp_var = create_temp_var();
            
            // Determine the TAC operation based on the AST operation
            TACOp operation;
            switch (node->data.bin_arop.op) {
                case PLUS: operation = TAC_ADD; break;
                case MINUS: operation = TAC_SUB; break;
                case MULT: operation = TAC_MUL; break;
                case DIV: operation = TAC_DIV; break;
                // Handle other operators as needed...
                default: operation = TAC_ADD; break; // Default to addition (for illustration)
            }

            // Create the TAC for this operation
            TAC *bin_op_code = create_tac(
                operation,
                node->temp_var,
                node->data.bin_arop.left->temp_var,
                node->data.bin_arop.right->temp_var
            );

            // Combine the TACs
            code = combine_tac(left_code, right_code);
            code = combine_tac(code, bin_op_code);
            break;
        case AST_TYPE_INT:
            node->temp_var = create_temp_var();
            code = create_tac(TAC_ASSIGN, node->temp_var, NULL, NULL);
            break;
        case AST_TYPE_VAR_DECL:
            TAC *expr_code = generate_tac(node->data.var_decl.expr, table);
            code = combine_tac(code, expr_code);
            break;
        default:
            break;
    }

    // Traverse child nodes
    ASTNodeList *child = node->children;
    while (child != NULL) {
        TAC *child_code = generate_tac(child->node, table);
        code = combine_tac(code, child_code);
        child = child->next;
    }

    return code;
}


TAC* combine_tac(TAC *first, TAC *second) {
    if (!first) return second;  
    if (!second) return first;  

    TAC *current = first;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = second; 
    return first;
}

void print_tac(TAC *tac) {
    while (tac != NULL) {
        switch (tac->op) {
            case TAC_ASSIGN:
                printf("%s = %s\n", tac->result, tac->arg1);
                break;
            case TAC_ADD:
                printf("%s = %s + %s\n", tac->result, tac->arg1, tac->arg2);
                break;
            case TAC_SUB:
                printf("%s = %s - %s\n", tac->result, tac->arg1, tac->arg2);
                break;
            case TAC_MUL:
                printf("%s = %s * %s\n", tac->result, tac->arg1, tac->arg2);
                break;
            case TAC_DIV:
                printf("%s = %s / %s\n", tac->result, tac->arg1, tac->arg2);
                break;
            case TAC_LABEL:
                printf("%s:\n", tac->label);
                break;
            case TAC_GOTO:
                printf("goto %s\n", tac->label);
                break;
            case TAC_IFGOTO:
                printf("if %s goto %s\n", tac->arg1, tac->label);
                break;
            case TAC_PARAM:
                printf("param %s\n", tac->arg1);
                break;
            case TAC_CALL:
                printf("%s = call %s\n", tac->result, tac->arg1);
                break;
            case TAC_RETURN:
                printf("return %s\n", tac->arg1);
                break;
            // Handle other TAC operations...
        }
        tac = tac->next;
    }
}
