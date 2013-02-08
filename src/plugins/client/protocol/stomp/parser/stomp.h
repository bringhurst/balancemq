/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_CLIENT_SEND = 258,
     T_CLIENT_SUBSCRIBE = 259,
     T_CLIENT_UNSUBSCRIBE = 260,
     T_CLIENT_BEGIN = 261,
     T_CLIENT_COMMIT = 262,
     T_CLIENT_ABORT = 263,
     T_CLIENT_ACK = 264,
     T_CLIENT_NACK = 265,
     T_CLIENT_DISCONNECT = 266,
     T_CLIENT_CONNECT = 267,
     T_CLIENT_STOMP = 268,
     T_SERVER_CONNECTED = 269,
     T_SERVER_MESSAGE = 270,
     T_SERVER_RECEIPT = 271,
     T_SERVER_ERROR = 272,
     T_NULL = 273,
     T_LF = 274,
     T_CR = 275,
     T_EOL = 276,
     T_COLON = 277,
     T_OCTET = 278,
     T_SPECIAL = 279
   };
#endif
/* Tokens.  */
#define T_CLIENT_SEND 258
#define T_CLIENT_SUBSCRIBE 259
#define T_CLIENT_UNSUBSCRIBE 260
#define T_CLIENT_BEGIN 261
#define T_CLIENT_COMMIT 262
#define T_CLIENT_ABORT 263
#define T_CLIENT_ACK 264
#define T_CLIENT_NACK 265
#define T_CLIENT_DISCONNECT 266
#define T_CLIENT_CONNECT 267
#define T_CLIENT_STOMP 268
#define T_SERVER_CONNECTED 269
#define T_SERVER_MESSAGE 270
#define T_SERVER_RECEIPT 271
#define T_SERVER_ERROR 272
#define T_NULL 273
#define T_LF 274
#define T_CR 275
#define T_EOL 276
#define T_COLON 277
#define T_OCTET 278
#define T_SPECIAL 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 29 "stomp.y"

    stomp_node_t node;



/* Line 2068 of yacc.c  */
#line 104 "stomp.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


