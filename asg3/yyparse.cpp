/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

// $Id: parser.y,v 1.11 2017-10-11 14:27:30-07 - - $
// Dummy parser for scanner project.
//Joseph Castelan
//jgcastel@ucsc.edu

//Cesar Neri
//ceneri@ucsc.edu

#include <cassert>

#include "lyutils.h"
#include "astree.h"


#line 82 "yyparse.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_VOID = 258,
    TOK_CHAR = 259,
    TOK_INT = 260,
    TOK_STRING = 261,
    TOK_IF = 262,
    TOK_ELSE = 263,
    TOK_WHILE = 264,
    TOK_RETURN = 265,
    TOK_STRUCT = 266,
    TOK_NULL = 267,
    TOK_NEW = 268,
    TOK_ARRAY = 269,
    TOK_EQ = 270,
    TOK_NE = 271,
    TOK_LT = 272,
    TOK_LE = 273,
    TOK_GT = 274,
    TOK_GE = 275,
    TOK_IDENT = 276,
    TOK_INTCON = 277,
    TOK_CHARCON = 278,
    TOK_STRINGCON = 279,
    TOK_BLOCK = 280,
    TOK_CALL = 281,
    TOK_IFELSE = 282,
    TOK_INITDECL = 283,
    TOK_POS = 284,
    TOK_NEG = 285,
    TOK_NEWARRAY = 286,
    TOK_TYPEID = 287,
    TOK_FIELD = 288,
    TOK_ORD = 289,
    TOK_CHR = 290,
    TOK_ROOT = 291,
    TOK_DECLID = 292,
    TOK_PARAMLIST = 293,
    TOK_FUNCTION = 294,
    TOK_PROTOTYPE = 295,
    TOK_VARDECL = 296,
    TOK_RETURNVOID = 297,
    TOK_NEWSTRING = 298,
    TOK_INDEX = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 178 "yyparse.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   648

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,    59,     2,     2,
      45,    46,    57,    55,    52,    56,    53,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
       2,    54,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    57,    58,    59,    60,    61,    62,    65,
      70,    78,    80,    84,    88,    94,    95,    96,    97,    98,
     101,   106,   114,   120,   131,   135,   141,   146,   153,   158,
     164,   167,   169,   177,   178,   179,   180,   181,   182,   185,
     191,   198,   203,   212,   216,   222,   223,   224,   225,   226,
     229,   230,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   247,   251,   255,   256,   259,   265,
     271,   279,   283,   286,   289,   293,   294,   299,   303,   304,
     305,   306
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_CHAR", "TOK_INT",
  "TOK_STRING", "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_RETURN",
  "TOK_STRUCT", "TOK_NULL", "TOK_NEW", "TOK_ARRAY", "TOK_EQ", "TOK_NE",
  "TOK_LT", "TOK_LE", "TOK_GT", "TOK_GE", "TOK_IDENT", "TOK_INTCON",
  "TOK_CHARCON", "TOK_STRINGCON", "TOK_BLOCK", "TOK_CALL", "TOK_IFELSE",
  "TOK_INITDECL", "TOK_POS", "TOK_NEG", "TOK_NEWARRAY", "TOK_TYPEID",
  "TOK_FIELD", "TOK_ORD", "TOK_CHR", "TOK_ROOT", "TOK_DECLID",
  "TOK_PARAMLIST", "TOK_FUNCTION", "TOK_PROTOTYPE", "TOK_VARDECL",
  "TOK_RETURNVOID", "TOK_NEWSTRING", "TOK_INDEX", "'('", "')'", "'['",
  "']'", "'{'", "'}'", "';'", "','", "'.'", "'='", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "$accept", "start", "program", "structdef",
  "fielddecls", "fielddecl", "basetype", "function", "params", "identdecl",
  "block", "statements", "statement", "vardecl", "while", "ifelse",
  "return", "expr", "binop", "unop", "allocator", "call", "multiexpr",
  "variable", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    40,    41,    91,    93,   123,
     125,    59,    44,    46,    61,    43,    45,    42,    47,    37,
      33
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -20

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -82,    13,   106,   -82,   -47,   -82,   -82,   -82,   -82,   -37,
     -15,     3,    10,   -82,   293,     8,   -82,   -82,   -82,   345,
     164,   -82,   345,   345,   345,   -82,    -9,   -82,   -43,   -82,
     222,   -82,   -82,   -82,   -82,   -82,   355,   -82,   -82,   -82,
     -82,   -14,   -82,   -82,   -82,   -82,   345,   345,     5,   -82,
     400,    -2,    11,    46,    17,     2,   299,   414,   -82,     6,
     -82,    95,    95,     2,    19,   -82,    40,   345,   -13,   -82,
     -82,   345,   345,   345,   345,   345,   345,   345,   -82,    36,
     345,   345,   345,   345,   345,   345,   -82,   345,   459,   473,
     -82,    31,    93,   345,   339,   345,   -82,   183,   -82,   -82,
     -82,    43,   -82,   518,    54,   117,    78,    78,    78,    78,
      78,    78,   531,   -82,   183,    95,    95,     2,     2,     2,
     183,   280,   280,   -82,    22,     7,   -82,    23,   576,   -82,
     589,   -82,   -82,   -82,   -82,   -82,   -82,   -82,    75,   -82,
     -82,    66,   -82,   -82,   -82,   -82,   280,   -82,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    15,    18,    16,    17,     0,
       0,     0,     0,    81,     0,    75,    78,    79,    80,     0,
       0,    30,     0,     0,     0,     3,     0,     4,     0,    33,
       0,     5,    34,    35,    36,    37,     0,    45,    46,    47,
      48,     0,    50,    51,     6,     7,     0,     0,    75,    43,
       0,     0,    17,    75,     0,    67,     0,     0,    29,     0,
      32,    64,    65,    66,     0,    27,     0,     0,     0,    28,
      31,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    71,    74,    49,    26,
      19,     0,    25,     0,     0,     0,    53,    54,    55,    56,
      57,    58,     0,    77,    52,    59,    60,    61,    62,    63,
      73,     0,     0,    10,     0,     0,     9,     0,     0,    68,
       0,    23,    21,    39,    22,    20,    24,    76,    41,    40,
      12,     0,    14,    11,    69,    70,     0,    13,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,   -82,   -82,   -82,    16,    -7,   -82,   -82,    -1,
     -81,   -82,   -20,   -82,   -82,   -82,   -82,    -5,   -82,   -82,
     -82,   -82,   -82,   -82,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    25,    92,   124,    26,    27,    68,    59,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    28,    66,    44,    45,    64,    50,    54,    46,    55,
      70,    67,    65,     3,    57,    13,    14,    61,    62,    63,
     132,   141,   -19,   135,    48,    16,    17,    18,   142,   -19,
      47,    51,    86,   104,     5,     6,     7,     8,    87,   105,
      99,    88,    89,     5,     6,     7,     8,    91,    19,    77,
      56,    97,   100,    56,    49,    79,    93,   113,    22,    23,
      67,   100,   103,    24,    95,   102,   106,   107,   108,   109,
     110,   111,   112,   140,   143,   114,   115,   116,   117,   118,
     119,   123,   120,   146,   125,   125,   101,   147,   128,    97,
     130,    94,    20,   -19,   131,     0,     5,     6,     7,     8,
       0,   138,   139,    20,   136,   134,    -2,     4,   127,     5,
       6,     7,     8,     9,   100,    10,    11,    12,    13,    14,
       5,     6,     7,     8,     0,    77,   148,    15,    16,    17,
      18,    79,     0,    81,    82,    83,    84,    85,   100,     0,
       0,     0,    77,   126,     0,     0,     0,     0,    79,     0,
       0,    19,    83,    84,    85,    20,     0,    21,     0,     0,
       0,    22,    23,     0,     0,     0,    24,     5,     6,     7,
       8,     9,     0,    10,    11,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,    19,
       0,     0,     0,    20,    58,    21,     0,     0,     0,    22,
      23,     0,     0,     0,    24,     5,     6,     7,     8,     9,
      77,    10,    11,     0,    13,    14,    79,    80,    81,    82,
      83,    84,    85,    15,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,    20,    69,    21,     0,     0,     0,    22,    23,     0,
       0,     0,    24,     5,     6,     7,     8,     9,     0,    10,
      11,     0,    13,    14,     0,     0,     5,     6,     7,    52,
       0,    15,    16,    17,    18,    13,    14,     0,     0,     0,
       0,    13,    14,     0,    53,    16,    17,    18,     0,     0,
      48,    16,    17,    18,     0,    19,     0,     0,     0,    20,
       0,    21,     0,     0,     0,    22,    23,     0,    19,     0,
      24,     0,     0,     0,    19,    96,     0,     0,    22,    23,
       0,    13,    14,    24,    22,    23,     0,    13,    14,    24,
      48,    16,    17,    18,     0,     0,    48,    16,    17,    18,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,    19,   129,     0,     0,     0,     0,
      19,     0,     0,     0,    22,    23,     0,     0,     0,    24,
      22,    23,    77,     0,     0,    24,    78,     0,    79,    80,
      81,    82,    83,    84,    85,    71,    72,    73,    74,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    71,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,    90,     0,    79,    80,    81,    82,    83,    84,    85,
      98,    77,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    71,    72,    73,    74,    75,    76,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,    77,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,   122,
      77,     0,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    71,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,   133,
       0,    79,    80,    81,    82,    83,    84,    85,    77,   137,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    71,    72,    73,    74,    75,    76,     0,     0,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,    77,     0,     0,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    77,   145,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      20,     2,    45,    50,    51,    14,    11,    14,    45,    14,
      30,    54,    21,     0,    19,    12,    13,    22,    23,    24,
     101,    14,    14,   104,    21,    22,    23,    24,    21,    21,
      45,    21,    46,    46,     3,     4,     5,     6,    52,    52,
      21,    46,    47,     3,     4,     5,     6,    49,    45,    47,
      45,    56,    21,    45,    51,    53,    45,    21,    55,    56,
      54,    21,    67,    60,    47,    66,    71,    72,    73,    74,
      75,    76,    77,    51,    51,    80,    81,    82,    83,    84,
      85,    50,    87,     8,    91,    92,    46,    21,    93,    94,
      95,    45,    49,    47,    51,    -1,     3,     4,     5,     6,
      -1,   121,   122,    49,   105,    51,     0,     1,    92,     3,
       4,     5,     6,     7,    21,     9,    10,    11,    12,    13,
       3,     4,     5,     6,    -1,    47,   146,    21,    22,    23,
      24,    53,    -1,    55,    56,    57,    58,    59,    21,    -1,
      -1,    -1,    47,    50,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    45,    57,    58,    59,    49,    -1,    51,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    49,    50,    51,    -1,    -1,    -1,    55,
      56,    -1,    -1,    -1,    60,     3,     4,     5,     6,     7,
      47,     9,    10,    -1,    12,    13,    53,    54,    55,    56,
      57,    58,    59,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    49,    50,    51,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    60,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,    13,    -1,    -1,     3,     4,     5,     6,
      -1,    21,    22,    23,    24,    12,    13,    -1,    -1,    -1,
      -1,    12,    13,    -1,    21,    22,    23,    24,    -1,    -1,
      21,    22,    23,    24,    -1,    45,    -1,    -1,    -1,    49,
      -1,    51,    -1,    -1,    -1,    55,    56,    -1,    45,    -1,
      60,    -1,    -1,    -1,    45,    46,    -1,    -1,    55,    56,
      -1,    12,    13,    60,    55,    56,    -1,    12,    13,    60,
      21,    22,    23,    24,    -1,    -1,    21,    22,    23,    24,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,
      55,    56,    47,    -1,    -1,    60,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      46,    47,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    58,    59,    46,
      47,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    47,    48,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    47,    48,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    58,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    62,    63,     0,     1,     3,     4,     5,     6,     7,
       9,    10,    11,    12,    13,    21,    22,    23,    24,    45,
      49,    51,    55,    56,    60,    64,    67,    68,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    50,    51,    45,    45,    21,    51,
      78,    21,     6,    21,    67,    78,    45,    78,    50,    70,
      73,    78,    78,    78,    14,    21,    45,    54,    69,    50,
      73,    15,    16,    17,    18,    19,    20,    47,    51,    53,
      54,    55,    56,    57,    58,    59,    46,    52,    78,    78,
      51,    49,    65,    45,    45,    47,    46,    78,    46,    21,
      21,    46,    70,    78,    46,    52,    78,    78,    78,    78,
      78,    78,    78,    21,    78,    78,    78,    78,    78,    78,
      78,    46,    46,    50,    66,    67,    50,    66,    78,    46,
      78,    51,    71,    51,    51,    71,    70,    48,    73,    73,
      51,    14,    21,    51,    46,    48,     8,    21,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    69,    69,    70,    70,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    74,
      75,    76,    76,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    81,    81,
      81,    82,    82,    83,    83,    84,    84,    84,    85,    85,
      85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     4,
       4,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     3,     2,     3,     2,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     2,     4,
       5,     5,     7,     2,     3,     1,     1,     1,     1,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     4,     5,
       5,     3,     2,     3,     3,     1,     4,     3,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 54 "parser.y" /* yacc.c:1646  */
    { yyparse_astree = (yyvsp[0]); }
