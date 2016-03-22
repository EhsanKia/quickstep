/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         quickstep_yyparse
#define yylex           quickstep_yylex
#define yyerror         quickstep_yyerror
#define yydebug         quickstep_yydebug
#define yynerrs         quickstep_yynerrs


/* Copy the first part of user declarations.  */
#line 33 "../SqlParser.ypp" /* yacc.c:339  */


/* Override the default definition, as we only need <first_line> and <first_column>. */
typedef struct YYLTYPE {
  int first_line;
  int first_column;
} YYLTYPE;

#define YYLTYPE_IS_DECLARED 1

/*
 * Modified from the default YYLLOC_DEFAULT
 * (http://www.gnu.org/software/bison/manual/html_node/Location-Default-Action.html).
 * The assignments for last_line and last_column are removed as they are not used.
 */
#define YYLLOC_DEFAULT(current, rhs, n)                         \
  do {                                                          \
    if (n) {                                                    \
      (current).first_line   = YYRHSLOC(rhs, 1).first_line;     \
      (current).first_column = YYRHSLOC(rhs, 1).first_column;   \
    } else {                                                    \
      /* empty RHS */                                           \
      (current).first_line = YYRHSLOC(rhs, 0).first_line;       \
      (current).first_column = YYRHSLOC(rhs, 0).first_column;   \
    }                                                           \
  } while (0)

#line 62 "../SqlParser.ypp" /* yacc.c:339  */

#include <cstdlib>
#include <string>
#include <utility>

#include "parser/ParseAssignment.hpp"
#include "parser/ParseAttributeDefinition.hpp"
#include "parser/ParseBasicExpressions.hpp"
#include "parser/ParseBlockProperties.hpp"
#include "parser/ParseExpression.hpp"
#include "parser/ParseGeneratorTableReference.hpp"
#include "parser/ParseGroupBy.hpp"
#include "parser/ParseHaving.hpp"
#include "parser/ParseKeyValue.hpp"
#include "parser/ParseLimit.hpp"
#include "parser/ParseWindow.hpp"
#include "parser/ParseLiteralValue.hpp"
#include "parser/ParseOrderBy.hpp"
#include "parser/ParsePredicate.hpp"
#include "parser/ParserUtil.hpp"
#include "parser/ParseSample.hpp"
#include "parser/ParseSelect.hpp"
#include "parser/ParseSelectionClause.hpp"
#include "parser/ParseSimpleTableReference.hpp"
#include "parser/ParseStatement.hpp"
#include "parser/ParseString.hpp"
#include "parser/ParseSubqueryExpression.hpp"
#include "parser/ParseSubqueryTableReference.hpp"
#include "parser/ParseTableReference.hpp"
#include "storage/StorageBlockInfo.hpp"
#include "types/Type.hpp"
#include "types/TypeFactory.hpp"
#include "types/TypeID.hpp"
#include "types/operations/binary_operations/BinaryOperation.hpp"
#include "types/operations/binary_operations/BinaryOperationFactory.hpp"
#include "types/operations/binary_operations/BinaryOperationID.hpp"
#include "types/operations/comparisons/Comparison.hpp"
#include "types/operations/comparisons/ComparisonFactory.hpp"
#include "types/operations/comparisons/ComparisonID.hpp"
#include "types/operations/unary_operations/UnaryOperation.hpp"
#include "types/operations/unary_operations/UnaryOperationFactory.hpp"
#include "types/operations/unary_operations/UnaryOperationID.hpp"
#include "utility/PtrList.hpp"
#include "utility/PtrVector.hpp"

// Needed for Bison 2.6 and higher, which do not automatically provide this typedef.
typedef void* yyscan_t;

#line 149 "SqlParser_gen.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "SqlParser_gen.hpp".  */
#ifndef YY_QUICKSTEP_YY_SQLPARSER_GEN_HPP_INCLUDED
# define YY_QUICKSTEP_YY_SQLPARSER_GEN_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int quickstep_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_COMMAND = 258,
    TOKEN_NAME = 259,
    TOKEN_STRING_SINGLE_QUOTED = 260,
    TOKEN_STRING_DOUBLE_QUOTED = 261,
    TOKEN_UNSIGNED_NUMVAL = 262,
    TOKEN_OR = 263,
    TOKEN_AND = 264,
    TOKEN_NOT = 265,
    TOKEN_EQ = 266,
    TOKEN_LT = 267,
    TOKEN_LEQ = 268,
    TOKEN_GT = 269,
    TOKEN_GEQ = 270,
    TOKEN_NEQ = 271,
    TOKEN_LIKE = 272,
    TOKEN_REGEXP = 273,
    TOKEN_BETWEEN = 274,
    TOKEN_IS = 275,
    UNARY_PLUS = 276,
    UNARY_MINUS = 277,
    TOKEN_ADD = 278,
    TOKEN_AGE = 279,
    TOKEN_ALL = 280,
    TOKEN_ALTER = 281,
    TOKEN_AS = 282,
    TOKEN_ASC = 283,
    TOKEN_BIGINT = 284,
    TOKEN_BIT = 285,
    TOKEN_BLOCKPROPERTIES = 286,
    TOKEN_BLOCKSAMPLE = 287,
    TOKEN_BLOOM_FILTER = 288,
    TOKEN_CSB_TREE = 289,
    TOKEN_BY = 290,
    TOKEN_CHARACTER = 291,
    TOKEN_CHECK = 292,
    TOKEN_COLUMN = 293,
    TOKEN_CONSTRAINT = 294,
    TOKEN_COPY = 295,
    TOKEN_CREATE = 296,
    TOKEN_DATE = 297,
    TOKEN_DATETIME = 298,
    TOKEN_DECIMAL = 299,
    TOKEN_DEFAULT = 300,
    TOKEN_DELETE = 301,
    TOKEN_DELIMITER = 302,
    TOKEN_DESC = 303,
    TOKEN_DISTINCT = 304,
    TOKEN_DOUBLE = 305,
    TOKEN_DROP = 306,
    TOKEN_ESCAPE_STRINGS = 307,
    TOKEN_EMIT = 308,
    TOKEN_FALSE = 309,
    TOKEN_FIRST = 310,
    TOKEN_FLOAT = 311,
    TOKEN_FOREIGN = 312,
    TOKEN_FROM = 313,
    TOKEN_FULL = 314,
    TOKEN_GROUP = 315,
    TOKEN_HAVING = 316,
    TOKEN_INDEX = 317,
    TOKEN_INNER = 318,
    TOKEN_INSERT = 319,
    TOKEN_INTEGER = 320,
    TOKEN_INTERVAL = 321,
    TOKEN_INTO = 322,
    TOKEN_JOIN = 323,
    TOKEN_KEY = 324,
    TOKEN_LAST = 325,
    TOKEN_LEFT = 326,
    TOKEN_LIMIT = 327,
    TOKEN_LONG = 328,
    TOKEN_NULL = 329,
    TOKEN_NULLS = 330,
    TOKEN_OFF = 331,
    TOKEN_ON = 332,
    TOKEN_ORDER = 333,
    TOKEN_OUTER = 334,
    TOKEN_PERCENT = 335,
    TOKEN_PRIMARY = 336,
    TOKEN_PARTITION = 337,
    TOKEN_QUIT = 338,
    TOKEN_REAL = 339,
    TOKEN_REFERENCES = 340,
    TOKEN_RIGHT = 341,
    TOKEN_ROW_DELIMITER = 342,
    TOKEN_SELECT = 343,
    TOKEN_SET = 344,
    TOKEN_SMALLINT = 345,
    TOKEN_TABLE = 346,
    TOKEN_TIME = 347,
    TOKEN_TIMESTAMP = 348,
    TOKEN_TRUE = 349,
    TOKEN_TUPLESAMPLE = 350,
    TOKEN_UNIQUE = 351,
    TOKEN_UPDATE = 352,
    TOKEN_USING = 353,
    TOKEN_VALUES = 354,
    TOKEN_VARCHAR = 355,
    TOKEN_WHERE = 356,
    TOKEN_WITH = 357,
    TOKEN_WINDOW = 358,
    TOKEN_YEARMONTH = 359,
    TOKEN_EOF = 360,
    TOKEN_LEX_ERROR = 361
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 111 "../SqlParser.ypp" /* yacc.c:355  */

  quickstep::ParseString *string_value_;

  quickstep::PtrList<quickstep::ParseString> *string_list_;

  bool boolean_value_;

  quickstep::NumericParseLiteralValue *numeric_literal_value_;
  quickstep::ParseLiteralValue *literal_value_;
  quickstep::PtrList<quickstep::ParseScalarLiteral> *literal_value_list_;

  quickstep::ParseExpression *expression_;

  quickstep::ParseScalarLiteral *scalar_literal_;
  quickstep::ParseAttribute *attribute_;

  quickstep::ParsePredicate *predicate_;

  quickstep::ParseSubqueryExpression *subquery_expression_;

  quickstep::ParseSelectionClause *selection_;
  quickstep::ParseSelectionItem *selection_item_;
  quickstep::ParseSelectionList *selection_list_;

  quickstep::ParseTableReference *table_reference_;
  quickstep::PtrList<quickstep::ParseTableReference> *table_reference_list_;
  quickstep::ParseTableReferenceSignature *table_reference_signature_;

  quickstep::ParseDataType *data_type_;
  quickstep::ParseAttributeDefinition *attribute_definition_;
  quickstep::ParseColumnConstraint *column_constraint_;
  quickstep::PtrList<quickstep::ParseColumnConstraint> *column_constraint_list_;
  quickstep::PtrList<quickstep::ParseAttributeDefinition> *attribute_definition_list_;

  quickstep::ParseKeyValue *key_value_;
  quickstep::PtrList<quickstep::ParseKeyValue> *key_value_list_;
  quickstep::ParseKeyStringValue *key_string_value_;
  quickstep::ParseKeyStringList *key_string_list_;
  quickstep::ParseKeyIntegerValue *key_integer_value_;

  quickstep::ParseCopyFromParams *copy_from_params_;

  quickstep::ParseAssignment *assignment_;
  quickstep::PtrList<quickstep::ParseAssignment> *assignment_list_;

  quickstep::ParseCommand *command_;
  quickstep::PtrVector<quickstep::ParseString> *command_argument_list_;

  quickstep::ParseStatement *statement_;
  quickstep::ParseStatementSelect *select_statement_;
  quickstep::ParseStatementUpdate *update_statement_;
  quickstep::ParseStatementInsert *insert_statement_;
  quickstep::ParseStatementDelete *delete_statement_;
  quickstep::ParseStatementCopyFrom *copy_from_statement_;
  quickstep::ParseStatementCreateTable *create_table_statement_;
  quickstep::ParseBlockProperties *block_properties_;
  quickstep::ParseStatementDropTable *drop_table_statement_;
  quickstep::ParseStatementQuit *quit_statement_;

  const quickstep::Comparison *comparison_;
  const quickstep::UnaryOperation *unary_operation_;
  const quickstep::BinaryOperation *binary_operation_;

  quickstep::ParseFunctionCall *function_call_;
  quickstep::PtrList<quickstep::ParseExpression> *expression_list_;
  quickstep::PtrList<quickstep::ParseExpression> *window_partition_by_list_;

  quickstep::ParseSelect *select_query_;
  quickstep::ParseGroupBy *opt_group_by_clause_;
  quickstep::ParseHaving *opt_having_clause_;
  quickstep::ParseOrderBy *opt_order_by_clause_;
  bool *order_direction_;
  quickstep::ParseLimit *opt_limit_clause_;
  quickstep::ParseSample *opt_sample_clause_;
 
  quickstep::ParseWindow *opt_window_clause_;


  quickstep::PtrList<quickstep::ParseOrderByItem> *order_commalist_;
  quickstep::ParseOrderByItem *order_item_;

  quickstep::PtrVector<quickstep::ParseSubqueryTableReference> *with_list_;
  quickstep::ParseSubqueryTableReference *with_list_element_;

