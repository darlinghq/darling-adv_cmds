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
     RUNE = 258,
     LBRK = 259,
     RBRK = 260,
     THRU = 261,
     MAPLOWER = 262,
     MAPUPPER = 263,
     DIGITMAP = 264,
     CHARCLASS = 265,
     LIST = 266,
     VARIABLE = 267,
     ENCODING = 268,
     INVALID = 269,
     STRING = 270
   };
#endif
/* Tokens.  */
#define RUNE 258
#define LBRK 259
#define RBRK 260
#define THRU 261
#define MAPLOWER 262
#define MAPUPPER 263
#define DIGITMAP 264
#define CHARCLASS 265
#define LIST 266
#define VARIABLE 267
#define ENCODING 268
#define INVALID 269
#define STRING 270




/* Copy the first part of user declarations.  */
#line 1 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"

/*-
 * Copyright (c) 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Paul Borman at Krystal Technologies.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef lint
#if 0
static char sccsid[] = "@(#)yacc.y	8.1 (Berkeley) 6/6/93";
#endif /* 0 */
#endif /* not lint */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/usr.bin/mklocale/yacc.y,v 1.28 2008/01/22 00:04:50 ache Exp $");

#include <arpa/inet.h>

#include <ctype.h>
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ldef.h"
#include "extern.h"
#include "runefile.h"

#define	MAX_CHARCLASS	4
#define	CHARCLASSBIT	4

static void *xmalloc(unsigned int sz);
static uint32_t *xlalloc(unsigned int sz);
void yyerror(const char *s);
static uint32_t *xrelalloc(uint32_t *old, unsigned int sz);
static void dump_tables(void);
static void cleanout(void);

const char	*locale_file = "<stdout>";

rune_map	maplower = { { 0 }, NULL };
rune_map	mapupper = { { 0 }, NULL };
rune_map	types = { { 0 }, NULL };

