/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_BALANCEMQ_SETTINGS_YY_BALANCEMQ_SETTINGS_PARSER_H_INCLUDED
# define YY_BALANCEMQ_SETTINGS_YY_BALANCEMQ_SETTINGS_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef BALANCEMQ_SETTINGS_YYDEBUG
# if defined YYDEBUG
#  if YYDEBUG
#   define BALANCEMQ_SETTINGS_YYDEBUG 1
#  else
#   define BALANCEMQ_SETTINGS_YYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define BALANCEMQ_SETTINGS_YYDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined BALANCEMQ_SETTINGS_YYDEBUG */
#if BALANCEMQ_SETTINGS_YYDEBUG
extern int balancemq_settings_yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 17 "balancemq_settings.y"

  #include <log.h>
  #include <xlist.h>

  #include "settings.h"


/* Line 2058 of yacc.c  */
#line 62 "balancemq_settings.parser.h"

/* Tokens.  */
#ifndef BALANCEMQ_SETTINGS_YYTOKENTYPE
# define BALANCEMQ_SETTINGS_YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum balancemq_settings_yytokentype {
     T_IDENTIFIER = 258,
     T_LBRACE = 259,
     T_RBRACE = 260,
     T_COMMA = 261,
     T_DOUBLE = 262,
     T_INTEGER = 263
   };
#endif
/* Tokens.  */
#define T_IDENTIFIER 258
#define T_LBRACE 259
#define T_RBRACE 260
#define T_COMMA 261
#define T_DOUBLE 262
#define T_INTEGER 263



#if ! defined BALANCEMQ_SETTINGS_YYSTYPE && ! defined BALANCEMQ_SETTINGS_YYSTYPE_IS_DECLARED

# define balancemq_settings_yystype BALANCEMQ_SETTINGS_YYSTYPE /* obsolescent; will be withdrawn */
# define BALANCEMQ_SETTINGS_YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int balancemq_settings_yyparse (void *YYPARSE_PARAM);
#else
int balancemq_settings_yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int balancemq_settings_yyparse (BALANCEMQ_settings_t* settings_tree);
#else
int balancemq_settings_yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_BALANCEMQ_SETTINGS_YY_BALANCEMQ_SETTINGS_PARSER_H_INCLUDED  */