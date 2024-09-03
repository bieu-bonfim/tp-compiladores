/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TRANSLATE_TAB_H_INCLUDED
# define YY_YY_TRANSLATE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 28 "translate.y"

#include "structures/SymbolTable.h"
#include "structures/Expression.h"
#include "structures/Operators.h"

#line 55 "translate.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    ID = 260,                      /* ID  */
    LITERALSTRING = 261,           /* LITERALSTRING  */
    LITERALCHAR = 262,             /* LITERALCHAR  */
    TRUE = 263,                    /* TRUE  */
    FALSE = 264,                   /* FALSE  */
    RELOP = 265,                   /* RELOP  */
    LOGOP = 266,                   /* LOGOP  */
    NOT = 267,                     /* NOT  */
    AROP = 268,                    /* AROP  */
    ASSIGN = 269,                  /* ASSIGN  */
    ENDLINE = 270,                 /* ENDLINE  */
    COMMA = 271,                   /* COMMA  */
    REF = 272,                     /* REF  */
    DEREF = 273,                   /* DEREF  */
    DELIMCASE = 274,               /* DELIMCASE  */
    WHILE = 275,                   /* WHILE  */
    FOR = 276,                     /* FOR  */
    IF = 277,                      /* IF  */
    ELSE = 278,                    /* ELSE  */
    SWITCH = 279,                  /* SWITCH  */
    CASE = 280,                    /* CASE  */
    DEFAULT = 281,                 /* DEFAULT  */
    TYPEDEF = 282,                 /* TYPEDEF  */
    STRUCT = 283,                  /* STRUCT  */
    UNION = 284,                   /* UNION  */
    PLUSONE = 285,                 /* PLUSONE  */
    MINUSONE = 286,                /* MINUSONE  */
    OPENBLOCK = 287,               /* OPENBLOCK  */
    CLOSEBLOCK = 288,              /* CLOSEBLOCK  */
    OPENARRAY = 289,               /* OPENARRAY  */
    CLOSEARRAY = 290,              /* CLOSEARRAY  */
    NULLT = 291,                   /* NULLT  */
    IMPORT = 292,                  /* IMPORT  */
    OPENBRACK = 293,               /* OPENBRACK  */
    CLOSEBRACK = 294,              /* CLOSEBRACK  */
    BREAK = 295,                   /* BREAK  */
    CONTINUE = 296,                /* CONTINUE  */
    ENUM = 297,                    /* ENUM  */
    CONJUNCTURE = 298,             /* CONJUNCTURE  */
    GOTO = 299,                    /* GOTO  */
    QUOTE = 300,                   /* QUOTE  */
    POINT = 301,                   /* POINT  */
    DOT = 302,                     /* DOT  */
    PARAMS = 303,                  /* PARAMS  */
    CALLFUNC = 304,                /* CALLFUNC  */
    DECLFUNC = 305,                /* DECLFUNC  */
    RETURNT = 306,                 /* RETURNT  */
    CONST = 307,                   /* CONST  */
    VOLATILE = 308,                /* VOLATILE  */
    TYPEINT = 309,                 /* TYPEINT  */
    TYPEFLOAT = 310,               /* TYPEFLOAT  */
    TYPEBOOL = 311,                /* TYPEBOOL  */
    TYPECHAR = 312,                /* TYPECHAR  */
    TYPEVOID = 313,                /* TYPEVOID  */
    TYPESHORT = 314,               /* TYPESHORT  */
    TYPEDOUBLE = 315,              /* TYPEDOUBLE  */
    TYPELONG = 316,                /* TYPELONG  */
    AND = 317,                     /* AND  */
    OR = 318                       /* OR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "translate.y"

    int ival;
    float fval;
    char *sval;
    char cval;
    Symbol *symbol;
    Type type;
    Param *param;
    Expression *result;
    ArOp arOp;
    RelOp relOp;
    LogOp logOp;
    struct ASTNodeList *node_list;
    struct ASTNode *node;

#line 151 "translate.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TRANSLATE_TAB_H_INCLUDED  */
