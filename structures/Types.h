#ifndef TYPES_H
#define TYPES_H

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_BOOL,
    TYPE_FUNC,
    TYPE_VOID,
    TYPE_STRUCT,
    TYPE_UNION,
    TYPE_ENUM,
    TYPE_LONG,
    TYPE_SHORT,
    TYPE_POINTER,
    TYPE_ARRAY,
    TYPE_STRING,
    TYPE_NULL
} Type;

char *type_to_string(Type type);

#endif