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

#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

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
    LITERAL = 261,                 /* LITERAL  */
    TRUE = 262,                    /* TRUE  */
    FALSE = 263,                   /* FALSE  */
    PLUS = 264,                    /* PLUS  */
    MINUS = 265,                   /* MINUS  */
    MULT = 266,                    /* MULT  */
    DIV = 267,                     /* DIV  */
    MOD = 268,                     /* MOD  */
    ASSIGN = 269,                  /* ASSIGN  */
    ENDLINE = 270,                 /* ENDLINE  */
    COMMA = 271,                   /* COMMA  */
    REF = 272,                     /* REF  */
    DEREF = 273,                   /* DEREF  */
    QUOTE = 274,                   /* QUOTE  */
    DELIMCASE = 275,               /* DELIMCASE  */
    WHILE = 276,                   /* WHILE  */
    FOR = 277,                     /* FOR  */
    IF = 278,                      /* IF  */
    ELSE = 279,                    /* ELSE  */
    ELSEIF = 280,                  /* ELSEIF  */
    SWITCH = 281,                  /* SWITCH  */
    CASE = 282,                    /* CASE  */
    DEFAULT = 283,                 /* DEFAULT  */
    GOTO = 284,                    /* GOTO  */
    TYPEDEF = 285,                 /* TYPEDEF  */
    STRUCT = 286,                  /* STRUCT  */
    UNION = 287,                   /* UNION  */
    PLUSONE = 288,                 /* PLUSONE  */
    MINUSONE = 289,                /* MINUSONE  */
    OPENBLOCK = 290,               /* OPENBLOCK  */
    CLOSEBLOCK = 291,              /* CLOSEBLOCK  */
    IMPORT = 292,                  /* IMPORT  */
    OPENBRACK = 293,               /* OPENBRACK  */
    CLOSEBRACK = 294,              /* CLOSEBRACK  */
    PREPARE = 295,                 /* PREPARE  */
    CONJURE = 296,                 /* CONJURE  */
    OR = 297,                      /* OR  */
    AND = 298,                     /* AND  */
    NOT = 299,                     /* NOT  */
    GT = 300,                      /* GT  */
    LT = 301,                      /* LT  */
    GE = 302,                      /* GE  */
    LE = 303,                      /* LE  */
    EQ = 304,                      /* EQ  */
    NE = 305,                      /* NE  */
    PARAMS = 306,                  /* PARAMS  */
    CALLFUNC = 307,                /* CALLFUNC  */
    DECLFUNC = 308,                /* DECLFUNC  */
    RETURNT = 309,                 /* RETURNT  */
    CONST = 310,                   /* CONST  */
    VOLATILE = 311,                /* VOLATILE  */
    TYPEINT = 312,                 /* TYPEINT  */
    TYPEFLOAT = 313,               /* TYPEFLOAT  */
    TYPEBOOL = 314,                /* TYPEBOOL  */
    TYPECHAR = 315,                /* TYPECHAR  */
    TYPEVOID = 316,                /* TYPEVOID  */
    TYPESHORT = 317,               /* TYPESHORT  */
    TYPEDOUBLE = 318,              /* TYPEDOUBLE  */
    TYPELONG = 319                 /* TYPELONG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "yacc.y"

    int ival;
    float fval;
    char *sval;

#line 134 "yacc.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
