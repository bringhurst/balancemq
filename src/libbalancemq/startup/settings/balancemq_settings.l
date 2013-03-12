/* A lexer for balancemq.conf */

%option prefix="balancemq_settings_yy"

%{
 extern int balancemq_settings_yywrap() {
     /* Nothing */
 }
%}

%%

[ \t\n]                 ;
[a-zA-Z_][a-zA-Z0-9_]*  balancemq_settings_yylval = balancemq_settings_yytext; return T_IDENTIFIER;
[0-9]+\.[0-9]*          balancemq_settings_yylval = atof(balancemq_settings_yytext); return T_DOUBLE
[0-9]+                  balancemq_settings_yylval = atoi(balancemq_settings_yytext); return T_INTEGER;

"{"                     return T_LBRACE;
"}"                     return T_RBRACE;
","                     return T_COMMA;

.                       printf("Unknown token in settings file.\n"); balancemq_settings_yyterminate();

%%
