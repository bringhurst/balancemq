/* A lexer for balancemq.conf */

%option prefix="balancemq_config_yy"

%{
 #include "config.h"

 extern int balancemq_config_yywrap() {
     /* Nothing */
 }
%}

%%

[ \t\n]                 ;
[a-zA-Z_][a-zA-Z0-9_]*  balancemq_config_yylval = balancemq_config_yytext; return T_IDENTIFIER;
[0-9]+\.[0-9]*          balancemq_config_yylval = atof(balancemq_config_yytext); return T_DOUBLE
[0-9]+                  balancemq_config_yylval = atoi(balancemq_config_yytext); return T_INTEGER;

"{"                     return T_LBRACE;
"}"                     return T_RBRACE;
","                     return T_COMMA;

.                       printf("Unknown token in configuration file.\n"); balancemq_config_yyterminate();

%%
