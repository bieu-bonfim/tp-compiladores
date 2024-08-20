#include "Types.h"

char *type_names[] = {
    "int",
    "float",
    "double",
    "char",
    "bool",
    "function",
    "void",
    "struct",
    "union",
    "enum",
    "long",
    "short"
};

char *type_to_string(Type type)
{
    return type_names[type];
}