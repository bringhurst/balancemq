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

#ifndef YY_BALANCEMQ_SETTINGS_YY_BALANCEMQ_SETTINGS_H_INCLUDED
# define YY_BALANCEMQ_SETTINGS_YY_BALANCEMQ_SETTINGS_H_INCLUDED
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
#line 14 "balancemq_settings.y"

  #include "balancemq_settings.h"


/* Line 2058 of yacc.c  */
#line 59 "balancemq_settings.h"

/* Tokens.  */
#ifndef BALANCEMQ_SETTINGS_YYTOKENTYPE
# define BALANCEMQ_SETTINGS_YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum balancemq_settings_yytokentype {
     T_IDENTIFIER = 258,
     T_LBRACE = 259,
     T_RBRACE = 260,
     T_DOUBLE = 261,
     T_INTEGER = 262
   };
#endif
/* Tokens.  */
#define T_IDENTIFIER 258
#define T_LBRACE 259
#define T_RBRACE 260
#define T_DOUBLE 261
#define T_INTEGER 262



#if ! defined BALANCEMQ_SETTINGS_YYSTYPE && ! defined BALANCEMQ_SETTINGS_YYSTYPE_IS_DECLARED
typedef union BALANCEMQ_SETTINGS_YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 31 "balancemq_settings.y"

    const char* string_value;
    float       double_value;
    int         integer_value;

    BALANCEMQ_settings_value_t*    balance_value;
    BALANCEMQ_settings_variable_t* variable_value;
    BALANCEMQ_settings_block_t*    block_value;
    BALANCEMQ_settings_t*          settings_value;
    BALANCEMQ_settings_list_t*     list_value;


/* Line 2058 of yacc.c  */
#line 101 "balancemq_settings.h"
} BALANCEMQ_SETTINGS_YYSTYPE;
# define BALANCEMQ_SETTINGS_YYSTYPE_IS_TRIVIAL 1
# define balancemq_settings_yystype BALANCEMQ_SETTINGS_YYSTYPE /* obsolescent; will be withdrawn */
# define BALANCEMQ_SETTINGS_YYSTYPE_IS_DECLARED 1
#endif


#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct balancemq_settings_yypstate balancemq_settings_yypstate;

#if defined __STDC__ || defined __cplusplus
int balancemq_settings_yypush_parse (balancemq_settings_yypstate *ps, int pushed_char, BALANCEMQ_SETTINGS_YYSTYPE const *pushed_val);
#else
int balancemq_settings_yypush_parse ();
#endif

#if defined __STDC__ || defined __cplusplus
balancemq_settings_yypstate * balancemq_settings_yypstate_new (void);
#else
balancemq_settings_yypstate * balancemq_settings_yypstate_new ();
#endif
#if defined __STDC__ || defined __cplusplus
void balancemq_settings_yypstate_delete (balancemq_settings_yypstate *ps);
#else
void balancemq_settings_yypstate_delete ();
#endif
/* "%code provides" blocks.  */
/* Line 2058 of yacc.c  */
#line 18 "balancemq_settings.y"

 void balancemq_settings_yyerror(const char *str) {
     /* TODO: use common logging here. */
     fprintf(stderr,"error: %s\n",str);
 }
 
 int balancemq_settings_yywrap() {
     return 1;
 }

 extern int balancemq_settings_yylex(void);


/* Line 2058 of yacc.c  */
#line 149 "balancemq_settings.h"

#endif /* !YY_BALANCEMQ_SETTINGS_YY_BALANCEMQ_SETTINGS_H_INCLUDED  */