#line 381 "SqlParser_gen.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int quickstep_yyparse (yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement);

#endif /* !YY_QUICKSTEP_YY_SQLPARSER_GEN_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 196 "../SqlParser.ypp" /* yacc.c:358  */

/* This header needs YYSTYPE, which is defined by the %union directive above */
#include "SqlLexer_gen.hpp"
void NotSupported(const YYLTYPE *location, yyscan_t yyscanner, const std::string &feature);

#line 414 "SqlParser_gen.cpp" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   903

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  117
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  233
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  446

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   361

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     113,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     114,   115,    23,    21,   116,    22,    27,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   112,
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
      15,    16,    17,    18,    19,    20,    25,    26,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   542,   542,   546,   550,   554,   558,   561,   568,   571,
     574,   577,   580,   583,   586,   589,   592,   595,   601,   607,
     614,   620,   627,   636,   641,   646,   651,   656,   660,   666,
     671,   674,   677,   682,   685,   688,   691,   694,   697,   700,
     703,   706,   709,   721,   724,   727,   745,   765,   768,   771,
     776,   781,   787,   793,   802,   806,   812,   815,   820,   825,
     830,   837,   844,   848,   854,   857,   862,   865,   873,   876,
     881,   885,   891,   894,   897,   902,   905,   912,   917,   928,
     932,   938,   941,   947,   955,   960,   965,   968,   973,   977,
     981,   985,   991,   996,  1001,  1005,  1011,  1017,  1022,  1025,
    1030,  1034,  1040,  1046,  1052,  1055,  1059,  1065,  1068,  1073,
    1077,  1083,  1086,  1089,  1094,  1099,  1102,  1108,  1112,  1118,
    1124,  1130,  1136,  1142,  1148,  1154,  1160,  1168,  1173,  1176,
    1179,  1184,  1188,  1192,  1195,  1199,  1204,  1207,  1212,  1215,
    1220,  1224,  1230,  1233,  1238,  1241,  1246,  1249,  1254,  1257,
    1276,  1279,  1284,  1289,  1294,  1297,  1302,  1307,  1312,  1316,
    1322,  1329,  1332,  1335,  1340,  1343,  1346,  1352,  1355,  1360,
    1365,  1374,  1379,  1388,  1393,  1396,  1401,  1404,  1409,  1415,
    1421,  1424,  1430,  1433,  1438,  1441,  1446,  1449,  1454,  1457,
    1460,  1463,  1468,  1472,  1476,  1481,  1485,  1491,  1494,  1497,
    1500,  1512,  1516,  1535,  1550,  1554,  1560,  1563,  1569,  1572,
    1575,  1578,  1581,  1584,  1587,  1590,  1593,  1596,  1601,  1612,
    1615,  1620,  1623,  1629,  1633,  1639,  1642,  1650,  1653,  1656,
    1659,  1665,  1670,  1675
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_COMMAND", "TOKEN_NAME",
  "TOKEN_STRING_SINGLE_QUOTED", "TOKEN_STRING_DOUBLE_QUOTED",
  "TOKEN_UNSIGNED_NUMVAL", "TOKEN_OR", "TOKEN_AND", "TOKEN_NOT",
  "TOKEN_EQ", "TOKEN_LT", "TOKEN_LEQ", "TOKEN_GT", "TOKEN_GEQ",
  "TOKEN_NEQ", "TOKEN_LIKE", "TOKEN_REGEXP", "TOKEN_BETWEEN", "TOKEN_IS",
  "'+'", "'-'", "'*'", "'/'", "UNARY_PLUS", "UNARY_MINUS", "'.'",
  "TOKEN_ADD", "TOKEN_AGE", "TOKEN_ALL", "TOKEN_ALTER", "TOKEN_AS",
  "TOKEN_ASC", "TOKEN_BIGINT", "TOKEN_BIT", "TOKEN_BLOCKPROPERTIES",
  "TOKEN_BLOCKSAMPLE", "TOKEN_BLOOM_FILTER", "TOKEN_CSB_TREE", "TOKEN_BY",
  "TOKEN_CHARACTER", "TOKEN_CHECK", "TOKEN_COLUMN", "TOKEN_CONSTRAINT",
  "TOKEN_COPY", "TOKEN_CREATE", "TOKEN_DATE", "TOKEN_DATETIME",
  "TOKEN_DECIMAL", "TOKEN_DEFAULT", "TOKEN_DELETE", "TOKEN_DELIMITER",
  "TOKEN_DESC", "TOKEN_DISTINCT", "TOKEN_DOUBLE", "TOKEN_DROP",
  "TOKEN_ESCAPE_STRINGS", "TOKEN_EMIT", "TOKEN_FALSE", "TOKEN_FIRST",
  "TOKEN_FLOAT", "TOKEN_FOREIGN", "TOKEN_FROM", "TOKEN_FULL",
  "TOKEN_GROUP", "TOKEN_HAVING", "TOKEN_INDEX", "TOKEN_INNER",
  "TOKEN_INSERT", "TOKEN_INTEGER", "TOKEN_INTERVAL", "TOKEN_INTO",
  "TOKEN_JOIN", "TOKEN_KEY", "TOKEN_LAST", "TOKEN_LEFT", "TOKEN_LIMIT",
  "TOKEN_LONG", "TOKEN_NULL", "TOKEN_NULLS", "TOKEN_OFF", "TOKEN_ON",
  "TOKEN_ORDER", "TOKEN_OUTER", "TOKEN_PERCENT", "TOKEN_PRIMARY",
  "TOKEN_PARTITION", "TOKEN_QUIT", "TOKEN_REAL", "TOKEN_REFERENCES",
  "TOKEN_RIGHT", "TOKEN_ROW_DELIMITER", "TOKEN_SELECT", "TOKEN_SET",
  "TOKEN_SMALLINT", "TOKEN_TABLE", "TOKEN_TIME", "TOKEN_TIMESTAMP",
  "TOKEN_TRUE", "TOKEN_TUPLESAMPLE", "TOKEN_UNIQUE", "TOKEN_UPDATE",
  "TOKEN_USING", "TOKEN_VALUES", "TOKEN_VARCHAR", "TOKEN_WHERE",
  "TOKEN_WITH", "TOKEN_WINDOW", "TOKEN_YEARMONTH", "TOKEN_EOF",
  "TOKEN_LEX_ERROR", "';'", "'\\n'", "'('", "')'", "','", "$accept",
  "start", "sql_statement", "quit_statement", "alter_table_statement",
  "create_table_statement", "create_index_statement",
  "drop_table_statement", "column_def", "column_def_commalist",
  "data_type", "column_constraint_def", "column_constraint_def_list",
  "opt_column_constraint_def_list", "table_constraint_def",
  "table_constraint_def_commalist", "opt_table_constraint_def_commalist",
  "opt_column_list", "opt_block_properties", "key_value_list", "key_value",
  "key_string_value", "key_string_list", "key_integer_value", "index_type",
  "opt_index_properties", "insert_statement", "copy_from_statement",
  "opt_copy_from_params", "copy_from_params", "update_statement",
  "delete_statement", "assignment_list", "assignment_item",
  "select_statement", "opt_with_clause", "with_list", "with_list_element",
  "select_query", "opt_all_distinct", "selection",
  "selection_item_commalist", "selection_item", "from_clause",
  "opt_join_chain", "join_chain", "join", "subquery_expression",
  "opt_sample_clause", "table_reference", "table_reference_signature",
  "table_reference_signature_primary", "table_reference_commalist",
  "opt_group_by_clause", "opt_having_clause", "opt_order_by_clause",
  "opt_limit_clause", "opt_window_clause", "window_duration",
  "window_attribute", "opt_window_partition", "emit_duration",
  "age_duration", "order_commalist", "order_item", "opt_order_direction",
  "opt_nulls_first", "opt_where_clause", "where_clause", "or_expression",
  "and_expression", "not_expression", "predicate_expression_base",
  "add_expression", "multiply_expression", "unary_expression",
  "expression_base", "function_call", "expression_list", "literal_value",
  "literal_value_commalist", "attribute_ref", "comparison_operation",
  "unary_operation", "add_operation", "multiply_operation",
  "name_commalist", "any_name", "boolean_value", "command",
  "command_argument_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    43,    45,    42,    47,   276,   277,    46,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,    59,    10,    40,    41,    44
};
# endif

#define YYPACT_NINF -326

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-326)))

