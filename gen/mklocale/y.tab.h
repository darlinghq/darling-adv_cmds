/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 89 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/mklocale/yacc.y"
{
    int32_t	rune;
    int		i;
    char	*str;

    rune_list	*list;
}
/* Line 1529 of yacc.c.  */
#line 87 "/Users/thomasa/Library/Developer/Xcode/DerivedData/adv_cmds-gcqksaoexabncqfyxdglupyaedsy/Build/Intermediates.noindex/adv_cmds.build/Release/mklocale.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