_FileRuneLocale	new_locale = { "", "", 0, 0, 0, {}, {}, {}, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char		*variable = NULL;

rune_charclass	charclasses[MAX_CHARCLASS];
int		charclass_index = 0;

void set_map(rune_map *, rune_list *, uint32_t);
void set_digitmap(rune_map *, rune_list *);
void add_map(rune_map *, rune_list *, uint32_t);
static void usage(void);


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
#line 89 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
{
    int32_t	rune;
    int		i;
    char	*str;

    rune_list	*list;
}
/* Line 193 of yacc.c.  */
#line 222 "/Users/ariel/Library/Developer/Xcode/DerivedData/adv_cmds-gklnqbcrcqescghbhgkvtzrtwvdp/Build/Intermediates.noindex/adv_cmds.build/Release/mklocale.build/DerivedSources/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 235 "/Users/ariel/Library/Developer/Xcode/DerivedData/adv_cmds-gklnqbcrcqescghbhgkvtzrtwvdp/Build/Intermediates.noindex/adv_cmds.build/Release/mklocale.build/DerivedSources/y.tab.c"

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
#define YYLAST   50

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  17
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  21
/* YYNRULES -- Number of states.  */
#define YYNSTATES  46

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    16,     2,
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
      15
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    14,    16,    19,
      22,    25,    28,    31,    35,    37,    41,    44,    49,    54,
      60,    68
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      18,     0,    -1,    -1,    19,    -1,    20,    -1,    19,    20,
      -1,    13,    15,    -1,    12,    -1,    14,     3,    -1,    11,
      21,    -1,     7,    22,    -1,     8,    22,    -1,     9,    22,
      -1,    10,    15,    21,    -1,     3,    -1,     3,     6,     3,
      -1,    21,     3,    -1,    21,     3,     6,     3,    -1,     4,
       3,     3,     5,    -1,    22,     4,     3,     3,     5,    -1,
       4,     3,     6,     3,    16,     3,     5,    -1,    22,     4,
       3,     6,     3,    16,     3,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   117,   117,   118,   122,   123,   126,   140,   145,   147,
     149,   151,   153,   159,   178,   185,   192,   199,   208,   216,
     224,   232
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RUNE", "LBRK", "RBRK", "THRU",
  "MAPLOWER", "MAPUPPER", "DIGITMAP", "CHARCLASS", "LIST", "VARIABLE",
  "ENCODING", "INVALID", "STRING", "':'", "$accept", "locale", "table",
  "entry", "list", "map", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    17,    18,    18,    19,    19,    20,    20,    20,    20,
      20,    20,    20,    20,    21,    21,    21,    21,    22,    22,
      22,    22
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     3,     1,     3,     2,     4,     4,     5,
       7,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       3,     4,     0,    10,    11,    12,     0,    14,     9,     6,
       8,     1,     5,     0,     0,    13,     0,    16,     0,     0,
       0,    15,     0,    18,     0,     0,     0,    17,     0,    19,
       0,     0,     0,    20,     0,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    18,    13
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -8
static const yytype_int8 yypact[] =
{
      -7,    12,    12,    12,    -5,    14,    -8,     0,    15,    19,
      -7,    -8,    17,    18,    18,    18,    14,    20,    21,    -8,
      -8,    -8,    -8,     5,    22,    21,    24,    23,    16,    25,
       6,    -8,    27,    -8,     7,    26,    29,    -8,    30,    -8,
      28,    31,    32,    -8,    33,    -8
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
      -8,    -8,    -8,    35,    34,    11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       1,     2,     3,     4,     5,     6,     7,     8,    28,    35,
      16,    29,    36,    14,    15,    19,    12,    17,    20,    21,
      23,    33,    24,    38,    27,    30,    26,    31,    34,    32,
      37,    39,    40,    41,     0,    44,    43,     0,    45,     0,
       0,     0,     0,     0,    42,    22,     0,     0,     0,     0,
      25
};

static const yytype_int8 yycheck[] =
{
       7,     8,     9,    10,    11,    12,    13,    14,     3,     3,
      15,     6,     6,     2,     3,    15,     4,     3,     3,     0,
       3,     5,     4,    16,     3,     3,     6,     3,     3,     6,
       3,     5,     3,     3,    -1,     3,     5,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    16,    10,    -1,    -1,    -1,    -1,
      16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    12,    13,    14,    18,
      19,    20,     4,    22,    22,    22,    15,     3,    21,    15,
       3,     0,    20,     3,     4,    21,     6,     3,     3,     6,
       3,     3,     6,     5,     3,     3,     6,     3,    16,     5,
       3,     3,    16,     5,     3,     5
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
        case 3:
#line 119 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    { dump_tables(); }
    break;

  case 6:
#line 127 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    { if (strcmp((yyvsp[(2) - (2)].str), "NONE") &&
		      strcmp((yyvsp[(2) - (2)].str), "ASCII") &&
		      strcmp((yyvsp[(2) - (2)].str), "UTF-8") &&
		      strcmp((yyvsp[(2) - (2)].str), "EUC") &&
		      strcmp((yyvsp[(2) - (2)].str), "GBK") &&
		      strcmp((yyvsp[(2) - (2)].str), "GB18030") &&
		      strcmp((yyvsp[(2) - (2)].str), "GB2312") &&
		      strcmp((yyvsp[(2) - (2)].str), "BIG5") &&
		      strcmp((yyvsp[(2) - (2)].str), "MSKanji") &&
		      strcmp((yyvsp[(2) - (2)].str), "UTF2"))
			warnx("ENCODING %s is not supported by libc", (yyvsp[(2) - (2)].str));
		strncpy(new_locale.encoding, (yyvsp[(2) - (2)].str),
		    sizeof(new_locale.encoding)); }
    break;

  case 7:
#line 141 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    { new_locale.variable_len = strlen((yyvsp[(1) - (1)].str)) + 1;
		  variable = xmalloc(new_locale.variable_len);
		  strcpy(variable, (yyvsp[(1) - (1)].str));
		}
    break;

  case 8:
#line 146 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    { warnx("the INVALID keyword is deprecated"); }
    break;

  case 9:
#line 148 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    { set_map(&types, (yyvsp[(2) - (2)].list), (yyvsp[(1) - (2)].i)); }
    break;

  case 10:
#line 150 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    { set_map(&maplower, (yyvsp[(2) - (2)].list), 0); }
    break;

  case 11:
#line 152 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    { set_map(&mapupper, (yyvsp[(2) - (2)].list), 0); }
    break;

  case 12:
#line 154 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    {
			if (((yyvsp[(2) - (2)].list)->map >= 0) && ((yyvsp[(2) - (2)].list)->map <= 255)) { /* Data corruption otherwise */
				set_digitmap(&types, (yyvsp[(2) - (2)].list));
			}
		}
    break;

  case 13:
#line 160 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    {
		  int i;
		  if (strlen((yyvsp[(2) - (3)].str)) > CHARCLASS_NAME_MAX)
		      errx(1, "Exceeded maximum charclass name size (%d) \"%s\"", CHARCLASS_NAME_MAX, (yyvsp[(2) - (3)].str));
		  for(i = 0; i < charclass_index; i++)
		      if (strncmp(charclasses[i].name, (yyvsp[(2) - (3)].str), CHARCLASS_NAME_MAX) == 0)
			  break;
		  if (i >= charclass_index) {
		      if (charclass_index >= MAX_CHARCLASS)
			  errx(1, "Exceeded maximum number of charclasses (%d)", MAX_CHARCLASS);
		      strncpy(charclasses[charclass_index].name, (yyvsp[(2) - (3)].str), CHARCLASS_NAME_MAX);
		      charclasses[charclass_index].mask = (1 << (charclass_index + CHARCLASSBIT));
		      charclass_index++;
		  }
		  set_map(&types, (yyvsp[(3) - (3)].list), charclasses[i].mask);
		}
    break;

  case 14:
#line 179 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    {
		    (yyval.list) = (rune_list *)xmalloc(sizeof(rune_list));
		    (yyval.list)->min = (yyvsp[(1) - (1)].rune);
		    (yyval.list)->max = (yyvsp[(1) - (1)].rune);
		    (yyval.list)->next = 0;
		}
    break;

  case 15:
#line 186 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    {
		    (yyval.list) = (rune_list *)xmalloc(sizeof(rune_list));
		    (yyval.list)->min = (yyvsp[(1) - (3)].rune);
		    (yyval.list)->max = (yyvsp[(3) - (3)].rune);
		    (yyval.list)->next = 0;
		}
    break;

  case 16:
#line 193 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    {
		    (yyval.list) = (rune_list *)xmalloc(sizeof(rune_list));
		    (yyval.list)->min = (yyvsp[(2) - (2)].rune);
		    (yyval.list)->max = (yyvsp[(2) - (2)].rune);
		    (yyval.list)->next = (yyvsp[(1) - (2)].list);
		}
    break;

  case 17:
#line 200 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    {
		    (yyval.list) = (rune_list *)xmalloc(sizeof(rune_list));
		    (yyval.list)->min = (yyvsp[(2) - (4)].rune);
		    (yyval.list)->max = (yyvsp[(4) - (4)].rune);
		    (yyval.list)->next = (yyvsp[(1) - (4)].list);
		}
    break;

  case 18:
#line 209 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    {
		    (yyval.list) = (rune_list *)xmalloc(sizeof(rune_list));
		    (yyval.list)->min = (yyvsp[(2) - (4)].rune);
		    (yyval.list)->max = (yyvsp[(2) - (4)].rune);
		    (yyval.list)->map = (yyvsp[(3) - (4)].rune);
		    (yyval.list)->next = 0;
		}
    break;

  case 19:
#line 217 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    {
		    (yyval.list) = (rune_list *)xmalloc(sizeof(rune_list));
		    (yyval.list)->min = (yyvsp[(3) - (5)].rune);
		    (yyval.list)->max = (yyvsp[(3) - (5)].rune);
		    (yyval.list)->map = (yyvsp[(4) - (5)].rune);
		    (yyval.list)->next = (yyvsp[(1) - (5)].list);
		}
    break;

  case 20:
#line 225 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    {
		    (yyval.list) = (rune_list *)xmalloc(sizeof(rune_list));
		    (yyval.list)->min = (yyvsp[(2) - (7)].rune);
		    (yyval.list)->max = (yyvsp[(4) - (7)].rune);
		    (yyval.list)->map = (yyvsp[(6) - (7)].rune);
		    (yyval.list)->next = 0;
		}
    break;

  case 21:
#line 233 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"
    {
		    (yyval.list) = (rune_list *)xmalloc(sizeof(rune_list));
		    (yyval.list)->min = (yyvsp[(3) - (8)].rune);
		    (yyval.list)->max = (yyvsp[(5) - (8)].rune);
		    (yyval.list)->map = (yyvsp[(7) - (8)].rune);
		    (yyval.list)->next = (yyvsp[(1) - (8)].list);
		}
    break;


/* Line 1267 of yacc.c.  */
#line 1619 "/Users/ariel/Library/Developer/Xcode/DerivedData/adv_cmds-gklnqbcrcqescghbhgkvtzrtwvdp/Build/Intermediates.noindex/adv_cmds.build/Release/mklocale.build/DerivedSources/y.tab.c"
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


#line 241 "/Users/ariel/git/darling/src/external/adv_cmds/mklocale/yacc.y"


int debug;
FILE *fp;

static void
cleanout(void)
{
    if (fp != NULL)
	unlink(locale_file);
}

int
main(int ac, char *av[])
{
    int x;

    fp = stdout;

    while ((x = getopt(ac, av, "do:")) != -1) {
	switch(x) {
	case 'd':
	    debug = 1;
	    break;
	case 'o':
	    locale_file = optarg;
	    if ((fp = fopen(locale_file, "w")) == NULL)
		err(1, "%s: fopen", locale_file);
	    atexit(cleanout);
	    break;
	default:
	    usage();
	}
    }

    switch (ac - optind) {
    case 0:
	break;
    case 1:
	if (freopen(av[optind], "r", stdin) == 0)
	    err(1, "%s: freopen", av[optind]);
	break;
    default:
	usage();
    }
    for (x = 0; x < _CACHED_RUNES; ++x) {
	mapupper.map[x] = x;
	maplower.map[x] = x;
    }
    memcpy(new_locale.magic, _RUNE_MAGIC_A, sizeof(new_locale.magic));

    yyparse();

    return(0);
}

static void
usage()
{
    fprintf(stderr, "usage: mklocale [-d] [-o output] [source]\n");
    exit(1);
}

void
yyerror(s)
	const char *s;
{
    fprintf(stderr, "%s\n", s);
}

static void *
xmalloc(sz)
	unsigned int sz;
{
    void *r = malloc(sz);
    if (!r)
	errx(1, "xmalloc");
    return(r);
}

static uint32_t *
xlalloc(sz)
	unsigned int sz;
{
    uint32_t *r = (uint32_t *)malloc(sz * sizeof(uint32_t));
    if (!r)
	errx(1, "xlalloc");
    return(r);
}

static uint32_t *
xrelalloc(old, sz)
	uint32_t *old;
	unsigned int sz;
{
    uint32_t *r = (uint32_t *)realloc((char *)old,
						sz * sizeof(uint32_t));
    if (!r)
	errx(1, "xrelalloc");
    return(r);
}

void
set_map(map, list, flag)
	rune_map *map;
	rune_list *list;
	uint32_t flag;
{
    while (list) {
	rune_list *nlist = list->next;
	add_map(map, list, flag);
	list = nlist;
    }
}

