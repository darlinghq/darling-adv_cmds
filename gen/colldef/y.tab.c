/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SUBSTITUTE = 258,
     WITH = 259,
     START_LC_COLLATE = 260,
     END_LC_COLLATE = 261,
     COLLATING_ELEMENT = 262,
     FROM = 263,
     COLLATING_SYMBOL = 264,
     ELLIPSIS = 265,
     IGNORE = 266,
     UNDEFINED = 267,
     ORDER = 268,
     RANGE = 269,
     ORDER_START = 270,
     ORDER_END = 271,
     ORDER_SECOND_PASS = 272,
     STRING = 273,
     DEFN = 274,
     ELEM = 275,
     CHAR = 276,
     ORDER_DIRECTIVE = 277
   };
#endif
/* Tokens.  */
#define SUBSTITUTE 258
#define WITH 259
#define START_LC_COLLATE 260
#define END_LC_COLLATE 261
#define COLLATING_ELEMENT 262
#define FROM 263
#define COLLATING_SYMBOL 264
#define ELLIPSIS 265
#define IGNORE 266
#define UNDEFINED 267
#define ORDER 268
#define RANGE 269
#define ORDER_START 270
#define ORDER_END 271
#define ORDER_SECOND_PASS 272
#define STRING 273
#define DEFN 274
#define ELEM 275
#define CHAR 276
#define ORDER_DIRECTIVE 277




/* Copy the first part of user declarations.  */
#line 1 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"

/*-
 * Copyright (c) 1995 Alex Tatmanjants <alex@elvisti.kiev.ua>
 *		at Electronni Visti IA, Kiev, Ukraine.
 *			All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/usr.bin/colldef/parse.y,v 1.31 2002/10/16 12:56:22 charnier Exp $");

#include <arpa/inet.h>
#include <err.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <unistd.h>
#include <sysexits.h>
#include <limits.h>
#include "collate.h"
#include "common.h"

#define PRI_UNDEFINED	(-1)
#define PRI_IGNORE	0
#define LINE_NONE	(-1)
#define LINE_NORMAL	0
#define LINE_ELLIPSIS	1
#define LINE_UNDEFINED	2
/* If UNDEFINED is specified with ellipses, we reposition prim_pri to
 * UNDEFINED_PRI, leaving gap for undefined characters. */
#define UNDEFINED_PRI	(COLLATE_MAX_PRIORITY - (COLLATE_MAX_PRIORITY >> 2))

extern FILE *yyin;
void yyerror(const char *fmt, ...) __printflike(1, 2);
int yyparse(void);
int yylex(void);
static void usage(void);
static void collate_print_tables(void);
static struct __collate_st_char_pri *getpri(int32_t);
static struct __collate_st_char_pri *haspri(int32_t);
static struct __collate_st_chain_pri *getchain(const wchar_t *, int);
static struct symbol *getsymbolbychar(wchar_t);
static struct symbol *hassymbolbychar(wchar_t);
static void setsymbolbychar(struct symbol *);
struct symbol *getstring(const wchar_t *);
static void makeforwardref(int, const struct symbol *, const struct symbol *);
static int charpricompar(const void *, const void *);
static int substcompar(const void *, const void *);
static int chainpricompar(const void *, const void *);
static void putsubst(int32_t, int, const wchar_t *);
static int hassubst(int32_t, int);
static const wchar_t *__collate_wcsnchr(const wchar_t *, wchar_t, int);
static int __collate_wcsnlen(const wchar_t *, int);
char *showwcs(const wchar_t *, int);
static char *charname(wchar_t);
static char *charname2(wchar_t);

char map_name[FILENAME_MAX] = ".";
wchar_t curr_chain[STR_LEN + 1];

char __collate_version[STR_LEN];
DB *charmapdb;
static DB *charmapdb2;
static DB *largemapdb;
static int nlargemap = 0;
static DB *substdb[COLL_WEIGHTS_MAX];
static int nsubst[COLL_WEIGHTS_MAX];
static DB *chaindb;
static int nchain = 0;
static DB *stringdb;
static DB *forward_ref[COLL_WEIGHTS_MAX];
static struct symbol *prev_weight_table[COLL_WEIGHTS_MAX];
static struct symbol *prev2_weight_table[COLL_WEIGHTS_MAX];
static struct symbol *weight_table[COLL_WEIGHTS_MAX];
static int prev_line = LINE_NONE;
static struct symbol *prev_elem;
static int weight_index = 0;
static int allow_ellipsis = 0;
static struct symbol sym_ellipsis = {SYMBOL_ELLIPSIS, PRI_UNDEFINED};
static struct symbol sym_ignore = {SYMBOL_IGNORE, PRI_IGNORE};
static struct symbol sym_undefined = {SYMBOL_CHAR, PRI_UNDEFINED};
static int order_pass = 0;

#undef __collate_char_pri_table
struct __collate_st_char_pri __collate_char_pri_table[UCHAR_MAX + 1];
struct __collate_st_chain_pri *__collate_chain_pri_table;
struct __collate_st_subst *__collate_substitute_table[COLL_WEIGHTS_MAX];
struct __collate_st_large_char_pri *__collate_large_char_pri_table;

int prim_pri = 2, sec_pri = 2;
#ifdef COLLATE_DEBUG
int debug;
#endif
struct __collate_st_info info = {{DIRECTIVE_FORWARD, DIRECTIVE_FORWARD}, 0, 0, 0, {PRI_UNDEFINED, PRI_UNDEFINED}};

/* Some of the code expects COLL_WEIGHTS_MAX == 2 */
int directive_count = COLL_WEIGHTS_MAX;

