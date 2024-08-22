/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "translate.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "structures/SymbolTable.h"
#include "structures/Expression.h"
#include "structures/Operators.h"

extern int yyparse();
extern int invalid_found;
extern char invalid_chars[];
extern int line_number;
int error_found = 0;

void yyerror(const char *s);

SymbolTable *current_table;
Expression *evaluate_arithmetic(Expression left, Expression right, ArOp op);
Expression *evaluate_relational(Expression left, Expression right, RelOp op);
Expression *evaluate_and(Expression left, Expression right);
Expression *evaluate_or(Expression left, Expression right);
Expression *evaluate_not(Expression expr);
Expression *id_to_expression(char *id);
void* perform_arithmetic(Expression left, Expression right, ArOp op);
void* perform_int_arithmetic(void *left, void *right, ArOp op);
void* perform_float_arithmetic(void *left, void *right, ArOp op);
void* perform_double_arithmetic(void *left, void *right, ArOp op);
void* perform_long_arithmetic(void *left, void *right, ArOp op);
void* perform_short_arithmetic(void *left, void *right, ArOp op);
Expression* create_expression(Type type, void *value);
void assign_value_to_symbol(Symbol *symbol, Expression *expr);
void assign_value_to_expression(Symbol *symbol, Expression *expr);
void apply_unary_operation(Expression *result, Symbol *operand, int operation);

int yylex(void);


