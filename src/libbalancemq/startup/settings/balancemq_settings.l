/* A lexer for balancemq.conf */

%option noyywrap nounput
%option reentrant
%option bison-bridge

%option prefix="balancemq_settings_yy"

WHITESPACE [ \t\n]
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
DOUBLE     [0-9]+\.[0-9]*
INTEGER    [0-9]+

%%

WHITESPACE ;
IDENTIFIER balancemq_settings_yylval = balancemq_settings_yytext; return T_IDENTIFIER;
DOUBLE     balancemq_settings_yylval = atof(balancemq_settings_yytext); return T_DOUBLE
INTEGER    balancemq_settings_yylval = atoi(balancemq_settings_yytext); return T_INTEGER;

"{"        return T_LBRACE;
"}"        return T_RBRACE;
","        return T_COMMA;

.          printf("Unknown token in settings file.\n"); balancemq_settings_yyterminate();

%%