#define YYTABLE_NINF -99

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,  -326,  -326,   -61,   187,    -6,   -20,   -45,   -17,  -326,
     187,   187,  -326,    68,    94,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,   -22,    76,    79,   187,  -326,
    -326,    28,   187,   187,   187,   187,   187,     1,    -9,  -326,
      96,    38,  -326,  -326,  -326,     8,  -326,  -326,  -326,  -326,
      66,   151,    93,    95,    84,  -326,    23,   187,   187,   101,
     187,  -326,  -326,   441,   141,   152,   116,   187,   187,   519,
    -326,  -326,   112,   187,    53,  -326,   200,  -326,   -22,  -326,
      98,  -326,  -326,  -326,   221,   232,  -326,  -326,  -326,   136,
    -326,   185,  -326,  -326,  -326,  -326,   253,  -326,  -326,  -326,
    -326,  -326,  -326,   150,   196,   571,   269,   217,   168,  -326,
     160,   194,  -326,  -326,  -326,  -326,  -326,   640,   -12,   187,
      15,   187,   187,   172,  -326,   174,  -326,   104,   794,   692,
     519,   295,   297,  -326,  -326,   863,   287,   761,   106,   187,
    -326,   571,   193,  -326,   187,  -326,  -326,   302,  -326,  -326,
     303,  -326,    -2,  -326,    12,    84,   571,  -326,  -326,   187,
     571,  -326,  -326,  -326,   571,   232,  -326,   187,   389,  -326,
     197,   246,   247,   209,  -326,  -326,  -326,    -5,   187,   223,
      15,   187,  -326,   126,  -326,     4,   283,   519,   519,   184,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,   571,   571,
       0,  -326,   115,   220,  -326,   211,  -326,  -326,   213,   215,
    -326,    99,  -326,    81,    99,   -15,   266,  -326,  -326,   194,
    -326,  -326,   218,  -326,   211,   119,   519,   222,   224,   187,
     327,   -23,   121,   127,   206,  -326,   225,   235,  -326,   264,
     230,   761,  -326,   274,   187,  -326,  -326,   126,  -326,  -326,
     297,  -326,  -326,  -326,   571,   158,   211,   271,  -326,  -326,
     761,   238,  -326,  -326,   187,  -326,  -326,    27,   280,   187,
      69,    87,    12,  -326,    97,  -326,  -326,   347,   348,    99,
     316,   291,  -326,  -326,   571,    17,   187,   187,   131,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,    57,  -326,  -326,  -326,
     248,    15,   324,  -326,  -326,   519,  -326,  -326,   249,  -326,
     178,   571,  -326,  -326,   761,  -326,   187,   288,   187,   -56,
     187,   292,   187,   293,  -326,  -326,   279,   284,  -326,   571,
     519,   289,   211,  -326,   133,   137,  -326,   365,   -23,   187,
    -326,  -326,   257,    26,   187,   571,   211,   147,   -49,   187,
     -43,   519,   -42,   187,   -41,   187,  -326,  -326,   258,   295,
     333,   298,   300,  -326,  -326,  -326,   155,  -326,  -326,  -326,
    -326,     7,   187,  -326,   268,   211,  -326,   519,   -36,   519,
     295,   519,   -33,   519,   -32,   571,   372,   273,   187,  -326,
     187,  -326,  -326,   187,  -326,   157,  -326,   295,   519,   295,
     295,   519,   295,   519,   272,  -326,   125,  -326,   761,  -326,
     305,   277,  -326,   162,  -326,   295,   295,   295,   571,  -326,
    -326,   312,  -326,   187,   310,   187,  -326,  -326,    18,  -326,
    -326,   358,   359,   342,   175,  -326,  -326,   571,   761,   373,
    -326,   258,  -326,   761,  -326,  -326
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,   233,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     7,     0,     0,    15,     8,    10,    11,    13,
      14,     9,    17,    12,    16,     0,     0,   231,     0,   225,
     226,     0,     0,     0,     0,     0,     0,     0,    99,   100,
       0,   138,     1,     3,     2,   104,    97,     5,     4,   232,
       0,     0,     0,     0,   167,    25,     0,     0,     0,     0,
       0,   105,   106,     0,     0,     0,    86,     0,     0,     0,
      93,   168,     0,     0,   167,    95,     0,   101,     0,   102,
       0,   223,   201,   198,     0,   218,   107,    40,    29,     0,
      30,    31,    34,    36,    37,    39,     0,    41,   197,    35,
      38,    32,    33,     0,     0,     0,     0,     0,   108,   109,
     113,   183,   185,   187,   190,   189,   188,     0,   206,     0,
       0,     0,     0,     0,    85,    66,    27,     0,     0,     0,
       0,   169,   171,   173,   175,     0,   188,     0,     0,     0,
      92,     0,     0,   139,     0,   199,   200,     0,    43,   202,
       0,    44,     0,   203,     0,   167,     0,   219,   220,     0,
       0,   112,   221,   222,     0,     0,   186,     0,     0,    19,
       0,     0,     0,     0,    20,    21,    22,     0,     0,     0,
      64,     0,    42,    56,   174,     0,     0,     0,     0,     0,
     208,   210,   211,   212,   213,   209,   214,   216,     0,     0,
       0,   204,     0,     0,    94,    96,   127,   224,     0,     0,
     191,     0,   140,   115,   135,   128,   142,   110,   111,   182,
     184,   207,     0,   192,   195,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    65,    68,    28,     0,
       0,     0,    47,     0,     0,    49,    55,    57,    26,   181,
     170,   172,   215,   217,     0,     0,   180,     0,   179,    84,
       0,     0,    45,    46,     0,   131,   136,     0,     0,     0,
       0,     0,     0,   114,   116,   118,   134,     0,     0,   133,
       0,   144,   193,   194,     0,     0,     0,     0,     0,    88,
     229,   230,   228,   227,    89,    87,     0,    67,    79,    80,
      81,     0,     0,    23,    48,     0,    51,    50,     0,    54,
       0,     0,   178,   205,     0,   137,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   117,     0,     0,   132,     0,
       0,   146,   196,    61,     0,     0,    58,     0,     0,     0,
      24,    62,     0,     0,     0,     0,   176,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   143,   145,
       0,   148,     0,    59,    90,    91,     0,    70,    72,    73,
      74,     0,     0,    52,     0,   177,    83,     0,     0,     0,
     120,     0,     0,     0,     0,     0,     0,   150,     0,    82,
       0,    78,    76,     0,    75,     0,    53,   126,     0,   119,
     122,     0,   124,     0,   147,   158,   161,   149,     0,   103,
       0,     0,    71,     0,    69,   125,   121,   123,     0,   162,
     163,   164,   152,     0,   154,     0,    77,   159,     0,   160,
     153,   206,     0,     0,     0,   165,   166,     0,     0,     0,
      60,   155,   156,     0,   151,   157
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,   -92,  -326,
     275,   154,  -326,  -326,  -171,  -326,  -326,  -326,  -326,    32,
      16,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,   278,  -326,  -326,  -326,   349,   330,  -326,
    -326,  -326,   260,  -326,  -326,  -326,   140,   346,  -326,   146,
    -191,   -10,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,     2,  -326,  -326,   -57,  -326,  -122,
     239,   234,   296,   -60,   267,   265,   311,  -152,  -325,  -116,
     117,   -64,  -326,  -326,  -326,  -326,    60,    -4,   102,  -326,
    -326
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,    19,   126,   127,
     106,   246,   247,   248,   174,   236,   237,   179,   303,   366,
     367,   368,   369,   370,   300,   340,    20,    21,   124,   232,
      22,    23,    74,    75,    24,    25,    38,    39,    46,    63,
     107,   108,   109,   155,   273,   274,   275,   211,   279,   212,
     265,   266,   213,   281,   331,   361,   387,   409,   410,   424,
     433,   439,   444,   404,   405,   421,   429,    70,    71,   131,
     132,   133,   134,   135,   111,   112,   113,   114,   225,   115,
     202,   116,   199,   117,   160,   164,    80,   118,   294,    26,
      27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    40,   214,   110,   358,   136,    37,    41,   185,   235,
     257,    29,   187,    30,   391,   167,    29,   140,    30,   157,
     158,   201,   277,   276,    50,   187,   351,   169,    52,    53,
      54,    55,    56,   377,   187,    28,   290,   392,    61,   379,
     381,   383,     1,    34,     2,   152,   398,   230,    40,   401,
     403,    35,   231,    76,    41,    36,    81,   170,   291,   292,
     144,    32,    62,   125,   128,   136,   136,   144,    42,    81,
     186,    45,     3,   144,   144,   144,   293,   171,   435,   258,
     144,   205,    49,   144,   144,   278,     4,     5,   328,   238,
      33,    51,     6,   436,    64,    57,   110,     7,   216,   168,
     316,   172,   168,    29,   285,    30,   161,    58,   224,   337,
       8,   317,   441,   210,   338,   128,   173,   175,   176,   249,
     214,   393,    65,   136,   136,   306,    78,    72,    59,     9,
     341,   264,   333,   138,   -98,    76,   239,    73,   255,   256,
     207,   373,   320,    10,   313,   267,   157,   158,    11,   268,
     215,    12,    60,   321,   269,   218,    66,   270,   419,    69,
     322,   267,   136,   221,    29,   268,    30,   311,   240,   139,
     269,   323,   271,   270,    81,    67,   241,   128,   420,   157,
     158,   157,   158,   343,   119,   120,    47,   345,   271,    48,
      69,    29,   159,    30,   310,   121,   122,   272,   201,   157,
     158,   252,   253,   254,    43,   242,    44,    41,   359,    68,
      41,   141,   243,   143,   144,    78,   244,   162,   163,   180,
     181,   203,   144,   123,   332,    81,   137,   245,   145,   380,
     259,   260,   157,   158,   283,   284,   295,   296,   233,   146,
     308,   136,   297,   144,   298,   299,   336,   144,   362,   144,
     147,   346,   363,   144,   315,   397,   148,   399,   149,   400,
      41,   402,   376,   260,   150,    81,   136,   151,   215,   224,
     389,   390,   414,   390,   153,    41,   415,   426,   144,   416,
     154,   417,    81,    81,   156,   375,   177,   136,   178,   288,
     440,   144,   422,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   187,   157,   158,   188,   200,   206,   208,
     209,   226,    81,   136,    81,   136,    81,   136,    81,   136,
     227,   228,   442,   229,   261,   406,   234,   445,   262,   319,
     263,   280,   289,   282,   136,   371,   286,   136,   287,   136,
     374,   301,   302,   304,   305,    81,   334,   335,   307,    81,
     312,    81,   314,   318,   326,   327,   329,   330,   406,   430,
     342,   349,   339,   344,   356,   353,   355,   394,   371,   357,
     364,   372,   360,   385,   284,   386,   348,   224,   350,   407,
     352,   408,   354,   396,   411,   167,   371,   423,   418,    81,
     388,   425,   428,    29,    82,    30,    83,   432,   210,   437,
     438,   309,   443,   183,   395,    79,   412,    77,   142,   378,
      84,    85,   222,   382,   325,   384,   217,   204,   324,   431,
     427,    81,   251,    87,    88,   184,   250,   219,   166,   220,
      89,   347,     0,     0,     0,     0,    90,    91,    92,     0,
     365,     0,     0,     0,    93,    29,    82,    30,    83,     0,
      94,     0,     0,   413,     0,     0,     0,     0,     0,    95,
      96,     0,    84,    85,    86,     0,     0,    97,    98,     0,
       0,     0,     0,     0,     0,    87,    88,     0,    99,     0,
       0,     0,    89,     0,   100,   434,   101,   102,    90,    91,
      92,     0,     0,     0,   103,     0,    93,     0,   104,     0,
       0,     0,    94,   105,   223,     0,     0,     0,     0,     0,
       0,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,    29,    82,    30,    83,     0,     0,   129,
      99,     0,     0,     0,     0,     0,   100,     0,   101,   102,
      84,    85,     0,     0,     0,     0,   103,     0,     0,     0,
     104,     0,     0,    87,    88,   105,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,    93,    29,    82,    30,    83,     0,
      94,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,     0,    84,    85,     0,     0,     0,    97,    98,     0,
       0,     0,     0,     0,     0,    87,    88,     0,    99,     0,
       0,     0,    89,     0,   100,     0,   101,   102,    90,    91,
      92,     0,     0,     0,   103,     0,    93,     0,   104,     0,
       0,     0,    94,   130,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,    29,    82,    30,    83,     0,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,    84,   165,     0,     0,     0,   100,     0,   101,   102,
       0,     0,     0,     0,    87,    88,   103,     0,     0,     0,
     104,    89,     0,     0,     0,   105,     0,    90,    91,    92,
       0,     0,     0,     0,     0,    93,    29,    82,    30,    83,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,     0,    84,    85,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,    87,    88,     0,    99,
       0,     0,     0,    89,     0,   100,     0,   101,   102,    90,
      91,    92,     0,     0,     0,   103,     0,    93,     0,   104,
       0,     0,     0,    94,   105,     0,     0,     0,     0,     0,
       0,     0,    95,    96,     0,     0,    82,     0,    83,     0,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,    84,   165,     0,     0,     0,   100,     0,   101,
     102,     0,     0,     0,     0,    87,    88,   103,     0,     0,
       0,   104,    89,     0,     0,     0,   130,     0,    90,    91,
      92,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,    94,     0,     0,     0,     0,     0,    87,    88,
       0,    95,    96,     0,     0,    89,     0,     0,     0,    97,
      98,    90,    91,    92,     0,     0,     0,     0,     0,    93,
      99,     0,     0,     0,     0,    94,   100,     0,   101,   102,
       0,     0,     0,     0,    95,   182,   103,     0,     0,     0,
     104,     0,    97,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,    99,   157,   158,     0,     0,     0,   100,
       0,   101,   102,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,   104
};

