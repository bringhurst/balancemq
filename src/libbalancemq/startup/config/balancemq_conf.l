%{
 /* A simple config file lexer. */

 #include "config.h"

 extern int yywrap()
 {
     /* Nothing */
 }
%}

%%

[ \t\n]                 ;
[a-zA-Z_][a-zA-Z0-9_]*  yylval = yytext; return T_IDENTIFIER;
[0-9]+\.[0-9]*          yylval = atof(yytext); return T_DOUBLE
[0-9]+                  yylval = atoi(yytext); return T_INTEGER;

"{"                     return T_LBRACE;
"}"                     return T_RBRACE;
","                     return T_COMMA;

.                       printf("Unknown token in configuration file.\n"); yyterminate();

%%