#line 111 "translate.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "translate.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_LITERALSTRING = 6,              /* LITERALSTRING  */
  YYSYMBOL_LITERALCHAR = 7,                /* LITERALCHAR  */
  YYSYMBOL_TRUE = 8,                       /* TRUE  */
  YYSYMBOL_FALSE = 9,                      /* FALSE  */
  YYSYMBOL_RELOP = 10,                     /* RELOP  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_NOT = 13,                       /* NOT  */
  YYSYMBOL_AROP = 14,                      /* AROP  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_ENDLINE = 16,                   /* ENDLINE  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_REF = 18,                       /* REF  */
  YYSYMBOL_DEREF = 19,                     /* DEREF  */
  YYSYMBOL_DELIMCASE = 20,                 /* DELIMCASE  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_SWITCH = 25,                    /* SWITCH  */
  YYSYMBOL_CASE = 26,                      /* CASE  */
  YYSYMBOL_DEFAULT = 27,                   /* DEFAULT  */
  YYSYMBOL_TYPEDEF = 28,                   /* TYPEDEF  */
  YYSYMBOL_STRUCT = 29,                    /* STRUCT  */
  YYSYMBOL_UNION = 30,                     /* UNION  */
  YYSYMBOL_PLUSONE = 31,                   /* PLUSONE  */
  YYSYMBOL_MINUSONE = 32,                  /* MINUSONE  */
  YYSYMBOL_OPENBLOCK = 33,                 /* OPENBLOCK  */
  YYSYMBOL_CLOSEBLOCK = 34,                /* CLOSEBLOCK  */
  YYSYMBOL_OPENARRAY = 35,                 /* OPENARRAY  */
  YYSYMBOL_CLOSEARRAY = 36,                /* CLOSEARRAY  */
  YYSYMBOL_NULLT = 37,                     /* NULLT  */
  YYSYMBOL_IMPORT = 38,                    /* IMPORT  */
  YYSYMBOL_OPENBRACK = 39,                 /* OPENBRACK  */
  YYSYMBOL_CLOSEBRACK = 40,                /* CLOSEBRACK  */
  YYSYMBOL_BREAK = 41,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 42,                  /* CONTINUE  */
  YYSYMBOL_ENUM = 43,                      /* ENUM  */
  YYSYMBOL_CONJUNCTURE = 44,               /* CONJUNCTURE  */
  YYSYMBOL_GOTO = 45,                      /* GOTO  */
  YYSYMBOL_QUOTE = 46,                     /* QUOTE  */
  YYSYMBOL_POINT = 47,                     /* POINT  */
  YYSYMBOL_DOT = 48,                       /* DOT  */
  YYSYMBOL_PARAMS = 49,                    /* PARAMS  */
  YYSYMBOL_CALLFUNC = 50,                  /* CALLFUNC  */
  YYSYMBOL_DECLFUNC = 51,                  /* DECLFUNC  */
  YYSYMBOL_RETURNT = 52,                   /* RETURNT  */
  YYSYMBOL_CONST = 53,                     /* CONST  */
  YYSYMBOL_VOLATILE = 54,                  /* VOLATILE  */
  YYSYMBOL_TYPEINT = 55,                   /* TYPEINT  */
  YYSYMBOL_TYPEFLOAT = 56,                 /* TYPEFLOAT  */
  YYSYMBOL_TYPEBOOL = 57,                  /* TYPEBOOL  */
  YYSYMBOL_TYPECHAR = 58,                  /* TYPECHAR  */
  YYSYMBOL_TYPEVOID = 59,                  /* TYPEVOID  */
  YYSYMBOL_TYPESHORT = 60,                 /* TYPESHORT  */
  YYSYMBOL_TYPEDOUBLE = 61,                /* TYPEDOUBLE  */
  YYSYMBOL_TYPELONG = 62,                  /* TYPELONG  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_begin = 64,                     /* begin  */
  YYSYMBOL_start = 65,                     /* start  */
  YYSYMBOL_start_item = 66,                /* start_item  */
  YYSYMBOL_decl_import = 67,               /* decl_import  */
  YYSYMBOL_decl_func = 68,                 /* decl_func  */
  YYSYMBOL_decl_stmt = 69,                 /* decl_stmt  */
  YYSYMBOL_stmt_block = 70,                /* stmt_block  */
  YYSYMBOL_71_1 = 71,                      /* $@1  */
  YYSYMBOL_stmt_if = 72,                   /* stmt_if  */
  YYSYMBOL_stmt_else = 73,                 /* stmt_else  */
  YYSYMBOL_stmt_switch = 74,               /* stmt_switch  */
  YYSYMBOL_75_2 = 75,                      /* $@2  */
  YYSYMBOL_case_list = 76,                 /* case_list  */
  YYSYMBOL_case_stmt = 77,                 /* case_stmt  */
  YYSYMBOL_default_case = 78,              /* default_case  */
  YYSYMBOL_stmt_return = 79,               /* stmt_return  */
  YYSYMBOL_stmt_for = 80,                  /* stmt_for  */
  YYSYMBOL_stmt_while = 81,                /* stmt_while  */
  YYSYMBOL_stmt_break = 82,                /* stmt_break  */
  YYSYMBOL_stmt_continue = 83,             /* stmt_continue  */
  YYSYMBOL_stmts = 84,                     /* stmts  */
  YYSYMBOL_stmt = 85,                      /* stmt  */
  YYSYMBOL_assignment = 86,                /* assignment  */
  YYSYMBOL_opt_assignment = 87,            /* opt_assignment  */
  YYSYMBOL_decl_var = 88,                  /* decl_var  */
  YYSYMBOL_type_qualifier = 89,            /* type_qualifier  */
  YYSYMBOL_sign_func = 90,                 /* sign_func  */
  YYSYMBOL_expr = 91,                      /* expr  */
  YYSYMBOL_term = 92,                      /* term  */
  YYSYMBOL_variable = 93,                  /* variable  */
  YYSYMBOL_attributes = 94,                /* attributes  */
  YYSYMBOL_bool = 95,                      /* bool  */
  YYSYMBOL_function_call = 96,             /* function_call  */
  YYSYMBOL_unary_expr = 97,                /* unary_expr  */
  YYSYMBOL_arguments = 98,                 /* arguments  */
  YYSYMBOL_argument = 99,                  /* argument  */
  YYSYMBOL_params = 100,                   /* params  */
  YYSYMBOL_param = 101,                    /* param  */
  YYSYMBOL_type = 102,                     /* type  */
  YYSYMBOL_enum_def = 103,                 /* enum_def  */
  YYSYMBOL_enum_list = 104,                /* enum_list  */
  YYSYMBOL_struct_def = 105,               /* struct_def  */
  YYSYMBOL_struct_list = 106,              /* struct_list  */
  YYSYMBOL_union_def = 107,                /* union_def  */
  YYSYMBOL_union_list = 108,               /* union_list  */
  YYSYMBOL_type_def = 109,                 /* type_def  */
  YYSYMBOL_type_enum = 110,                /* type_enum  */
  YYSYMBOL_type_struct = 111,              /* type_struct  */
  YYSYMBOL_type_union = 112,               /* type_union  */
  YYSYMBOL_accesses = 113,                 /* accesses  */
  YYSYMBOL_access = 114,                   /* access  */
  YYSYMBOL_literal = 115                   /* literal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   112,   113,   116,   117,   118,   119,   122,
     125,   134,   135,   136,   137,   141,   140,   153,   156,   157,
     158,   163,   161,   176,   177,   180,   183,   184,   187,   190,
     193,   196,   199,   202,   203,   206,   207,   208,   209,   210,
     211,   212,   213,   216,   228,   234,   240,   247,   256,   257,
     258,   261,   264,   265,   266,   267,   268,   269,   272,   273,
     280,   287,   293,   294,   295,   296,   299,   309,   310,   311,
     314,   323,   334,   365,   373,   381,   387,   395,   396,   399,
     404,   411,   412,   415,   420,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   441,   444,   445,   448,
     451,   452,   455,   458,   459,   462,   463,   464,   465,   468,
     471,   474,   477,   478,   481,   484,   491,   498
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "ID",
  "LITERALSTRING", "LITERALCHAR", "TRUE", "FALSE", "RELOP", "AND", "OR",
  "NOT", "AROP", "ASSIGN", "ENDLINE", "COMMA", "REF", "DEREF", "DELIMCASE",
  "WHILE", "FOR", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "TYPEDEF",
  "STRUCT", "UNION", "PLUSONE", "MINUSONE", "OPENBLOCK", "CLOSEBLOCK",
  "OPENARRAY", "CLOSEARRAY", "NULLT", "IMPORT", "OPENBRACK", "CLOSEBRACK",
  "BREAK", "CONTINUE", "ENUM", "CONJUNCTURE", "GOTO", "QUOTE", "POINT",
  "DOT", "PARAMS", "CALLFUNC", "DECLFUNC", "RETURNT", "CONST", "VOLATILE",
  "TYPEINT", "TYPEFLOAT", "TYPEBOOL", "TYPECHAR", "TYPEVOID", "TYPESHORT",
  "TYPEDOUBLE", "TYPELONG", "$accept", "begin", "start", "start_item",
  "decl_import", "decl_func", "decl_stmt", "stmt_block", "$@1", "stmt_if",
  "stmt_else", "stmt_switch", "$@2", "case_list", "case_stmt",
  "default_case", "stmt_return", "stmt_for", "stmt_while", "stmt_break",
  "stmt_continue", "stmts", "stmt", "assignment", "opt_assignment",
  "decl_var", "type_qualifier", "sign_func", "expr", "term", "variable",
  "attributes", "bool", "function_call", "unary_expr", "arguments",
  "argument", "params", "param", "type", "enum_def", "enum_list",
  "struct_def", "struct_list", "union_def", "union_list", "type_def",
  "type_enum", "type_struct", "type_union", "accesses", "access",
  "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-175)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -175,    15,   125,  -175,  -175,    13,    13,   235,    43,    51,
      13,    13,    62,    75,   246,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,    66,    77,    81,
      76,    82,    -3,  -175,  -175,  -175,  -175,    59,  -175,  -175,
       8,     9,    11,   112,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,   102,  -175,   114,  -175,  -175,  -175,   187,  -175,    -9,
    -175,    70,   123,   187,    -6,  -175,   126,   127,   128,  -175,
    -175,    87,  -175,  -175,  -175,  -175,  -175,  -175,   187,  -175,
     187,   133,   135,  -175,  -175,  -175,  -175,  -175,  -175,   187,
     246,  -175,  -175,   149,    98,   168,   173,   107,   146,   164,
     159,   135,    67,   139,   224,   224,   224,   224,   135,  -175,
    -175,   194,  -175,  -175,  -175,  -175,   246,   246,   196,   246,
    -175,   163,  -175,  -175,  -175,  -175,   186,    59,    59,   199,
     191,   202,   211,  -175,     0,   175,   187,   246,   197,  -175,
     217,   207,  -175,   230,   231,  -175,   183,   160,   198,  -175,
    -175,  -175,   223,  -175,   228,  -175,  -175,  -175,   187,  -175,
    -175,  -175,  -175,  -175,     2,   187,   187,   187,   187,  -175,
     241,   242,   187,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,    78,   200,    78,   115,  -175,  -175,   269,  -175,
      52,   236,  -175,  -175,   183,   -13,  -175,  -175,  -175,  -175,
    -175,    12,   187,   239,  -175,   243,   155,  -175,  -175,  -175,
      44,    44,   248,    -5
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      92,    90,    91,     4,     7,     6,     5,     0,     0,     0,
       0,     0,     0,    13,    93,    94,    95,    67,    76,    75,
       0,     0,     0,     0,   106,   107,   108,   110,   111,    74,
      73,     0,   109,     0,    11,    14,    12,     0,     8,    44,
      48,    49,     0,     0,    66,   113,     0,     0,     0,   105,
       9,     0,    59,    60,   115,   116,    70,    71,     0,   117,
       0,     0,    43,    57,    61,    62,    63,    64,    58,     0,
      77,    47,    50,    44,     0,     0,     0,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,    45,    51,
      78,     0,    46,   114,   112,   112,     0,     0,     0,    77,
      65,     0,    53,    54,    55,    52,    79,    69,    68,     0,
       0,     0,     0,    97,     0,     0,    81,     0,     0,    99,
       0,     0,   102,     0,     0,    96,     0,    83,     0,    82,
      80,   100,     0,   103,     0,    98,    15,    10,     0,    72,
     101,   104,    33,    84,     0,     0,     0,     0,     0,    16,
       0,     0,     0,    35,    36,    37,    40,    39,    38,    41,
      42,    34,     0,     0,     0,     0,    31,    32,     0,    30,
       0,    20,    21,    28,     0,     0,    17,    23,    29,    18,
      19,    26,     0,     0,    24,     0,     0,    33,    22,    33,
       0,     0,    41,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,  -175,  -175,  -175,  -175,   260,   -43,  -175,    89,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -164,
    -175,  -174,  -175,  -175,   193,  -175,  -175,  -175,   -52,    54,
      -2,  -175,  -175,  -175,    -1,   169,   150,  -175,   140,     5,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,
     -39,  -175,  -175
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    23,    24,    25,   173,   157,   162,   174,
     196,   175,   197,   201,   204,   205,   176,   177,   178,   179,
     180,   164,   181,    27,    91,    28,    62,    29,   147,    83,
      84,    64,    85,    86,    87,   109,   110,   148,   149,    32,
      44,   134,    45,   130,    46,   132,    33,    34,    35,    36,
      37,    65,    88
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    31,    59,    38,    39,    82,    89,     4,    49,    50,
     167,    94,    43,    47,    48,     3,    52,   144,     4,    53,
     156,   -25,   -25,   165,   166,   167,   101,   168,   102,   -25,
       7,     8,     9,   210,   145,   211,   169,   108,   202,   203,
      90,    95,    96,   170,   171,    13,   212,   213,    47,     4,
      60,    61,    66,    67,   172,    68,    48,    15,    16,    17,
      18,    19,    20,    21,    22,   165,   166,   167,    51,   168,
       5,     6,     7,     8,     9,   127,   128,   104,   105,   106,
      52,   107,    54,    10,    11,   170,   171,    13,   104,   105,
     106,    57,   107,    55,    63,   111,   172,    56,    58,    15,
      16,    17,    18,    19,    20,    21,    22,   120,   104,   105,
     106,   156,   107,   182,   183,   184,   185,    69,    70,    71,
     188,   129,   131,    92,   111,   104,   105,   106,    93,   107,
       4,    97,    98,    99,   113,   140,   100,   143,   103,   189,
     116,   191,   111,     5,     6,   104,   105,   106,   192,   107,
     206,   198,   199,     7,     8,     9,    10,    11,   122,   123,
     124,   125,    30,    12,    89,   104,   105,   106,    13,   107,
     104,   105,   106,   114,   107,   209,    14,   158,   115,   117,
      15,    16,    17,    18,    19,    20,    21,    22,   121,   194,
      72,    73,     4,    74,    75,    76,    77,   118,   119,   126,
      78,   133,   136,   137,   138,     5,     6,   141,    30,    30,
     104,   105,   106,   151,   107,   146,   156,   190,    10,    11,
       8,     9,   152,   153,    79,   139,    80,    72,    73,     4,
      74,    75,    76,    77,    13,   154,   155,    81,   159,   160,
       8,     9,     5,     6,   161,   142,    15,    16,    17,    18,
      19,    20,    21,    22,    13,    10,    11,   186,   187,   207,
     195,    79,    26,    80,    40,    41,    15,    16,    17,    18,
      19,    20,    21,    22,    81,     8,     9,   208,    42,   104,
     105,   106,   -27,   107,   200,   193,   112,   150,   135,    13,
      15,    16,    17,    18,    19,    20,    21,    22,   163,     0,
       0,    15,    16,    17,    18,    19,    20,    21,    22
};

static const yytype_int16 yycheck[] =
{
       2,     2,     5,     5,     6,    57,    15,     5,    10,    11,
      23,    63,     7,     5,     5,     0,     5,    17,     5,    14,
      33,    26,    27,    21,    22,    23,    78,    25,    80,    34,
      28,    29,    30,   207,    34,   209,    34,    89,    26,    27,
      49,    47,    48,    41,    42,    43,   210,   211,     5,     5,
      53,    54,    44,    44,    52,    44,     5,    55,    56,    57,
      58,    59,    60,    61,    62,    21,    22,    23,     6,    25,
      18,    19,    28,    29,    30,   114,   115,    10,    11,    12,
       5,    14,    16,    31,    32,    41,    42,    43,    10,    11,
      12,    15,    14,    16,    35,    90,    52,    16,    16,    55,
      56,    57,    58,    59,    60,    61,    62,    40,    10,    11,
      12,    33,    14,   165,   166,   167,   168,     5,    16,     5,
     172,   116,   117,    53,   119,    10,    11,    12,     5,    14,
       5,     5,     5,     5,    36,   130,    49,   132,     5,   182,
      33,   184,   137,    18,    19,    10,    11,    12,    33,    14,
     202,   194,   195,    28,    29,    30,    31,    32,   104,   105,
     106,   107,   164,    38,    15,    10,    11,    12,    43,    14,
      10,    11,    12,     5,    14,    20,    51,    17,     5,    33,
      55,    56,    57,    58,    59,    60,    61,    62,    49,   190,
       3,     4,     5,     6,     7,     8,     9,    33,    39,     5,
      13,     5,    39,    17,     5,    18,    19,     5,   210,   211,
      10,    11,    12,    16,    14,    40,    33,    17,    31,    32,
      29,    30,     5,    16,    37,    34,    39,     3,     4,     5,
       6,     7,     8,     9,    43,     5,     5,    50,    40,    16,
      29,    30,    18,    19,    16,    34,    55,    56,    57,    58,
      59,    60,    61,    62,    43,    31,    32,    16,    16,    20,
      24,    37,     2,    39,    29,    30,    55,    56,    57,    58,
      59,    60,    61,    62,    50,    29,    30,    34,    43,    10,
      11,    12,    34,    14,   195,    16,    93,   137,   119,    43,
      55,    56,    57,    58,    59,    60,    61,    62,   158,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,     0,     5,    18,    19,    28,    29,    30,
      31,    32,    38,    43,    51,    55,    56,    57,    58,    59,
      60,    61,    62,    66,    67,    68,    69,    86,    88,    90,
      93,    97,   102,   109,   110,   111,   112,   113,    93,    93,
      29,    30,    43,   102,   103,   105,   107,     5,     5,    93,
      93,     6,     5,   102,    16,    16,    16,    15,    16,     5,
      53,    54,    89,    35,    94,   114,    44,    44,    44,     5,
      16,     5,     3,     4,     6,     7,     8,     9,    13,    37,
      39,    50,    91,    92,    93,    95,    96,    97,   115,    15,
      49,    87,    53,     5,    91,    47,    48,     5,     5,     5,
      49,    91,    91,     5,    10,    11,    12,    14,    91,    98,
      99,   102,    87,    36,     5,     5,    33,    33,    33,    39,
      40,    49,    92,    92,    92,    92,     5,   113,   113,   102,
     106,   102,   108,     5,   104,    98,    39,    17,     5,    34,
     102,     5,    34,   102,    17,    34,    40,    91,   100,   101,
      99,    16,     5,    16,     5,     5,    33,    70,    17,    40,
      16,    16,    71,   101,    84,    21,    22,    23,    25,    34,
      41,    42,    52,    69,    72,    74,    79,    80,    81,    82,
      83,    85,    91,    91,    91,    91,    16,    16,    91,    70,
      17,    70,    33,    16,    97,    24,    73,    75,    70,    70,
      72,    76,    26,    27,    77,    78,    91,    20,    34,    20,
      84,    84,    82,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    66,    67,
      68,    69,    69,    69,    69,    71,    70,    72,    73,    73,
      73,    75,    74,    76,    76,    77,    78,    78,    79,    80,
      81,    82,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    87,    87,    88,    88,    89,    89,
      89,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    94,    94,    94,
      95,    95,    96,    97,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   104,   104,   105,
     106,   106,   107,   108,   108,   109,   109,   109,   109,   110,
     111,   112,   113,   113,   114,   115,   115,   115
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     2,     3,
       8,     2,     2,     1,     2,     0,     4,     4,     2,     2,
       0,     0,     7,     0,     2,     5,     0,     4,     3,     5,
       3,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     2,     4,     3,     1,     1,
       2,     4,     3,     3,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     0,     4,     4,
       1,     1,     6,     2,     2,     2,     2,     0,     1,     2,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     1,     3,     6,
       3,     4,     6,     3,     4,     3,     2,     2,     2,     2,
       2,     2,     0,     2,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 10: /* decl_func: DECLFUNC type ID PARAMS OPENBRACK arguments CLOSEBRACK stmt_block  */