static const yytype_int16 yycheck[] =
{
       4,    11,   154,    63,   329,    69,    10,    11,   130,   180,
      10,     4,     8,     6,     7,    27,     4,    74,     6,    21,
      22,   137,    37,   214,    28,     8,    82,   119,    32,    33,
      34,    35,    36,    82,     8,    96,    59,    30,    30,    82,
      82,    82,     1,    63,     3,   105,    82,    52,    58,    82,
      82,    96,    57,    57,    58,    72,    60,    42,    81,    82,
     116,    67,    54,    67,    68,   129,   130,   116,     0,    73,
     130,    93,    31,   116,   116,   116,    99,    62,    60,    79,
     116,   141,     3,   116,   116,   100,    45,    46,   279,   181,
      96,    63,    51,    75,    28,    94,   156,    56,   155,   114,
      73,    86,   114,     4,   226,     6,   110,   116,   168,    52,
      69,    84,   437,   115,    57,   119,   101,   121,   122,   115,
     272,   114,    56,   187,   188,   241,   114,   104,    32,    88,
     301,    32,   115,    73,    93,   139,    10,   114,   198,   199,
     144,   115,    73,   102,   260,    64,    21,    22,   107,    68,
     154,   110,   114,    84,    73,   159,     5,    76,    33,   106,
      73,    64,   226,   167,     4,    68,     6,     9,    42,   116,
      73,    84,    91,    76,   178,    82,    50,   181,    53,    21,
      22,    21,    22,   305,    43,    44,   110,     9,    91,   113,
     106,     4,    32,     6,   254,    43,    44,   116,   314,    21,
      22,    17,    18,    19,   110,    79,   112,   211,   330,   114,
     214,    11,    86,   115,   116,   114,    90,    23,    24,   115,
     116,   115,   116,   107,   284,   229,   114,   101,     7,   351,
     115,   116,    21,    22,   115,   116,   115,   116,   178,     7,
     244,   305,   115,   116,    38,    39,   115,   116,   115,   116,
     114,   311,   115,   116,   264,   377,    71,   379,     5,   381,
     264,   383,   115,   116,   114,   269,   330,    71,   272,   329,
     115,   116,   115,   116,     5,   279,   398,   115,   116,   401,
      63,   403,   286,   287,   116,   345,   114,   351,   114,   229,
     115,   116,   408,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     8,    21,    22,     9,    20,   115,     7,
       7,   114,   316,   377,   318,   379,   320,   381,   322,   383,
      74,    74,   438,   114,   104,   385,   103,   443,   115,   269,
     115,    65,     5,   115,   398,   339,   114,   401,   114,   403,
     344,   116,   107,    79,   114,   349,   286,   287,    74,   353,
      79,   355,   114,    73,     7,     7,    40,    66,   418,   423,
      36,    73,   114,   114,    85,    73,    73,   371,   372,    85,
       5,   114,    83,    40,   116,    77,   316,   437,   318,     7,
     320,   108,   322,   115,   388,    27,   390,    82,   116,   393,
      90,   114,    80,     4,     5,     6,     7,    87,   115,    40,
      58,   247,    29,   128,   372,    59,   390,    58,    78,   349,
      21,    22,    23,   353,   274,   355,   156,   139,   272,   423,
     418,   425,   188,    34,    35,   129,   187,   160,   117,   164,
      41,   314,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
     338,    -1,    -1,    -1,    55,     4,     5,     6,     7,    -1,
      61,    -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    21,    22,    23,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    89,    -1,
      -1,    -1,    41,    -1,    95,   425,    97,    98,    47,    48,
      49,    -1,    -1,    -1,   105,    -1,    55,    -1,   109,    -1,
      -1,    -1,    61,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    -1,    -1,     4,     5,     6,     7,    -1,    -1,    10,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    97,    98,
      21,    22,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
     109,    -1,    -1,    34,    35,   114,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    55,     4,     5,     6,     7,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    21,    22,    -1,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    89,    -1,
      -1,    -1,    41,    -1,    95,    -1,    97,    98,    47,    48,
      49,    -1,    -1,    -1,   105,    -1,    55,    -1,   109,    -1,
      -1,    -1,    61,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,     4,     5,     6,     7,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    21,    22,    -1,    -1,    -1,    95,    -1,    97,    98,
      -1,    -1,    -1,    -1,    34,    35,   105,    -1,    -1,    -1,
     109,    41,    -1,    -1,    -1,   114,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    55,     4,     5,     6,     7,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    21,    22,    -1,    -1,    -1,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    89,
      -1,    -1,    -1,    41,    -1,    95,    -1,    97,    98,    47,
      48,    49,    -1,    -1,    -1,   105,    -1,    55,    -1,   109,
      -1,    -1,    -1,    61,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    -1,     5,    -1,     7,    -1,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    21,    22,    -1,    -1,    -1,    95,    -1,    97,
      98,    -1,    -1,    -1,    -1,    34,    35,   105,    -1,    -1,
      -1,   109,    41,    -1,    -1,    -1,   114,    -1,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    70,    71,    -1,    -1,    41,    -1,    -1,    -1,    78,
      79,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,
      89,    -1,    -1,    -1,    -1,    61,    95,    -1,    97,    98,
      -1,    -1,    -1,    -1,    70,    71,   105,    -1,    -1,    -1,
     109,    -1,    78,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    89,    21,    22,    -1,    -1,    -1,    95,
      -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    31,    45,    46,    51,    56,    69,    88,
     102,   107,   110,   118,   119,   120,   121,   122,   123,   124,
     143,   144,   147,   148,   151,   152,   206,   207,    96,     4,
       6,   204,    67,    96,    63,    96,    72,   204,   153,   154,
     168,   204,     0,   110,   112,    93,   155,   110,   113,     3,
     204,    63,   204,   204,   204,   204,   204,    94,   116,    32,
     114,    30,    54,   156,    28,    56,     5,    82,   114,   106,
     184,   185,   104,   114,   149,   150,   204,   154,   114,   164,
     203,   204,     5,     7,    21,    22,    23,    34,    35,    41,
      47,    48,    49,    55,    61,    70,    71,    78,    79,    89,
      95,    97,    98,   105,   109,   114,   127,   157,   158,   159,
     190,   191,   192,   193,   194,   196,   198,   200,   204,    43,
      44,    43,    44,   107,   145,   204,   125,   126,   204,    10,
     114,   186,   187,   188,   189,   190,   198,   114,   203,   116,
     184,    11,   155,   115,   116,     7,     7,   114,    71,     5,
     114,    71,   190,     5,    63,   160,   116,    21,    22,    32,
     201,   204,    23,    24,   202,    22,   193,    27,   114,   125,
      42,    62,    86,   101,   131,   204,   204,   114,   114,   134,
     115,   116,    71,   127,   189,   186,   190,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   199,
      20,   196,   197,   115,   150,   190,   115,   204,     7,     7,
     115,   164,   166,   169,   194,   204,   184,   159,   204,   191,
     192,   204,    23,   115,   190,   195,   114,    74,    74,   114,
      52,    57,   146,   203,   103,   131,   132,   133,   125,    10,
      42,    50,    79,    86,    90,   101,   128,   129,   130,   115,
     187,   188,    17,    18,    19,   190,   190,    10,    79,   115,
     116,   104,   115,   115,    32,   167,   168,    64,    68,    73,
      76,    91,   116,   161,   162,   163,   167,    37,   100,   165,
      65,   170,   115,   115,   116,   186,   114,   114,   203,     5,
      59,    81,    82,    99,   205,   115,   116,   115,    38,    39,
     141,   116,   107,   135,    79,   114,   196,    74,   204,   128,
     190,     9,    79,   196,   114,   168,    73,    84,    73,   203,
      73,    84,    73,    84,   166,   163,     7,     7,   167,    40,
      66,   171,   190,   115,   203,   203,   115,    52,    57,   114,
     142,   131,    36,   186,   114,     9,   190,   197,   203,    73,
     203,    82,   203,    73,   203,    73,    85,    85,   195,   186,
      83,   172,   115,   115,     5,   205,   136,   137,   138,   139,
     140,   204,   114,   115,   204,   190,   115,    82,   203,    82,
     186,    82,   203,    82,   203,    40,    77,   173,    90,   115,
     116,     7,    30,   114,   204,   136,   115,   186,    82,   186,
     186,    82,   186,    82,   180,   181,   190,     7,   108,   174,
     175,   204,   137,   203,   115,   186,   186,   186,   116,    33,
      53,   182,   196,    82,   176,   114,   115,   181,    80,   183,
     198,   204,    87,   177,   203,    60,    75,    40,    58,   178,
     115,   195,   196,    29,   179,   196
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   117,   118,   118,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   121,
     121,   121,   121,   122,   123,   124,   125,   126,   126,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   128,   128,   128,
     128,   128,   128,   128,   129,   129,   130,   130,   131,   131,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   137,   138,   138,   139,   140,   141,
     141,   142,   142,   143,   143,   144,   145,   145,   146,   146,
     146,   146,   147,   148,   149,   149,   150,   151,   152,   152,
     153,   153,   154,   155,   156,   156,   156,   157,   157,   158,
     158,   159,   159,   159,   160,   161,   161,   162,   162,   163,
     163,   163,   163,   163,   163,   163,   163,   164,   165,   165,
     165,   166,   166,   166,   166,   166,   167,   167,   168,   168,
     169,   169,   170,   170,   171,   171,   172,   172,   173,   173,
     174,   174,   175,   176,   177,   177,   178,   179,   180,   180,
     181,   182,   182,   182,   183,   183,   183,   184,   184,   185,
     186,   186,   187,   187,   188,   188,   189,   189,   189,   189,
     189,   189,   190,   190,   191,   191,   192,   192,   193,   193,
     193,   193,   194,   194,   194,   195,   195,   196,   196,   196,
     196,   196,   196,   196,   197,   197,   198,   198,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   200,   201,
     201,   202,   202,   203,   203,   204,   204,   205,   205,   205,
     205,   206,   207,   207
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
       6,     6,     6,     8,     9,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     4,     1,     2,     1,
       2,     2,     4,     5,     2,     1,     0,     1,     4,     5,
      10,     4,     3,     1,     0,     1,     0,     3,     0,     5,
       1,     3,     1,     1,     1,     2,     2,     4,     2,     1,
       1,     0,     3,    10,     7,     5,     0,     4,     2,     2,
       4,     4,     5,     4,     3,     1,     3,     2,     0,     2,
       1,     3,     3,    10,     0,     1,     1,     1,     1,     1,
       3,     3,     2,     1,     3,     0,     1,     2,     1,     5,
       4,     6,     5,     6,     5,     6,     5,     3,     0,     3,
       3,     2,     3,     2,     2,     1,     1,     2,     1,     4,
       1,     3,     0,     3,     0,     2,     0,     3,     0,     2,
       0,     5,     2,     2,     0,     3,     2,     2,     1,     3,
       3,     0,     1,     1,     0,     2,     2,     0,     1,     2,
       3,     1,     3,     1,     2,     1,     5,     6,     4,     3,
       3,     3,     3,     1,     3,     1,     2,     1,     1,     1,
       1,     3,     3,     4,     4,     1,     3,     1,     1,     2,
       2,     1,     2,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     0
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
      yyerror (&yylloc, yyscanner, parsedStatement, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, yyscanner, parsedStatement); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (yyscanner);
  YYUSE (parsedStatement);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, yyscanner, parsedStatement);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , yyscanner, parsedStatement);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, yyscanner, parsedStatement); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (yyscanner);
  YYUSE (parsedStatement);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* TOKEN_COMMAND  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1780 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 4: /* TOKEN_NAME  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1790 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 5: /* TOKEN_STRING_SINGLE_QUOTED  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1800 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 6: /* TOKEN_STRING_DOUBLE_QUOTED  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 1810 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 7: /* TOKEN_UNSIGNED_NUMVAL  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).numeric_literal_value_) != nullptr) {
    delete ((*yyvaluep).numeric_literal_value_);
  }
}
#line 1820 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 119: /* sql_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1830 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 120: /* quit_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).quit_statement_) != nullptr) {
    delete ((*yyvaluep).quit_statement_);
  }
}
#line 1840 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 121: /* alter_table_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1850 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 122: /* create_table_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).create_table_statement_) != nullptr) {
    delete ((*yyvaluep).create_table_statement_);
  }
}
#line 1860 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 123: /* create_index_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).statement_) != nullptr) {
    delete ((*yyvaluep).statement_);
  }
}
#line 1870 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 124: /* drop_table_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).drop_table_statement_) != nullptr) {
    delete ((*yyvaluep).drop_table_statement_);
  }
}
#line 1880 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 125: /* column_def  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_);
  }
}
#line 1890 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 126: /* column_def_commalist  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_definition_list_) != nullptr) {
    delete ((*yyvaluep).attribute_definition_list_);
  }
}
#line 1900 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 127: /* data_type  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).data_type_) != nullptr) {
    delete ((*yyvaluep).data_type_);
  }
}
#line 1910 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 128: /* column_constraint_def  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_) != nullptr) {
    delete ((*yyvaluep).column_constraint_);
  }
}
#line 1920 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 129: /* column_constraint_def_list  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 1930 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 130: /* opt_column_constraint_def_list  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).column_constraint_list_) != nullptr) {
    delete ((*yyvaluep).column_constraint_list_);
  }
}
#line 1940 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 134: /* opt_column_list  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_list_) != nullptr) {
    delete ((*yyvaluep).string_list_);
  }
}
#line 1950 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 135: /* opt_block_properties  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).block_properties_) != nullptr) {
    delete ((*yyvaluep).block_properties_);
  }
}
#line 1960 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 136: /* key_value_list  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 1970 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 137: /* key_value  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_) != nullptr) {
    delete ((*yyvaluep).key_value_);
  }
}
#line 1980 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 138: /* key_string_value  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_value_) != nullptr) {
    delete ((*yyvaluep).key_string_value_);
  }
}
#line 1990 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 139: /* key_string_list  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_string_list_) != nullptr) {
    delete ((*yyvaluep).key_string_list_);
  }
}
#line 2000 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 140: /* key_integer_value  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_integer_value_) != nullptr) {
    delete ((*yyvaluep).key_integer_value_);
  }
}
#line 2010 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 141: /* index_type  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2020 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 142: /* opt_index_properties  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).key_value_list_) != nullptr) {
    delete ((*yyvaluep).key_value_list_);
  }
}
#line 2030 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 143: /* insert_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).insert_statement_) != nullptr) {
    delete ((*yyvaluep).insert_statement_);
  }
}
#line 2040 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 144: /* copy_from_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_statement_) != nullptr) {
    delete ((*yyvaluep).copy_from_statement_);
  }
}
#line 2050 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 145: /* opt_copy_from_params  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2060 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 146: /* copy_from_params  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).copy_from_params_) != nullptr) {
    delete ((*yyvaluep).copy_from_params_);
  }
}
#line 2070 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 147: /* update_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).update_statement_) != nullptr) {
    delete ((*yyvaluep).update_statement_);
  }
}
#line 2080 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 148: /* delete_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).delete_statement_) != nullptr) {
    delete ((*yyvaluep).delete_statement_);
  }
}
#line 2090 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 149: /* assignment_list  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_list_) != nullptr) {
    delete ((*yyvaluep).assignment_list_);
  }
}
#line 2100 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 150: /* assignment_item  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).assignment_) != nullptr) {
    delete ((*yyvaluep).assignment_);
  }
}
#line 2110 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 151: /* select_statement  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_statement_) != nullptr) {
    delete ((*yyvaluep).select_statement_);
  }
}
#line 2120 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 152: /* opt_with_clause  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2130 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 153: /* with_list  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_) != nullptr) {
    delete ((*yyvaluep).with_list_);
  }
}
#line 2140 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 154: /* with_list_element  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).with_list_element_) != nullptr) {
    delete ((*yyvaluep).with_list_element_);
  }
}
#line 2150 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 155: /* select_query  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).select_query_) != nullptr) {
    delete ((*yyvaluep).select_query_);
  }
}
#line 2160 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 157: /* selection  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_) != nullptr) {
    delete ((*yyvaluep).selection_);
  }
}
#line 2170 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 158: /* selection_item_commalist  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_list_) != nullptr) {
    delete ((*yyvaluep).selection_list_);
  }
}
#line 2180 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 159: /* selection_item  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).selection_item_) != nullptr) {
    delete ((*yyvaluep).selection_item_);
  }
}
#line 2190 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 160: /* from_clause  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2200 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 164: /* subquery_expression  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).subquery_expression_) != nullptr) {
    delete ((*yyvaluep).subquery_expression_);
  }
}
#line 2210 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 165: /* opt_sample_clause  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_sample_clause_) != nullptr) {
    delete ((*yyvaluep).opt_sample_clause_);
  }
}
#line 2220 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 166: /* table_reference  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_) != nullptr) {
    delete ((*yyvaluep).table_reference_);
  }
}
#line 2230 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 167: /* table_reference_signature  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2240 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 168: /* table_reference_signature_primary  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_signature_) != nullptr) {
    delete ((*yyvaluep).table_reference_signature_);
  }
}
#line 2250 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 169: /* table_reference_commalist  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).table_reference_list_) != nullptr) {
    delete ((*yyvaluep).table_reference_list_);
  }
}
#line 2260 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 170: /* opt_group_by_clause  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_group_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_group_by_clause_);
  }
}
#line 2270 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 171: /* opt_having_clause  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_having_clause_) != nullptr) {
    delete ((*yyvaluep).opt_having_clause_);
  }
}
#line 2280 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 172: /* opt_order_by_clause  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_order_by_clause_) != nullptr) {
    delete ((*yyvaluep).opt_order_by_clause_);
  }
}
#line 2290 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 173: /* opt_limit_clause  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_limit_clause_) != nullptr) {
    delete ((*yyvaluep).opt_limit_clause_);
  }
}
#line 2300 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 174: /* opt_window_clause  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).opt_window_clause_) != nullptr) {
    delete ((*yyvaluep).opt_window_clause_);
  }
}
#line 2310 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 175: /* window_duration  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2320 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 176: /* window_attribute  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_) != nullptr) {
    delete ((*yyvaluep).attribute_);
  }
}
#line 2330 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 177: /* opt_window_partition  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).window_partition_by_list_) != nullptr) {
    delete ((*yyvaluep).window_partition_by_list_);
  }
}
#line 2340 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 178: /* emit_duration  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2350 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 179: /* age_duration  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2360 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 180: /* order_commalist  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_commalist_) != nullptr) {
    delete ((*yyvaluep).order_commalist_);
  }
}
#line 2370 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 181: /* order_item  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_item_) != nullptr) {
    delete ((*yyvaluep).order_item_);
  }
}
#line 2380 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 182: /* opt_order_direction  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2390 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 183: /* opt_nulls_first  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).order_direction_) != nullptr) {
    delete ((*yyvaluep).order_direction_);
  }
}
#line 2400 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 184: /* opt_where_clause  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2410 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 185: /* where_clause  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2420 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 186: /* or_expression  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2430 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 187: /* and_expression  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2440 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 188: /* not_expression  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2450 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 189: /* predicate_expression_base  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).predicate_) != nullptr) {
    delete ((*yyvaluep).predicate_);
  }
}
#line 2460 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 190: /* add_expression  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2470 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 191: /* multiply_expression  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2480 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 192: /* unary_expression  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2490 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 193: /* expression_base  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_) != nullptr) {
    delete ((*yyvaluep).expression_);
  }
}
#line 2500 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 194: /* function_call  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).function_call_) != nullptr) {
    delete ((*yyvaluep).function_call_);
  }
}
#line 2510 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 195: /* expression_list  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).expression_list_) != nullptr) {
    delete ((*yyvaluep).expression_list_);
  }
}
#line 2520 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 196: /* literal_value  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_) != nullptr) {
    delete ((*yyvaluep).literal_value_);
  }
}
#line 2530 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 197: /* literal_value_commalist  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).literal_value_list_) != nullptr) {
    delete ((*yyvaluep).literal_value_list_);
  }
}
#line 2540 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 198: /* attribute_ref  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).attribute_) != nullptr) {
    delete ((*yyvaluep).attribute_);
  }
}
#line 2550 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 199: /* comparison_operation  */
#line 529 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2556 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 200: /* unary_operation  */
#line 530 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2562 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 201: /* add_operation  */
#line 531 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2568 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 202: /* multiply_operation  */
#line 531 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2574 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 203: /* name_commalist  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_list_) != nullptr) {
    delete ((*yyvaluep).string_list_);
  }
}
#line 2584 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 204: /* any_name  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).string_value_) != nullptr) {
    delete ((*yyvaluep).string_value_);
  }
}
#line 2594 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 205: /* boolean_value  */
#line 528 "../SqlParser.ypp" /* yacc.c:1257  */
      { }
