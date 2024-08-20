#include "SymbolTable.h"

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

void insert_symbol(SymbolTable *table, char *name, Type type)
{
  unsigned int index = hash(name);
  Symbol *new_symbol = (Symbol *)malloc(sizeof(Symbol));
  new_symbol->name = strdup(name);
  new_symbol->type = type;

  if (type == TYPE_INT)
  {
    new_symbol->TypeVal.intVal = 0;
  }
  else if (type == TYPE_FLOAT)
  {
    new_symbol->TypeVal.floatVal = 0.0;
  }
  else if (type == TYPE_DOUBLE)
  {
    new_symbol->TypeVal.doubleVal = 0.0;
  }
  else if (type == TYPE_CHAR)
  {
    new_symbol->TypeVal.charVal = '\0';
  }
  else if (type == TYPE_BOOL)
  {
    new_symbol->TypeVal.boolVal = 1;
  }

  new_symbol->next = table->table[index];
  table->table[index] = new_symbol;
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

void print_table(SymbolTable *table)
{
  printf("-----------------------------\n");
  for (int i = 0; i < HASH_SIZE; i++)
  {
    Symbol *current_symbol = table->table[i];
    while (current_symbol)
    {
      printf("Name: %s, Type: %s", current_symbol->name, type_to_string(current_symbol->type));
      if (current_symbol->type == TYPE_INT)
      {
        printf("Value: %d\n", current_symbol->TypeVal.intVal);
      }
      else if (current_symbol->type == TYPE_FLOAT)
      {
        printf("Value: %f\n", current_symbol->TypeVal.floatVal);
      }
      else if (current_symbol->type == TYPE_DOUBLE)
      {
        printf("Value: %f\n", current_symbol->TypeVal.doubleVal);
      }
      else if (current_symbol->type == TYPE_CHAR)
      {
        printf("Value: %c\n", current_symbol->TypeVal.charVal);
      }
      else if (current_symbol->type == TYPE_BOOL)
      {
        printf("Value: %d\n", current_symbol->TypeVal.boolVal);
      }
      else if (current_symbol->type == TYPE_FUNC)
      {
        print_function(current_symbol->TypeVal.funcVal);
      } else {
        printf("\n");
      }
      
      current_symbol = current_symbol->next;
    }
  }
  if (table->parent)
  {
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