#line 1464 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[0])); }
#line 1470 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[0])); }
#line 1476 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt ((yyvsp[0])); }
#line 1482 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 60 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 1488 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 1494 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 62 "parser.y" /* yacc.c:1646  */
    { (yyval) = emptyTree(); }
#line 1500 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2]) = (yyvsp[-2]) ->change_sym((yyvsp[-2]), TOK_TYPEID);     
                  (yyval) = (yyvsp[-3]) -> adopt ((yyvsp[-2]), (yyvsp[-1])); 
                  destroy((yyvsp[0]));
                }
#line 1509 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 71 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2]) = (yyvsp[-2]) ->change_sym((yyvsp[-2]), TOK_TYPEID);
                  (yyval) = (yyvsp[-3]) -> adopt ((yyvsp[-2]));
                  destroy((yyvsp[0]));
                  destroy((yyvsp[-1]));
                }
#line 1519 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 78 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2])->adopt((yyvsp[-1])); 
                                            destroy((yyvsp[0]));}
#line 1526 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 80 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2])->adopt((yyvsp[-1])); 
                                            destroy((yyvsp[0]));}
#line 1533 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 85 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0]) = (yyvsp[0]) ->change_sym((yyvsp[0]), TOK_FIELD);     
                  (yyval) = (yyvsp[-1]) ->adopt ((yyvsp[-2]), (yyvsp[0])); 
                }