#line 126 "translate.y"
           {
            Function *func = create_function((yyvsp[-6].type));
            Param *param = (yyvsp[-2].param);
            add_parameter_list(func, &param);
            Symbol *new_symbol = insert_symbol(current_table, (yyvsp[-5].sval), TYPE_FUNC, (void*)func);
           }
#line 1394 "translate.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 141 "translate.y"
            { 
              SymbolTable *new_table = create_symbol_table(current_table); 
              current_table = new_table; 
            }
#line 1403 "translate.tab.c"
    break;

  case 16: /* stmt_block: OPENBLOCK $@1 stmts CLOSEBLOCK  */
#line 147 "translate.y"
            {
              SymbolTable *old_table = current_table;
              current_table = current_table->parent;
            }
#line 1412 "translate.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 163 "translate.y"
             {
               SymbolTable *new_table = create_symbol_table(current_table);
               current_table = new_table;

             }
#line 1422 "translate.tab.c"
    break;

  case 22: /* stmt_switch: SWITCH expr OPENBLOCK $@2 case_list default_case CLOSEBLOCK  */
#line 170 "translate.y"
             {
               SymbolTable *old_table = current_table;
               current_table = current_table->parent;
             }
#line 1431 "translate.tab.c"
    break;

  case 43: /* assignment: variable ASSIGN expr  */
