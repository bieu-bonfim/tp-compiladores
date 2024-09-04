#include "SymbolTable.h"

#include <stdio.h>
#include <stdlib.h>
#include "./AST/Colors.h"

#define HASH_SIZE 47

unsigned int hash(char *name)
{
  unsigned int hash_value = 0;
  while (*name)
  {
    hash_value = (hash_value << 3) + *name++;
  }
  return hash_value % HASH_SIZE;
}

SymbolTable *create_symbol_table(SymbolTable *parent)
{
  SymbolTable *new_table = (SymbolTable *)malloc(sizeof(SymbolTable));
  new_table->parent = parent;
  for (int i = 0; i < HASH_SIZE; i++)
  {
    new_table->table[i] = NULL;
  }
  return new_table;
}

Symbol* insert_symbol(SymbolTable *table, char *name, Type type, void* value)
{
  unsigned int index = hash(name);
  Symbol *new_symbol = (Symbol *)malloc(sizeof(Symbol));
  new_symbol->name = strdup(name);
  new_symbol->type = type;

  if (value == NULL) {
    new_symbol->value = allocate_and_initialize(type);
  } else {
    new_symbol->value = value;
  }

  new_symbol->next = table->table[index];
  table->table[index] = new_symbol;
  return new_symbol;
}

Symbol* create_symbol(char *name, Type type, void* value)
{
  Symbol *new_symbol = (Symbol *)malloc(sizeof(Symbol));
  new_symbol->name = strdup(name);
  new_symbol->type = type;

  if (value == NULL) {
    new_symbol->value = allocate_and_initialize(type);
  } else {
    new_symbol->value = value;
  }

  new_symbol->next = NULL;
  return new_symbol;
}

void* allocate_and_initialize(Type type) {
    void *defaultValue = NULL;

    switch (type) {
        case TYPE_INT: {
            int *val = (int*)malloc(sizeof(int));
            *val = 0;
            defaultValue = (void*)val;
            break;
        }
        case TYPE_FLOAT: {
            float *val = (float*)malloc(sizeof(float));
            *val = 0.0;
            defaultValue = (void*)val;
            break;
        }
        case TYPE_DOUBLE: {
            double *val = (double*) malloc(sizeof(double));
            *val = 0.0;
            defaultValue = (void*)val;
            break;
        }
        case TYPE_CHAR: {
            char *val = (char*) malloc(sizeof(char));
            *val = '\0';
            defaultValue = (void*)val;
            break;
        }
        case TYPE_BOOL: {
            int *val = (int*)malloc(sizeof(int));
            *val = 0;
            defaultValue = (void*)val;
            break;
        }
        case TYPE_LONG: {
            long *val = (long*)malloc(sizeof(long));
            *val = 0;
            defaultValue = (void*)val;
            break;
        }
        case TYPE_SHORT: {
            short *val = (short*)malloc(sizeof(short));
            *val = 0;
            defaultValue = (void*)val;
            break;
        }
    }
    
    return defaultValue;
}


Symbol *lookup_symbol(SymbolTable *table, char *name)
{
  unsigned int index = hash(name);
  Symbol *current_symbol = table->table[index];
  while (current_symbol)
  {
    if (strcmp(current_symbol->name, name) == 0)
    {
      return current_symbol;
    }
    current_symbol = current_symbol->next;
  }
  if (table->parent)
  {
    return lookup_symbol(table->parent, name);
  }
  return NULL;
}

void print_table(SymbolTable *table) {
    printf("\n\n");
    printf("┌──────────────────────────────────────────────────┐\n");
    printf("|"BLACK_TEXT MAGENTA_BG "                TABELA DE SIMBOLOS                "RESET"|""\n");  
    printf("├──────────────────────────────────────────────────┤\n");
    printf("│"BLACK_TEXT MAGENTA_BG"      Nome      "RESET BLACK_TEXT MAGENTA_BG"│" RESET BLACK_TEXT MAGENTA_BG"      Tipo      " RESET MAGENTA_BG BLACK_TEXT"│"RESET BLACK_TEXT MAGENTA_BG"      Valor     " RESET "│" RESET "\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        Symbol *current_symbol = table->table[i];
        while (current_symbol) {
            if (current_symbol->type == TYPE_INT) {
              printf("│"BLACK_BG PINK_TEXT" %-14s "RESET BLACK_BG"│"PINK_TEXT" %-14s "RESET"│"RESET, current_symbol->name, type_to_string(current_symbol->type));
              printf(""BLACK_BG PINK_TEXT" %-14d "RESET"│\n" RESET, *(int *)current_symbol->value);
            } else if (current_symbol->type == TYPE_FLOAT) {
                printf("│"BLACK_BG CYAN_TEXT" %-14s "RESET BLACK_BG "│"CYAN_TEXT" %-14s "RESET"│"RESET, current_symbol->name, type_to_string(current_symbol->type));
                printf(BLACK_BG CYAN_TEXT" %-14.2f "RESET"│\n" RESET, *(float *)current_symbol->value);
            } else if (current_symbol->type == TYPE_DOUBLE) {
                printf("│"BLACK_BG CYAN_TEXT" %-14s "RESET BLACK_BG"│"CYAN_TEXT" %-14s "RESET"│"RESET, current_symbol->name, type_to_string(current_symbol->type));
                printf(BLACK_BG CYAN_TEXT" %-14.2f "RESET"│\n" RESET, *(double *)current_symbol->value);
            } else if (current_symbol->type == TYPE_CHAR) {
                printf("│"BLACK_BG YELLOW_TEXT" %-14s "RESET BLACK_BG"│"YELLOW_TEXT" %-14s │"RESET, current_symbol->name, type_to_string(current_symbol->type));
                printf(BLACK_BG YELLOW_TEXT" %-15c "RESET"│\n" RESET, *(char *)current_symbol->value);
            } else if (current_symbol->type == TYPE_BOOL) {
                printf("│"BLACK_BG RED_TEXT" %-14s "RESET BLACK_BG"│"RED_TEXT" %-14s "RESET"│"RESET, current_symbol->name, type_to_string(current_symbol->type));
                printf(BLACK_BG RED_TEXT" %-14s "RESET"│\n" RESET, bool_to_string(*(int *)current_symbol->value));
            } else if (current_symbol->type == TYPE_FUNC) {
                printf("│"BLACK_BG GREEN_TEXT" %-14s "RESET BLACK_BG"│"GREEN_TEXT" %-14s │"RESET, current_symbol->name, type_to_string(current_symbol->type));
                printf(BLACK_BG GREEN_TEXT" %-14s "RESET"│\n", "");                
                print_function(*(Function *)current_symbol->value);
            } else {
                printf("│"BLACK_BG" %-14s │ %-14s │"RESET, current_symbol->name, type_to_string(current_symbol->type));
                printf(" %-14s "RESET"│""\n", "");
            }

            current_symbol = current_symbol->next;
        }
    }

    printf("└────────────────┴────────────────┴────────────────┘\n");

    if (table->parent) {
        print_table(table->parent);
    }
}



void free_symbol_table(SymbolTable *table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Symbol *symbol = table->table[i];
        while (symbol) {
            Symbol *temp = symbol;
            symbol = symbol->next;
            free(temp->name);
            free(temp);
        }
    }
    free(table);
}

char* bool_to_string(int value) {
    if (value == 0) {
        return "Falsum";
    } else {
        return "Veritas";
    }
}