#line 1541 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 89 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0]) = (yyvsp[0]) ->change_sym((yyvsp[0]), TOK_FIELD);     
                  (yyval) = (yyvsp[-1]) ->adopt ((yyvsp[0])); 
                }
#line 1549 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1555 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 95 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1561 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 96 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1567 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 97 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1573 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]) ->change_sym((yyvsp[0]), TOK_TYPEID);}
#line 1579 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 102 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-1]));
                  (yyval) = new astree(TOK_FUNCTION, (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]), (yyvsp[-2]), (yyvsp[0]));
                }
#line 1588 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2]) = (yyvsp[-2]) ->change_sym((yyvsp[-2]), 
                        TOK_PARAMLIST);                   
                  (yyval) = new astree(TOK_FUNCTION, 
                        (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]), (yyvsp[-2]), (yyvsp[0]));
                  destroy((yyvsp[-1]));
                }
#line 1600 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 115 "parser.y" /* yacc.c:1646  */
    {destroy((yyvsp[-1]));
                  destroy((yyvsp[0]));
                  (yyval) = new astree(TOK_PROTOTYPE, (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]), (yyvsp[-2]));
                }
#line 1610 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2]) = (yyvsp[-2]) ->change_sym((yyvsp[-2]), 
                    TOK_PARAMLIST);                    
                  (yyval) = new astree(TOK_PROTOTYPE,
                    (yyvsp[-3])->lloc, "");
                  (yyval) = (yyval)->adopt((yyvsp[-3]), (yyvsp[-2]));
                  destroy((yyvsp[-1]));
                  destroy((yyvsp[0]));
                }