#line 217 "translate.y"
           {
            Symbol *symbol = lookup_symbol(current_table, (yyvsp[-2].symbol)->name);
            if (symbol == NULL) {
                yyerror("\033[0;34mInscricao arcana\033[0m nao encontrada...\n");
            } else {
                assign_value_to_symbol(symbol, (yyvsp[0].result));
            }
           }
#line 1444 "translate.tab.c"
    break;

  case 44: /* opt_assignment: %empty  */
#line 228 "translate.y"
               { 
                Expression *expression = (Expression*)malloc(sizeof(Expression)); 
                expression->type = TYPE_VOID;
                expression->value = NULL;
                (yyval.result) = expression; 
               }
#line 1455 "translate.tab.c"
    break;

  case 45: /* opt_assignment: ASSIGN expr  */
#line 235 "translate.y"
              { 
               (yyval.result) = (yyvsp[0].result); 
              }
#line 1463 "translate.tab.c"
    break;

  case 46: /* decl_var: type type_qualifier ID opt_assignment  */
#line 241 "translate.y"
          { 
           if ((yyvsp[0].result)->type != (yyvsp[-3].type) && (yyvsp[0].result)->type != TYPE_VOID) {
             yyerror("\033[0;34mInscricao Arcana\033[0m nao inicializada com o tipo correto...\n");
           }
           Symbol *new_symbol = insert_symbol(current_table, (yyvsp[-1].sval), (yyvsp[-3].type), (yyvsp[0].result)->value); 
          }