const char *out_file = "LC_COLLATE";


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 123 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
{
	int32_t ch;
	wchar_t str[BUFSIZE];
}
/* Line 193 of yacc.c.  */
#line 268 "/Users/thomasa/Library/Developer/Xcode/DerivedData/adv_cmds-gcqksaoexabncqfyxdglupyaedsy/Build/Intermediates.noindex/adv_cmds.build/Release/colldef.build/DerivedSources/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 281 "/Users/thomasa/Library/Developer/Xcode/DerivedData/adv_cmds-gcqksaoexabncqfyxdglupyaedsy/Build/Intermediates.noindex/adv_cmds.build/Release/colldef.build/DerivedSources/y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  128

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,     2,     2,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    14,    16,    20,    21,    23,
      25,    27,    28,    30,    33,    36,    39,    42,    45,    49,
      50,    52,    54,    56,    61,    64,    70,    74,    76,    78,
      82,    84,    88,    91,    95,    96,    97,   101,   102,   106,
     107,   111,   114,   118,   119,   120,   124,   125,   129,   130,
     134,   135,   137,   141,   143,   145,   147,   149,   152,   155,
     160,   163,   165,   169,   172,   175,   177,   179,   183,   187,
     191,   193,   197,   199,   203,   205,   209,   211,   215,   217,
     219,   223
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      31,     0,    -1,    32,    -1,    33,    -1,    35,    36,    38,
      35,    37,    35,    -1,    34,    -1,    33,    23,    34,    -1,
      -1,    61,    -1,    62,    -1,    63,    -1,    -1,    23,    -1,
      35,    23,    -1,     5,    23,    -1,     6,    23,    -1,    39,
      43,    -1,    40,    23,    -1,    39,    40,    23,    -1,    -1,
      61,    -1,    41,    -1,    42,    -1,     7,    20,     8,    18,
      -1,     9,    20,    -1,    44,    48,    45,    53,    60,    -1,
      15,    46,    23,    -1,    17,    -1,    47,    -1,    46,    24,
      47,    -1,    22,    -1,    47,    25,    22,    -1,    49,    23,
      -1,    48,    49,    23,    -1,    -1,    -1,    20,    50,    58,
      -1,    -1,    10,    51,    58,    -1,    -1,    12,    52,    58,
      -1,    54,    23,    -1,    53,    54,    23,    -1,    -1,    -1,
      20,    55,    58,    -1,    -1,    10,    56,    58,    -1,    -1,
      12,    57,    58,    -1,    -1,    59,    -1,    58,    24,    59,
      -1,    20,    -1,    10,    -1,    11,    -1,    18,    -1,    16,
      23,    -1,    19,    21,    -1,     3,    21,     4,    18,    -1,
      13,    64,    -1,    66,    -1,    64,    24,    66,    -1,    21,
      21,    -1,    65,    21,    -1,    21,    -1,    65,    -1,    21,
      14,    21,    -1,    26,    67,    27,    -1,    28,    69,    29,
      -1,    68,    -1,    67,    24,    68,    -1,    70,    -1,    68,
      25,    70,    -1,    71,    -1,    69,    25,    71,    -1,    21,
      -1,    21,    14,    21,    -1,    65,    -1,    21,    -1,    21,
      14,    21,    -1,    65,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   405,   406,   408,   409,   411,   412,   413,
     414,   416,   417,   418,   420,   429,   431,   433,   434,   436,
     437,   438,   439,   441,   457,   466,   468,   470,   476,   483,
     491,   494,   502,   503,   505,   506,   506,   548,   548,   580,
     580,   598,   599,   601,   602,   602,   717,   717,   749,   749,
     780,   781,   782,   784,   793,   800,   805,   813,   815,   827,
     833,   835,   836,   838,   845,   855,   862,   867,   882,   885,
     889,   892,   896,   897,   899,   900,   902,   909,   925,   930,
     937,   953
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SUBSTITUTE", "WITH", "START_LC_COLLATE",
  "END_LC_COLLATE", "COLLATING_ELEMENT", "FROM", "COLLATING_SYMBOL",
  "ELLIPSIS", "IGNORE", "UNDEFINED", "ORDER", "RANGE", "ORDER_START",
  "ORDER_END", "ORDER_SECOND_PASS", "STRING", "DEFN", "ELEM", "CHAR",
  "ORDER_DIRECTIVE", "'\\n'", "';'", "','", "'{'", "'}'", "'('", "')'",
  "$accept", "collate", "datafile", "statment_list", "statment",
  "blank_lines", "start_localedef", "end_localedef", "localedef_sections",
  "localedef_preface", "localedef_statment", "collating_element",
  "collating_symbol", "localedef_order", "order_start",
  "order_second_pass", "order_start_list", "order_start_list_directives",
  "order_lines1", "order_line1", "@1", "@2", "@3", "order_lines2",
  "order_line2", "@4", "@5", "@6", "weights", "weight", "order_end",
  "charmap", "substitute", "order", "order_list", "chain", "item",
  "mixed_order_list", "mixed_sub_list", "sec_order_list", "mixed_sub_item",
  "sec_sub_item", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    10,    59,    44,   123,   125,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    34,    34,    34,
      34,    35,    35,    35,    36,    37,    38,    39,    39,    40,
      40,    40,    40,    41,    42,    43,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    50,    49,    51,    49,    52,
      49,    53,    53,    54,    55,    54,    56,    54,    57,    54,
      58,    58,    58,    59,    59,    59,    59,    60,    61,    62,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    70,    70,    70,    71,
      71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     6,     1,     3,     0,     1,     1,
       1,     0,     1,     2,     2,     2,     2,     2,     3,     0,
       1,     1,     1,     4,     2,     5,     3,     1,     1,     3,
       1,     3,     2,     3,     0,     0,     3,     0,     3,     0,
       3,     2,     3,     0,     0,     3,     0,     3,     0,     3,
       0,     1,     3,     1,     1,     1,     1,     2,     2,     4,
       2,     1,     3,     2,     2,     1,     1,     3,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,     0,    12,     0,     2,     3,     5,     0,
       8,     9,    10,     0,    65,     0,     0,    60,    66,    61,
      58,     1,     7,     0,    13,    19,     0,     0,    63,    76,
      78,     0,    70,    72,    79,    81,     0,    74,     0,    64,
       6,    14,     0,     0,    11,    19,     0,    21,    22,    20,
      59,    67,     0,     0,    68,     0,     0,     0,    69,    62,
       0,    24,     0,     0,     0,    16,    34,    17,    77,    71,
      73,    80,    75,     0,     0,    11,    30,     0,    28,    18,
      37,    39,    35,    34,     0,    23,    15,     4,    26,     0,
       0,    50,    50,    50,    27,    43,     0,    32,    29,    31,
      54,    55,    56,    53,    38,    51,    40,    36,    46,    48,
      44,    43,     0,    33,     0,    50,    50,    50,     0,     0,
      25,    41,    52,    47,    49,    45,    57,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    25,    75,    44,    45,
      46,    47,    48,    65,    66,    95,    77,    78,    83,    84,
      93,    91,    92,   111,   112,   117,   115,   116,   104,   105,
     120,    10,    11,    12,    17,    30,    19,    31,    32,    36,
      33,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const yytype_int8 yypact[] =
{
       5,     9,    -9,    13,   -91,    20,   -91,    15,   -91,    -1,
     -91,   -91,   -91,    58,    45,    46,    50,    52,    53,   -91,
     -91,   -91,     2,    54,   -91,    28,    55,    57,   -91,    49,
      53,   -11,    56,   -91,    51,    53,   -18,   -91,    -9,   -91,
     -91,   -91,    59,    60,    61,    24,    62,   -91,   -91,   -91,
     -91,   -91,    65,    46,   -91,    46,    66,    50,   -91,   -91,
      67,   -91,     0,    47,    68,   -91,    44,   -91,   -91,    56,
     -91,   -91,   -91,    64,    69,    61,   -91,    22,    63,   -91,
     -91,   -91,   -91,    32,    70,   -91,   -91,    71,   -91,    47,
      73,    30,    30,    30,   -91,    48,    74,   -91,    63,   -91,
     -91,   -91,   -91,   -91,    72,   -91,    72,    72,   -91,   -91,
     -91,    41,    75,   -91,    30,    30,    30,    30,    76,    77,
     -91,   -91,   -91,    72,    72,    72,   -91,   -91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   -91,   -91,    79,   -43,   -91,   -91,   -91,   -91,
      38,   -91,   -91,   -91,   -91,   -91,   -91,     1,   -91,     6,
     -91,   -91,   -91,   -91,    -8,   -91,   -91,   -91,   -90,   -12,
     -91,   -16,   -91,   -91,   -91,    -2,    78,   -91,    80,   -91,
      81,    82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -12
static const yytype_int8 yytable[] =
{
      18,    62,   106,   107,    23,     1,    74,    57,     1,    49,
     -11,    58,    14,    53,    35,     2,    54,    15,     2,    16,
      21,     3,    24,    24,     3,   123,   124,   125,     4,    49,
      13,    42,    87,    43,    20,    42,    18,    43,    22,    63,
     100,   101,    80,     3,    81,    88,    89,     3,   102,    94,
     103,   108,    82,   109,    80,    35,    81,   118,   108,    27,
     109,   110,    26,    52,    82,    56,    28,    29,   110,    76,
      28,    34,    28,    50,    39,    73,    38,    41,    51,    60,
      61,    55,    85,    64,     4,    67,    68,    71,    90,    96,
      98,    79,    86,    97,    24,    99,   114,   113,   121,   126,
     127,    40,   122,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,    70,     0,     0,    72
};

static const yytype_int8 yycheck[] =
{
       2,    44,    92,    93,     5,     3,     6,    25,     3,    25,
       5,    29,    21,    24,    16,    13,    27,    26,    13,    28,
       0,    19,    23,    23,    19,   115,   116,   117,    23,    45,
      21,     7,    75,     9,    21,     7,    38,     9,    23,    15,
      10,    11,    10,    19,    12,    23,    24,    19,    18,    17,
      20,    10,    20,    12,    10,    57,    12,    16,    10,    14,
      12,    20,     4,    14,    20,    14,    21,    21,    20,    22,
      21,    21,    21,    18,    21,     8,    24,    23,    21,    20,
      20,    25,    18,    45,    23,    23,    21,    21,    25,    83,
      89,    23,    23,    23,    23,    22,    24,    23,    23,    23,
      23,    22,   114,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    55,    -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    13,    19,    23,    31,    32,    33,    34,    35,
      61,    62,    63,    21,    21,    26,    28,    64,    65,    66,
      21,     0,    23,     5,    23,    36,     4,    14,    21,    21,
      65,    67,    68,    70,    21,    65,    69,    71,    24,    21,
      34,    23,     7,     9,    38,    39,    40,    41,    42,    61,
      18,    21,    14,    24,    27,    25,    14,    25,    29,    66,
      20,    20,    35,    15,    40,    43,    44,    23,    21,    68,
      70,    21,    71,     8,     6,    37,    22,    46,    47,    23,
      10,    12,    20,    48,    49,    18,    23,    35,    23,    24,
      25,    51,    52,    50,    17,    45,    49,    23,    47,    22,
      10,    11,    18,    20,    58,    59,    58,    58,    10,    12,
      20,    53,    54,    23,    24,    56,    57,    55,    16,    54,
      60,    23,    59,    58,    58,    58,    23,    23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 137 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	FILE *fp;
	int localedef = (stringdb != NULL);
	int z;

	if (nchain > 0) {
		DBT key, val;
		struct __collate_st_chain_pri *t, *v;
		wchar_t *wp, *tp;
		int flags, i, len;

		if ((__collate_chain_pri_table = (struct __collate_st_chain_pri *)malloc(nchain * sizeof(struct __collate_st_chain_pri))) == NULL)
			err(1, "chain malloc");
		flags = R_FIRST;
		t = __collate_chain_pri_table;
		for(i = 0; i < nchain; i++) {
			if (chaindb->seq(chaindb, &key, &val, flags) != 0)
				err(1, "Can't retrieve chaindb %d", i);
			memcpy(&v, val.data, sizeof(struct __collate_st_chain_pri *));
			*t++ = *v;
			if ((len = __collate_wcsnlen(v->str, STR_LEN)) > info.chain_max_len)
				info.chain_max_len = len;
			flags = R_NEXT;
		}
		if (chaindb->seq(chaindb, &key, &val, flags) == 0)
			err(1, "More in chaindb after retrieving %d", nchain);
		qsort(__collate_chain_pri_table, nchain, sizeof(struct __collate_st_chain_pri), chainpricompar);
	}
	for(z = 0; z < directive_count; z++) {
		if (nsubst[z] > 0) {
			DBT key, val;
			struct __collate_st_subst *t;
			wchar_t *wp, *tp;
			int flags, i, j;
			int32_t cval;

			if ((__collate_substitute_table[z] = (struct __collate_st_subst *)calloc(nsubst[z], sizeof(struct __collate_st_subst))) == NULL)
				err(1, "__collate_substitute_table[%d] calloc", z);
			flags = R_FIRST;
			t = __collate_substitute_table[z];
			for(i = 0; i < nsubst[z]; i++) {
				if (substdb[z]->seq(substdb[z], &key, &val, flags) != 0)
					err(1, "Can't retrieve substdb[%d]", z);
				memcpy(&cval, key.data, sizeof(int32_t));
				/* we don't set the byte order of t->val, since we
				 * need it for sorting */
				t->val = cval;
				for(wp = (wchar_t *)val.data, tp = t->str, j = STR_LEN; *wp && j-- > 0;)
					*tp++ = htonl(*wp++);
				t++;
				flags = R_NEXT;
			}
			if (substdb[z]->seq(substdb[z], &key, &val, flags) == 0)
				err(1, "More in substdb[%d] after retrieving %d", z, nsubst[z]);
			qsort(__collate_substitute_table[z], nsubst[z], sizeof(struct __collate_st_subst), substcompar);
		}
	}
	if (nlargemap > 0) {
		DBT key, val;
		struct __collate_st_large_char_pri *t;
		struct __collate_st_char_pri *p;
		int flags, i, z;
		int32_t cval;

		if ((__collate_large_char_pri_table = (struct __collate_st_large_char_pri *)malloc(nlargemap * sizeof(struct __collate_st_large_char_pri))) == NULL)
			err(1, "nlargemap malloc");
		flags = R_FIRST;
		t = __collate_large_char_pri_table;
		for(i = 0; i < nlargemap; i++) {
			if (largemapdb->seq(largemapdb, &key, &val, flags) != 0)
				err(1, "Can't retrieve largemapdb %d", i);
			memcpy(&cval, key.data, sizeof(int32_t));
			memcpy(&p, val.data, sizeof(struct __collate_st_char_pri *));
			/* we don't set the byte order of t->val, since we
			 * need it for sorting */
			t->val = cval;
			for(z = 0; z < directive_count; z++)
				t->pri.pri[z] = htonl(p->pri[z]);
			t++;
			flags = R_NEXT;
		}
		if (largemapdb->seq(largemapdb, &key, &val, flags) == 0)
			err(1, "More in largemapdb after retrieving %d", nlargemap);
		qsort(__collate_large_char_pri_table, nlargemap, sizeof(struct __collate_st_large_char_pri), charpricompar);
	}

	if (info.undef_pri[0] == PRI_UNDEFINED) {
		int i;
		info.undef_pri[0] = prim_pri;
		for(i = 1; i < directive_count; i++)
			info.undef_pri[i] = -prim_pri;
	}

	if (localedef) {
		int ch, z, ret;
		if (sym_undefined.val == PRI_UNDEFINED) {
			int flags = R_FIRST;
			DBT key, val;
			struct symbol *v;
			while((ret = charmapdb->seq(charmapdb, &key, &val, flags)) == 0) {
				memcpy(&v, val.data, sizeof(struct symbol *));
				switch(v->type) {
				case SYMBOL_CHAR: {
					struct __collate_st_char_pri *p = haspri(v->u.wc);
					if (!p || p->pri[0] == PRI_UNDEFINED)
						warnx("<%s> was not defined", showwcs((const wchar_t *)key.data, key.size / sizeof(wchar_t)));
					break;
				}
				case SYMBOL_CHAIN: {
					struct __collate_st_chain_pri *p = getchain(v->u.str, EXISTS);
					if (p->pri[0] == PRI_UNDEFINED)
						warnx("<%s> was not defined", showwcs((const wchar_t *)key.data, key.size / sizeof(wchar_t)));
					break;
				}
				}
				flags = R_NEXT;
			}
			if (ret < 0)
				err(1, "Error retrieving from charmapdb");
		}
		for (ch = 1; ch < UCHAR_MAX + 1; ch++) {
			for(z = 0; z < directive_count; z++)
				if (__collate_char_pri_table[ch].pri[z] == PRI_UNDEFINED)
					__collate_char_pri_table[ch].pri[z] = (info.undef_pri[z] >= 0) ? info.undef_pri[z] : (ch - info.undef_pri[z]);
		}
		for (ch = 0; ch < nlargemap; ch++) {
			for(z = 0; z < directive_count; z++)
				if (__collate_large_char_pri_table[ch].pri.pri[z] == PRI_UNDEFINED)
					__collate_large_char_pri_table[ch].pri.pri[z] = (info.undef_pri[z] >= 0) ? info.undef_pri[z] : (__collate_large_char_pri_table[ch].val - info.undef_pri[z]);
		}
	} else {
		int ch, substed, ordered;
		int fatal = 0;
		for (ch = 1; ch < UCHAR_MAX + 1; ch++) {
			substed = hassubst(ch, 0);
			ordered = (__collate_char_pri_table[ch].pri[0] != PRI_UNDEFINED);
			if (!ordered && !substed) {
				fatal = 1;
				warnx("%s not found", charname(ch));
			}
			if (substed && ordered) {
				fatal = 1;
				warnx("%s can't be ordered since substituted", charname(ch));
			}
		}
		if (fatal)
			exit(1);
	}

	/* COLLATE_SUBST_DUP depends on COLL_WEIGHTS_MAX == 2 */
	if (localedef) {
		if (nsubst[0] == nsubst[1] && (nsubst[0] == 0 ||
		    memcmp(__collate_substitute_table[0], __collate_substitute_table[1], nsubst[0] * sizeof(struct __collate_st_subst)) == 0)) {
			info.flags |= COLLATE_SUBST_DUP;
			nsubst[1] = 0;
		}
	} else {
		info.flags |= COLLATE_SUBST_DUP;
		nsubst[1] = 0;
	}

	for(z = 0; z < directive_count; z++)
		info.subst_count[z] = nsubst[z];

	info.directive_count = directive_count;
	info.chain_count = nchain;
	info.large_pri_count = nlargemap;

	if ((fp = fopen(out_file, "w")) == NULL)
		err(EX_UNAVAILABLE, "can't open destination file %s",
		    out_file);

	strcpy(__collate_version, COLLATE_VERSION1_1A);
	if (fwrite(__collate_version, sizeof(__collate_version), 1, fp) != 1)
		err(EX_IOERR,
		"IO error writting collate version to destination file %s",
		    out_file);
#if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
	for(z = 0; z < directive_count; z++) {
		info.undef_pri[z] = htonl(info.undef_pri[z]);
		info.subst_count[z] = htonl(info.subst_count[z]);
	}
	info.chain_count = htonl(info.chain_count);
	info.large_pri_count = htonl(info.large_pri_count);
#endif /* __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN */
	if (fwrite(&info, sizeof(info), 1, fp) != 1)
		err(EX_IOERR,
		"IO error writting collate info to destination file %s",
		    out_file);
#if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
	{
		int i, z;
		struct __collate_st_char_pri *p = __collate_char_pri_table;

		for(i = UCHAR_MAX + 1; i-- > 0; p++) {
			for(z = 0; z < directive_count; z++)
				p->pri[z] = htonl(p->pri[z]);
		}
	}
#endif /* __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN */
	if (fwrite(__collate_char_pri_table,
		   sizeof(__collate_char_pri_table), 1, fp) != 1)
		err(EX_IOERR,
		"IO error writting char table to destination file %s",
		    out_file);
	for(z = 0; z < directive_count; z++) {
		if (nsubst[z] > 0) {
#if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
			struct __collate_st_subst *t = __collate_substitute_table[z];
			int i;
			for(i = nsubst[z]; i > 0; i--) {
				t->val = htonl(t->val);
				t++;
			}
#endif /* __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN */
			if (fwrite(__collate_substitute_table[z], sizeof(struct __collate_st_subst), nsubst[z], fp) != nsubst[z])
				err(EX_IOERR,
				"IO error writting large substprim table %d to destination file %s",
				    z, out_file);
		}
	}
	if (nchain > 0) {
#if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
		int i, j, z;
		struct __collate_st_chain_pri *p = __collate_chain_pri_table;
		wchar_t *w;

		for(i = nchain; i-- > 0; p++) {
			for(j = STR_LEN, w = p->str; *w && j-- > 0; w++)
				*w = htonl(*w);
			for(z = 0; z < directive_count; z++)
				p->pri[z] = htonl(p->pri[z]);
		}
#endif /* __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN */
		if (fwrite(__collate_chain_pri_table,
			   sizeof(*__collate_chain_pri_table), nchain, fp) !=
			   (size_t)nchain)
			err(EX_IOERR,
			"IO error writting chain table to destination file %s",
			    out_file);
	}

	if (nlargemap > 0) {
#if __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN
		struct __collate_st_large_char_pri *t = __collate_large_char_pri_table;
		int i;
		for(i = 0; i < nlargemap; i++) {
			t->val = htonl(t->val);
			t++;
		}
#endif /* __DARWIN_BYTE_ORDER == __DARWIN_LITTLE_ENDIAN */
		if (fwrite(__collate_large_char_pri_table, sizeof(struct __collate_st_large_char_pri), nlargemap, fp) != nlargemap)
			err(EX_IOERR,
			"IO error writting large pri tables to destination file %s",
			    out_file);
	}

	if (fclose(fp) != 0)
		err(EX_IOERR, "IO error closing destination file %s",
		    out_file);

#ifdef COLLATE_DEBUG
	if (debug)
		collate_print_tables();
#endif
	exit(EX_OK);
}
    break;

  case 14:
#line 420 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	int i;
	if ((stringdb = dbopen(NULL, O_CREAT | O_RDWR, 0600, DB_HASH, NULL)) == NULL)
		err(1, "dbopen stringdb");
	directive_count = 0;
	for(i = 0; i < COLL_WEIGHTS_MAX; i++)
		info.directive[i] = DIRECTIVE_UNDEF;
}
    break;

  case 23:
#line 441 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	int len;
	struct symbol *s;
	if (wcslen((yyvsp[(2) - (4)].str)) > CHARMAP_SYMBOL_LEN)
		yyerror("collating-element symbol name '%s' is too long", showwcs((yyvsp[(2) - (4)].str), CHARMAP_SYMBOL_LEN));
	if ((len = wcslen((yyvsp[(4) - (4)].str))) > STR_LEN)
		yyerror("collating-element string '%s' is too long", showwcs((yyvsp[(4) - (4)].str), STR_LEN));
	if (len < 2)
		yyerror("collating-element string '%s' must be at least two characters", showwcs((yyvsp[(4) - (4)].str), STR_LEN));
	s = getsymbol((yyvsp[(2) - (4)].str), NOTEXISTS);
	s->val = PRI_UNDEFINED;
	s->type = SYMBOL_CHAIN;
	wcsncpy(s->u.str, (yyvsp[(4) - (4)].str), STR_LEN);
	getchain((yyvsp[(4) - (4)].str), NOTEXISTS);
}
    break;

  case 24:
#line 457 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	struct symbol *s;
	if (wcslen((yyvsp[(2) - (2)].str)) > CHARMAP_SYMBOL_LEN)
		yyerror("collating-element symbol name '%s' is too long", showwcs((yyvsp[(2) - (2)].str), CHARMAP_SYMBOL_LEN));
	s = getsymbol((yyvsp[(2) - (2)].str), NOTEXISTS);
	s->val = PRI_UNDEFINED;
	s->type = SYMBOL_SYMBOL;
}
    break;

  case 27:
#line 470 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	prev_line = LINE_NONE;
	prev_elem = NULL;
	order_pass++;
}
    break;

  case 28:
#line 476 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	if (directive_count > 0)
		yyerror("Multiple order_start lines not allowed");
	if ((info.directive[0] & DIRECTIVE_DIRECTION_MASK) == 0)
		info.directive[0] |= DIRECTIVE_FORWARD;
	directive_count++;
}
    break;

  case 29:
#line 483 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	if (directive_count >= COLL_WEIGHTS_MAX)
		yyerror("only COLL_WEIGHTS_MAX weights allowed");
	if ((info.directive[directive_count] & DIRECTIVE_DIRECTION_MASK) == 0)
		info.directive[directive_count] |= DIRECTIVE_FORWARD;
	directive_count++;
}
    break;

  case 30:
#line 491 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	info.directive[directive_count] = (yyvsp[(1) - (1)].ch);
}
    break;

  case 31:
#line 494 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	int direction = ((yyvsp[(3) - (3)].ch) & DIRECTIVE_DIRECTION_MASK);
	int prev = (info.directive[directive_count] & DIRECTIVE_DIRECTION_MASK);
	if (direction && prev && direction != prev)
		yyerror("The forward and backward directives are mutually exclusive");
	info.directive[directive_count] |= (yyvsp[(3) - (3)].ch);
}
    break;

  case 35:
#line 506 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	struct symbol *s = getsymbol((yyvsp[(1) - (1)].str), EXISTS);
	if (s->val != PRI_UNDEFINED)
		yyerror("<%s> redefined", showwcs((yyvsp[(1) - (1)].str), CHARMAP_SYMBOL_LEN));
	if (prev_line == LINE_ELLIPSIS) {
		struct symbol *m;
		wchar_t i;
		int v;
		switch (s->type) {
		case SYMBOL_CHAIN:
			yyerror("Chain <%s> can't be endpoints of ellipsis", showwcs((yyvsp[(1) - (1)].str), CHARMAP_SYMBOL_LEN));
		case SYMBOL_SYMBOL:
			yyerror("Collating symbol <%s> can't be endpoints of ellipsis", showwcs((yyvsp[(1) - (1)].str), CHARMAP_SYMBOL_LEN));
		}
		if (s->u.wc <= prev_elem->u.wc)
			yyerror("<%s> is before starting point of ellipsis", showwcs((yyvsp[(1) - (1)].str), CHARMAP_SYMBOL_LEN));
		for(i = prev_elem->u.wc + 1, v = prev_elem->val + 1; i < s->u.wc; i++, v++) {
			m = getsymbolbychar(i);
			if (m->val != PRI_UNDEFINED)
				yyerror("<%s> was previously defined while filling ellipsis symbols", showwcs(m->name, CHARMAP_SYMBOL_LEN));
			m->val = v;
		}
		s->val = v;
	} else
		s->val = prim_pri;
	prim_pri = s->val + 1;
	weight_index = 0;
}
    break;

  case 36:
#line 533 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	int i;
	struct symbol *s = getsymbol((yyvsp[(1) - (3)].str), EXISTS);
	if (s->type == SYMBOL_SYMBOL) {
		if (weight_index != 0)
			yyerror("Can't specify weights for collating symbol <%s>", showwcs((yyvsp[(1) - (3)].str), CHARMAP_SYMBOL_LEN));
	} else if (weight_index == 0) {
		for(i = 0; i < directive_count; i++)
			weight_table[i] = s;
	} else if (weight_index != directive_count)
		yyerror("Not enough weights specified");
	memcpy(prev_weight_table, weight_table, sizeof(weight_table));
	prev_line = LINE_NORMAL;
	prev_elem = s;
}
    break;

  case 37:
#line 548 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    { weight_index = 0; allow_ellipsis = 1; }
    break;

  case 38:
#line 548 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	int i;
	if (prev_line == LINE_ELLIPSIS)
		yyerror("Illegal sequential ellipsis lines");
	if (prev_line == LINE_UNDEFINED)
		yyerror("Ellipsis line can not follow UNDEFINED line");
	if (prev_line == LINE_NONE)
		yyerror("Ellipsis line must follow a collating identifier lines");
	if (weight_index == 0) {
		for(i = 0; i < directive_count; i++)
			weight_table[i] = &sym_ellipsis;
	} else if (weight_index != directive_count)
		yyerror("Not enough weights specified");
	for(i = 0; i < directive_count; i++) {
		if (weight_table[i]->type != SYMBOL_ELLIPSIS)
			continue;
		switch (prev_weight_table[i]->type) {
		case SYMBOL_CHAIN:
			yyerror("Startpoint of ellipsis can't be a collating element");
		case SYMBOL_IGNORE:
			yyerror("Startpoint of ellipsis can't be IGNORE");
		case SYMBOL_SYMBOL:
			yyerror("Startpoint of ellipsis can't be a collating symbol");
		case SYMBOL_STRING:
			yyerror("Startpoint of ellipsis can't be a string");
		}
	}
	memcpy(prev2_weight_table, prev_weight_table, sizeof(prev_weight_table));
	memcpy(prev_weight_table, weight_table, sizeof(weight_table));
	prev_line = LINE_ELLIPSIS;
	allow_ellipsis = 0;
}
    break;

  case 39:
#line 580 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	if (sym_undefined.val != PRI_UNDEFINED)
		yyerror("Multiple UNDEFINED lines not allowed");
	sym_undefined.val = prim_pri++;
	weight_index = 0;
	allow_ellipsis = 1;
}
    break;

  case 40:
#line 586 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	int i;
	if (weight_index == 0) {
		weight_table[0] = &sym_undefined;
		for(i = 1; i < directive_count; i++)
			weight_table[i] = &sym_ellipsis;
	} else if (weight_index != directive_count)
		yyerror("Not enough weights specified");
	memcpy(prev_weight_table, weight_table, sizeof(weight_table));
	prev_line = LINE_UNDEFINED;
}
    break;

  case 44:
#line 602 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    { weight_index = 0; }
    break;

  case 45:
#line 602 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	int i;
	struct symbol *s = getsymbol((yyvsp[(1) - (3)].str), EXISTS);
	if (s->val == PRI_UNDEFINED)
		yyerror("<%s> undefined", showwcs((yyvsp[(1) - (3)].str), CHARMAP_SYMBOL_LEN));
	if (s->type == SYMBOL_SYMBOL) {
		if (weight_index != 0)
			yyerror("Can't specify weights for collating symbol <%s>", showwcs((yyvsp[(1) - (3)].str), CHARMAP_SYMBOL_LEN));
	} else if (weight_index == 0) {
		for(i = 0; i < directive_count; i++)
			weight_table[i] = s;
	} else if (weight_index != directive_count)
		yyerror("Not enough weights specified");
	if (prev_line == LINE_ELLIPSIS) {
		int w, x;
		for(i = 0; i < directive_count; i++) {
			switch (prev_weight_table[i]->type) {
			case SYMBOL_CHAR:
			case SYMBOL_CHAIN:
			case SYMBOL_IGNORE:
			case SYMBOL_SYMBOL:
				for (w = prev_elem->u.wc + 1; w < s->u.wc; w++) {
					struct __collate_st_char_pri *p = getpri(w);
					if (p->pri[i] != PRI_UNDEFINED)
						yyerror("Char 0x02x previously defined", w);
					p->pri[i] = prev_weight_table[i]->val;
				}
				break;
			case SYMBOL_ELLIPSIS:

				switch (weight_table[i]->type) {
				case SYMBOL_STRING:
					yyerror("Strings can't be endpoints of ellipsis");
				case SYMBOL_CHAIN:
					yyerror("Chains can't be endpoints of ellipsis");
				case SYMBOL_IGNORE:
					yyerror("IGNORE can't be endpoints of ellipsis");
				case SYMBOL_SYMBOL:
					yyerror("Collation symbols can't be endpoints of ellipsis");
				}
				if (s->val - prev_elem->val != weight_table[i]->val - prev2_weight_table[i]->val)
					yyerror("Range mismatch in weight %d", i);
				x = prev2_weight_table[i]->val + 1;
				for (w = prev_elem->u.wc + 1; w < s->u.wc; w++) {
					struct __collate_st_char_pri *p = getpri(w);
					if (p->pri[i] != PRI_UNDEFINED)
						yyerror("Char 0x02x previously defined", w);
					p->pri[i] = x++;
				}
				break;
			case SYMBOL_STRING:
				for (w = prev_elem->u.wc + 1; w < s->u.wc; w++) {
					struct __collate_st_char_pri *p = getpri(w);
					if (p->pri[i] != PRI_UNDEFINED)
						yyerror("Char 0x02x previously defined", w);
					putsubst(w, i, prev_weight_table[i]->u.str);
					p->pri[i] = prev_weight_table[i]->val;
				}
				break;
			}
		}
	}
	switch(s->type) {
	case SYMBOL_CHAR: {
		struct __collate_st_char_pri *p = getpri(s->u.wc);
		for(i = 0; i < directive_count; i++) {
			switch (weight_table[i]->type) {
			case SYMBOL_CHAR:
			case SYMBOL_CHAIN:
			case SYMBOL_IGNORE:
			case SYMBOL_SYMBOL:
				if (p->pri[i] != PRI_UNDEFINED)
					yyerror("Char 0x02x previously defined", s->u.wc);
				p->pri[i] = weight_table[i]->val;
				break;
			case SYMBOL_STRING:
				if (p->pri[i] != PRI_UNDEFINED)
					yyerror("Char 0x02x previously defined", s->u.wc);
				putsubst(s->u.wc, i, weight_table[i]->u.str);
				p->pri[i] = weight_table[i]->val;
				break;
			}
		}
		break;
	}
	case SYMBOL_CHAIN: {
		struct __collate_st_chain_pri *p = getchain(s->u.str, EXISTS);
		for(i = 0; i < directive_count; i++) {
			switch (weight_table[i]->type) {
			case SYMBOL_CHAR:
			case SYMBOL_CHAIN:
			case SYMBOL_IGNORE:
			case SYMBOL_SYMBOL:
				if (p->pri[i] != PRI_UNDEFINED)
					yyerror("Chain %s previously defined", showwcs(s->u.str, STR_LEN));
				p->pri[i] = weight_table[i]->val;
				break;
			case SYMBOL_STRING :
				if (wcsncmp(s->u.str, weight_table[i]->u.str, STR_LEN) != 0)
					yyerror("Chain/string mismatch");
				if (p->pri[i] != PRI_UNDEFINED)
					yyerror("Chain %s previously defined", showwcs(s->u.str, STR_LEN));
				/* negative value mean don't substitute
				 * the chain, but it is in an
				 * equivalence class */
				p->pri[i] = -weight_table[i]->val;
			}
		}
		break;
	}
	}
	memcpy(prev_weight_table, weight_table, sizeof(weight_table));
	prev_line = LINE_NORMAL;
	prev_elem = s;
}
    break;

  case 46:
#line 717 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    { weight_index = 0; allow_ellipsis = 1; }
    break;

  case 47:
#line 717 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	int i;
	if (prev_line == LINE_ELLIPSIS)
		yyerror("Illegal sequential ellipsis lines");
	if (prev_line == LINE_UNDEFINED)
		yyerror("Ellipsis line can not follow UNDEFINED line");
	if (prev_line == LINE_NONE)
		yyerror("Ellipsis line must follow a collating identifier lines");
	if (weight_index == 0) {
		for(i = 0; i < directive_count; i++)
			weight_table[i] = &sym_ellipsis;
	} else if (weight_index != directive_count)
		yyerror("Not enough weights specified");
	for(i = 0; i < directive_count; i++) {
		if (weight_table[i]->type != SYMBOL_ELLIPSIS)
			continue;
		switch (prev_weight_table[i]->type) {
		case SYMBOL_CHAIN:
			yyerror("Startpoint of ellipsis can't be a collating element");
		case SYMBOL_IGNORE:
			yyerror("Startpoint of ellipsis can't be IGNORE");
		case SYMBOL_SYMBOL:
			yyerror("Startpoint of ellipsis can't be a collating symbol");
		case SYMBOL_STRING:
			yyerror("Startpoint of ellipsis can't be a string");
		}
	}
	memcpy(prev2_weight_table, prev_weight_table, sizeof(prev_weight_table));
	memcpy(prev_weight_table, weight_table, sizeof(weight_table));
	prev_line = LINE_ELLIPSIS;
	allow_ellipsis = 0;
}
    break;

  case 48:
#line 749 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    { weight_index = 0; allow_ellipsis = 1; }
    break;

  case 49:
#line 749 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	int i;

	if (weight_index == 0) {
		weight_table[0] = &sym_undefined;
		for(i = 1; i < directive_count; i++)
			weight_table[i] = &sym_ellipsis;
	} else if (weight_index != directive_count)
		yyerror("Not enough weights specified");
	for(i = 0; i < directive_count; i++) {
		switch (weight_table[i]->type) {
		case SYMBOL_CHAR:
		case SYMBOL_CHAIN:
		case SYMBOL_IGNORE:
		case SYMBOL_SYMBOL:
			info.undef_pri[i] = weight_table[i]->val;
			break;
		case SYMBOL_ELLIPSIS :
			/* Negative values mean that the priority is
			 * relative to the lexical value */
			info.undef_pri[i] = -sym_undefined.val;
			prim_pri = UNDEFINED_PRI;
			break;
		case SYMBOL_STRING :
			yyerror("Strings can't be used with UNDEFINED");
		}
	}
	memcpy(prev_weight_table, weight_table, sizeof(weight_table));
	prev_line = LINE_UNDEFINED;
}
    break;

  case 53:
#line 784 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	struct symbol *s;
	if (weight_index >= directive_count)
		yyerror("More weights than specified by order_start");
	s = getsymbol((yyvsp[(1) - (1)].str), EXISTS);
	if (order_pass && s->val == PRI_UNDEFINED)
		yyerror("<%s> is undefined", showwcs((yyvsp[(1) - (1)].str), CHARMAP_SYMBOL_LEN));
	weight_table[weight_index++] = s;
}
    break;

  case 54:
#line 793 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	if (weight_index >= directive_count)
		yyerror("More weights than specified by order_start");
	if (!allow_ellipsis)
		yyerror("Ellipsis weight not allowed");
	weight_table[weight_index++] = &sym_ellipsis;
}
    break;

  case 55:
#line 800 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	if (weight_index >= directive_count)
		yyerror("More weights than specified by order_start");
	weight_table[weight_index++] = &sym_ignore;
}
    break;

  case 56:
#line 805 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	if (weight_index >= directive_count)
		yyerror("More weights than specified by order_start");
	if (wcslen((yyvsp[(1) - (1)].str)) > STR_LEN)
		yyerror("String '%s' is too long", showwcs((yyvsp[(1) - (1)].str), STR_LEN));
	weight_table[weight_index++] = getstring((yyvsp[(1) - (1)].str));
}
    break;

  case 58:
#line 815 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	int len = wcslen((yyvsp[(1) - (2)].str));
	struct symbol *s;
	if (len > CHARMAP_SYMBOL_LEN)
		yyerror("Charmap symbol name '%s' is too long", showwcs((yyvsp[(1) - (2)].str), CHARMAP_SYMBOL_LEN));
	s = getsymbol((yyvsp[(1) - (2)].str), NOTEXISTS);
	s->type = SYMBOL_CHAR;
	s->val = PRI_UNDEFINED;
	s->u.wc = (yyvsp[(2) - (2)].ch);
	setsymbolbychar(s);
}
    break;

  case 59:
#line 827 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	if (wcslen((yyvsp[(4) - (4)].str)) + 1 > STR_LEN)
		yyerror("%s substitution is too long", charname((yyvsp[(2) - (4)].ch)));
	putsubst((yyvsp[(2) - (4)].ch), 0, (yyvsp[(4) - (4)].str));
}
    break;

  case 63:
#line 838 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	curr_chain[0] = (yyvsp[(1) - (2)].ch);
	curr_chain[1] = (yyvsp[(2) - (2)].ch);
	if (curr_chain[0] == '\0' || curr_chain[1] == '\0')
		yyerror("\\0 can't be chained");
	curr_chain[2] = '\0';
}
    break;

  case 64:
#line 845 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	static wchar_t tb[2];
	tb[0] = (yyvsp[(2) - (2)].ch);
	if (tb[0] == '\0')
		yyerror("\\0 can't be chained");
	if (wcslen(curr_chain) + 1 > STR_LEN)
		yyerror("Chain '%s' grows too long", curr_chain);
	(void)wcscat(curr_chain, tb);
}
    break;

  case 65:
#line 855 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	struct __collate_st_char_pri *p = getpri((yyvsp[(1) - (1)].ch));
	if (p->pri[0] >= 0)
		yyerror("%s duplicated", charname((yyvsp[(1) - (1)].ch)));
	p->pri[0] = p->pri[1] = prim_pri;
	sec_pri = ++prim_pri;
}
    break;

  case 66:
#line 862 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	struct __collate_st_chain_pri *c = getchain(curr_chain, NOTEXISTS);
	c->pri[0] = c->pri[1] = prim_pri;
	sec_pri = ++prim_pri;
}
    break;

  case 67:
#line 867 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	u_int i;
	struct __collate_st_char_pri *p;

	if ((yyvsp[(3) - (3)].ch) <= (yyvsp[(1) - (3)].ch))
		yyerror("Illegal range %s -- %s", charname((yyvsp[(1) - (3)].ch)), charname2((yyvsp[(3) - (3)].ch)));

	for (i = (yyvsp[(1) - (3)].ch); i <= (yyvsp[(3) - (3)].ch); i++) {
		p = getpri(i);
		if (p->pri[0] >= 0)
			yyerror("%s duplicated", charname(i));
		p->pri[0] = p->pri[1] = prim_pri++;
	}
	sec_pri = prim_pri;
}
    break;

  case 68:
#line 882 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	prim_pri = sec_pri;
}
    break;

  case 69:
#line 885 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	prim_pri = sec_pri;
}
    break;

  case 70:
#line 889 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	sec_pri++;
}
    break;

  case 71:
#line 892 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	sec_pri++;
}
    break;

  case 76:
#line 902 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	struct __collate_st_char_pri *p = getpri((yyvsp[(1) - (1)].ch));
	if (p->pri[0] >= 0)
		yyerror("%s duplicated", charname((yyvsp[(1) - (1)].ch)));
	p->pri[0] = prim_pri;
	p->pri[1] = sec_pri;
}
    break;

  case 77:
#line 909 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	u_int i;
	struct __collate_st_char_pri *p;

	if ((yyvsp[(3) - (3)].ch) <= (yyvsp[(1) - (3)].ch))
		yyerror("Illegal range %s -- %s",
			charname((yyvsp[(1) - (3)].ch)), charname2((yyvsp[(3) - (3)].ch)));

	for (i = (yyvsp[(1) - (3)].ch); i <= (yyvsp[(3) - (3)].ch); i++) {
		p = getpri(i);
		if (p->pri[0] >= 0)
			yyerror("%s duplicated", charname(i));
		p->pri[0] = prim_pri;
		p->pri[1] = sec_pri;
	}
}
    break;

  case 78:
#line 925 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	struct __collate_st_chain_pri *c = getchain(curr_chain, NOTEXISTS);
	c->pri[0] = prim_pri;
	c->pri[1] = sec_pri;
}
    break;

  case 79:
#line 930 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	struct __collate_st_char_pri *p = getpri((yyvsp[(1) - (1)].ch));
	if (p->pri[0] >= 0)
		yyerror("%s duplicated", charname((yyvsp[(1) - (1)].ch)));
	p->pri[0] = prim_pri;
	p->pri[1] = sec_pri++;
}
    break;

  case 80:
#line 937 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	u_int i;
	struct __collate_st_char_pri *p;

	if ((yyvsp[(3) - (3)].ch) <= (yyvsp[(1) - (3)].ch))
		yyerror("Illegal range %s -- %s",
			charname((yyvsp[(1) - (3)].ch)), charname2((yyvsp[(3) - (3)].ch)));

	for (i = (yyvsp[(1) - (3)].ch); i <= (yyvsp[(3) - (3)].ch); i++) {
		p = getpri(i);
		if (p->pri[0] >= 0)
			yyerror("%s duplicated", charname(i));
		p->pri[0] = prim_pri;
		p->pri[1] = sec_pri++;
	}
}
    break;

  case 81:
#line 953 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
    {
	struct __collate_st_chain_pri *c = getchain(curr_chain, NOTEXISTS);
	c->pri[0] = prim_pri;
	c->pri[1] = sec_pri++;
}
    break;


/* Line 1267 of yacc.c.  */
#line 2525 "/Users/thomasa/Library/Developer/Xcode/DerivedData/adv_cmds-gcqksaoexabncqfyxdglupyaedsy/Build/Intermediates.noindex/adv_cmds.build/Release/colldef.build/DerivedSources/y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 959 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"

int
main(int ac, char **av)
{
	int ch, z;

	if ((charmapdb = dbopen(NULL, O_CREAT | O_RDWR, 0600, DB_HASH, NULL)) == NULL)
		err(1, "dbopen charmapdb");
	if ((charmapdb2 = dbopen(NULL, O_CREAT | O_RDWR, 0600, DB_HASH, NULL)) == NULL)
		err(1, "dbopen charmapdb");
	if ((largemapdb = dbopen(NULL, O_CREAT | O_RDWR, 0600, DB_HASH, NULL)) == NULL)
		err(1, "dbopen largemapdb");
	if ((substdb[0] = dbopen(NULL, O_CREAT | O_RDWR, 0600, DB_HASH, NULL)) == NULL)
		err(1, "dbopen substdb[0]");
	if ((chaindb = dbopen(NULL, O_CREAT | O_RDWR, 0600, DB_HASH, NULL)) == NULL)
		err(1, "dbopen chaindb");
	/* -1 means an undefined priority, which we adjust after parsing */
	for (ch = 0; ch <= UCHAR_MAX; ch++)
		for(z = 0; z < COLL_WEIGHTS_MAX; z++)
			__collate_char_pri_table[ch].pri[z] = PRI_UNDEFINED;
#ifdef COLLATE_DEBUG
	while((ch = getopt(ac, av, ":do:I:")) != -1) {
#else
	while((ch = getopt(ac, av, ":o:I:")) != -1) {
#endif
		switch (ch)
		{
#ifdef COLLATE_DEBUG
		  case 'd':
			debug++;
			break;
#endif
		  case 'o':
			out_file = optarg;
			break;

		  case 'I':
			strlcpy(map_name, optarg, sizeof(map_name));
			break;

		  default:
			usage();
		}
	}
	ac -= optind;
	av += optind;
	if (ac > 0) {
		if ((yyin = fopen(*av, "r")) == NULL)
			err(EX_UNAVAILABLE, "can't open source file %s", *av);
	}
	yyparse();
	return 0;
}

static struct __collate_st_char_pri *
getpri(int32_t c)
{
	DBT key, val;
	struct __collate_st_char_pri *p;
	int ret;

	if (c <= UCHAR_MAX)
		return &__collate_char_pri_table[c];
	key.data = &c;
	key.size = sizeof(int32_t);
	if ((ret = largemapdb->get(largemapdb, &key, &val, 0)) < 0)
		err(1, "getpri: Error getting %s", charname(c));
	if (ret != 0) {
		struct __collate_st_char_pri *pn;
		int z;
		if ((pn = (struct __collate_st_char_pri *)malloc(sizeof(struct __collate_st_char_pri))) == NULL)
			err(1, "getpri: malloc");
		for(z = 0; z < COLL_WEIGHTS_MAX; z++)
			pn->pri[z] = PRI_UNDEFINED;
		val.data = &pn;
		val.size = sizeof(struct __collate_st_char_pri *);
		if (largemapdb->put(largemapdb, &key, &val, 0) < 0)
			err(1, "getpri: Error storing %s", charname(c));
		nlargemap++;
	}
	memcpy(&p, val.data, sizeof(struct __collate_st_char_pri *));
	return p;
}

static struct __collate_st_char_pri *
haspri(int32_t c)
{
	DBT key, val;
	struct __collate_st_char_pri *p;
	int ret;

	if (c <= UCHAR_MAX)
		return &__collate_char_pri_table[c];
	key.data = &c;
	key.size = sizeof(int32_t);
	if ((ret = largemapdb->get(largemapdb, &key, &val, 0)) < 0)
		err(1, "haspri: Error getting %s", charname(c));
	if (ret != 0)
		return NULL;
	memcpy(&p, val.data, sizeof(struct __collate_st_char_pri *));
	return p;
}

static struct __collate_st_chain_pri *
getchain(const wchar_t *wcs, int exists)
{
	DBT key, val;
	struct __collate_st_chain_pri *p;
	int ret;

	key.data = (void *)wcs;
	key.size = __collate_wcsnlen(wcs, STR_LEN) * sizeof(wchar_t);
	if ((ret = chaindb->get(chaindb, &key, &val, 0)) < 0)
		err(1, "getchain: Error getting \"%s\"", showwcs(wcs, STR_LEN));
	if (ret != 0) {
		struct __collate_st_chain_pri *pn;
		int z;
		if (exists > 0)
			errx(1, "getchain: \"%s\" is not defined", showwcs(wcs, STR_LEN));
		if ((pn = (struct __collate_st_chain_pri *)malloc(sizeof(struct __collate_st_chain_pri))) == NULL)
			err(1, "getchain: malloc");
		for(z = 0; z < COLL_WEIGHTS_MAX; z++)
			pn->pri[z] = PRI_UNDEFINED;
		bzero(pn->str, sizeof(pn->str));
		wcsncpy(pn->str, wcs, STR_LEN);
		val.data = &pn;
		val.size = sizeof(struct __collate_st_chain_pri *);
		if (chaindb->put(chaindb, &key, &val, 0) < 0)
			err(1, "getchain: Error storing \"%s\"", showwcs(wcs, STR_LEN));
		nchain++;
	} else if (exists == 0)
		errx(1, "getchain: \"%s\" already exists", showwcs(wcs, STR_LEN));
	memcpy(&p, val.data, sizeof(struct __collate_st_chain_pri *));
	return p;
}

struct symbol *
getsymbol(const wchar_t *wcs, int exists)
{
	DBT key, val;
	struct symbol *p;
	int ret;

	key.data = (void *)wcs;
	key.size = wcslen(wcs) * sizeof(wchar_t);
	if ((ret = charmapdb->get(charmapdb, &key, &val, 0)) < 0)
		err(1, "getsymbol: Error getting \"%s\"", showwcs(wcs, CHARMAP_SYMBOL_LEN));
	if (ret != 0) {
		struct symbol *pn;
		if (exists > 0)
			errx(1, "getsymbol: \"%s\" is not defined", showwcs(wcs, CHARMAP_SYMBOL_LEN));
		if ((pn = (struct symbol *)malloc(sizeof(struct symbol))) == NULL)
			err(1, "getsymbol: malloc");
		pn->val = PRI_UNDEFINED;
		wcsncpy(pn->name, wcs, CHARMAP_SYMBOL_LEN);
		val.data = &pn;
		val.size = sizeof(struct symbol *);
		if (charmapdb->put(charmapdb, &key, &val, 0) < 0)
			err(1, "getsymbol: Error storing \"%s\"", showwcs(wcs, CHARMAP_SYMBOL_LEN));
	} else if (exists == 0)
		errx(1, "getsymbol: \"%s\" already exists", showwcs(wcs, CHARMAP_SYMBOL_LEN));
	memcpy(&p, val.data, sizeof(struct symbol *));
	return p;
}

static struct symbol *
getsymbolbychar(wchar_t wc)
{
	DBT key, val;
	struct symbol *p;
	int ret;

	key.data = &wc;
	key.size = sizeof(wchar_t);
	if ((ret = charmapdb2->get(charmapdb2, &key, &val, 0)) < 0)
		err(1, "getsymbolbychar: Error getting Char 0x%02x", wc);
	if (ret != 0)
		errx(1, "getsymbolbychar: Char 0x%02x is not defined", wc);
	memcpy(&p, val.data, sizeof(struct symbol *));
	return p;
}

static struct symbol *
hassymbolbychar(wchar_t wc)
{
	DBT key, val;
	struct symbol *p;
	int ret;

	key.data = &wc;
	key.size = sizeof(wchar_t);
	if ((ret = charmapdb2->get(charmapdb2, &key, &val, 0)) < 0)
		err(1, "hassymbolbychar: Error getting Char 0x%02x", wc);
	if (ret != 0)
		return NULL;
	memcpy(&p, val.data, sizeof(struct symbol *));
	return p;
}

static void
setsymbolbychar(struct symbol *s)
{
	DBT key, val;
	struct symbol *p;
	int ret;

	key.data = &s->u.wc;
	key.size = sizeof(wchar_t);
	val.data = &s;
	val.size = sizeof(struct symbol *);
	if (charmapdb2->put(charmapdb2, &key, &val, 0) < 0)
		err(1, "setsymbolbychar: Error storing <%s>", showwcs(s->name, CHARMAP_SYMBOL_LEN));
}

struct symbol *
getstring(const wchar_t *wcs)
{
	DBT key, val;
	struct symbol *p;
	int ret;

	key.data = (void *)wcs;
	key.size = wcslen(wcs) * sizeof(wchar_t);
	if ((ret = stringdb->get(stringdb, &key, &val, 0)) < 0)
		err(1, "getstring: Error getting \"%s\"", showwcs(wcs, STR_LEN));
	if (ret != 0) {
		struct symbol *pn;
		if ((pn = (struct symbol *)malloc(sizeof(struct symbol))) == NULL)
			err(1, "getstring: malloc");
		pn->type = SYMBOL_STRING;
		pn->val = prim_pri++;
		wcsncpy(pn->u.str, wcs, STR_LEN);
		val.data = &pn;
		val.size = sizeof(struct symbol *);
		if (stringdb->put(stringdb, &key, &val, 0) < 0)
			err(1, "getstring: Error storing \"%s\"", showwcs(wcs, STR_LEN));
	}
	memcpy(&p, val.data, sizeof(struct symbol *));
	return p;
}

static void
makeforwardref(int i, const struct symbol *from, const struct symbol * to)
{
}

static void
putsubst(int32_t c, int i, const wchar_t *str)
{
	DBT key, val;
	int ret;
	wchar_t clean[STR_LEN];

	if (!substdb[i])
		if ((substdb[i] = dbopen(NULL, O_CREAT | O_RDWR, 0600, DB_HASH, NULL)) == NULL)
			err(1, "dbopen substdb[%d]", i);
	key.data = &c;
	key.size = sizeof(int32_t);
	bzero(clean, sizeof(clean));
	wcsncpy(clean, str, STR_LEN);
	val.data = clean;
	val.size = sizeof(clean);
	if ((ret = substdb[i]->put(substdb[i], &key, &val, R_NOOVERWRITE)) < 0)
		err(1, "putsubst: Error on %s", charname(c));
	if (ret != 0)
		errx(1, "putsubst: Duplicate substitution of %s", charname(c));
	nsubst[i]++;
}

static int
hassubst(int32_t c, int i)
{
	DBT key, val;
	int ret;

	if (!substdb[i])
		return 0;
	key.data = &c;
	key.size = sizeof(int32_t);
	if ((ret = substdb[i]->get(substdb[i], &key, &val, 0)) < 0)
		err(1, "hassubst: Error getting %s", charname(c));
	return (ret == 0);
}

static int
chainpricompar(const void *a, const void *b)
{
	return wcsncmp(((struct __collate_st_chain_pri *)a)->str, ((struct __collate_st_chain_pri *)b)->str, STR_LEN);
}

static int
charpricompar(const void *a, const void *b)
{
	return ((struct __collate_st_large_char_pri *)a)->val - ((struct __collate_st_large_char_pri *)b)->val;
}

static int
substcompar(const void *a, const void *b)
{
	return ((struct __collate_st_subst *)a)->val - ((struct __collate_st_subst *)b)->val;
}

static const wchar_t *
__collate_wcsnchr(const wchar_t *s, wchar_t c, int len)
{
	while (*s && len > 0) {
		if (*s == c)
			return s;
		s++;
		len--;
	}
	return NULL;
}

static int
__collate_wcsnlen(const wchar_t *s, int len)
{
	int n = 0;
	while (*s && n < len) {
		s++;
		n++;
	}
	return n;
}

static void
usage(void)
{
	fprintf(stderr, "usage: colldef [-o out_file] [-I map_dir] [filename]\n");
	exit(EX_USAGE);
}

void
yyerror(const char *fmt, ...)
{
	va_list ap;
	char msg[128];

	va_start(ap, fmt);
	vsnprintf(msg, sizeof(msg), fmt, ap);
	va_end(ap);
	errx(EX_UNAVAILABLE, "%s, near line %d", msg, line_no);
}

char *
showwcs(const wchar_t *t, int len)
{
	static char buf[8* CHARMAP_SYMBOL_LEN];
	char *cp = buf;

	for(; *t && len > 0; len--, t++) {
		if (*t >=32 && *t <= 126)
			*cp++ = *t;
		else {
			sprintf(cp, "\\x{%02x}", *t);
			cp += strlen(cp);
		}
	}
	*cp = 0;
	return buf;
}

static char *
charname(wchar_t wc)
{
	static char buf[CHARMAP_SYMBOL_LEN + 1];
	struct symbol *s = hassymbolbychar(wc);

	if (s)
		strcpy(buf, showwcs(s->name, CHARMAP_SYMBOL_LEN));
	else
		sprintf(buf, "Char 0x%02x", wc);
	return buf;
}

static char *
charname2(wchar_t wc)
{
	static char buf[CHARMAP_SYMBOL_LEN + 1];
	struct symbol *s = hassymbolbychar(wc);

	if (s)
		strcpy(buf, showwcs(s->name, CHARMAP_SYMBOL_LEN));
	else
		sprintf(buf, "Char 0x%02x", wc);
	return buf;
}

#ifdef COLLATE_DEBUG
static char *
show(int c)
{
	static char buf[5];

	if (c >=32 && c <= 126)
		sprintf(buf, "'%c' ", c);
	else
		sprintf(buf, "\\x{%02x}", c);
	return buf;
}

static void
collate_print_tables(void)
{
	int i, z;

	printf("Info: p=%d s=%d f=0x%02x m=%d dc=%d up=%d us=%d pc=%d sc=%d cc=%d lc=%d\n",
	    info.directive[0], info.directive[1],
	    info.flags, info.chain_max_len,
	    info.directive_count,
	    info.undef_pri[0], info.undef_pri[1],
	    info.subst_count[0], info.subst_count[1],
	    info.chain_count, info.large_pri_count);
	for(z = 0; z < info.directive_count; z++) {
		if (info.subst_count[z] > 0) {
			struct __collate_st_subst *p2 = __collate_substitute_table[z];
			if (z == 0 && (info.flags & COLLATE_SUBST_DUP))
				printf("Both substitute tables:\n");
			else
				printf("Substitute table %d:\n", z);
			for (i = info.subst_count[z]; i-- > 0; p2++)
				printf("\t%s --> \"%s\"\n",
					show(p2->val),
					showwcs(p2->str, STR_LEN));
		}
	}
	if (info.chain_count > 0) {
		printf("Chain priority table:\n");
		struct __collate_st_chain_pri *p2 = __collate_chain_pri_table;
		for (i = info.chain_count; i-- > 0; p2++) {
			printf("\t\"%s\" :", showwcs(p2->str, STR_LEN));
			for(z = 0; z < info.directive_count; z++)
				printf(" %d", p2->pri[z]);
			putchar('\n');
		}
	}
	printf("Char priority table:\n");
	{
		struct __collate_st_char_pri *p2 = __collate_char_pri_table;
		for (i = 0; i < UCHAR_MAX + 1; i++, p2++) {
			printf("\t%s :", show(i));
			for(z = 0; z < info.directive_count; z++)
				printf(" %d", p2->pri[z]);
			putchar('\n');
		}
	}
	if (info.large_pri_count > 0) {
		struct __collate_st_large_char_pri *p2 = __collate_large_char_pri_table;
		printf("Large priority table:\n");
		for (i = info.large_pri_count; i-- > 0; p2++) {
			printf("\t%s :", show(p2->val));
			for(z = 0; z < info.directive_count; z++)
				printf(" %d", p2->pri.pri[z]);
			putchar('\n');
		}
	}
}
#endif