#line 1623 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2])->adopt((yyvsp[0])); 
                  destroy((yyvsp[-1]));
                }
#line 1631 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]) = (yyvsp[-1]) ->change_sym((yyvsp[-1]), TOK_PARAMLIST);
                  (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); 
                }
#line 1639 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0]) = (yyvsp[0]) ->change_sym((yyvsp[0]), 
                    TOK_DECLID);                    
                  (yyval) = (yyvsp[-1]) -> adopt((yyvsp[-2]), (yyvsp[0]));
                }
#line 1648 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0]) = (yyvsp[0]) ->change_sym((yyvsp[0]), 
                    TOK_DECLID);                    
                  (yyval) = (yyvsp[-1]) -> adopt((yyvsp[0]));
                }
#line 1657 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 154 "parser.y" /* yacc.c:1646  */
    {                   
                  (yyval) = (yyvsp[-1]);
                  destroy((yyvsp[0]));
                }
#line 1666 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]) = (yyvsp[-1]) ->change_sym((yyvsp[-1]), 
                    TOK_BLOCK);
                    (yyval) = (yyvsp[-1]);
                  destroy((yyvsp[0]));
                }
#line 1676 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 164 "parser.y" /* yacc.c:1646  */
    {destroy((yyvsp[0]));}
#line 1682 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 1688 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]) = (yyvsp[-1]) ->change_sym((yyvsp[-1]), 
                    TOK_BLOCK);  
                (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); 
                }
