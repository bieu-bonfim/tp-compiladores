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
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MULT = 260,                    /* MULT  */
    DIV = 261,                     /* DIV  */
    MOD = 262,                     /* MOD  */
    ASSIGN = 263,                  /* ASSIGN  */
    ENDLINE = 264,                 /* ENDLINE  */
    INT = 265,                     /* INT  */
    FLOAT = 266,                   /* FLOAT  */
    TRUE = 267,                    /* TRUE  */
    FALSE = 268,                   /* FALSE  */
    ID = 269,                      /* ID  */
    COMMA = 270,                   /* COMMA  */
    REF = 271,                     /* REF  */
    DEREF = 272,                   /* DEREF  */
    LITERAL = 273,                 /* LITERAL  */
    PLUSONE = 274,                 /* PLUSONE  */
    MINUSONE = 275,                /* MINUSONE  */
    OPENBLOCK = 276,               /* OPENBLOCK  */
    CLOSEBLOCK = 277,              /* CLOSEBLOCK  */
    IMPORT = 278,                  /* IMPORT  */
    OPENBRACK = 279,               /* OPENBRACK  */
    CLOSEBRACK = 280,              /* CLOSEBRACK  */
    PREPARE = 281,                 /* PREPARE  */
    CONJURE = 282,                 /* CONJURE  */
    OR = 283,                      /* OR  */
    AND = 284,                     /* AND  */
    NOT = 285,                     /* NOT  */
    GT = 286,                      /* GT  */
    LT = 287,                      /* LT  */
    GE = 288,                      /* GE  */
    LE = 289,                      /* LE  */
    EQ = 290,                      /* EQ  */
    NE = 291,                      /* NE  */
    COMPONENTS = 292,              /* COMPONENTS  */
    TYPEINT = 293,                 /* TYPEINT  */
    TYPEFLOAT = 294,               /* TYPEFLOAT  */
    TYPEBOOL = 295,                /* TYPEBOOL  */
    TYPECHAR = 296,                /* TYPECHAR  */
    TYPEVOID = 297,                /* TYPEVOID  */
    TYPESHORT = 298,               /* TYPESHORT  */
    TYPEDOUBLE = 299,              /* TYPEDOUBLE  */
    TYPELONG = 300                 /* TYPELONG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