#line 2600 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 206: /* command  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_) != nullptr) {
    delete ((*yyvaluep).command_);
  }
}
#line 2610 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;

    case 207: /* command_argument_list  */
#line 533 "../SqlParser.ypp" /* yacc.c:1257  */
      {
  if (((*yyvaluep).command_argument_list_) != nullptr) {
    delete ((*yyvaluep).command_argument_list_);
  }
}
#line 2620 "SqlParser_gen.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t yyscanner, quickstep::ParseStatement **parsedStatement)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, yyscanner);
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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 542 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 2917 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 546 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].statement_);
    YYACCEPT;
  }
#line 2926 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 550 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 2935 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 554 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    *parsedStatement = (yyvsp[-1].command_);
    YYACCEPT;
  }
#line 2944 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 558 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    YYABORT;
  }
#line 2952 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 561 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // Regular yyparse() return codes are non-negative, so use a negative one here.
    return -1;
  }
#line 2961 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 568 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 2969 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 571 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].copy_from_statement_);
  }
#line 2977 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 574 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].create_table_statement_);
  }
#line 2985 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 577 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].statement_);
  }
#line 2993 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 580 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].delete_statement_);
  }
#line 3001 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 583 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].drop_table_statement_);
  }
#line 3009 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 586 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].insert_statement_);
  }