#line 1474 "translate.tab.c"
    break;

  case 47: /* decl_var: type ID opt_assignment  */
#line 248 "translate.y"
          { 
           if ((yyvsp[0].result)->type != (yyvsp[-2].type) && (yyvsp[0].result)->type != TYPE_VOID) {
             yyerror("\033[0;34mInscricao Arcana\033[0m nao inicializada com o tipo correto...\n");
           }
           Symbol *new_symbol = insert_symbol(current_table, (yyvsp[-1].sval), (yyvsp[-2].type), (yyvsp[0].result)->value); 
          }
#line 1485 "translate.tab.c"
    break;

  case 52: /* expr: expr AROP term  */
#line 264 "translate.y"
                     { (yyval.result) = evaluate_arithmetic(*(yyvsp[-2].result), *(yyvsp[0].result), (yyvsp[-1].arOp)); }
#line 1491 "translate.tab.c"
    break;

  case 53: /* expr: expr RELOP term  */
#line 265 "translate.y"
                      { (yyval.result) = evaluate_relational(*(yyvsp[-2].result), *(yyvsp[0].result), (yyvsp[-1].relOp)); }
#line 1497 "translate.tab.c"
    break;

  case 54: /* expr: expr AND term  */
#line 266 "translate.y"
                    { (yyval.result) = evaluate_and(*(yyvsp[-2].result), *(yyvsp[0].result)); }
#line 1503 "translate.tab.c"
    break;

  case 55: /* expr: expr OR term  */
#line 267 "translate.y"
                   { (yyval.result) = evaluate_or(*(yyvsp[-2].result), *(yyvsp[0].result)); }
#line 1509 "translate.tab.c"
    break;

  case 56: /* expr: NOT expr  */
#line 268 "translate.y"
               { (yyval.result) = evaluate_not(*(yyvsp[0].result)); }
#line 1515 "translate.tab.c"
    break;

  case 57: /* expr: term  */
#line 269 "translate.y"
           { (yyval.result) = (yyvsp[0].result); }
#line 1521 "translate.tab.c"
    break;

  case 58: /* term: literal  */
#line 272 "translate.y"
              { (yyval.result) = (yyvsp[0].result); }
#line 1527 "translate.tab.c"
    break;

  case 59: /* term: INT  */
#line 274 "translate.y"
    { 
     Expression *result = create_expression(TYPE_INT, NULL);
     result->value = malloc(sizeof(int));
     *(int*)result->value = (yyvsp[0].ival);
     (yyval.result) = result; 
    }
#line 1538 "translate.tab.c"
    break;

  case 60: /* term: FLOAT  */
#line 281 "translate.y"
    {
     Expression *result = create_expression(TYPE_FLOAT, NULL);
     result->value = malloc(sizeof(float));
     *(float*)result->value = (yyvsp[0].fval);
     (yyval.result) = result; 
    }
#line 1549 "translate.tab.c"
    break;

  case 61: /* term: variable  */
#line 288 "translate.y"
    { 
     Expression *result = create_expression((yyvsp[0].symbol)->type, NULL);
     assign_value_to_expression((yyvsp[0].symbol), result);
     (yyval.result) = result; 
    }
#line 1559 "translate.tab.c"
    break;

  case 62: /* term: bool  */
#line 293 "translate.y"
           { (yyval.result) = (yyvsp[0].result); }
#line 1565 "translate.tab.c"
    break;

  case 63: /* term: function_call  */
#line 294 "translate.y"
                    { (yyval.result) = (yyvsp[0].result); }
#line 1571 "translate.tab.c"
    break;

  case 64: /* term: unary_expr  */
#line 295 "translate.y"
                 { (yyval.result) = (yyvsp[0].result); }
#line 1577 "translate.tab.c"
    break;

  case 65: /* term: OPENBRACK expr CLOSEBRACK  */
#line 296 "translate.y"
                                { (yyval.result) = (yyvsp[-1].result); }
#line 1583 "translate.tab.c"
    break;

  case 66: /* variable: ID accesses attributes  */
#line 300 "translate.y"
         {
          Symbol *symbol = lookup_symbol(current_table, (yyvsp[-2].sval));
          if (symbol == NULL) {
            yyerror("\033[0;34mInscricao arcana\033[0m nao encontrada...\n");
          }
          (yyval.symbol) = symbol;
         }
#line 1595 "translate.tab.c"
    break;

  case 70: /* bool: TRUE  */
#line 315 "translate.y"
     {  
      Expression *result = (Expression*)malloc(sizeof(Expression));
      result->type = TYPE_BOOL;
      int *value = (int*)malloc(sizeof(int));
      *value = 1;
      result->value = (void*)value;
      (yyval.result) = result;
     }
#line 1608 "translate.tab.c"
    break;

  case 71: /* bool: FALSE  */
#line 324 "translate.y"
     {
      Expression *result = (Expression*)malloc(sizeof(Expression));
      result->type = TYPE_BOOL;
      int *value = (int*)malloc(sizeof(int));
      *value = 0;
      result->value = (void*)value;
      (yyval.result) = result;
     }
#line 1621 "translate.tab.c"
    break;

  case 72: /* function_call: CALLFUNC ID PARAMS OPENBRACK params CLOSEBRACK  */
