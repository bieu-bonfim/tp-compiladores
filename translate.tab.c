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
#include "structures/AST/AST.h"
#include "structures/Types.h"

extern int yyparse();
extern int invalid_found;
extern char invalid_chars[];
extern int line_number;
int error_found = 0;

void yyerror(const char *s);

SymbolTable *current_table;
SymbolTable *global_table;
ASTNode *ast;

int yylex(void);
void semantic_analysis(ASTNode *node, SymbolTable *table);


#line 100 "translate.tab.c"

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
  YYSYMBOL_stmt_if = 72,                   /* stmt_if  */
  YYSYMBOL_stmt_else = 73,                 /* stmt_else  */
  YYSYMBOL_stmt_switch = 74,               /* stmt_switch  */
  YYSYMBOL_case_list = 75,                 /* case_list  */
  YYSYMBOL_case_stmt = 76,                 /* case_stmt  */
  YYSYMBOL_default_case = 77,              /* default_case  */
  YYSYMBOL_stmt_return = 78,               /* stmt_return  */
  YYSYMBOL_stmt_for = 79,                  /* stmt_for  */
  YYSYMBOL_stmt_while = 80,                /* stmt_while  */
  YYSYMBOL_stmt_break = 81,                /* stmt_break  */
  YYSYMBOL_stmt_continue = 82,             /* stmt_continue  */
  YYSYMBOL_stmts = 83,                     /* stmts  */
  YYSYMBOL_stmt = 84,                      /* stmt  */
  YYSYMBOL_assignment = 85,                /* assignment  */
  YYSYMBOL_opt_assignment = 86,            /* opt_assignment  */
  YYSYMBOL_decl_var = 87,                  /* decl_var  */
  YYSYMBOL_type_qualifier = 88,            /* type_qualifier  */
  YYSYMBOL_sign_func = 89,                 /* sign_func  */
  YYSYMBOL_expr = 90,                      /* expr  */
  YYSYMBOL_term = 91,                      /* term  */
  YYSYMBOL_variable = 92,                  /* variable  */
  YYSYMBOL_attributes = 93,                /* attributes  */
  YYSYMBOL_bool = 94,                      /* bool  */
  YYSYMBOL_function_call = 95,             /* function_call  */
  YYSYMBOL_unnary_expr = 96,               /* unnary_expr  */
  YYSYMBOL_arguments = 97,                 /* arguments  */
  YYSYMBOL_argument = 98,                  /* argument  */
  YYSYMBOL_params = 99,                    /* params  */
  YYSYMBOL_param = 100,                    /* param  */
  YYSYMBOL_type = 101,                     /* type  */
  YYSYMBOL_enum_def = 102,                 /* enum_def  */
  YYSYMBOL_enum_list = 103,                /* enum_list  */
  YYSYMBOL_struct_def = 104,               /* struct_def  */
  YYSYMBOL_struct_list = 105,              /* struct_list  */
  YYSYMBOL_union_def = 106,                /* union_def  */
  YYSYMBOL_union_list = 107,               /* union_list  */
  YYSYMBOL_type_def = 108,                 /* type_def  */
  YYSYMBOL_type_enum = 109,                /* type_enum  */
  YYSYMBOL_type_struct = 110,              /* type_struct  */
  YYSYMBOL_type_union = 111,               /* type_union  */
  YYSYMBOL_accesses = 112,                 /* accesses  */
  YYSYMBOL_access = 113,                   /* access  */
  YYSYMBOL_literal = 114                   /* literal  */
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
#define YYLAST   321

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
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
       0,   103,   103,   106,   107,   110,   111,   112,   113,   116,
     119,   131,   132,   133,   134,   135,   138,   144,   150,   154,
     159,   164,   171,   174,   180,   187,   190,   196,   202,   208,
     214,   220,   226,   227,   230,   231,   232,   233,   234,   235,
     236,   237,   240,   247,   250,   256,   260,   266,   267,   268,
     271,   274,   278,   282,   286,   290,   293,   294,   295,   296,
     297,   298,   299,   300,   303,   309,   310,   311,   314,   318,
     324,   330,   334,   338,   342,   348,   349,   352,   357,   364,
     365,   368,   372,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   391,   394,   395,   398,   401,   402,
     405,   408,   409,   412,   413,   414,   415,   418,   421,   424,
     427,   428,   431,   434,   438,   442
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
  "stmt_if", "stmt_else", "stmt_switch", "case_list", "case_stmt",
  "default_case", "stmt_return", "stmt_for", "stmt_while", "stmt_break",
  "stmt_continue", "stmts", "stmt", "assignment", "opt_assignment",
  "decl_var", "type_qualifier", "sign_func", "expr", "term", "variable",
  "attributes", "bool", "function_call", "unnary_expr", "arguments",
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

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-27)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -166,    46,    20,  -166,  -166,    21,    21,    81,    81,    81,
      81,    96,    59,    61,    21,    21,    88,    92,    98,    97,
     118,   260,    81,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,   113,   119,   120,   126,   134,   143,     6,
    -166,  -166,  -166,  -166,    99,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,    81,  -166,    81,    90,  -166,  -166,  -166,
    -166,  -166,  -166,   158,    90,   153,     9,    11,    12,   157,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,   155,  -166,  -166,
    -166,   124,   173,   183,  -166,  -166,  -166,    81,  -166,  -166,
       5,  -166,   128,   187,    81,    26,  -166,   166,    17,   263,
     263,   263,  -166,  -166,    65,   174,  -166,   196,   200,   201,
    -166,  -166,   169,   160,  -166,   166,    81,   260,  -166,  -166,
     198,    10,   205,   209,  -166,  -166,  -166,  -166,   162,   195,
       7,  -166,    66,   197,   206,   207,    81,   177,   166,  -166,
    -166,   225,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,    81,   217,  -166,   208,   260,   260,   237,   224,   210,
    -166,   260,   227,    99,    99,    95,  -166,  -166,   242,    87,
     243,   249,  -166,     2,    81,  -166,   211,   260,  -166,   204,
     236,  -166,   247,   239,  -166,   251,   252,  -166,  -166,   195,
    -166,   204,   240,  -166,   259,  -166,   261,  -166,  -166,   106,
    -166,  -166
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    90,    88,
      89,     4,     6,     5,    34,    35,    36,    39,    38,    37,
      40,    41,     7,     0,     0,     0,     0,     0,     0,     0,
      13,    91,    92,    93,    65,    74,    73,    57,    58,   113,
     114,    68,    69,     0,   115,     0,     0,    55,    59,    60,
      61,    62,    56,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   108,   109,    72,    71,     0,    30,    31,
     107,     0,     0,     0,    11,    14,    12,     0,    15,     8,
      43,    47,    48,     0,     0,    64,   111,    54,     0,     0,
       0,     0,    32,    29,     0,    20,    22,     0,     0,     0,
     103,     9,     0,     0,    27,    42,     0,    75,    46,    49,
      43,     0,     0,     0,    63,    52,    53,    51,     0,     0,
       0,    17,    25,     0,     0,     0,    79,     0,    44,    50,
      76,     0,    45,   112,   110,   110,    16,    33,    28,    18,
      19,     0,     0,    23,     0,     0,     0,     0,    81,     0,
      80,    75,    77,    67,    66,     0,    32,    21,     0,     0,
       0,     0,    95,     0,     0,    70,     0,     0,    32,     0,
       0,    97,     0,     0,   100,     0,     0,    94,    82,     0,
      78,     0,    40,    98,     0,   101,     0,    96,    10,    40,
      99,   102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,  -166,  -166,  -166,  -166,   -72,   135,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -165,  -166,  -145,
     277,  -166,   154,  -166,  -166,  -166,     0,   -77,    -2,  -166,
    -166,    -1,     4,   112,   100,  -166,   101,    -6,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,   -45,  -166,
    -166
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    31,    32,    33,    34,   113,    35,   141,
      36,   142,   163,   164,    37,    38,    39,    40,    41,   138,
     157,    43,   128,    44,   103,    45,   168,    67,    68,   105,
      69,    70,    71,   149,   150,   169,   170,    49,    80,   183,
      81,   179,    82,   181,    50,    51,    52,    53,    54,   106,
      72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    47,   115,    55,    56,    79,    48,    66,    73,    74,
      75,   100,    85,    86,    83,    92,    84,    90,   196,   126,
     109,   110,    93,   111,   202,     4,     4,   109,   110,     9,
     111,   189,   135,   136,   137,   197,   209,     5,     6,   112,
       7,     8,     9,   201,    10,   153,     3,    11,    12,    13,
      14,    15,   117,   127,   118,   119,   134,    16,   101,   102,
      17,    18,    19,   107,    83,   108,    84,   158,   159,    20,
      21,    22,   132,   133,    23,    24,    25,    26,    27,    28,
      29,    30,     5,     6,    57,    58,     4,    59,    60,    61,
      62,   161,   162,    63,    87,    14,    15,   125,     5,     6,
     109,   110,    90,   111,   131,   109,   110,    88,   111,   173,
     174,    14,    15,    89,   188,    12,    13,    64,   139,    65,
     191,   151,   112,    91,    76,    77,   148,   208,    94,    19,
      20,   -24,   -24,   104,    95,    96,    46,    47,    78,   -24,
      97,    23,    24,    25,    26,    27,    28,    29,    30,    98,
      23,    24,    25,    26,    27,    28,    29,    30,    99,   178,
     180,   175,   120,   109,   110,   151,   111,     4,   109,   110,
     121,   111,   122,   192,   114,   195,   109,   110,   123,   111,
     129,   151,     7,     8,     9,   116,    10,    46,    47,    11,
      12,    13,   130,   109,   110,   156,   111,   140,   124,    46,
      47,   143,    17,    18,    19,   144,   145,   146,   147,     4,
     154,    20,   126,    22,   155,   171,    23,    24,    25,    26,
      27,    28,    29,    30,     7,     8,     9,   112,    10,   165,
     172,    11,    12,    13,   109,   110,   176,   111,   166,   167,
     184,   177,   182,   187,    17,    18,    19,   190,   193,   185,
     199,   203,   204,    20,   205,    22,   206,   207,    23,    24,
      25,    26,    27,    28,    29,    30,    57,    58,     4,    59,
      60,    61,    62,   -26,   210,   160,   211,    12,    13,    42,
       5,     6,   194,   186,   152,   198,     0,   200,    12,    13,
       0,    19,     0,    14,    15,     0,     0,     0,     0,    64,
       0,    65,    19,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    20,     0,    23,    24,    25,    26,    27,    28,
      29,    30
};

