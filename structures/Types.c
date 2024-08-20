#include "Types.h"

char *type_names[] = {
    "int",
    "float",
    "double",
    "char",
    "bool",
    "void"
};

char *type_to_string(Type type)
{
    return type_names[type];
}