#line 335 "translate.y"
              {
                Symbol *symbol = lookup_symbol(current_table, (yyvsp[-4].sval));
                if (symbol == NULL) {
                  yyerror("\033[0;32mMagia\033[0m nao encontrada...\n");
                }
                if (symbol->type != TYPE_FUNC) {
                  yyerror("Simbolo nao e uma \033[0;32mmagia\033[0m...\n");
                }
                Function *func = (Function *)symbol->value;
                Param *param = (yyvsp[-1].param);
                if (func->params != NULL) {
                  if (param_list_length(param) != param_list_length(func->params)) {
                    yyerror("Numero de componentes incorreto...\n");
                  }
                  Param *current = func->params;
                  while (current != NULL) {
                    if (current->type != param->type) {
                      yyerror("Tipo de componente incorreto...\n");
                    }
                    current = current->next;
                    param = param->next;
                  }
                }
                Expression *result = create_expression(func->type, NULL);
                // TODO: Call function
                result->value = allocate_and_initialize(result->type);
                (yyval.result) = result;
              }
#line 1654 "translate.tab.c"
    break;

  case 73: /* unary_expr: MINUSONE variable  */
#line 366 "translate.y"
          { 
            Expression *result = create_expression((yyvsp[0].symbol)->type, NULL);
            apply_unary_operation(result, (yyvsp[0].symbol), MINUSONEOP);
            Symbol *symbol = lookup_symbol(current_table, (yyvsp[0].symbol)->name);
            assign_value_to_symbol(symbol, result);
            (yyval.result) = result; 
          }
#line 1666 "translate.tab.c"
    break;

  case 74: /* unary_expr: PLUSONE variable  */
#line 374 "translate.y"
          { 
            Expression *result = create_expression((yyvsp[0].symbol)->type, NULL);
            apply_unary_operation(result, (yyvsp[0].symbol), PLUSONEOP);
            Symbol *symbol = lookup_symbol(current_table, (yyvsp[0].symbol)->name);
            assign_value_to_symbol(symbol, result);
            (yyval.result) = result; 
          }
#line 1678 "translate.tab.c"
    break;

  case 75: /* unary_expr: DEREF variable  */
#line 382 "translate.y"
          { 
            Expression *result = create_expression((yyvsp[0].symbol)->type, NULL);
            apply_unary_operation(result, (yyvsp[0].symbol), DEREFOP);
            (yyval.result) = result; 
          }
#line 1688 "translate.tab.c"
    break;

  case 76: /* unary_expr: REF variable  */
#line 388 "translate.y"
          { 
            Expression *result = create_expression((yyvsp[0].symbol)->type, NULL);
            apply_unary_operation(result, (yyvsp[0].symbol), REFOP);
            (yyval.result) = result; 
          }
#line 1698 "translate.tab.c"
    break;

  case 77: /* arguments: %empty  */
#line 395 "translate.y"
                       { (yyval.param) = NULL; }
#line 1704 "translate.tab.c"
    break;

  case 78: /* arguments: argument  */
#line 396 "translate.y"
                    { (yyval.param) = (yyvsp[0].param); }
#line 1710 "translate.tab.c"
    break;

  case 79: /* argument: type ID  */
#line 400 "translate.y"
         {
          Param *param = create_param((yyvsp[0].sval), (yyvsp[-1].type));
          (yyval.param) = param;
         }
#line 1719 "translate.tab.c"
    break;

  case 80: /* argument: type ID COMMA argument  */
#line 405 "translate.y"
         {
          Param *param = create_param((yyvsp[-2].sval), (yyvsp[-3].type));
          link_params(param, (yyvsp[0].param));
          (yyval.param) = param;
         }
#line 1729 "translate.tab.c"
    break;

  case 81: /* params: %empty  */
#line 411 "translate.y"
                    { (yyval.param) = NULL; }
#line 1735 "translate.tab.c"
    break;

  case 82: /* params: param  */
#line 412 "translate.y"
              { (yyval.param) = (yyvsp[0].param); }
#line 1741 "translate.tab.c"
    break;

  case 83: /* param: expr  */
#line 416 "translate.y"
     { 
      Param *param = create_param("", (yyvsp[0].result)->type);
      (yyval.param) = param; 
     }
#line 1750 "translate.tab.c"
    break;

  case 84: /* param: expr COMMA param  */
#line 421 "translate.y"
     { 
      Param *param = create_param("", (yyvsp[-2].result)->type);
      link_params(param, (yyvsp[0].param));
      (yyval.param) = param; 
     }
#line 1760 "translate.tab.c"
    break;

  case 85: /* type: TYPEINT  */
#line 428 "translate.y"
              { (yyval.type) = TYPE_INT; }
#line 1766 "translate.tab.c"
    break;

  case 86: /* type: TYPEFLOAT  */
#line 429 "translate.y"
                { (yyval.type) = TYPE_FLOAT; }
#line 1772 "translate.tab.c"
    break;

  case 87: /* type: TYPEBOOL  */
#line 430 "translate.y"
               { (yyval.type) = TYPE_BOOL; }
#line 1778 "translate.tab.c"
    break;

  case 88: /* type: TYPECHAR  */
#line 431 "translate.y"
               { (yyval.type) = TYPE_CHAR; }
#line 1784 "translate.tab.c"
    break;

  case 89: /* type: TYPEVOID  */
#line 432 "translate.y"
               { (yyval.type) = TYPE_VOID; }
#line 1790 "translate.tab.c"
    break;

  case 90: /* type: TYPEDOUBLE  */
#line 433 "translate.y"
                 { (yyval.type) = TYPE_FLOAT; }
#line 1796 "translate.tab.c"
    break;

  case 91: /* type: TYPELONG  */
#line 434 "translate.y"
               { (yyval.type) = TYPE_INT; }
#line 1802 "translate.tab.c"
    break;

  case 92: /* type: TYPESHORT  */
#line 435 "translate.y"
                { (yyval.type) = TYPE_INT; }
#line 1808 "translate.tab.c"
    break;

  case 93: /* type: type_enum  */
#line 436 "translate.y"
                { (yyval.type) = TYPE_ENUM; }
#line 1814 "translate.tab.c"
    break;

  case 94: /* type: type_struct  */
#line 437 "translate.y"
                  { (yyval.type) = TYPE_STRUCT; }
#line 1820 "translate.tab.c"
    break;

  case 95: /* type: type_union  */
#line 438 "translate.y"
                 { (yyval.type) = TYPE_UNION; }
#line 1826 "translate.tab.c"
    break;

  case 115: /* literal: LITERALSTRING  */