void
set_digitmap(map, list)
	rune_map *map;
	rune_list *list;
{
    int32_t i;

    while (list) {
	rune_list *nlist = list->next;
	for (i = list->min; i <= list->max; ++i) {
	    if (list->map + (i - list->min)) {
		rune_list *tmp = (rune_list *)xmalloc(sizeof(rune_list));
		tmp->min = i;
		tmp->max = i;
		add_map(map, tmp, list->map + (i - list->min));
	    }
	}
	free(list);
	list = nlist;
    }
}

void
add_map(map, list, flag)
	rune_map *map;
	rune_list *list;
	uint32_t flag;
{
    int32_t i;
    rune_list *lr = 0;
    rune_list *r;
    int32_t run;

    while (list->min < _CACHED_RUNES && list->min <= list->max) {
	if (flag)
	    map->map[list->min++] |= flag;
	else
	    map->map[list->min++] = list->map++;
    }

    if (list->min > list->max) {
	free(list);
	return;
    }

    run = list->max - list->min + 1;

    if (!(r = map->root) || (list->max < r->min - 1)
			 || (!flag && list->max == r->min - 1)) {
	if (flag) {
	    list->types = xlalloc(run);
	    for (i = 0; i < run; ++i)
		list->types[i] = flag;
	}
	list->next = map->root;
	map->root = list;
	return;
    }

    for (r = map->root; r && r->max + 1 < list->min; r = r->next)
	lr = r;

    if (!r) {
	/*
	 * We are off the end.
	 */
	if (flag) {
	    list->types = xlalloc(run);
	    for (i = 0; i < run; ++i)
		list->types[i] = flag;
	}
	list->next = 0;
	lr->next = list;
	return;
    }

    if (list->max < r->min - 1) {
	/*
	 * We come before this range and we do not intersect it.
	 * We are not before the root node, it was checked before the loop
	 */
	if (flag) {
	    list->types = xlalloc(run);
	    for (i = 0; i < run; ++i)
		list->types[i] = flag;
	}
	list->next = lr->next;
	lr->next = list;
	return;
    }

    /*
     * At this point we have found that we at least intersect with
     * the range pointed to by `r', we might intersect with one or
     * more ranges beyond `r' as well.
     */

    if (!flag && list->map - list->min != r->map - r->min) {
	/*
	 * There are only two cases when we are doing case maps and
	 * our maps needn't have the same offset.  When we are adjoining
	 * but not intersecting.
	 */
	if (list->max + 1 == r->min) {
	    lr->next = list;
	    list->next = r;
	    return;
	}
	if (list->min - 1 == r->max) {
	    list->next = r->next;
	    r->next = list;
	    return;
	}
	errx(1, "error: conflicting map entries");
    }

    if (list->min >= r->min && list->max <= r->max) {
	/*
	 * Subset case.
	 */

	if (flag) {
	    for (i = list->min; i <= list->max; ++i)
		r->types[i - r->min] |= flag;
	}
	free(list);
	return;
    }
    if (list->min <= r->min && list->max >= r->max) {
	/*
	 * Superset case.  Make him big enough to hold us.
	 * We might need to merge with the guy after him.
	 */
	if (flag) {
	    list->types = xlalloc(list->max - list->min + 1);

	    for (i = list->min; i <= list->max; ++i)
		list->types[i - list->min] = flag;

	    for (i = r->min; i <= r->max; ++i)
		list->types[i - list->min] |= r->types[i - r->min];

	    free(r->types);
	    r->types = list->types;
	} else {
	    r->map = list->map;
	}
	r->min = list->min;
	r->max = list->max;
	free(list);
    } else if (list->min < r->min) {
	/*
	 * Our tail intersects his head.
	 */
	if (flag) {
	    list->types = xlalloc(r->max - list->min + 1);

	    for (i = r->min; i <= r->max; ++i)
		list->types[i - list->min] = r->types[i - r->min];

	    for (i = list->min; i < r->min; ++i)
		list->types[i - list->min] = flag;

	    for (i = r->min; i <= list->max; ++i)
		list->types[i - list->min] |= flag;

	    free(r->types);
	    r->types = list->types;
	} else {
	    r->map = list->map;
	}
	r->min = list->min;
	free(list);
	return;
    } else {
	/*
	 * Our head intersects his tail.
	 * We might need to merge with the guy after him.
	 */
	if (flag) {
	    r->types = xrelalloc(r->types, list->max - r->min + 1);

	    for (i = list->min; i <= r->max; ++i)
		r->types[i - r->min] |= flag;

	    for (i = r->max+1; i <= list->max; ++i)
		r->types[i - r->min] = flag;
	}
	r->max = list->max;
	free(list);
    }

    /*
     * Okay, check to see if we grew into the next guy(s)
     */
    while ((lr = r->next) && r->max >= lr->min) {
	if (flag) {
	    if (r->max >= lr->max) {
		/*
		 * Good, we consumed all of him.
		 */
		for (i = lr->min; i <= lr->max; ++i)
		    r->types[i - r->min] |= lr->types[i - lr->min];
	    } else {
		/*
		 * "append" him on to the end of us.
		 */
		r->types = xrelalloc(r->types, lr->max - r->min + 1);

		for (i = lr->min; i <= r->max; ++i)
		    r->types[i - r->min] |= lr->types[i - lr->min];

		for (i = r->max+1; i <= lr->max; ++i)
		    r->types[i - r->min] = lr->types[i - lr->min];

		r->max = lr->max;
	    }
	} else {
	    if (lr->max > r->max)
		r->max = lr->max;
	}

	r->next = lr->next;

	if (flag)
	    free(lr->types);
	free(lr);
    }
}