#line 1697 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1703 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1709 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1715 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1721 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1727 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); destroy((yyvsp[0]));}
#line 1733 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2]) = (yyvsp[-2]) ->change_sym((yyvsp[-2]), TOK_VARDECL);        
                  (yyval) = (yyvsp[-2]) ->adopt((yyvsp[-3]), (yyvsp[-1]));
                }
#line 1741 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-4]) ->adopt((yyvsp[-2]), (yyvsp[0]));
                  destroy((yyvsp[-3]));
                  destroy((yyvsp[-1]));
                }
#line 1750 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-4]) ->adopt((yyvsp[-2]), (yyvsp[0]));
                destroy((yyvsp[-3]));
                destroy((yyvsp[-1]));
                }
#line 1759 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-6]) = (yyvsp[-6]) ->change_sym((yyvsp[-6]), 
                    TOK_IFELSE);                  
                  (yyval) = (yyvsp[-6]) ->adopt((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
                  destroy((yyvsp[-5]));
                  destroy((yyvsp[-3]));
                }
#line 1770 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->change_sym((yyvsp[-1]), TOK_RETURNVOID);
                  destroy((yyvsp[0]));
                }
#line 1778 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]) ->adopt((yyvsp[-1]));
                destroy((yyvsp[0]));
                }
#line 1786 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1792 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1798 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1804 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1810 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); 
                                          destroy((yyvsp[-2]));
                                          destroy((yyvsp[0]));}
#line 1818 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1824 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1830 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1836 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1842 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1848 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1854 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1860 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 238 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1866 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1872 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1878 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 241 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1884 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 242 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1890 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1896 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1902 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]) = (yyvsp[-1]) ->change_sym((yyvsp[-1]), 
                                            TOK_POS); 
                                          (yyval) = (yyvsp[-1]) ->adopt((yyvsp[0])); 
                                        }
#line 1911 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 251 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]) = (yyvsp[-1]) ->change_sym((yyvsp[-1]), 
                                            TOK_NEG); 
                                          (yyval) = (yyvsp[-1]) ->adopt((yyvsp[0])); 
                                        }
#line 1920 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[0])); }
#line 1926 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]) ->adopt((yyvsp[0])); }
#line 1932 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2]) = (yyvsp[-2]) ->change_sym((yyvsp[-2]), TOK_TYPEID);
                  (yyval) = (yyvsp[-3]) ->adopt((yyvsp[-2]));
                  destroy((yyvsp[-1]));
                  destroy((yyvsp[0]));
                }
#line 1942 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-4]) = (yyvsp[-3]) ->change_sym((yyvsp[-4]), TOK_NEWSTRING);
                  (yyval) = (yyvsp[-4]) ->adopt((yyvsp[-1]));
                  destroy((yyvsp[-2]));
                  destroy((yyvsp[0]));
                }
#line 1952 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 272 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-4]) = (yyvsp[-4]) ->change_sym((yyvsp[-4]), TOK_NEWARRAY);
                  (yyval) = (yyvsp[-4]) ->adopt((yyvsp[-3]), (yyvsp[-1]));
                  destroy((yyvsp[-2]));
                  destroy((yyvsp[0]));
                }
#line 1962 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]) ->change_sym((yyvsp[-1]), TOK_CALL);
                                       destroy( (yyvsp[0]) );
                                       (yyval)=(yyvsp[-1])->adopt((yyvsp[-2]));
                                     }
#line 1971 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]); destroy((yyvsp[0]));}
#line 1977 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 286 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-1]));
                                      (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));
                                    }
#line 1985 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]) ->change_sym((yyvsp[-1]), TOK_CALL); 
                                      (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]),(yyvsp[0])); }
#line 1992 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 293 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1998 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 294 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2]) = (yyvsp[-2]) ->change_sym((yyvsp[-2]), 
                                        TOK_INDEX);
                                      destroy((yyvsp[0]));
                                      (yyval) = (yyvsp[-2])->adopt((yyvsp[-3]), (yyvsp[-1]));
                                    }
#line 2008 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0]) = (yyvsp[0])->change_sym((yyvsp[0]),TOK_FIELD);
                                      (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]), (yyvsp[0]));}
#line 2015 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 303 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2021 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 304 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2027 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2033 "yyparse.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 2039 "yyparse.cpp" /* yacc.c:1646  */
    break;


#line 2043 "yyparse.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 310 "parser.y" /* yacc.c:1906  */


const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

/*
static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != nullptr);
   return result;
}
*/