#line 485 "translate.y"
       { 
        Expression *result = create_expression(TYPE_STRING, NULL);        
        result->value = malloc(sizeof(char) * (strlen((yyvsp[0].sval)) + 1));
        strcpy((char*)result->value, (yyvsp[0].sval));
        (yyval.result) = result;
       }
#line 1837 "translate.tab.c"
    break;

  case 116: /* literal: LITERALCHAR  */
#line 492 "translate.y"
       { 
        Expression *result = create_expression(TYPE_CHAR, NULL);
        result->value = malloc(sizeof(char));
        *(char*)result->value = (yyvsp[0].cval);
        (yyval.result) = result;
       }
#line 1848 "translate.tab.c"
    break;

  case 117: /* literal: NULLT  */
#line 499 "translate.y"
       { 
        Expression *result = create_expression(TYPE_VOID, NULL);
        (yyval.result) = result; 
       }
#line 1857 "translate.tab.c"
    break;


#line 1861 "translate.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 505 "translate.y"


/* Error reporting function */
void yyerror(const char *s) {
    fprintf(stderr, "\033[0;31mErro Arcano...\033[0m A linha %d do grimório contém problemas.\n", line_number);
    fprintf(stderr, "%s\n", s);
    error_found = 1;
}

int main() {
    printf("\n| %d | ", line_number);
    current_table = create_symbol_table(NULL);
    yyparse();
    if (error_found) {
        printf("\nCodigo sintaticamente incorreto.\n");
    } else {
        printf("\nCodigo sintaticamente correto.\n");
    }
    print_table(current_table);
    return 0; 
}

Expression* evaluate_arithmetic(Expression left, Expression right, ArOp op) {
    Expression *result = (Expression*)malloc(sizeof(Expression));
    
    if (left.type != right.type) {
        yyerror("\033[0;36mTipos arcanos\033[0m incompativeis...\n");
    }

    result->value = perform_arithmetic(left, right, op);
    result->type = left.type;
    return result;
}

void* perform_arithmetic(Expression left, Expression right, ArOp op) {
    switch (left.type) {
        case TYPE_INT:
            return perform_int_arithmetic(left.value, right.value, op);
        case TYPE_FLOAT:
            return perform_float_arithmetic(left.value, right.value, op);
        case TYPE_DOUBLE:
            return perform_double_arithmetic(left.value, right.value, op);
        case TYPE_LONG:
            return perform_long_arithmetic(left.value, right.value, op);
        case TYPE_SHORT:
            return perform_short_arithmetic(left.value, right.value, op);
        default:
            yyerror("Tipo de \033[0;36minscricao arcana\033[0m nao suportado...\n");
    }
}

void* perform_int_arithmetic(void *left, void *right, ArOp op) {
    int *l = (int*)left;
    int *r = (int*)right;
    int *result = (int*)malloc(sizeof(int));
    switch (op) {
        case PLUS:
            *result = *l + *r;
            break;
        case MINUS:
            *result = *l - *r;
            break;
        case MULT:
            *result = *l * *r;
            break;
        case DIV:
            *result = *l / *r;
            break;
        case MOD:
            *result = *l % *r;
            break;
    }
    return (void*)result;
}

void *perform_float_arithmetic(void *left, void *right, ArOp op) {
    float *l = (float*)left;
    float *r = (float*)right;
    float *result = (float*)malloc(sizeof(float));
    switch (op) {
        case PLUS:
            *result = *l + *r;
            break;
        case MINUS:
            *result = *l - *r;
            break;
        case MULT:
            *result = *l * *r;
            break;
        case DIV:
            *result = *l / *r;
            break;
        case MOD:
            yyerror("\033[0;36mManipulacao arcana\033[0m nao suportada para fractais...\n");
            break;
    }
    return (void*)result;
}

void *perform_double_arithmetic(void *left, void *right, ArOp op) {
    double *l = (double*)left;
    double *r = (double*)right;
    double *result = (double*)malloc(sizeof(double));
    switch (op) {
        case PLUS:
            *result = *l + *r;
            break;
        case MINUS:
            *result = *l - *r;
            break;
        case MULT:
            *result = *l * *r;
            break;
        case DIV:
            *result = *l / *r;
            break;
        case MOD:
            yyerror("\033[0;36mManipulacao arcana\033[0m nao suportada para Arquifractais...\n");
            break;
    }
    return (void*)result;
}

void *perform_long_arithmetic(void *left, void *right, ArOp op) {
    long *l = (long*)left;
    long *r = (long*)right;
    long *result = (long*)malloc(sizeof(long));
    switch (op) {
        case PLUS:
            *result = *l + *r;
            break;
        case MINUS:
            *result = *l - *r;
            break;
        case MULT:
            *result = *l * *r;
            break;
        case DIV:
            *result = *l / *r;
            break;
        case MOD:
            *result = *l % *r;
            break;
    }
    return (void*)result;
}

void *perform_short_arithmetic(void *left, void *right, ArOp op) {
    short *l = (short*)left;
    short *r = (short*)right;
    short *result = (short*)malloc(sizeof(short));
    switch (op) {
        case PLUS:
            *result = *l + *r;
            break;
        case MINUS:
            *result = *l - *r;
            break;
        case MULT:
            *result = *l * *r;
            break;
        case DIV:
            *result = *l / *r;
            break;
        case MOD:
            *result = *l % *r;
            break;
    }
    return (void*)result;
}

Expression* evaluate_relational(Expression left, Expression right, RelOp op) {
    Expression *result = (Expression*)malloc(sizeof(Expression));
    result->type = TYPE_BOOL;
    int* value = (int*)malloc(sizeof(int));

    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    switch (op) {
        case GT:
            *value = (int*)left.value > (int*)right.value;
            break;
        case LT:
            *value = (int*)left.value < (int*)right.value;
            break;
        case GE:
            *value = (int*)left.value >= (int*)right.value;
            break;
        case LE:
            *value = (int*)left.value <= (int*)right.value;
            break;
        case EQ:
            *value = (int*)left.value == (int*)right.value;
            break;
        case NE:
            *value = (int*)left.value != (int*)right.value;
            break;
    }
    result->value = (void*)value;
    return result;
}