#line 3017 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 589 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].quit_statement_);
  }
#line 3025 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 592 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].select_statement_);
  }
#line 3033 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 595 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = (yyvsp[0].update_statement_);
  }
#line 3041 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 601 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.quit_statement_) = new quickstep::ParseStatementQuit((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3049 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 607 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].attribute_definition_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3061 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 614 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3072 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 620 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3084 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 627 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[0].string_value_);
    (yyval.statement_) = nullptr;
    NotSupported(&(yylsp[-5]), yyscanner, "ALTER statements");
    YYERROR;
  }
#line 3096 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 636 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.create_table_statement_) = new quickstep::ParseStatementCreateTable((yylsp[-7]).first_line, (yylsp[-7]).first_column, (yyvsp[-5].string_value_), (yyvsp[-3].attribute_definition_list_), (yyvsp[0].block_properties_));
  }
#line 3104 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 641 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.statement_) = new quickstep::ParseStatementCreateIndex((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-6].string_value_), (yyvsp[-4].string_value_), (yyvsp[-3].string_list_), (yyvsp[-1].string_value_), (yyvsp[0].key_value_list_));
  }
#line 3112 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 646 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.drop_table_statement_) = new quickstep::ParseStatementDropTable((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_));
  }
#line 3120 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 651 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_) = new quickstep::ParseAttributeDefinition((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].data_type_), (yyvsp[0].column_constraint_list_));
  }
#line 3128 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 656 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_list_) = new quickstep::PtrList<quickstep::ParseAttributeDefinition>();
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3137 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 660 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_definition_list_) = (yyvsp[-2].attribute_definition_list_);
    (yyval.attribute_definition_list_)->push_back((yyvsp[0].attribute_definition_));
  }
#line 3146 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 666 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "BIT data type");
    YYERROR;
  }
#line 3156 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 671 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3164 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 674 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3172 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 677 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "TIME data type");
    YYERROR;
  }
#line 3182 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 682 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetime));
  }
#line 3190 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 685 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3198 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 688 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3206 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 691 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDouble));
  }
#line 3214 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 694 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kFloat));
  }
#line 3222 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 697 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3230 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 700 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kInt));
  }
#line 3238 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 703 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3246 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 706 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kLong));
  }
#line 3254 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 709 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This pattern exhibits a shift/reduce conflict with the
     * TOKEN_INTERVAL case in 'literal_value'. Bison prefers to shift rather
     * than reduce, so the case in 'literal_value' has precedence over this.
     **/
    (yyval.data_type_) = nullptr;
    quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr,
        "INTERVAL is ambiguous as a column type. Specify either DATETIME INTERVAL "
        "or YEARMONTH INTERVAL");
    YYERROR;
  }
#line 3271 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 721 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kDatetimeInterval));
  }
#line 3279 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 724 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kYearMonthInterval));
  }
#line 3287 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 727 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-1].numeric_literal_value_)->float_like()) {
      delete (yyvsp[-1].numeric_literal_value_);
      (yyval.data_type_) = NULL;
      quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Non-integer length supplied for CHAR type");
      YYERROR;
    } else {
      if ((yyvsp[-1].numeric_literal_value_)->long_value() <= 0) {
        delete (yyvsp[-1].numeric_literal_value_);
        (yyval.data_type_) = NULL;
        quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Length for CHAR type must be at least 1");
        YYERROR;
      } else {
        (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kChar, (yyvsp[-1].numeric_literal_value_)->long_value(), false));
        delete (yyvsp[-1].numeric_literal_value_);
      }
    }
  }
#line 3310 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 745 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-1].numeric_literal_value_)->float_like()) {
      delete (yyvsp[-1].numeric_literal_value_);
      (yyval.data_type_) = NULL;
      quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Non-integer length supplied for VARCHAR type");
      YYERROR;
    } else {
      if ((yyvsp[-1].numeric_literal_value_)->long_value() < 0) {
        delete (yyvsp[-1].numeric_literal_value_);
        (yyval.data_type_) = NULL;
        quickstep_yyerror(&(yylsp[-1]), yyscanner, nullptr, "Negative length supplied for VARCHAR type");
        YYERROR;
      } else {
        (yyval.data_type_) = new quickstep::ParseDataType(quickstep::TypeFactory::GetType(quickstep::kVarChar, (yyvsp[-1].numeric_literal_value_)->long_value(), false));
        delete (yyvsp[-1].numeric_literal_value_);
      }
    }
  }
#line 3333 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 765 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNull((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3341 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 768 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = new quickstep::ParseColumnConstraintNotNull((yylsp[-1]).first_line, (yylsp[-1]).first_column);
  }
#line 3349 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 771 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[0]), yyscanner, "Column Constraints (UNIQUE)");
    YYERROR;
  }
#line 3359 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 776 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3369 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 781 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[0].literal_value_);
    NotSupported(&(yylsp[-1]), yyscanner, "Column Constraints (DEFAULT)");
    YYERROR;
  }
#line 3380 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 787 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Column Constraints (CHECK)");
    YYERROR;
  }
#line 3391 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 793 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_) = nullptr;
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_value_);
    NotSupported(&(yylsp[-4]), yyscanner, "Foreign Keys");
    YYERROR;
  }
#line 3403 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 802 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = (yyvsp[-1].column_constraint_list_);
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3412 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 806 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = new quickstep::PtrList<quickstep::ParseColumnConstraint>();
    (yyval.column_constraint_list_)->push_back((yyvsp[0].column_constraint_));
  }
#line 3421 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 812 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = nullptr;
  }
#line 3429 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 815 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.column_constraint_list_) = (yyvsp[0].column_constraint_list_);
  }
#line 3437 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 820 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (UNIQUE)");
    YYERROR;
  }
#line 3447 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 825 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-4]), yyscanner, "Table Constraints (PRIMARY KEY)");
    YYERROR;
  }
#line 3457 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 830 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-6].string_list_);
    delete (yyvsp[-3].string_value_);
    delete (yyvsp[-1].string_list_);
    NotSupported(&(yylsp[-9]), yyscanner, "Table Constraints (FOREIGN KEY)");
    YYERROR;
  }
