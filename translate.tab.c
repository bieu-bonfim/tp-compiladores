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

#include <llvm-c/Core.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
//#include <llvm-c/Transforms/Scalar.h>
#include <llvm-c/Analysis.h>
#include </usr/include/c++/13/cassert>
#include </usr/include/x86_64-linux-gnu/c++/13/bits/c++config.h>

#include "structures/SymbolTable.h"
#include "structures/Expression.h"
#include "structures/Operators.h"
#include "structures/AST/AST.h"
#include "structures/LLVM/codeGen.h"
#include "structures/LLVM/LLVMAST.h"
#include "structures/LLVM/NodeTypeAST.h"
#include "structures/Function.h"


extern int yyparse();
extern int invalid_found;
extern char invalid_chars[];
extern int line_number;
int error_found = 0;

void yyerror(const char *s);

SymbolTable *current_table;
ASTNode *ast;

int yylex(void);

extern ASTNode *root;


#line 112 "translate.tab.c"

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
  YYSYMBOL_LOGOP = 11,                     /* LOGOP  */
  YYSYMBOL_NOT = 12,                       /* NOT  */
  YYSYMBOL_AROP = 13,                      /* AROP  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_ENDLINE = 15,                   /* ENDLINE  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_REF = 17,                       /* REF  */
  YYSYMBOL_DEREF = 18,                     /* DEREF  */
  YYSYMBOL_DELIMCASE = 19,                 /* DELIMCASE  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_SWITCH = 24,                    /* SWITCH  */
  YYSYMBOL_CASE = 25,                      /* CASE  */
  YYSYMBOL_DEFAULT = 26,                   /* DEFAULT  */
  YYSYMBOL_TYPEDEF = 27,                   /* TYPEDEF  */
  YYSYMBOL_STRUCT = 28,                    /* STRUCT  */
  YYSYMBOL_UNION = 29,                     /* UNION  */
  YYSYMBOL_PLUSONE = 30,                   /* PLUSONE  */
  YYSYMBOL_MINUSONE = 31,                  /* MINUSONE  */
  YYSYMBOL_OPENBLOCK = 32,                 /* OPENBLOCK  */
  YYSYMBOL_CLOSEBLOCK = 33,                /* CLOSEBLOCK  */
  YYSYMBOL_OPENARRAY = 34,                 /* OPENARRAY  */
  YYSYMBOL_CLOSEARRAY = 35,                /* CLOSEARRAY  */
  YYSYMBOL_NULLT = 36,                     /* NULLT  */
  YYSYMBOL_IMPORT = 37,                    /* IMPORT  */
  YYSYMBOL_OPENBRACK = 38,                 /* OPENBRACK  */
  YYSYMBOL_CLOSEBRACK = 39,                /* CLOSEBRACK  */
  YYSYMBOL_BREAK = 40,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 41,                  /* CONTINUE  */
  YYSYMBOL_ENUM = 42,                      /* ENUM  */
  YYSYMBOL_CONJUNCTURE = 43,               /* CONJUNCTURE  */
  YYSYMBOL_GOTO = 44,                      /* GOTO  */
  YYSYMBOL_QUOTE = 45,                     /* QUOTE  */
  YYSYMBOL_POINT = 46,                     /* POINT  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_PARAMS = 48,                    /* PARAMS  */
  YYSYMBOL_CALLFUNC = 49,                  /* CALLFUNC  */
  YYSYMBOL_DECLFUNC = 50,                  /* DECLFUNC  */
  YYSYMBOL_RETURNT = 51,                   /* RETURNT  */
  YYSYMBOL_CONST = 52,                     /* CONST  */
  YYSYMBOL_VOLATILE = 53,                  /* VOLATILE  */
  YYSYMBOL_TYPEINT = 54,                   /* TYPEINT  */
  YYSYMBOL_TYPEFLOAT = 55,                 /* TYPEFLOAT  */
  YYSYMBOL_TYPEBOOL = 56,                  /* TYPEBOOL  */
  YYSYMBOL_TYPECHAR = 57,                  /* TYPECHAR  */
  YYSYMBOL_TYPEVOID = 58,                  /* TYPEVOID  */
  YYSYMBOL_TYPESHORT = 59,                 /* TYPESHORT  */
  YYSYMBOL_TYPEDOUBLE = 60,                /* TYPEDOUBLE  */
  YYSYMBOL_TYPELONG = 61,                  /* TYPELONG  */
  YYSYMBOL_AND = 62,                       /* AND  */
  YYSYMBOL_OR = 63,                        /* OR  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_begin = 65,                     /* begin  */
  YYSYMBOL_start = 66,                     /* start  */
  YYSYMBOL_start_item = 67,                /* start_item  */
  YYSYMBOL_decl_import = 68,               /* decl_import  */
  YYSYMBOL_decl_func = 69,                 /* decl_func  */
  YYSYMBOL_decl_stmt = 70,                 /* decl_stmt  */
  YYSYMBOL_stmt_block = 71,                /* stmt_block  */
  YYSYMBOL_72_1 = 72,                      /* $@1  */
  YYSYMBOL_stmt_if = 73,                   /* stmt_if  */
  YYSYMBOL_stmt_else = 74,                 /* stmt_else  */
  YYSYMBOL_stmt_switch = 75,               /* stmt_switch  */
  YYSYMBOL_76_2 = 76,                      /* $@2  */
  YYSYMBOL_case_list = 77,                 /* case_list  */
  YYSYMBOL_case_stmt = 78,                 /* case_stmt  */
  YYSYMBOL_default_case = 79,              /* default_case  */
  YYSYMBOL_stmt_return = 80,               /* stmt_return  */
  YYSYMBOL_stmt_for = 81,                  /* stmt_for  */
  YYSYMBOL_stmt_while = 82,                /* stmt_while  */
  YYSYMBOL_stmt_break = 83,                /* stmt_break  */
  YYSYMBOL_stmt_continue = 84,             /* stmt_continue  */
  YYSYMBOL_stmts = 85,                     /* stmts  */
  YYSYMBOL_stmt = 86,                      /* stmt  */
  YYSYMBOL_assignment = 87,                /* assignment  */
  YYSYMBOL_opt_assignment = 88,            /* opt_assignment  */
  YYSYMBOL_decl_var = 89,                  /* decl_var  */
  YYSYMBOL_type_qualifier = 90,            /* type_qualifier  */
  YYSYMBOL_sign_func = 91,                 /* sign_func  */
  YYSYMBOL_expr = 92,                      /* expr  */
  YYSYMBOL_term = 93,                      /* term  */
  YYSYMBOL_variable = 94,                  /* variable  */
  YYSYMBOL_attributes = 95,                /* attributes  */
  YYSYMBOL_bool = 96,                      /* bool  */
  YYSYMBOL_function_call = 97,             /* function_call  */
  YYSYMBOL_unnary_expr = 98,               /* unnary_expr  */
  YYSYMBOL_arguments = 99,                 /* arguments  */
  YYSYMBOL_argument = 100,                 /* argument  */
  YYSYMBOL_params = 101,                   /* params  */
  YYSYMBOL_param = 102,                    /* param  */
  YYSYMBOL_type = 103,                     /* type  */
  YYSYMBOL_enum_def = 104,                 /* enum_def  */
  YYSYMBOL_enum_list = 105,                /* enum_list  */
  YYSYMBOL_struct_def = 106,               /* struct_def  */
  YYSYMBOL_struct_list = 107,              /* struct_list  */
  YYSYMBOL_union_def = 108,                /* union_def  */
  YYSYMBOL_union_list = 109,               /* union_list  */
  YYSYMBOL_type_def = 110,                 /* type_def  */
  YYSYMBOL_type_enum = 111,                /* type_enum  */
  YYSYMBOL_type_struct = 112,              /* type_struct  */
  YYSYMBOL_type_union = 113,               /* type_union  */
  YYSYMBOL_accesses = 114,                 /* accesses  */
  YYSYMBOL_access = 115,                   /* access  */
  YYSYMBOL_literal = 116                   /* literal  */
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
#define YYLAST   322

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   116,   116,   119,   120,   123,   124,   125,   126,   129,
     132,   145,   146,   147,   148,   152,   151,   164,   170,   174,
     179,   186,   184,   199,   200,   203,   206,   207,   210,   216,
     222,   228,   234,   240,   241,   244,   245,   246,   247,   248,
     249,   250,   251,   254,   266,   269,   275,   280,   287,   288,
     289,   292,   295,   296,   297,   298,   299,   302,   303,   304,
     305,   306,   307,   308,   309,   312,   323,   324,   325,   328,
     332,   338,   364,   368,   372,   376,   382,   383,   386,   391,
     398,   399,   402,   406,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   425,   428,   429,   432,   435,
     436,   439,   442,   443,   446,   447,   448,   449,   452,   455,
     458,   461,   462,   465,   468,   472,   476
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
  "LITERALSTRING", "LITERALCHAR", "TRUE", "FALSE", "RELOP", "LOGOP", "NOT",
  "AROP", "ASSIGN", "ENDLINE", "COMMA", "REF", "DEREF", "DELIMCASE",
  "WHILE", "FOR", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "TYPEDEF",
  "STRUCT", "UNION", "PLUSONE", "MINUSONE", "OPENBLOCK", "CLOSEBLOCK",
  "OPENARRAY", "CLOSEARRAY", "NULLT", "IMPORT", "OPENBRACK", "CLOSEBRACK",
  "BREAK", "CONTINUE", "ENUM", "CONJUNCTURE", "GOTO", "QUOTE", "POINT",
  "DOT", "PARAMS", "CALLFUNC", "DECLFUNC", "RETURNT", "CONST", "VOLATILE",
  "TYPEINT", "TYPEFLOAT", "TYPEBOOL", "TYPECHAR", "TYPEVOID", "TYPESHORT",
  "TYPEDOUBLE", "TYPELONG", "AND", "OR", "$accept", "begin", "start",
  "start_item", "decl_import", "decl_func", "decl_stmt", "stmt_block",
  "$@1", "stmt_if", "stmt_else", "stmt_switch", "$@2", "case_list",
  "case_stmt", "default_case", "stmt_return", "stmt_for", "stmt_while",
  "stmt_break", "stmt_continue", "stmts", "stmt", "assignment",
  "opt_assignment", "decl_var", "type_qualifier", "sign_func", "expr",
  "term", "variable", "attributes", "bool", "function_call", "unnary_expr",
  "arguments", "argument", "params", "param", "type", "enum_def",
  "enum_list", "struct_def", "struct_list", "union_def", "union_list",
  "type_def", "type_enum", "type_struct", "type_union", "accesses",
  "access", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-171)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -171,     5,    13,  -171,  -171,    19,    19,   179,   179,   179,
     179,   227,    21,    31,    19,    19,    32,    41,    43,    42,
     261,   179,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,    46,    66,    72,    81,    78,    23,  -171,  -171,
    -171,  -171,    69,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,   179,  -171,   179,   107,    75,  -171,  -171,  -171,  -171,
    -171,  -171,   190,    75,    79,     9,    14,    16,   111,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,   106,  -171,  -171,  -171,
     118,   216,  -171,  -171,  -171,   179,  -171,     1,  -171,    87,
     138,   179,    62,  -171,    35,    12,   108,   215,   215,   215,
    -171,  -171,    96,   135,  -171,   154,   163,   167,  -171,  -171,
     141,  -171,    35,   179,   261,  -171,  -171,   176,    67,   187,
     188,  -171,   156,  -171,  -171,  -171,  -171,   170,    -5,  -171,
    -171,   172,   175,   181,   157,    35,  -171,  -171,   194,  -171,
    -171,  -171,  -171,   179,    77,  -171,  -171,  -171,   104,   261,
     261,   203,   261,   198,    69,    69,   247,   191,  -171,  -171,
    -171,   179,   217,  -171,   201,   230,   183,   244,   219,  -171,
      63,   211,   261,   179,  -171,   144,  -171,  -171,   239,  -171,
     254,   250,  -171,   257,   262,  -171,   170,  -171,  -171,  -171,
     120,  -171,   251,  -171,   253,  -171,  -171,   120,   237,  -171,
    -171,    58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    91,    89,    90,
       4,     6,     5,    35,    36,    37,    40,    39,    38,    41,
      42,     7,     0,     0,     0,     0,     0,     0,    13,    92,
      93,    94,    66,    75,    74,    58,    59,   114,   115,    69,
      70,     0,   116,     0,     0,     0,    56,    60,    61,    62,
      63,    57,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   109,   110,    73,    72,     0,    31,    32,   108,
       0,     0,    11,    14,    12,     0,     8,    44,    48,    49,
       0,     0,    65,   112,    55,     0,     0,     0,     0,     0,
      15,    30,     0,    20,    21,     0,     0,     0,   104,     9,
       0,    28,    43,     0,    76,    47,    50,    44,     0,     0,
       0,    64,     0,    53,    54,    52,    33,     0,     0,    17,
      23,     0,     0,     0,     0,    45,    51,    77,     0,    46,
     113,   111,   111,    80,     0,    29,    18,    19,    26,     0,
       0,     0,    76,    78,    68,    67,    82,     0,    81,    16,
      34,     0,     0,    24,     0,     0,     0,     0,     0,    96,
       0,     0,     0,     0,    71,     0,    33,    22,     0,    98,
       0,     0,   101,     0,     0,    95,     0,    79,    83,    33,
       0,    99,     0,   102,     0,    97,    10,     0,    41,   100,
     103,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,  -171,  -171,  -171,  -171,   -72,  -171,   133,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -168,
    -171,  -170,   270,  -171,   164,  -171,  -171,  -171,    -1,    57,
      -2,  -171,  -171,  -171,     8,   130,   112,  -171,   110,    -9,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
      -6,  -171,  -171
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    30,    31,    32,    33,   111,   136,    34,
     139,    35,   140,   158,   173,   174,    36,    37,    38,    39,
      40,   154,   170,    42,   125,    43,   100,    44,   166,    66,
      67,   102,    68,    69,    70,   146,   147,   167,   168,    47,
      79,   180,    80,   176,    81,   178,    48,    49,    50,    51,
      52,   103,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   113,    78,    53,    54,     3,    65,    72,    73,    74,
      46,    90,    84,    85,    82,   123,   200,     9,     4,    83,
      91,    89,   107,   108,     4,   109,    82,   110,    97,   207,
       5,     6,   208,     7,     8,     9,    83,    10,    86,   211,
      11,    12,    13,    14,    15,   107,   108,    89,   109,   124,
      16,   131,   115,    17,    18,    19,    87,   116,    88,   117,
     104,    92,   105,    20,    21,   155,   156,    22,    23,    24,
      25,    26,    27,    28,    29,    98,    99,   107,   108,   194,
     109,    93,     4,   -25,   -25,   107,   108,    94,   109,   107,
     108,   -25,   109,    96,   122,    95,   195,     7,     8,     9,
     128,    10,   150,   101,    11,    12,    13,   110,   129,   130,
     169,   114,   106,     5,     6,   148,   118,    17,    18,    19,
     137,   119,   145,   120,   206,     4,    14,    15,    21,   171,
     172,    22,    23,    24,    25,    26,    27,    28,    29,   126,
       7,     8,     9,   127,    10,   164,   165,    11,    12,    13,
     175,   177,    45,   148,   107,   108,   132,   109,   138,   141,
      17,    18,    19,   199,   133,   134,   135,   190,   142,   193,
     185,    21,   143,   148,    22,    23,    24,    25,    26,    27,
      28,    29,    55,    56,     4,    57,    58,    59,    60,   144,
     123,    61,   151,   152,   153,   162,     5,     6,    45,   163,
     107,   108,   110,   109,   159,    45,   112,   160,   179,    14,
      15,    12,    13,   161,   182,    62,   189,    63,    55,    56,
       4,    57,    58,    59,    60,    19,   107,   108,    64,   109,
     184,   121,     5,     6,   187,   188,   186,    22,    23,    24,
      25,    26,    27,    28,    29,    14,    15,    12,    13,   191,
     196,    62,   192,    63,   201,    75,    76,   107,   108,   202,
     109,    19,   204,   183,    64,   203,   209,   205,   210,    77,
     -27,   157,    41,    22,    23,    24,    25,    26,    27,    28,
      29,    22,    23,    24,    25,    26,    27,    28,    29,    12,
      13,   149,   181,   198,   197,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,    28,    29
};