static void
dump_tables()
{
    int x, first_d, curr_d;
    rune_list *list;

    /*
     * See if we can compress some of the istype arrays
     */
    for(list = types.root; list; list = list->next) {
	list->map = list->types[0];
	for (x = 1; x < list->max - list->min + 1; ++x) {
	    if ((int32_t)list->types[x] != list->map) {
		list->map = 0;
		break;
	    }
	}
    }

    first_d = curr_d = -1;
    for (x = 0; x < _CACHED_RUNES; ++x) {
	uint32_t r = types.map[x];

	if (r & _CTYPE_D) {
		if (first_d < 0)
			first_d = curr_d = x;
		else if (x != curr_d + 1)
			errx(1, "error: DIGIT range is not contiguous");
		else if (x - first_d > 9)
			errx(1, "error: DIGIT range is too big");
		else
			curr_d++;
		if (!(r & _CTYPE_X))
			errx(1,
			"error: DIGIT range is not a subset of XDIGIT range");
	}
    }
    if (first_d < 0)
	errx(1, "error: no DIGIT range defined in the single byte area");
    else if (curr_d - first_d < 9)
	errx(1, "error: DIGIT range is too small in the single byte area");

    new_locale.ncharclasses = htonl(charclass_index);

    /*
     * Fill in our tables.  Do this in network order so that
     * diverse machines have a chance of sharing data.
     * (Machines like Crays cannot share with little machines due to
     *  word size.  Sigh.  We tried.)
     */
    for (x = 0; x < _CACHED_RUNES; ++x) {
	new_locale.runetype[x] = htonl(types.map[x]);
	new_locale.maplower[x] = htonl(maplower.map[x]);
	new_locale.mapupper[x] = htonl(mapupper.map[x]);
    }

    /*
     * Count up how many ranges we will need for each of the extents.
     */
    list = types.root;

    while (list) {
	new_locale.runetype_ext_nranges++;
	list = list->next;
    }
    new_locale.runetype_ext_nranges =
         htonl(new_locale.runetype_ext_nranges);

    list = maplower.root;

    while (list) {
	new_locale.maplower_ext_nranges++;
	list = list->next;
    }
    new_locale.maplower_ext_nranges =
        htonl(new_locale.maplower_ext_nranges);

    list = mapupper.root;

    while (list) {
	new_locale.mapupper_ext_nranges++;
	list = list->next;
    }
    new_locale.mapupper_ext_nranges =
        htonl(new_locale.mapupper_ext_nranges);

    new_locale.variable_len = htonl(new_locale.variable_len);

    /*
     * Okay, we are now ready to write the new locale file.
     */

    /*
     * PART 1: The _FileRuneLocale structure
     */
    if (fwrite((char *)&new_locale, sizeof(new_locale), 1, fp) != 1) {
	err(1, "%s: _FileRuneLocale structure", locale_file);
    }
    /*
     * PART 2: The runetype_ext structures (not the actual tables)
     */
    list = types.root;

    while (list) {
	_FileRuneEntry re;

	re.min = htonl(list->min);
	re.max = htonl(list->max);
	re.map = htonl(list->map);
#ifdef __APPLE__
	re.__types_fake = 0;
#endif

	if (fwrite((char *)&re, sizeof(re), 1, fp) != 1) {
	    err(1, "%s: runetype_ext structures", locale_file);
	}

        list = list->next;
    }
    /*
     * PART 3: The maplower_ext structures
     */
    list = maplower.root;

    while (list) {
	_FileRuneEntry re;

	re.min = htonl(list->min);
	re.max = htonl(list->max);
	re.map = htonl(list->map);
#ifdef __APPLE__
	re.__types_fake = 0;
#endif

	if (fwrite((char *)&re, sizeof(re), 1, fp) != 1) {
	    err(1, "%s: maplower_ext structures", locale_file);
	}

        list = list->next;
    }
    /*
     * PART 4: The mapupper_ext structures
     */
    list = mapupper.root;

    while (list) {
	_FileRuneEntry re;

	re.min = htonl(list->min);
	re.max = htonl(list->max);
	re.map = htonl(list->map);
#ifdef __APPLE__
	re.__types_fake = 0;
#endif

	if (fwrite((char *)&re, sizeof(re), 1, fp) != 1) {
	    err(1, "%s: mapupper_ext structures", locale_file);
	}

        list = list->next;
    }
    /*
     * PART 5: The runetype_ext tables
     */
    list = types.root;

    while (list) {
	for (x = 0; x < list->max - list->min + 1; ++x)
	    list->types[x] = htonl(list->types[x]);

	if (!list->map) {
	    if (fwrite((char *)list->types,
		       (list->max - list->min + 1) * sizeof(uint32_t),
		       1, fp) != 1) {
		err(1, "%s: runetype_ext tables", locale_file);
	    }
	}
        list = list->next;
    }
    /*
     * PART 6: The charclass names table
     */
    for (x = 0; x < charclass_index; ++x) {
	charclasses[x].mask = ntohl(charclasses[x].mask);
	if (fwrite((char *)&charclasses[x], sizeof(rune_charclass), 1, fp) != 1) {
	    err(1, "%s: charclass names tables", locale_file);
	}
    }
    /*
     * PART 7: And finally the variable data
     * SUSv3 says fwrite returns zero when either size or nitems is zero.
     */
    if (ntohl(new_locale.variable_len) > 0 && fwrite(variable,
	       ntohl(new_locale.variable_len), 1, fp) != 1) {
	err(1, "%s: variable data", locale_file);
    }
    if (fclose(fp) != 0) {
	err(1, "%s: fclose", locale_file);
    }
    fp = NULL;

    if (!debug)
	return;

    if (new_locale.encoding[0])
	fprintf(stderr, "ENCODING	%s\n", new_locale.encoding);
    if (variable)
	fprintf(stderr, "VARIABLE	%s\n", variable);

    fprintf(stderr, "\nMAPLOWER:\n\n");

    for (x = 0; x < _CACHED_RUNES; ++x) {
	if (isprint(maplower.map[x]))
	    fprintf(stderr, " '%c'", (int)maplower.map[x]);
	else if (maplower.map[x])
	    fprintf(stderr, "%04x", maplower.map[x]);
	else
	    fprintf(stderr, "%4x", 0);
	if ((x & 0xf) == 0xf)
	    fprintf(stderr, "\n");
	else
	    fprintf(stderr, " ");
    }
    fprintf(stderr, "\n");

    for (list = maplower.root; list; list = list->next)
	fprintf(stderr, "\t%04x - %04x : %04x\n", list->min, list->max, list->map);

    fprintf(stderr, "\nMAPUPPER:\n\n");

    for (x = 0; x < _CACHED_RUNES; ++x) {
	if (isprint(mapupper.map[x]))
	    fprintf(stderr, " '%c'", (int)mapupper.map[x]);
	else if (mapupper.map[x])
	    fprintf(stderr, "%04x", mapupper.map[x]);
	else
	    fprintf(stderr, "%4x", 0);
	if ((x & 0xf) == 0xf)
	    fprintf(stderr, "\n");
	else
	    fprintf(stderr, " ");
    }
    fprintf(stderr, "\n");

    for (list = mapupper.root; list; list = list->next)
	fprintf(stderr, "\t%04x - %04x : %04x\n", list->min, list->max, list->map);


    fprintf(stderr, "\nTYPES:\n\n");

    for (x = 0; x < _CACHED_RUNES; ++x) {
	uint32_t r = types.map[x];

	if (r) {
	    if (isprint(x))
		fprintf(stderr, " '%c': %2d", x, (int)(r & 0xff));
	    else
		fprintf(stderr, "%04x: %2d", x, (int)(r & 0xff));

	    fprintf(stderr, " %4s", (r & _CTYPE_A) ? "alph" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_C) ? "ctrl" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_D) ? "dig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_G) ? "graf" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_L) ? "low" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_P) ? "punc" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_S) ? "spac" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_U) ? "upp" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_X) ? "xdig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_B) ? "blnk" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_R) ? "prnt" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_I) ? "ideo" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_T) ? "spec" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_Q) ? "phon" : "");
	    fprintf(stderr, "\n");
	}
    }

    for (list = types.root; list; list = list->next) {
	if (list->map && list->min + 3 < list->max) {
	    uint32_t r = list->map;

	    fprintf(stderr, "%04x: %2d",
		(uint32_t)list->min, (int)(r & 0xff));

	    fprintf(stderr, " %4s", (r & _CTYPE_A) ? "alph" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_C) ? "ctrl" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_D) ? "dig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_G) ? "graf" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_L) ? "low" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_P) ? "punc" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_S) ? "spac" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_U) ? "upp" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_X) ? "xdig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_B) ? "blnk" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_R) ? "prnt" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_I) ? "ideo" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_T) ? "spec" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_Q) ? "phon" : "");
	    fprintf(stderr, "\n...\n");

	    fprintf(stderr, "%04x: %2d",
		(uint32_t)list->max, (int)(r & 0xff));

	    fprintf(stderr, " %4s", (r & _CTYPE_A) ? "alph" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_C) ? "ctrl" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_D) ? "dig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_G) ? "graf" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_L) ? "low" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_P) ? "punc" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_S) ? "spac" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_U) ? "upp" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_X) ? "xdig" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_B) ? "blnk" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_R) ? "prnt" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_I) ? "ideo" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_T) ? "spec" : "");
	    fprintf(stderr, " %4s", (r & _CTYPE_Q) ? "phon" : "");
	    fprintf(stderr, "\n");
	} else 
	for (x = list->min; x <= list->max; ++x) {
	    uint32_t r = ntohl(list->types[x - list->min]);

	    if (r) {
		fprintf(stderr, "%04x: %2d", x, (int)(r & 0xff));

		fprintf(stderr, " %4s", (r & _CTYPE_A) ? "alph" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_C) ? "ctrl" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_D) ? "dig" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_G) ? "graf" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_L) ? "low" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_P) ? "punc" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_S) ? "spac" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_U) ? "upp" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_X) ? "xdig" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_B) ? "blnk" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_R) ? "prnt" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_I) ? "ideo" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_T) ? "spec" : "");
		fprintf(stderr, " %4s", (r & _CTYPE_Q) ? "phon" : "");
		fprintf(stderr, "\n");
	    }
	}
    }
}