Expression *evaluate_and(Expression left, Expression right) {
    Expression *result = (Expression*)malloc(sizeof(Expression));
    result->type = TYPE_BOOL;
    int* value = (int*)malloc(sizeof(int));

    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    *value = (int*)left.value && (int*)right.value;
    result->value = (void*)value;
    return result;
}

Expression* evaluate_or(Expression left, Expression right) {
    Expression* result = (Expression*)malloc(sizeof(Expression));
    result->type = TYPE_BOOL;
    int* value = (int*)malloc(sizeof(int));

    if (left.type != right.type) {
        yyerror("Tipos incompativeis...\n");
    }

    *value = (int*)left.value || (int*)right.value;
    result->value = (void*)value;
    return result;
}

Expression* evaluate_not(Expression expr) {
    Expression *result = (Expression*)malloc(sizeof(Expression));
    if (expr.type != TYPE_BOOL) {
        yyerror("Tipos incompativeis...\n");
    }
    int* value = (int*)malloc(sizeof(int));

    result->type = TYPE_BOOL;
    *value = (!(int*)expr.value);
    result->value = (void*)value;
    return result;
}

Expression* id_to_expression(char *id) {
    Symbol *symbol = lookup_symbol(current_table, id);
    if (symbol == NULL) {
        yyerror("\033[0;36mInscricao arcana\033[0m nao encontrada...\n");
    }
    Expression *result = (Expression*)malloc(sizeof(Expression));
    result->type = symbol->type;
    result->value = symbol->value;
    return result;
}

Expression* create_expression(Type type, void *value) {
    Expression *expression = (Expression*)malloc(sizeof(Expression));
    expression->type = type;
    expression->value = value;
    return expression;
}

void assign_value_to_symbol(Symbol *symbol, Expression *expr) {
    if (symbol == NULL || expr == NULL) {
        yyerror("Inscricao ou manipulacao arcana incompativel...\n");
        return;
    }

    if (symbol->type != expr->type) {
        yyerror("Tipos incompativeis...\n");
        return;
    }

    if (symbol->value != NULL) {
        free(symbol->value);
    }

    switch (expr->type) {
        case TYPE_INT:
            symbol->value = malloc(sizeof(int));
            if (symbol->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(int*)symbol->value = *(int*)expr->value;
            break;

        case TYPE_FLOAT:
            symbol->value = malloc(sizeof(float));
            if (symbol->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(float*)symbol->value = *(float*)expr->value;
            break;

        case TYPE_DOUBLE:
            symbol->value = malloc(sizeof(double));
            if (symbol->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(double*)symbol->value = *(double*)expr->value;
            break;

        case TYPE_LONG:
            symbol->value = malloc(sizeof(long));
            if (symbol->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(long*)symbol->value = *(long*)expr->value;
            break;

        case TYPE_SHORT:
            symbol->value = malloc(sizeof(short));
            if (symbol->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(short*)symbol->value = *(short*)expr->value;
            break;

        case TYPE_BOOL:
            symbol->value = malloc(sizeof(_Bool));
            if (symbol->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(_Bool*)symbol->value = *(_Bool*)expr->value;
            break;

        case TYPE_CHAR:
            symbol->value = malloc(sizeof(char));
            if (symbol->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(char*)symbol->value = *(char*)expr->value;
            break;
        default:
            yyerror("\033[0;35mFluxo mistico\033[0m desconhecido...\n");
            return;
    }
}


void assign_value_to_expression(Symbol *symbol, Expression *expr) {
    if (symbol == NULL || expr == NULL) {
        yyerror("Inscricao arcana ou expressao magica nao compativel...\n");
        return;
    }

    if (symbol->type != expr->type) {
        yyerror("Tipos incompativeis...\n");
        return;
    }

    switch (symbol->type) {
        case TYPE_INT:
            expr->value = malloc(sizeof(int));
            if (expr->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(int*)expr->value = *(int*)symbol->value;
            break;

        case TYPE_FLOAT:
            expr->value = malloc(sizeof(float));
            if (expr->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(float*)expr->value = *(float*)symbol->value;
            break;

        case TYPE_DOUBLE:
            expr->value = malloc(sizeof(double));
            if (expr->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(double*)expr->value = *(double*)symbol->value;
            break;

        case TYPE_LONG:
            expr->value = malloc(sizeof(long));
            if (expr->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(long*)expr->value = *(long*)symbol->value;
            break;

        case TYPE_SHORT:
            expr->value = malloc(sizeof(short));
            if (expr->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(short*)expr->value = *(short*)symbol->value;
            break;

        case TYPE_BOOL:
            expr->value = malloc(sizeof(_Bool));
            if (expr->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(_Bool*)expr->value = *(_Bool*)symbol->value;
            break;

        case TYPE_CHAR:
            expr->value = malloc(sizeof(char));
            if (expr->value == NULL) {
                yyerror("\033[0;35mAlocacao mistica\033[0m falhou...\n");
                return;
            }
            *(char*)expr->value = *(char*)symbol->value;
            break;
        default:
            yyerror("Manipulacao mistica desconhecida...\n");
            return;
    }
}

void apply_unary_operation(Expression *result, Symbol *operand, int operation) {
    switch (operation) {
        case MINUSONEOP:
            if (operand->type == TYPE_INT) {
                int value = *(int*)operand->value;
                value--;
                result->value = malloc(sizeof(int));
                *(int*)result->value = value;
            } else if (operand->type == TYPE_FLOAT) {
                float value = *(float*)operand->value;
                value--;
                result->value = malloc(sizeof(float));
                *(float*)result->value = value;
            } else {
                yyerror("Encantamento invalido...\n");
            }
            break;

        case PLUSONEOP:
            if (operand->type == TYPE_INT) {
                int value = *(int*)operand->value;
                value++;
                result->value = malloc(sizeof(int));
                *(int*)result->value = value;
            } else if (operand->type == TYPE_FLOAT) {
                float value = *(float*)operand->value;
                value++;
                result->value = malloc(sizeof(float));
                *(float*)result->value = value;
            } else {
                yyerror("Encantamento invalido...\n");
            }
            break;

        case DEREFOP:
            /* result->value = *(void**)operand->value; */
            break;

        case REFOP:
            /* result->value = &operand->value; */
            break;

        default:
            yyerror("Encantamento falhou...");
    }
    result->type = operand->type;
}
