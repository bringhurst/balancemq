%top {
  /* A lexer for balancemq.conf */
}

%option noyywrap nounput
%option reentrant
%option bison-bridge

WHITESPACE            [ \t\n]
IDENTIFIER            [a-zA-Z_][a-zA-Z0-9_]*
DOUBLE                [0-9]+\.[0-9]*
INTEGER               [0-9]+

%%

WHITESPACE            ; /* Ignore this token. */

"/*"                  BEGIN(comment); /* Handle C-style comments. */
<comment>[^*\n]*      ; /* Ignore anything that's not a '*'. */
<comment>"*"+[^*/\n]* ; /* Ignore '*'s not followed by a '/'. */
<comment>"*"+"/"      BEGIN(INITIAL);
     
"{"                   return T_LBRACE;
"}"                   return T_RBRACE;
","                   return T_COMMA;

IDENTIFIER            %{
                          balancemq_settings_yylval = balancemq_settings_yytext;
                          return T_IDENTIFIER;
                      %}

DOUBLE                %{
                          balancemq_settings_yylval = atof(balancemq_settings_yytext);
                          return T_DOUBLE;
                      %}

INTEGER               %{
                          balancemq_settings_yylval = atoi(balancemq_settings_yytext);
                          return T_INTEGER;
                      %}

.                     %{
                          printf("Unknown token in settings file.\n");
                          balancemq_settings_yyterminate();
                      %}

%%

/* EOF */