static const yytype_int16 yycheck[] =
{
       2,     2,    74,     5,     6,    11,     2,     7,     8,     9,
      10,     5,    14,    15,     5,    21,     5,     5,    16,    14,
      10,    11,    22,    13,   189,     5,     5,    10,    11,    22,
      13,   176,   109,   110,   111,    33,   201,    17,    18,    32,
      20,    21,    22,   188,    24,    35,     0,    27,    28,    29,
      30,    31,    43,    48,    43,    43,    39,    37,    52,    53,
      40,    41,    42,    63,     5,    65,     5,   139,   140,    49,
      50,    51,    46,    47,    54,    55,    56,    57,    58,    59,
      60,    61,    17,    18,     3,     4,     5,     6,     7,     8,
       9,    25,    26,    12,     6,    30,    31,    97,    17,    18,
      10,    11,     5,    13,   104,    10,    11,    15,    13,   154,
     155,    30,    31,    15,    19,    28,    29,    36,   114,    38,
      33,   127,    32,     5,    28,    29,   126,   199,    15,    42,
      49,    25,    26,    34,    15,    15,   138,   138,    42,    33,
      14,    54,    55,    56,    57,    58,    59,    60,    61,    15,
      54,    55,    56,    57,    58,    59,    60,    61,    15,   165,
     166,   161,     5,    10,    11,   171,    13,     5,    10,    11,
      15,    13,    48,   179,    16,   181,    10,    11,     5,    13,
      52,   187,    20,    21,    22,    32,    24,   189,   189,    27,
      28,    29,     5,    10,    11,    33,    13,    23,    15,   201,
     201,     5,    40,    41,    42,     5,     5,    38,    48,     5,
       5,    49,    14,    51,     5,    38,    54,    55,    56,    57,
      58,    59,    60,    61,    20,    21,    22,    32,    24,    32,
       5,    27,    28,    29,    10,    11,    19,    13,    32,    32,
      16,    33,     5,    16,    40,    41,    42,     5,     5,    39,
      39,    15,     5,    49,    15,    51,     5,     5,    54,    55,
      56,    57,    58,    59,    60,    61,     3,     4,     5,     6,
       7,     8,     9,    33,    15,   140,    15,    28,    29,     2,
      17,    18,    33,   171,   130,   184,    -1,   187,    28,    29,
      -1,    42,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,
      -1,    38,    42,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    49,    -1,    54,    55,    56,    57,    58,    59,
      60,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,    66,     0,     5,    17,    18,    20,    21,    22,
      24,    27,    28,    29,    30,    31,    37,    40,    41,    42,
      49,    50,    51,    54,    55,    56,    57,    58,    59,    60,
      61,    67,    68,    69,    70,    72,    74,    78,    79,    80,
      81,    82,    84,    85,    87,    89,    92,    95,    96,   101,
     108,   109,   110,   111,   112,    92,    92,     3,     4,     6,
       7,     8,     9,    12,    36,    38,    90,    91,    92,    94,
      95,    96,   114,    90,    90,    90,    28,    29,    42,   101,
     102,   104,   106,     5,     5,    92,    92,     6,    15,    15,
       5,     5,   101,    90,    15,    15,    15,    14,    15,    15,
       5,    52,    53,    88,    34,    93,   113,    90,    90,    10,
      11,    13,    32,    71,    16,    71,    32,    43,    43,    43,
       5,    15,    48,     5,    15,    90,    14,    48,    86,    52,
       5,    90,    46,    47,    39,    91,    91,    91,    83,    96,
      23,    73,    75,     5,     5,     5,    38,    48,    90,    97,
      98,   101,    86,    35,     5,     5,    33,    84,    71,    71,
      72,    25,    26,    76,    77,    32,    32,    32,    90,    99,
     100,    38,     5,   112,   112,    90,    19,    33,   101,   105,
     101,   107,     5,   103,    16,    39,    97,    16,    19,    83,
       5,    33,   101,     5,    33,   101,    16,    33,   100,    39,
      98,    83,    81,    15,     5,    15,     5,     5,    71,    81,
      15,    15
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    67,    68,
      69,    70,    70,    70,    70,    70,    71,    72,    73,    73,
      73,    74,    75,    75,    76,    77,    77,    78,    79,    80,
      81,    82,    83,    83,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    86,    86,    87,    87,    88,    88,    88,
      89,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    92,    93,    93,    93,    94,    94,
      95,    96,    96,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   103,   103,   104,   105,   105,
     106,   107,   107,   108,   108,   108,   108,   109,   110,   111,
     112,   112,   113,   114,   114,   114
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     2,     3,
       8,     2,     2,     1,     2,     2,     3,     4,     2,     2,
       0,     6,     0,     2,     5,     0,     4,     3,     5,     3,
       2,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     2,     4,     3,     1,     1,     2,
       4,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     0,     4,     4,     1,     1,
       6,     2,     2,     2,     2,     0,     1,     2,     4,     0,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     1,     3,     6,     3,     4,
       6,     3,     4,     3,     2,     2,     2,     2,     2,     2,
       0,     2,     3,     1,     1,     1
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
#line 103 "translate.y"
             { ast = create_root_node((yyvsp[0].node_list)); }
#line 1381 "translate.tab.c"
    break;

  case 3: /* start: %empty  */
#line 106 "translate.y"
                   { (yyval.node_list) = NULL; }
#line 1387 "translate.tab.c"
    break;

  case 4: /* start: start start_item  */
#line 107 "translate.y"
                         { (yyval.node_list) = append_to_list((yyvsp[-1].node_list), (yyvsp[0].node)); }
#line 1393 "translate.tab.c"
    break;

  case 5: /* start_item: decl_func  */
#line 110 "translate.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1399 "translate.tab.c"
    break;

  case 6: /* start_item: decl_import  */
#line 111 "translate.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1405 "translate.tab.c"
    break;

  case 7: /* start_item: stmt  */
#line 112 "translate.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1411 "translate.tab.c"
    break;

  case 8: /* start_item: unnary_expr ENDLINE  */
#line 113 "translate.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1417 "translate.tab.c"
    break;

  case 9: /* decl_import: IMPORT LITERALSTRING ENDLINE  */
#line 116 "translate.y"
                                          { (yyval.node) = create_import_node((yyvsp[-1].sval)); }
#line 1423 "translate.tab.c"
    break;

  case 10: /* decl_func: DECLFUNC type ID PARAMS OPENBRACK arguments CLOSEBRACK stmt_block  */
#line 120 "translate.y"
           {
            Function *func = create_function((yyvsp[-6].type));
            Param *param = (yyvsp[-2].param);
            add_parameter_list(func, &param);

            ASTNode *node = create_func_node((yyvsp[-5].sval), func, (yyvsp[-6].type), (yyvsp[0].node));

            (yyval.node) = node;
           }
#line 1437 "translate.tab.c"
    break;

  case 11: /* decl_stmt: assignment ENDLINE  */
#line 131 "translate.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 1443 "translate.tab.c"
    break;

  case 12: /* decl_stmt: sign_func ENDLINE  */
#line 132 "translate.y"
                             { (yyval.node) = NULL; }
#line 1449 "translate.tab.c"
    break;

  case 13: /* decl_stmt: type_def  */
#line 133 "translate.y"
                    { (yyval.node) = NULL; }
#line 1455 "translate.tab.c"
    break;

  case 14: /* decl_stmt: decl_var ENDLINE  */
#line 134 "translate.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 1461 "translate.tab.c"
    break;

  case 15: /* decl_stmt: function_call ENDLINE  */
#line 135 "translate.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 1467 "translate.tab.c"
    break;

  case 16: /* stmt_block: OPENBLOCK stmts CLOSEBLOCK  */
#line 139 "translate.y"
          {
           (yyval.node) = create_block_node((yyvsp[-1].node_list));
          }
#line 1475 "translate.tab.c"
    break;

  case 17: /* stmt_if: IF expr stmt_block stmt_else  */
#line 145 "translate.y"
       {
        (yyval.node) = create_if_node((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
       }
#line 1483 "translate.tab.c"
    break;

  case 18: /* stmt_else: ELSE stmt_block  */
#line 151 "translate.y"
         {
          (yyval.node) = (yyvsp[0].node);
         }
#line 1491 "translate.tab.c"
    break;

  case 19: /* stmt_else: ELSE stmt_if  */
#line 155 "translate.y"
         {
          (yyval.node) = (yyvsp[0].node);
         }
#line 1499 "translate.tab.c"
    break;

  case 20: /* stmt_else: %empty  */
#line 159 "translate.y"
         {
          (yyval.node) = NULL;
         }
#line 1507 "translate.tab.c"
    break;

  case 21: /* stmt_switch: SWITCH expr OPENBLOCK case_list default_case CLOSEBLOCK  */
#line 165 "translate.y"
           {
            (yyval.node) = create_switch_node((yyvsp[-4].node), (yyvsp[-2].node_list), (yyvsp[-1].node));
           }
#line 1515 "translate.tab.c"
    break;

  case 22: /* case_list: %empty  */
#line 171 "translate.y"
         {
          (yyval.node_list) = NULL;
         }
#line 1523 "translate.tab.c"
    break;

  case 23: /* case_list: case_list case_stmt  */
#line 175 "translate.y"
         {
          (yyval.node_list) = append_to_list((yyvsp[-1].node_list), (yyvsp[0].node));
         }
#line 1531 "translate.tab.c"
    break;

  case 24: /* case_stmt: CASE expr DELIMCASE stmts stmt_break  */
#line 181 "translate.y"
         {
          (yyval.node) = create_case_node((yyvsp[-3].node), (yyvsp[-1].node_list), 0); 
         }
#line 1539 "translate.tab.c"
    break;

  case 25: /* default_case: %empty  */
#line 187 "translate.y"
            {
             (yyval.node) = NULL;
            }
#line 1547 "translate.tab.c"
    break;

  case 26: /* default_case: DEFAULT DELIMCASE stmts stmt_break  */
#line 191 "translate.y"
            {
             (yyval.node) = create_case_node(NULL, (yyvsp[-1].node_list), 1);
            }
#line 1555 "translate.tab.c"
    break;

  case 27: /* stmt_return: RETURNT expr ENDLINE  */
#line 197 "translate.y"
           {
            (yyval.node) = create_return_node((yyvsp[-1].node));
           }
#line 1563 "translate.tab.c"
    break;

  case 28: /* stmt_for: FOR expr COMMA unnary_expr stmt_block  */
#line 203 "translate.y"
         {
          (yyval.node) = create_for_node((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
         }
#line 1571 "translate.tab.c"
    break;

  case 29: /* stmt_while: WHILE expr stmt_block  */
#line 209 "translate.y"
          {
            (yyval.node) = create_while_node((yyvsp[-1].node), (yyvsp[0].node));
          }
#line 1579 "translate.tab.c"
    break;

  case 30: /* stmt_break: BREAK ENDLINE  */
#line 215 "translate.y"
          {
            (yyval.node) = create_break_node();
          }
#line 1587 "translate.tab.c"
    break;

  case 31: /* stmt_continue: CONTINUE ENDLINE  */
#line 221 "translate.y"
             {
              (yyval.node) = create_continue_node();
             }
#line 1595 "translate.tab.c"
    break;

  case 32: /* stmts: %empty  */
#line 226 "translate.y"
                   { (yyval.node_list) = NULL; }
#line 1601 "translate.tab.c"
    break;

  case 33: /* stmts: stmts stmt  */
#line 227 "translate.y"
                  { (yyval.node_list) = append_to_list((yyvsp[-1].node_list), (yyvsp[0].node)); }
#line 1607 "translate.tab.c"
    break;

  case 34: /* stmt: decl_stmt  */
#line 230 "translate.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1613 "translate.tab.c"
    break;

  case 35: /* stmt: stmt_if  */
#line 231 "translate.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1619 "translate.tab.c"
    break;

  case 36: /* stmt: stmt_switch  */
#line 232 "translate.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1625 "translate.tab.c"
    break;

  case 37: /* stmt: stmt_while  */
#line 233 "translate.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1631 "translate.tab.c"
    break;

  case 38: /* stmt: stmt_for  */
#line 234 "translate.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1637 "translate.tab.c"
    break;

  case 39: /* stmt: stmt_return  */
#line 235 "translate.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1643 "translate.tab.c"
    break;

  case 40: /* stmt: stmt_break  */
#line 236 "translate.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1649 "translate.tab.c"
    break;

  case 41: /* stmt: stmt_continue  */
#line 237 "translate.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1655 "translate.tab.c"
    break;

  case 42: /* assignment: variable ASSIGN expr  */
#line 241 "translate.y"
          {
           (yyval.node) = create_assign_node((yyvsp[-2].node)->data.var_name, (yyvsp[0].node));
          }
#line 1663 "translate.tab.c"
    break;

  case 43: /* opt_assignment: %empty  */
#line 247 "translate.y"
              { 
               (yyval.node) = NULL; 
              }
#line 1671 "translate.tab.c"
    break;

  case 44: /* opt_assignment: ASSIGN expr  */
#line 251 "translate.y"
              { 
               (yyval.node) = (yyvsp[0].node); 
              }
#line 1679 "translate.tab.c"
    break;

  case 45: /* decl_var: type type_qualifier ID opt_assignment  */
#line 257 "translate.y"
        {
          (yyval.node) = create_var_decl_node((yyvsp[-1].sval), (yyvsp[-3].type), (yyvsp[0].node));
        }
#line 1687 "translate.tab.c"
    break;

  case 46: /* decl_var: type ID opt_assignment  */
#line 261 "translate.y"
        {
          (yyval.node) = create_var_decl_node((yyvsp[-1].sval), (yyvsp[-2].type), (yyvsp[0].node));
        }
#line 1695 "translate.tab.c"
    break;

  case 51: /* expr: expr AROP term  */
#line 275 "translate.y"
    { 
     (yyval.node) = create_bin_arop_node((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].arOp)); 
    }
#line 1703 "translate.tab.c"
    break;

  case 52: /* expr: expr RELOP term  */
#line 279 "translate.y"
    { 
     (yyval.node) = create_bin_relop_node((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].relOp)); 
    }
#line 1711 "translate.tab.c"
    break;

  case 53: /* expr: expr LOGOP term  */
#line 283 "translate.y"
    { 
     (yyval.node) = create_bin_logop_node((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].logOp)); 
    }
#line 1719 "translate.tab.c"
    break;

  case 54: /* expr: NOT expr  */
#line 287 "translate.y"
    { 
     (yyval.node) = create_unop_node((yyvsp[0].node), NOTOP); 
    }
#line 1727 "translate.tab.c"
    break;

  case 55: /* expr: term  */
#line 290 "translate.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1733 "translate.tab.c"
    break;

  case 56: /* term: literal  */
#line 293 "translate.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1739 "translate.tab.c"
    break;

  case 57: /* term: INT  */
#line 294 "translate.y"
          { (yyval.node) = create_int_node((yyvsp[0].ival)); }
#line 1745 "translate.tab.c"
    break;

  case 58: /* term: FLOAT  */
#line 295 "translate.y"
            { (yyval.node) = create_float_node((yyvsp[0].fval)); }
#line 1751 "translate.tab.c"
    break;

  case 59: /* term: variable  */
#line 296 "translate.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1757 "translate.tab.c"
    break;

  case 60: /* term: bool  */
#line 297 "translate.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1763 "translate.tab.c"
    break;

  case 61: /* term: function_call  */
#line 298 "translate.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1769 "translate.tab.c"
    break;

  case 62: /* term: unnary_expr  */
#line 299 "translate.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1775 "translate.tab.c"
    break;

  case 63: /* term: OPENBRACK expr CLOSEBRACK  */
#line 300 "translate.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1781 "translate.tab.c"
    break;

  case 64: /* variable: ID accesses attributes  */
#line 304 "translate.y"
         {
          (yyval.node) = create_var_ref_node((yyvsp[-2].sval));
         }
#line 1789 "translate.tab.c"
    break;

  case 68: /* bool: TRUE  */
#line 315 "translate.y"
     {  
      (yyval.node) = create_bool_node(1);
     }
#line 1797 "translate.tab.c"
    break;

  case 69: /* bool: FALSE  */
#line 319 "translate.y"
     {
      (yyval.node) = create_bool_node(0);
     }
#line 1805 "translate.tab.c"
    break;

  case 70: /* function_call: CALLFUNC ID PARAMS OPENBRACK params CLOSEBRACK  */
#line 325 "translate.y"
             {
              (yyval.node) = create_func_call_node((yyvsp[-4].sval), (yyvsp[-1].node_list));
             }
#line 1813 "translate.tab.c"
    break;

  case 71: /* unnary_expr: MINUSONE variable  */
#line 331 "translate.y"
          { 
            (yyval.node) = create_unop_node((yyvsp[0].node), MINUSONEOP);
          }
#line 1821 "translate.tab.c"
    break;

  case 72: /* unnary_expr: PLUSONE variable  */
#line 335 "translate.y"
          { 
            (yyval.node) = create_unop_node((yyvsp[0].node), PLUSONEOP);
          }
#line 1829 "translate.tab.c"
    break;

  case 73: /* unnary_expr: DEREF variable  */
#line 339 "translate.y"
          { 
            (yyval.node) = create_unop_node((yyvsp[0].node), DEREFOP);
          }
#line 1837 "translate.tab.c"
    break;

  case 74: /* unnary_expr: REF variable  */
#line 343 "translate.y"
          { 
            (yyval.node) = create_unop_node((yyvsp[0].node), REFOP);
          }
#line 1845 "translate.tab.c"
    break;

  case 75: /* arguments: %empty  */
#line 348 "translate.y"
                       { (yyval.param) = NULL; }
#line 1851 "translate.tab.c"
    break;

  case 76: /* arguments: argument  */
#line 349 "translate.y"
                    { (yyval.param) = (yyvsp[0].param); }
#line 1857 "translate.tab.c"
    break;

  case 77: /* argument: type ID  */
#line 353 "translate.y"
         {
          Param *param = create_param((yyvsp[0].sval), (yyvsp[-1].type));
          (yyval.param) = param;
         }
#line 1866 "translate.tab.c"
    break;

  case 78: /* argument: type ID COMMA argument  */
#line 358 "translate.y"
         {
          Param *param = create_param((yyvsp[-2].sval), (yyvsp[-3].type));
          link_params(param, (yyvsp[0].param));
          (yyval.param) = param;
         }
#line 1876 "translate.tab.c"
    break;

  case 79: /* params: %empty  */
#line 364 "translate.y"
                    { (yyval.node_list) = NULL; }
#line 1882 "translate.tab.c"
    break;

  case 80: /* params: param  */
#line 365 "translate.y"
              { (yyval.node_list) = (yyvsp[0].node_list); }
#line 1888 "translate.tab.c"
    break;

  case 81: /* param: expr  */
#line 369 "translate.y"
     { 
      (yyval.node_list) = append_to_list(NULL, (yyvsp[0].node)); 
     }
#line 1896 "translate.tab.c"
    break;

  case 82: /* param: expr COMMA param  */
#line 373 "translate.y"
     { 
      (yyval.node_list) = append_to_list((yyvsp[0].node_list), (yyvsp[-2].node)); 
     }
#line 1904 "translate.tab.c"
    break;

  case 83: /* type: TYPEINT  */
#line 378 "translate.y"
              { (yyval.type) = TYPE_INT; }
#line 1910 "translate.tab.c"
    break;

  case 84: /* type: TYPEFLOAT  */
#line 379 "translate.y"
                { (yyval.type) = TYPE_FLOAT; }
#line 1916 "translate.tab.c"
    break;

  case 85: /* type: TYPEBOOL  */
#line 380 "translate.y"
               { (yyval.type) = TYPE_BOOL; }
#line 1922 "translate.tab.c"
    break;

  case 86: /* type: TYPECHAR  */
#line 381 "translate.y"
               { (yyval.type) = TYPE_CHAR; }
#line 1928 "translate.tab.c"
    break;

  case 87: /* type: TYPEVOID  */
#line 382 "translate.y"
               { (yyval.type) = TYPE_VOID; }
#line 1934 "translate.tab.c"
    break;

  case 88: /* type: TYPEDOUBLE  */
#line 383 "translate.y"
                 { (yyval.type) = TYPE_FLOAT; }
#line 1940 "translate.tab.c"
    break;

  case 89: /* type: TYPELONG  */
#line 384 "translate.y"
               { (yyval.type) = TYPE_INT; }
#line 1946 "translate.tab.c"
    break;

  case 90: /* type: TYPESHORT  */
#line 385 "translate.y"
                { (yyval.type) = TYPE_INT; }
#line 1952 "translate.tab.c"
    break;

  case 91: /* type: type_enum  */
#line 386 "translate.y"
                { (yyval.type) = TYPE_ENUM; }
#line 1958 "translate.tab.c"
    break;

  case 92: /* type: type_struct  */
#line 387 "translate.y"
                  { (yyval.type) = TYPE_STRUCT; }
#line 1964 "translate.tab.c"
    break;

  case 93: /* type: type_union  */
#line 388 "translate.y"
                 { (yyval.type) = TYPE_UNION; }
#line 1970 "translate.tab.c"
    break;

  case 113: /* literal: LITERALSTRING  */
#line 435 "translate.y"
       { 
        (yyval.node) = create_string_node((yyvsp[0].sval));
       }
#line 1978 "translate.tab.c"
    break;

  case 114: /* literal: LITERALCHAR  */
#line 439 "translate.y"
       { 
        (yyval.node) = create_char_node((yyvsp[0].cval));
       }
#line 1986 "translate.tab.c"
    break;

  case 115: /* literal: NULLT  */
#line 443 "translate.y"
       { 
        (yyval.node) = create_null_node(); 
       }
#line 1994 "translate.tab.c"
    break;


#line 1998 "translate.tab.c"

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

#line 448 "translate.y"


/* Error reporting function */
void yyerror(const char *s) {
    fprintf(stderr, "\033[0;31mErro Arcano...\033[0m A linha %d do grimório contém problemas.\n", line_number);
    fprintf(stderr, "%s\n", s);
    error_found = 1;
}

int main() {
    printf("\n| %d | ", line_number);
    global_table = create_symbol_table(NULL);
    current_table = global_table;
    yyparse();
    if (error_found) {
        printf("\nCodigo sintaticamente incorreto.\n");
    } else {
        printf("\nCodigo sintaticamente correto.\n");
    }
    printf("\n");
    semantic_analysis(ast, current_table);
    // traverse_ast(ast, 0);
    print_table(current_table);
    return 0; 
}

void semantic_analysis(ASTNode *node, SymbolTable *table) {
 
 if (node == NULL) return;

  switch (node->type) {
    case AST_TYPE_VAR_DECL:
      if (lookup_symbol(current_table, node->data.var_decl.var_name)) {
        printf("Semantic Error: Variable '%s' already declared in this scope.\n", node->data.var_decl.var_name);
      }

      insert_symbol(current_table, node->data.var_decl.var_name, node->data.var_decl.var_type, NULL);

      if (node->data.var_decl.expr != NULL) {
        semantic_analysis(node->data.var_decl.expr, current_table);

        if (node->data.var_decl.var_type != node->data.var_decl.expr->data_type) {
          printf("Semantic Error: Type mismatch in variable '%s' initialization.\n", node->data.var_decl.var_name);
        }
      }
      break;
    case AST_TYPE_FUNC:
      if (lookup_symbol(current_table, node->data.func.func_name)) {
        printf("Semantic Error: Function '%s' already declared in this scope.\n", node->data.func.func_name);
      }
      insert_symbol(current_table, node->data.func.func_name, TYPE_FUNC, (void*)node->data.func.func);
      break;
    case AST_TYPE_FUNC_CALL:
      Symbol *func = lookup_symbol(current_table, node->data.func_call.func_name);
      if (func == NULL) {
        printf("Semantic Error: Function '%s' not declared in this scope.\n", node->data.func_call.func_name);
      } else if (func->type != TYPE_FUNC) {
        printf("Semantic Error: '%s' is not a function.\n", node->data.func_call.func_name);
      } else {
        Function *function = (Function*)func->value;
        Param *param = function->params;
        ASTNodeList *arg = node->data.func_call.args;
        while (param != NULL && arg != NULL) {
          semantic_analysis(arg->node, current_table);
          if (param->type != arg->node->data_type) {
            printf("Semantic Error: Type mismatch in function call.\n");
          }
          param = param->next;
          arg = arg->next;
        }
        if (param != NULL || arg != NULL) {
          printf("Semantic Error: Number of arguments mismatch in function call.\n");
        }
      }
      break;
    case AST_TYPE_BIN_AROP:
      semantic_analysis(node->data.bin_arop.left, current_table);
      semantic_analysis(node->data.bin_arop.right, current_table);
      if (node->data.bin_arop.left->data_type != node->data.bin_arop.right->data_type) {
        printf("Semantic Error: Type mismatch in binary arithmetic operation.\n");
      }
      node->data_type = node->data.bin_arop.left->data_type;
      break;
    case AST_TYPE_BIN_RELOP:
      semantic_analysis(node->data.bin_relop.left, current_table);
      semantic_analysis(node->data.bin_relop.right, current_table);
      if (node->data.bin_relop.left->data_type != node->data.bin_relop.right->data_type) {
        printf("Semantic Error: Type mismatch in binary relational operation.\n");
      }
      node->data_type = TYPE_BOOL;
      break;
    case AST_TYPE_BIN_LOGOP:
      semantic_analysis(node->data.bin_logop.left, current_table);
      semantic_analysis(node->data.bin_logop.right, current_table);
      if (node->data.bin_logop.left->data_type != node->data.bin_logop.right->data_type) {
        printf("Semantic Error: Type mismatch in binary logical operation.\n");
      }
      node->data_type = TYPE_BOOL;
      break;
    case AST_TYPE_UNOP_NOT:
      semantic_analysis(node->data.unnop.expr, current_table);
      if (node->data.unnop.expr->data_type != TYPE_BOOL) {
        printf("Semantic Error: Type mismatch in unary logical operation.\n");
      }
      break;
    case AST_TYPE_VAR:
      Symbol *var = lookup_symbol(current_table, node->data.var_name);
      if (var == NULL) {
        printf("Semantic Error: Variable '%s' not declared in this scope.\n", node->data.var_name);
      } else {
        node->data_type = var->type;
      }
      break;
    case AST_TYPE_INT:
      node->data_type = TYPE_INT;
      break;
    case AST_TYPE_FLOAT:
      node->data_type = TYPE_FLOAT;
      break;
    case AST_TYPE_BOOL:
      node->data_type = TYPE_BOOL;
      break;
    case AST_TYPE_CHAR:
      node->data_type = TYPE_CHAR;
      break;
    case AST_TYPE_STRING:
      node->data_type = TYPE_STRING;
      break;
    case AST_TYPE_NULL:
      node->data_type = TYPE_NULL;
      break;
    case AST_TYPE_BLOCK:
        printf("stmt\n");
      current_table = create_symbol_table(current_table);
      ASTNodeList *stmt = node->children;
      while (stmt != NULL) {
        semantic_analysis(stmt->node, current_table);
        stmt = stmt->next;
      }
      current_table = current_table->parent;
      break;
    case AST_TYPE_IF:
      semantic_analysis(node->data.if_node.condition, current_table);
      if (node->data.if_node.condition->data_type != TYPE_BOOL) {
        printf("Semantic Error: Type mismatch in if condition.\n");
      }
      semantic_analysis(node->data.if_node.body_branch, current_table);
      if (node->data.if_node.else_branch != NULL) {
        semantic_analysis(node->data.if_node.else_branch, current_table);
      }
      break;
    case AST_TYPE_SWITCH:
      semantic_analysis(node->data.switch_node.condition, current_table);
      ASTNodeList *case_stmt = node->data.switch_node.cases;
      while (case_stmt != NULL) {
        semantic_analysis(case_stmt->node, current_table);
        case_stmt = case_stmt->next;
      }
      break;
    case AST_TYPE_CASE:
      if (node->data.case_node.case_expr != NULL) {
        semantic_analysis(node->data.case_node.case_expr, current_table);
      }
      current_table = create_symbol_table(current_table);
      ASTNodeList *stmts = node->data.case_node.stmts;
      while (stmts != NULL) {
        semantic_analysis(stmts->node, current_table);
        stmts = stmts->next;
      }
      break;
    default:
      break;
  }

  ASTNodeList *child = node->children;
  while (child != NULL) {
      semantic_analysis(child->node, current_table);
      child = child->next;
  }
}
