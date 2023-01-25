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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 123 "/Volumes/CaseSensitive/git/distribution-macOS/adv_cmds/colldef/parse.y"
{
	int32_t ch;
	wchar_t str[BUFSIZE];
}
/* Line 1529 of yacc.c.  */
#line 98 "/Users/thomasa/Library/Developer/Xcode/DerivedData/adv_cmds-gcqksaoexabncqfyxdglupyaedsy/Build/Intermediates.noindex/adv_cmds.build/Release/colldef.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

