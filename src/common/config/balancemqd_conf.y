%{
 /* Parser for a balancemqd.conf file. */

 #include "balancemqd_conf.h"

 void yyerror(const char *str) {
     fprintf(stderr,"error: %s\n",str);
 }
 
 int yywrap() {
     return 1;
 }

 int yylex(void);
%}

%defines
%error-verbose

/* Tokens for header file generation. */
%token <string> T_IDENTIFIER T_EQUAL T_LBRACE T_RBRACE T_COMMA
%token <double_type> T_DOUBLE
%token <integer_type> T_INTEGER

%union {
    char* string;
    float double_type;
    int integer_type;
}

%%
 /* FIXME: bnf here */
%%