#line 3469 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 837 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "Table Constraints (CHECK)");
    YYERROR;
  }
#line 3479 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 844 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[-2]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3488 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 848 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "Table Constraints");
    YYERROR;
  }
#line 3497 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 854 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 3505 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 857 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = $1; */
  }
#line 3513 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 862 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = nullptr;
  }
#line 3521 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 865 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-1].string_list_);
    (yyval.string_list_) = nullptr;
    NotSupported(&(yylsp[-2]), yyscanner, "list of column names in CREATE INDEX statement");
    YYERROR;
  }
#line 3532 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 873 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.block_properties_) = nullptr;
  }
#line 3540 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 876 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.block_properties_) = new quickstep::ParseBlockProperties((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].key_value_list_));
  }
#line 3548 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 881 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = new quickstep::PtrList<quickstep::ParseKeyValue>();
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 3557 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 885 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = (yyvsp[-2].key_value_list_);
    (yyval.key_value_list_)->push_back((yyvsp[0].key_value_));
  }
#line 3566 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 891 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_value_);
  }
#line 3574 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 894 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_string_list_);
  }
#line 3582 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 897 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_) = (yyvsp[0].key_integer_value_);
  }
#line 3590 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 902 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].string_value_));
  }
#line 3598 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 905 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    // This is a special case to handle the COMPRESS ALL option of the BLOCK PROPERTIES.
    (yyval.key_string_value_) = new quickstep::ParseKeyStringValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), 
        new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column, "ALL"));
  }
#line 3608 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 912 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_string_list_) = new quickstep::ParseKeyStringList((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 3616 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 917 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.key_integer_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Value must be an integer");
      YYERROR;
    }
    (yyval.key_integer_value_) = new quickstep::ParseKeyIntegerValue((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].numeric_literal_value_));
  }
#line 3630 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 928 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kBloomFilter));
  }
#line 3639 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 932 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = new quickstep::ParseString((yylsp[0]).first_line, (yylsp[0]).first_column,
           std::to_string(quickstep::IndexSubBlockType::kCSBTree));
  }
#line 3648 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 938 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = nullptr;
  }
#line 3656 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 941 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.key_value_list_) = (yyvsp[-1].key_value_list_);
  }
#line 3664 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 947 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-7].string_value_);
    delete (yyvsp[-5].string_list_);
    delete (yyvsp[-1].literal_value_list_);
    (yyval.insert_statement_) = nullptr;
    NotSupported(&(yylsp[-6]), yyscanner, "list of column names in INSERT statement");
    YYERROR;
  }
#line 3677 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 955 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.insert_statement_) = new quickstep::ParseStatementInsert((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-4].string_value_), (yyvsp[-1].literal_value_list_));
  }
#line 3685 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 960 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_statement_) = new quickstep::ParseStatementCopyFrom((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_value_), (yyvsp[0].copy_from_params_));
  }
#line 3693 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 965 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = nullptr;
  }
#line 3701 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 968 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-1].copy_from_params_);
  }
#line 3709 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 973 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 3718 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 977 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = new quickstep::ParseCopyFromParams((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 3727 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 981 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->set_delimiter((yyvsp[0].string_value_));
  }
#line 3736 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 985 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.copy_from_params_) = (yyvsp[-3].copy_from_params_);
    (yyval.copy_from_params_)->escape_strings = (yyvsp[0].boolean_value_);
  }
#line 3745 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 991 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.update_statement_) = new quickstep::ParseStatementUpdate((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].assignment_list_), (yyvsp[0].predicate_));
  }
#line 3753 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 996 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.delete_statement_) = new quickstep::ParseStatementDelete((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].predicate_));
  }
#line 3761 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1001 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_list_) = (yyvsp[-2].assignment_list_);
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 3770 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1005 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_list_) = new quickstep::PtrList<quickstep::ParseAssignment>();
    (yyval.assignment_list_)->push_back((yyvsp[0].assignment_));
  }
#line 3779 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1011 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.assignment_) = new quickstep::ParseAssignment((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[0].expression_));
  }
#line 3787 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1017 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_statement_) = new quickstep::ParseStatementSelect((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].select_query_), (yyvsp[-1].with_list_));
  }
#line 3795 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1022 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = nullptr;
  }
#line 3803 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1025 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = (yyvsp[0].with_list_);
  }
#line 3811 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1030 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = new quickstep::PtrVector<quickstep::ParseSubqueryTableReference>();
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 3820 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1034 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_) = (yyvsp[-2].with_list_);
    (yyval.with_list_)->push_back((yyvsp[0].with_list_element_));
  }
#line 3829 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1040 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.with_list_element_) = new quickstep::ParseSubqueryTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].subquery_expression_));
    (yyval.with_list_element_)->set_table_reference_signature((yyvsp[-2].table_reference_signature_));
  }
#line 3838 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1047 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.select_query_) = new quickstep::ParseSelect((yylsp[-9]).first_line, (yylsp[-9]).first_column, (yyvsp[-7].selection_), (yyvsp[-6].table_reference_list_), (yyvsp[-5].predicate_), (yyvsp[-4].opt_group_by_clause_), (yyvsp[-3].opt_having_clause_), (yyvsp[-2].opt_order_by_clause_), (yyvsp[-1].opt_limit_clause_), (yyvsp[0].opt_window_clause_));
  }
#line 3846 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1052 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 3854 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1055 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "ALL in selection");
    YYERROR;
  }
#line 3863 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1059 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "DISTINCT in selection");
    YYERROR;
  }
#line 3872 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1065 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_) = new quickstep::ParseSelectionStar((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 3880 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1068 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_) = (yyvsp[0].selection_list_);
  }
#line 3888 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1073 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_list_) = new quickstep::ParseSelectionList((yylsp[0]).first_line, (yylsp[0]).first_column);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 3897 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1077 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_list_) = (yyvsp[-2].selection_list_);
    (yyval.selection_list_)->add((yyvsp[0].selection_item_));
  }
#line 3906 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1083 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[0].string_value_));
  }
#line 3914 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1086 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].expression_), (yyvsp[0].string_value_));
  }
#line 3922 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1089 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.selection_item_) = new quickstep::ParseSelectionItem((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].expression_));
  }
#line 3930 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1094 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = (yyvsp[-1].table_reference_list_);
  }
#line 3938 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1099 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /* $$ = nullptr; */
  }
#line 3946 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1102 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "alternate JOIN syntax (specify in WHERE clause instead)");
    YYERROR;
  }
#line 3955 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1108 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[-1]), yyscanner, "alternate JOIN syntax (specify in WHERE clause instead)");
    YYERROR;
  }
#line 3964 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1112 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    NotSupported(&(yylsp[0]), yyscanner, "alternate JOIN syntax (specify in WHERE clause instead)");
    YYERROR;
  }
#line 3973 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1118 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-4]), yyscanner, "alternate JOIN syntax (specify in WHERE clause instead)");
    YYERROR;
  }
#line 3984 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1124 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-3]), yyscanner, "alternate JOIN syntax (specify in WHERE clause instead)");
    YYERROR;
  }
#line 3995 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1130 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-5]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4006 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1136 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-4]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4017 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1142 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-5]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4028 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1148 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-4]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4039 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1154 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-5]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4050 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1160 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].string_list_);
    delete (yyvsp[0].predicate_);
    NotSupported(&(yylsp[-4]), yyscanner, "OUTER JOIN");
    YYERROR;
  }
#line 4061 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1168 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.subquery_expression_) = new quickstep::ParseSubqueryExpression((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].select_query_));
  }
#line 4069 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1173 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = NULL;
  }
#line 4077 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1176 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, true, (yyvsp[-1].numeric_literal_value_));
  }
#line 4085 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1179 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_sample_clause_) = new quickstep::ParseSample((yylsp[-2]).first_line, (yylsp[-2]).first_column, false, (yyvsp[-1].numeric_literal_value_));
  }
#line 4093 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1184 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSubqueryTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].subquery_expression_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4102 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1188 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), (yyvsp[-1].opt_sample_clause_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4111 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1192 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseSimpleTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].opt_sample_clause_));
  }
#line 4119 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1195 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].function_call_));
    (yyval.table_reference_)->set_table_reference_signature((yyvsp[0].table_reference_signature_));
  }
#line 4128 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1199 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_) = new quickstep::ParseGeneratorTableReference((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].function_call_));
  }
#line 4136 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1204 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4144 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1207 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = (yyvsp[0].table_reference_signature_);
  }
#line 4152 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1212 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 4160 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1215 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_signature_) = new ::quickstep::ParseTableReferenceSignature((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].string_list_));
  }
#line 4168 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1220 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = new quickstep::PtrList<quickstep::ParseTableReference>();
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4177 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1224 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.table_reference_list_) = (yyvsp[-2].table_reference_list_);
    (yyval.table_reference_list_)->push_back((yyvsp[0].table_reference_));
  }
#line 4186 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1230 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_group_by_clause_) = nullptr;
  }
#line 4194 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1233 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_group_by_clause_) = new quickstep::ParseGroupBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].expression_list_));
  }
#line 4202 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1238 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_having_clause_) = nullptr;
  }
#line 4210 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1241 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_having_clause_) = new quickstep::ParseHaving((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4218 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1246 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_order_by_clause_) = nullptr;
  }
#line 4226 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1249 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_order_by_clause_) = new quickstep::ParseOrderBy((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].order_commalist_));
  }
#line 4234 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1254 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_limit_clause_) = nullptr;
  }
#line 4242 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1257 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].numeric_literal_value_)->float_like()) {
      delete (yyvsp[0].numeric_literal_value_);
      (yyval.opt_limit_clause_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "LIMIT value must be an integer");
      YYERROR;
    } else {
      if ((yyvsp[0].numeric_literal_value_)->long_value() <= 0) {
        delete (yyvsp[0].numeric_literal_value_);
        (yyval.opt_limit_clause_) = nullptr;
        quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "LIMIT value must be positive");
        YYERROR;
      } else {
        (yyval.opt_limit_clause_) = new quickstep::ParseLimit((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].numeric_literal_value_));
      }
    }
  }
#line 4264 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1276 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_window_clause_) = nullptr;
  }
#line 4272 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1279 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.opt_window_clause_) = new quickstep::ParseWindow((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].attribute_), (yyvsp[-2].window_partition_by_list_), (yyvsp[-4].literal_value_), (yyvsp[-1].literal_value_), (yyvsp[0].literal_value_));
  }
#line 4280 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1284 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4288 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1289 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = (yyvsp[0].attribute_);
  }