static const yytype_int16 yycheck[] =
{
       2,    73,    11,     5,     6,     0,     7,     8,     9,    10,
       2,    20,    14,    15,     5,    14,   186,    22,     5,     5,
      21,     5,    10,    11,     5,    13,     5,    32,     5,   199,
      17,    18,   200,    20,    21,    22,     5,    24,     6,   207,
      27,    28,    29,    30,    31,    10,    11,     5,    13,    48,
      37,    39,    43,    40,    41,    42,    15,    43,    15,    43,
      61,    15,    63,    50,    51,   137,   138,    54,    55,    56,
      57,    58,    59,    60,    61,    52,    53,    10,    11,    16,
      13,    15,     5,    25,    26,    10,    11,    15,    13,    10,
      11,    33,    13,    15,    95,    14,    33,    20,    21,    22,
     101,    24,    35,    34,    27,    28,    29,    32,    46,    47,
      33,    32,     5,    17,    18,   124,     5,    40,    41,    42,
     112,    15,   123,     5,   196,     5,    30,    31,    51,    25,
      26,    54,    55,    56,    57,    58,    59,    60,    61,    52,
      20,    21,    22,     5,    24,   151,   152,    27,    28,    29,
     159,   160,   154,   162,    10,    11,    48,    13,    23,     5,
      40,    41,    42,    19,   107,   108,   109,   176,     5,   178,
     171,    51,     5,   182,    54,    55,    56,    57,    58,    59,
      60,    61,     3,     4,     5,     6,     7,     8,     9,    48,
      14,    12,     5,     5,    38,    38,    17,    18,   200,     5,
      10,    11,    32,    13,    32,   207,    16,    32,     5,    30,
      31,    28,    29,    32,    16,    36,    33,    38,     3,     4,
       5,     6,     7,     8,     9,    42,    10,    11,    49,    13,
      39,    15,    17,    18,    33,     5,    19,    54,    55,    56,
      57,    58,    59,    60,    61,    30,    31,    28,    29,     5,
      39,    36,    33,    38,    15,    28,    29,    10,    11,     5,
      13,    42,     5,    16,    49,    15,    15,     5,    15,    42,
      33,   138,     2,    54,    55,    56,    57,    58,    59,    60,
      61,    54,    55,    56,    57,    58,    59,    60,    61,    28,
      29,   127,   162,   183,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      59,    60,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,    66,     0,     5,    17,    18,    20,    21,    22,
      24,    27,    28,    29,    30,    31,    37,    40,    41,    42,
      50,    51,    54,    55,    56,    57,    58,    59,    60,    61,
      67,    68,    69,    70,    73,    75,    80,    81,    82,    83,
      84,    86,    87,    89,    91,    94,    98,   103,   110,   111,
     112,   113,   114,    94,    94,     3,     4,     6,     7,     8,
       9,    12,    36,    38,    49,    92,    93,    94,    96,    97,
      98,   116,    92,    92,    92,    28,    29,    42,   103,   104,
     106,   108,     5,     5,    94,    94,     6,    15,    15,     5,
     103,    92,    15,    15,    15,    14,    15,     5,    52,    53,
      90,    34,    95,   115,    92,    92,     5,    10,    11,    13,
      32,    71,    16,    71,    32,    43,    43,    43,     5,    15,
       5,    15,    92,    14,    48,    88,    52,     5,    92,    46,
      47,    39,    48,    93,    93,    93,    72,    98,    23,    74,
      76,     5,     5,     5,    48,    92,    99,   100,   103,    88,
      35,     5,     5,    38,    85,    71,    71,    73,    77,    32,
      32,    32,    38,     5,   114,   114,    92,   101,   102,    33,
      86,    25,    26,    78,    79,   103,   107,   103,   109,     5,
     105,    99,    16,    16,    39,    92,    19,    33,     5,    33,
     103,     5,    33,   103,    16,    33,    39,   100,   102,    19,
      85,    15,     5,    15,     5,     5,    71,    85,    83,    15,
      15,    83
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    67,    68,
      69,    70,    70,    70,    70,    72,    71,    73,    74,    74,
      74,    76,    75,    77,    77,    78,    79,    79,    80,    81,
      82,    83,    84,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    88,    88,    89,    89,    90,    90,
      90,    91,    92,    92,    92,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    95,    95,    95,    96,
      96,    97,    98,    98,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   104,   105,   105,   106,   107,
     107,   108,   109,   109,   110,   110,   110,   110,   111,   112,
     113,   114,   114,   115,   116,   116,   116
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     2,     3,
       8,     2,     2,     1,     2,     0,     4,     4,     2,     2,
       0,     0,     7,     0,     2,     5,     0,     4,     3,     5,
       3,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     2,     4,     3,     1,     1,
       2,     4,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     0,     4,     4,     1,
       1,     6,     2,     2,     2,     2,     0,     1,     2,     4,
       0,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     1,     3,     6,     3,
       4,     6,     3,     4,     3,     2,     2,     2,     2,     2,
       2,     0,     2,     3,     1,     1,     1
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
  case 2: /* begin: start  */
#line 116 "translate.y"
             { ast = create_root_node((yyvsp[0].node_list)); }
#line 1395 "translate.tab.c"
    break;

  case 3: /* start: %empty  */
#line 119 "translate.y"
                   { (yyval.node_list) = NULL; }
#line 1401 "translate.tab.c"
    break;

  case 4: /* start: start start_item  */
#line 120 "translate.y"
                         { (yyval.node_list) = append_to_list((yyvsp[-1].node_list), (yyvsp[0].node)); }
#line 1407 "translate.tab.c"
    break;

  case 5: /* start_item: decl_func  */
#line 123 "translate.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1413 "translate.tab.c"
    break;

  case 6: /* start_item: decl_import  */
#line 124 "translate.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1419 "translate.tab.c"
    break;

  case 7: /* start_item: stmt  */
#line 125 "translate.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1425 "translate.tab.c"
    break;

  case 8: /* start_item: unnary_expr ENDLINE  */
#line 126 "translate.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1431 "translate.tab.c"
    break;

  case 9: /* decl_import: IMPORT LITERALSTRING ENDLINE  */
#line 129 "translate.y"
                                          { (yyval.node) = create_import_node((yyvsp[-1].sval)); }
#line 1437 "translate.tab.c"
    break;

  case 10: /* decl_func: DECLFUNC type ID PARAMS OPENBRACK arguments CLOSEBRACK stmt_block  */
#line 133 "translate.y"
           {
            Function *func = create_function((yyvsp[-6].type));
            Param *param = (yyvsp[-2].param);
            add_parameter_list(func, &param);
            Symbol *new_symbol = insert_symbol(current_table, (yyvsp[-5].sval), TYPE_FUNC, (void*)func);

            ASTNode *node = create_func_node(new_symbol, (yyvsp[0].node));

            (yyval.node) = node;
           }
#line 1452 "translate.tab.c"
    break;

  case 11: /* decl_stmt: assignment ENDLINE  */
#line 145 "translate.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 1458 "translate.tab.c"
    break;

  case 12: /* decl_stmt: sign_func ENDLINE  */
#line 146 "translate.y"
                             { (yyval.node) = NULL; }
#line 1464 "translate.tab.c"
    break;

  case 13: /* decl_stmt: type_def  */
#line 147 "translate.y"
                    { (yyval.node) = NULL; }
#line 1470 "translate.tab.c"
    break;

  case 14: /* decl_stmt: decl_var ENDLINE  */
#line 148 "translate.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1476 "translate.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 152 "translate.y"
            { 
              SymbolTable *new_table = create_symbol_table(current_table); 
              current_table = new_table; 
            }
#line 1485 "translate.tab.c"
    break;

  case 16: /* stmt_block: OPENBLOCK $@1 stmts CLOSEBLOCK  */
#line 158 "translate.y"
            {
              SymbolTable *old_table = current_table;
              current_table = current_table->parent;
            }
#line 1494 "translate.tab.c"
    break;

  case 17: /* stmt_if: IF expr stmt_block stmt_else  */
#line 165 "translate.y"
       {
        (yyval.node) = create_if_node((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
       }
#line 1502 "translate.tab.c"
    break;

  case 18: /* stmt_else: ELSE stmt_block  */
#line 171 "translate.y"
         {
          (yyval.node) = (yyvsp[0].node);
         }
#line 1510 "translate.tab.c"
    break;

  case 19: /* stmt_else: ELSE stmt_if  */
#line 175 "translate.y"
         {
          (yyval.node) = (yyvsp[0].node);
         }
#line 1518 "translate.tab.c"
    break;

  case 20: /* stmt_else: %empty  */
#line 179 "translate.y"
         {
          (yyval.node) = NULL;
         }
#line 1526 "translate.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 186 "translate.y"
             {
               SymbolTable *new_table = create_symbol_table(current_table);
               current_table = new_table;

             }
#line 1536 "translate.tab.c"
    break;

  case 22: /* stmt_switch: SWITCH expr OPENBLOCK $@2 case_list default_case CLOSEBLOCK  */
#line 193 "translate.y"
             {
               SymbolTable *old_table = current_table;
               current_table = current_table->parent;
             }
#line 1545 "translate.tab.c"
    break;

  case 28: /* stmt_return: RETURNT expr ENDLINE  */
#line 211 "translate.y"
           {
            (yyval.node) = create_return_node((yyvsp[-1].node));
           }
#line 1553 "translate.tab.c"
    break;

  case 29: /* stmt_for: FOR expr COMMA unnary_expr stmt_block  */
#line 217 "translate.y"
         {
          (yyval.node) = create_for_node((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
         }
#line 1561 "translate.tab.c"
    break;

  case 30: /* stmt_while: WHILE expr stmt_block  */
#line 223 "translate.y"
          {
            (yyval.node) = create_while_node((yyvsp[-1].node), (yyvsp[0].node));
          }
#line 1569 "translate.tab.c"
    break;

  case 31: /* stmt_break: BREAK ENDLINE  */
#line 229 "translate.y"
          {
            (yyval.node) = create_break_node();
          }
#line 1577 "translate.tab.c"
    break;

  case 32: /* stmt_continue: CONTINUE ENDLINE  */
#line 235 "translate.y"
             {
              (yyval.node) = create_continue_node();
             }
#line 1585 "translate.tab.c"
    break;

  case 33: /* stmts: %empty  */
#line 240 "translate.y"
                   { (yyval.node_list) = NULL; }
#line 1591 "translate.tab.c"
    break;

  case 34: /* stmts: stmts stmt  */
#line 241 "translate.y"
                  { (yyval.node_list) = append_to_list((yyvsp[-1].node_list), (yyvsp[0].node)); }
#line 1597 "translate.tab.c"
    break;

  case 36: /* stmt: stmt_if  */
#line 245 "translate.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1603 "translate.tab.c"
    break;

  case 37: /* stmt: stmt_switch  */
#line 246 "translate.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1609 "translate.tab.c"
    break;

  case 38: /* stmt: stmt_while  */
#line 247 "translate.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1615 "translate.tab.c"
    break;

  case 39: /* stmt: stmt_for  */
#line 248 "translate.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1621 "translate.tab.c"
    break;

  case 40: /* stmt: stmt_return  */
#line 249 "translate.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1627 "translate.tab.c"
    break;

  case 41: /* stmt: stmt_break  */
#line 250 "translate.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1633 "translate.tab.c"
    break;

  case 42: /* stmt: stmt_continue  */
#line 251 "translate.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1639 "translate.tab.c"
    break;

  case 43: /* assignment: variable ASSIGN expr  */
#line 255 "translate.y"
           {
            Symbol *symbol = (yyvsp[-2].node)->data.symbol;
            if (symbol == NULL) {
                yyerror("\033[0;34mInscricao arcana\033[0m nao encontrada...\n");
            } else {
                (yyval.node) = create_assign_node(symbol, (yyvsp[0].node));
            }
           }
#line 1652 "translate.tab.c"
    break;

  case 44: /* opt_assignment: %empty  */
#line 266 "translate.y"
              { 
               (yyval.node) = NULL; 
              }
#line 1660 "translate.tab.c"
    break;

  case 45: /* opt_assignment: ASSIGN expr  */
#line 270 "translate.y"
              { 
               (yyval.node) = (yyvsp[0].node); 
              }
#line 1668 "translate.tab.c"
    break;

  case 46: /* decl_var: type type_qualifier ID opt_assignment  */
#line 276 "translate.y"
        {
          Symbol *symbol = insert_symbol(current_table, (yyvsp[-1].sval), (yyvsp[-3].type), NULL);
          (yyval.node) = create_var_decl_node(symbol, (yyvsp[0].node));
        }
#line 1677 "translate.tab.c"
    break;

  case 47: /* decl_var: type ID opt_assignment  */
#line 281 "translate.y"
        {
          Symbol *symbol = insert_symbol(current_table, (yyvsp[-1].sval), (yyvsp[-2].type), NULL);
          (yyval.node) = create_var_decl_node(symbol, (yyvsp[0].node));
        }
#line 1686 "translate.tab.c"
    break;

  case 52: /* expr: expr AROP term  */
#line 295 "translate.y"
                     { (yyval.node) = create_bin_arop_node((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].arOp)); }
#line 1692 "translate.tab.c"
    break;

  case 53: /* expr: expr RELOP term  */
#line 296 "translate.y"
                      { (yyval.node) = create_bin_relop_node((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].relOp)); }
#line 1698 "translate.tab.c"
    break;

  case 54: /* expr: expr LOGOP term  */
#line 297 "translate.y"
                      { (yyval.node) = create_bin_logop_node((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].logOp)); }
#line 1704 "translate.tab.c"
    break;

  case 55: /* expr: NOT expr  */
#line 298 "translate.y"
               { (yyval.node) = create_unop_node((yyvsp[0].node), NOTOP); }
#line 1710 "translate.tab.c"
    break;

  case 56: /* expr: term  */
#line 299 "translate.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1716 "translate.tab.c"
    break;

  case 57: /* term: literal  */
#line 302 "translate.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1722 "translate.tab.c"
    break;

  case 58: /* term: INT  */
#line 303 "translate.y"
          { (yyval.node) = create_int_node((yyvsp[0].ival)); }
#line 1728 "translate.tab.c"
    break;

  case 59: /* term: FLOAT  */
#line 304 "translate.y"
            { (yyval.node) = create_float_node((yyvsp[0].fval)); }
#line 1734 "translate.tab.c"
    break;

  case 60: /* term: variable  */
#line 305 "translate.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1740 "translate.tab.c"
    break;

  case 61: /* term: bool  */
#line 306 "translate.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1746 "translate.tab.c"
    break;

  case 62: /* term: function_call  */
#line 307 "translate.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1752 "translate.tab.c"
    break;

  case 63: /* term: unnary_expr  */
#line 308 "translate.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1758 "translate.tab.c"
    break;

  case 64: /* term: OPENBRACK expr CLOSEBRACK  */
#line 309 "translate.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1764 "translate.tab.c"
    break;

  case 65: /* variable: ID accesses attributes  */
#line 313 "translate.y"
         {
          Symbol *symbol = lookup_symbol(current_table, (yyvsp[-2].sval));
          if (symbol == NULL) {
            yyerror("\033[0;34mInscricao arcana\033[0m nao encontrada...\n");
          }
          // $$ = create_var_node(symbol, $2, $3);
          (yyval.node) = create_var_ref_node(symbol);
         }
#line 1777 "translate.tab.c"
    break;

  case 69: /* bool: TRUE  */
#line 329 "translate.y"
     {  
      (yyval.node) = create_bool_node(1);
     }
#line 1785 "translate.tab.c"
    break;

  case 70: /* bool: FALSE  */
#line 333 "translate.y"
     {
      (yyval.node) = create_bool_node(0);
     }
#line 1793 "translate.tab.c"
    break;

  case 71: /* function_call: CALLFUNC ID PARAMS OPENBRACK params CLOSEBRACK  */
#line 339 "translate.y"
              {
                Symbol *symbol = lookup_symbol(current_table, (yyvsp[-4].sval));
                if (symbol == NULL) {
                  yyerror("\033[0;32mMagia\033[0m nao encontrada...\n");
                }
                if (symbol->type != TYPE_FUNC) {
                  yyerror("Simbolo nao e uma \033[0;32mmagia\033[0m...\n");
                }
                Function *func = (Function *)symbol->value;
                ASTNodeList *params = (yyvsp[-1].node_list);
                // if (func->params != NULL) {
                //   Param *current = func->params;
                //   while (current != NULL) {
                //     if (current->type != param->type) {
                //       yyerror("Tipo de componente incorreto...\n");
                //     }
                //     current = current->next;
                //     param = param->next;
                //   }
                // }
                
                (yyval.node) = create_func_call_node(symbol, (yyvsp[-1].node_list));
              }
#line 1821 "translate.tab.c"
    break;

  case 72: /* unnary_expr: MINUSONE variable  */
#line 365 "translate.y"
          { 
            (yyval.node) = create_unop_node((yyvsp[0].node), MINUSONEOP);
          }
#line 1829 "translate.tab.c"
    break;

  case 73: /* unnary_expr: PLUSONE variable  */
#line 369 "translate.y"
          { 
            (yyval.node) = create_unop_node((yyvsp[0].node), PLUSONEOP);
          }
#line 1837 "translate.tab.c"
    break;

  case 74: /* unnary_expr: DEREF variable  */
#line 373 "translate.y"
          { 
            (yyval.node) = create_unop_node((yyvsp[0].node), DEREFOP);
          }
#line 1845 "translate.tab.c"
    break;

  case 75: /* unnary_expr: REF variable  */
#line 377 "translate.y"
          { 
            (yyval.node) = create_unop_node((yyvsp[0].node), REFOP);
          }
#line 1853 "translate.tab.c"
    break;

  case 76: /* arguments: %empty  */
#line 382 "translate.y"
                       { (yyval.param) = NULL; }
#line 1859 "translate.tab.c"
    break;

  case 77: /* arguments: argument  */
#line 383 "translate.y"
                    { (yyval.param) = (yyvsp[0].param); }
#line 1865 "translate.tab.c"
    break;

  case 78: /* argument: type ID  */
#line 387 "translate.y"
         {
          Param *param = create_param((yyvsp[0].sval), (yyvsp[-1].type));
          (yyval.param) = param;
         }
#line 1874 "translate.tab.c"
    break;

  case 79: /* argument: type ID COMMA argument  */
#line 392 "translate.y"
         {
          Param *param = create_param((yyvsp[-2].sval), (yyvsp[-3].type));
          link_params(param, (yyvsp[0].param));
          (yyval.param) = param;
         }
#line 1884 "translate.tab.c"
    break;

  case 80: /* params: %empty  */
#line 398 "translate.y"
                    { (yyval.node_list) = NULL; }
#line 1890 "translate.tab.c"
    break;

  case 81: /* params: param  */
#line 399 "translate.y"
              { (yyval.node_list) = (yyvsp[0].node_list); }
#line 1896 "translate.tab.c"
    break;

  case 82: /* param: expr  */
#line 403 "translate.y"
     { 
      (yyval.node_list) = append_to_list(NULL, (yyvsp[0].node)); 
     }
#line 1904 "translate.tab.c"
    break;

  case 83: /* param: expr COMMA param  */
#line 407 "translate.y"
     { 
      (yyval.node_list) = append_to_list((yyvsp[0].node_list), (yyvsp[-2].node)); 
     }
#line 1912 "translate.tab.c"
    break;

  case 84: /* type: TYPEINT  */
#line 412 "translate.y"
              { (yyval.type) = TYPE_INT; }
#line 1918 "translate.tab.c"
    break;

  case 85: /* type: TYPEFLOAT  */
#line 413 "translate.y"
                { (yyval.type) = TYPE_FLOAT; }
#line 1924 "translate.tab.c"
    break;

  case 86: /* type: TYPEBOOL  */
#line 414 "translate.y"
               { (yyval.type) = TYPE_BOOL; }
#line 1930 "translate.tab.c"
    break;

  case 87: /* type: TYPECHAR  */
#line 415 "translate.y"
               { (yyval.type) = TYPE_CHAR; }
#line 1936 "translate.tab.c"
    break;

  case 88: /* type: TYPEVOID  */
#line 416 "translate.y"
               { (yyval.type) = TYPE_VOID; }
#line 1942 "translate.tab.c"
    break;

  case 89: /* type: TYPEDOUBLE  */
#line 417 "translate.y"
                 { (yyval.type) = TYPE_FLOAT; }
#line 1948 "translate.tab.c"
    break;

  case 90: /* type: TYPELONG  */
#line 418 "translate.y"
               { (yyval.type) = TYPE_INT; }
#line 1954 "translate.tab.c"
    break;

  case 91: /* type: TYPESHORT  */
#line 419 "translate.y"
                { (yyval.type) = TYPE_INT; }
#line 1960 "translate.tab.c"
    break;

  case 92: /* type: type_enum  */
#line 420 "translate.y"
                { (yyval.type) = TYPE_ENUM; }
#line 1966 "translate.tab.c"
    break;

  case 93: /* type: type_struct  */
#line 421 "translate.y"
                  { (yyval.type) = TYPE_STRUCT; }
#line 1972 "translate.tab.c"
    break;

  case 94: /* type: type_union  */
#line 422 "translate.y"
                 { (yyval.type) = TYPE_UNION; }
#line 1978 "translate.tab.c"
    break;

  case 114: /* literal: LITERALSTRING  */
#line 469 "translate.y"
       { 
        (yyval.node) = create_string_node((yyvsp[0].sval));
       }
#line 1986 "translate.tab.c"
    break;

  case 115: /* literal: LITERALCHAR  */
#line 473 "translate.y"
       { 
        (yyval.node) = create_char_node((yyvsp[0].cval));
       }
#line 1994 "translate.tab.c"
    break;

  case 116: /* literal: NULLT  */
#line 477 "translate.y"
       { 
        (yyval.node) = create_null_node(); 
       }
#line 2002 "translate.tab.c"
    break;


#line 2006 "translate.tab.c"

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

#line 482 "translate.y"


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
    traverse_ast(ast, 0);
    print_table(current_table);
    initLLVM();
    codegen(root);
    generateLLVMIR();
    return 0; 
}
