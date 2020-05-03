/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_ASSIGN5_TAB_H_INCLUDED
# define YY_YY_ASSIGN5_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPE_INT = 258,
    TYPE_FLOAT = 259,
    NAME = 260,
    NUM_INT = 261,
    NUM_FLOAT = 262,
    LESS = 263,
    GREATER = 264,
    EQUAL = 265,
    LESS_EQUAL = 266,
    GREATER_EQUAL = 267,
    NOT_EQUAL = 268,
    IS_EQUAL = 269,
    AND = 270,
    OR = 271,
    NOT = 272,
    PLUS = 273,
    MINUS = 274,
    MUL = 275,
    DIV = 276,
    MOD = 277,
    SEMI = 278,
    COMMA = 279,
    COLON = 280,
    LB = 281,
    RB = 282,
    LC = 283,
    RC = 284,
    KEY_MAIN = 285,
    KEY_VOID = 286,
    KEY_RETURN = 287,
    KEY_BREAK = 288,
    KEY_DEFAULT = 289,
    KEY_IF = 290,
    KEY_ELSE = 291,
    KEY_SWITCH = 292,
    KEY_CASE = 293,
    KEY_FOR = 294,
    KEY_WHILE = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "assign5.y" /* yacc.c:1909  */

	float num_f;
	int num_i;
	char* str;

#line 101 "assign5.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASSIGN5_TAB_H_INCLUDED  */
