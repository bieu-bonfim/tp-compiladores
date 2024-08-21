#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Types.h"

typedef struct Expression {
  Type type;
  void *value;
} Expression;

#endif