#line 4296 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1294 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.window_partition_by_list_) = nullptr;
  }
#line 4304 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1297 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.window_partition_by_list_) = (yyvsp[0].expression_list_);
  }
#line 4312 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1302 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4320 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1307 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].literal_value_);
  }
#line 4328 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1312 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_commalist_) = new quickstep::PtrList<quickstep::ParseOrderByItem>();
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4337 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1316 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_commalist_) = (yyvsp[-2].order_commalist_);
    (yyval.order_commalist_)->push_back((yyvsp[0].order_item_));
  }
#line 4346 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1322 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_item_) = new quickstep::ParseOrderByItem((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].expression_), (yyvsp[-1].order_direction_), (yyvsp[0].order_direction_));
    delete (yyvsp[-1].order_direction_);
    delete (yyvsp[0].order_direction_);
  }
#line 4356 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1329 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 4364 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1332 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 4372 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1335 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 4380 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1340 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = nullptr;
  }
#line 4388 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1343 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(true);
  }
#line 4396 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1346 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.order_direction_) = new bool(false);
  }
#line 4404 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1352 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = nullptr;
  }
#line 4412 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1355 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4420 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1360 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4428 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1365 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kDisjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateDisjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateDisjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 4442 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1374 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4450 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1379 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[-2].predicate_)->getParsePredicateType() == quickstep::ParsePredicate::kConjunction) {
      (yyval.predicate_) = (yyvsp[-2].predicate_);
    } else {
      (yyval.predicate_) = new quickstep::ParsePredicateConjunction((yylsp[-2]).first_line, (yylsp[-2]).first_column);
      static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[-2].predicate_));
    }
    static_cast<quickstep::ParsePredicateConjunction *>((yyval.predicate_))->addPredicate((yyvsp[0].predicate_));
  }
#line 4464 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1388 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4472 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1393 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[0].predicate_));
  }
#line 4480 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1396 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[0].predicate_);
  }
#line 4488 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1401 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-4].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4496 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1404 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateNegation(
        (yylsp[-4]).first_line, (yylsp[-4]).first_column,
        new quickstep::ParsePredicateBetween((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-5].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_)));
  }
#line 4506 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1409 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-3].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-2]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 4517 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1415 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    delete (yyvsp[-2].attribute_);
    (yyval.predicate_) = nullptr;
    NotSupported(&(yylsp[-1]), yyscanner, "NULL comparison predicates");
    YYERROR;
  }
#line 4528 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1421 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = new quickstep::ParsePredicateComparison((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].comparison_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4536 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1424 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.predicate_) = (yyvsp[-1].predicate_);
  }
#line 4544 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1430 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseBinaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].binary_operation_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4552 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1433 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4560 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1438 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseBinaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].binary_operation_), (yyvsp[-2].expression_), (yyvsp[0].expression_));
  }
#line 4568 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1441 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4576 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1446 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseUnaryExpression((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].unary_operation_), (yyvsp[0].expression_));
  }
#line 4584 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1449 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].expression_);
  }
#line 4592 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1454 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].attribute_);
  }
#line 4600 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1457 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_));
  }
#line 4608 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1460 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[0].function_call_);
  }
#line 4616 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1463 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_) = (yyvsp[-1].expression_);
  }
#line 4624 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1468 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].string_value_), new quickstep::PtrList<quickstep::ParseExpression>());
  }
#line 4633 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1472 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall(
        (yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), new quickstep::ParseStar((yylsp[-1]).first_line, (yylsp[-1]).first_column));
  }
#line 4642 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1476 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.function_call_) = new quickstep::ParseFunctionCall((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].string_value_), (yyvsp[-1].expression_list_));
  }
#line 4650 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1481 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_list_) = new quickstep::PtrList<quickstep::ParseExpression>();
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 4659 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1485 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.expression_list_) = (yyvsp[-2].expression_list_);
    (yyval.expression_list_)->push_back((yyvsp[0].expression_));
  }
#line 4668 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1491 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = new quickstep::NullParseLiteralValue((yylsp[0]).first_line, (yylsp[0]).first_column);
  }
#line 4676 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1494 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 4684 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1497 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 4692 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1500 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * minus character as a 'unary_operation' followed by a numeric literal.
     * Because Bison prefers to shift rather than reduce, this case has
     * precedence (i.e. the parser will prefer to interpret the ambiguous
     * pattern as a negative number literal rather than a unary minus operation
     * applied to a non-negative number literal).
     **/
    (yyvsp[0].numeric_literal_value_)->prependMinus();
    (yyval.literal_value_) = (yyvsp[0].numeric_literal_value_);
  }
#line 4709 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1512 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_) = new quickstep::StringParseLiteralValue((yyvsp[0].string_value_),
                                                nullptr);  // No explicit type.
  }
#line 4718 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1516 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * plain TOKEN_INTERVAL case in 'data_type' reduced and used in the case
     * below. Because Bison prefers to shift rather than reduce, this case has
     * precedence (i.e. the special
     * StringParseLiteralValue::ParseAmbiguousInterval() method will be used to
     * parse the string as either one of the interval types, rather than an
     * error being emitted because of an ambiguous type).
     **/
    quickstep::StringParseLiteralValue *parse_value;
    if (quickstep::StringParseLiteralValue::ParseAmbiguousInterval((yyvsp[0].string_value_), &parse_value)) {
      (yyval.literal_value_) = parse_value;
    } else {
      (yyval.literal_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Failed to parse literal as specified type");
      YYERROR;
    }
  }
#line 4742 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1535 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    quickstep::StringParseLiteralValue *parse_value
        = new quickstep::StringParseLiteralValue((yyvsp[0].string_value_), &((yyvsp[-1].data_type_)->getType()));
    delete (yyvsp[-1].data_type_);
    if (!parse_value->tryExplicitTypeParse()) {
      delete parse_value;
      (yyval.literal_value_) = nullptr;
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Failed to parse literal as specified type");
      YYERROR;
    } else {
      (yyval.literal_value_) = parse_value;
    }
  }
#line 4760 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1550 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_list_) = new quickstep::PtrList<quickstep::ParseScalarLiteral>();
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 4769 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1554 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.literal_value_list_) = (yyvsp[-2].literal_value_list_);
    (yyval.literal_value_list_)->push_back(new quickstep::ParseScalarLiteral((yyvsp[0].literal_value_)));
  }
#line 4778 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1560 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].string_value_));
  }
#line 4786 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1563 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.attribute_) = new quickstep::ParseAttribute((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[0].string_value_), (yyvsp[-2].string_value_));
  }
#line 4794 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1569 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kEqual);
  }
#line 4802 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1572 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotEqual);
  }
#line 4810 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1575 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLess);
  }
#line 4818 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1578 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLessOrEqual);
  }
#line 4826 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1581 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreater);
  }
#line 4834 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1584 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) = &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kGreaterOrEqual);
  }
#line 4842 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1587 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kLike);
  }
#line 4850 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1590 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotLike);
  }
#line 4858 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1593 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kRegexMatch);
  }
#line 4866 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1596 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.comparison_) =  &quickstep::ComparisonFactory::GetComparison(quickstep::ComparisonID::kNotRegexMatch);
  }
#line 4874 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1601 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    /**
     * NOTE(chasseur): This case exhibits a shift/reduce conflict with the
     * '-' TOKEN_UNSIGNED_NUMVAL case in 'literal_value'. Because Bison prefers
     * to shift rather than reduce, the case in 'literal_value' has precedence
     * over this one.
     **/
    (yyval.unary_operation_) = &quickstep::UnaryOperationFactory::GetUnaryOperation(quickstep::UnaryOperationID::kNegate);
  }
#line 4888 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1612 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kAdd);
  }
#line 4896 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1615 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kSubtract);
  }
#line 4904 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1620 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kMultiply);
  }
#line 4912 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1623 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.binary_operation_) = &quickstep::BinaryOperationFactory::GetBinaryOperation(quickstep::BinaryOperationID::kDivide);
  }
#line 4920 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1629 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = new quickstep::PtrList<quickstep::ParseString>();
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 4929 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1633 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_list_) = (yyvsp[-2].string_list_);
    (yyval.string_list_)->push_back((yyvsp[0].string_value_));
  }
#line 4938 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1639 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 4946 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1642 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    if ((yyvsp[0].string_value_)->value().empty()) {
      quickstep_yyerror(&(yylsp[0]), yyscanner, nullptr, "Zero-length identifier");
    }
    (yyval.string_value_) = (yyvsp[0].string_value_);
  }
#line 4957 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1650 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = true;
  }
#line 4965 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1653 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = true;
  }
#line 4973 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1656 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = false;
  }
#line 4981 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1659 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.boolean_value_) = false;
  }
#line 4989 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1665 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    (yyval.command_) = new quickstep::ParseCommand((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].string_value_), (yyvsp[0].command_argument_list_));
  }
#line 4997 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1670 "../SqlParser.ypp" /* yacc.c:1646  */
    {
    quickstep::PtrVector<quickstep::ParseString> *argument_list = (yyvsp[-1].command_argument_list_);
    argument_list->push_back((yyvsp[0].string_value_));
    (yyval.command_argument_list_) = argument_list;
  }
#line 5007 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1675 "../SqlParser.ypp" /* yacc.c:1646  */
    { /* Epsilon, an empy match. */
    (yyval.command_argument_list_) = new quickstep::PtrVector<quickstep::ParseString>();
  }
#line 5015 "SqlParser_gen.cpp" /* yacc.c:1646  */
    break;


#line 5019 "SqlParser_gen.cpp" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, yyscanner, parsedStatement, YY_("syntax error"));
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
        yyerror (&yylloc, yyscanner, parsedStatement, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, yyscanner, parsedStatement);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, yyscanner, parsedStatement);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, yyscanner, parsedStatement, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, yyscanner, parsedStatement);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, yyscanner, parsedStatement);
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
#line 1679 "../SqlParser.ypp" /* yacc.c:1906  */


void NotSupported(const YYLTYPE *location, yyscan_t yyscanner, const std::string &feature) {
  std::string msg;
  msg.append(feature);
  msg.append(" is not supported yet");

  quickstep_yyerror(location, yyscanner, nullptr, msg.c_str());
}

int quickstep_yyget_line_number(const YYLTYPE *yyloc) {
  return yyloc->first_line;
}

int quickstep_yyget_column_number(const YYLTYPE *yyloc) {
  return yyloc->first_column;
}
