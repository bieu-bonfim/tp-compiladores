#include "TAC.h"
#include <stdio.h>

int temp_count = 0;

void generateTAC(ASTNode *node) {
    if (node == NULL) return;

    switch (node->type) {
        case AST_TYPE_VAR_DECL:
            if (node->data.var_decl.expr != NULL) {
                generateTAC(node->data.var_decl.expr);
                printf("%s = %s\n", node->data.var_decl.var_name, node->data.var_decl.expr->temp_var);
            } else
            printf("%s = 0\n", node->data.var_decl.var_name);
            break;

        case AST_TYPE_ASSIGN:
            generateTAC(node->data.assign.expr);
            printf("%s = %s\n", node->data.assign.var_name, node->data.assign.expr->temp_var);
            break;

        case AST_TYPE_BIN_AROP:
            generateTAC(node->data.bin_arop.left);  
            generateTAC(node->data.bin_arop.right); 

            node->temp_var = generateTempVar();
            printf("%s = %s %s %s\n", node->temp_var,
                   node->data.bin_arop.left->temp_var,
                   getArOpString(node->data.bin_arop.op),
                   node->data.bin_arop.right->temp_var);
            break;

        case AST_TYPE_IF:
            node->true_label = generateLabel();
            node->false_label = generateLabel();
            node->next_label = generateLabel();

            generateTAC(node->data.if_node.condition);
            printf("if %s goto %s\n", node->data.if_node.condition->temp_var, node->true_label);
            printf("goto %s\n", node->false_label);

            printf("%s:\n", node->true_label);
            generateTAC(node->data.if_node.body_branch);
            printf("goto %s\n", node->next_label);

            printf("%s:\n", node->false_label);
            if (node->data.if_node.else_branch) {
                generateTAC(node->data.if_node.else_branch);
            }
            printf("%s:\n", node->next_label);
            break;
        
        default:
            ASTNodeList *child = node->children;
            while (child != NULL) {
                generateTAC(child->node);
                child = child->next;
            }
            break;
    }
}

char* generateTempVar() {
    static int tempVarCount = 0;
    char* tempVar = (char*)malloc(20);
    sprintf(tempVar, "t%d", tempVarCount++);
    return tempVar;
}

char* generateLabel() {
    static int labelCount = 0;
    char* label = (char*)malloc(20);
    sprintf(label, "L%d", labelCount++);
    return label;
}

const char* getArOpString(ArOp op) {
    switch (op) {
        case PLUS: return "+";
        case MINUS: return "-";
        case MULT: return "*";
        case DIV: return "/";
        default: return "?";
    }
}