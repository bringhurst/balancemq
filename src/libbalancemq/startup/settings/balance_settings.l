%top {
  /* A lexer for balancemq.conf */

  /* Needed for extra type BALANCE_settings_t and YYSTYPE. */
  #include "balancemq/settings.h"
  #define YYSTYPE BALANCE_SETTINGS_YYSTYPE

  /* Include for token constants. */
  #include "balancemq_settings.parser.h"
}

%option 8bit reentrant warn
%option bison-bridge nounput
%option align read perf-report

%option prefix="balance_settings_yy"
%option outfile="balance_settings.scanner.c"

%option extra-type="BALANCE_settings_t*"

WHITESPACE            [ \t\n]
IDENTIFIER            [a-zA-Z_][a-zA-Z0-9_]*
DOUBLE                [0-9]+\.[0-9]*
INTEGER               [0-9]+

%x                    comment

%%

%{
  BALANCE_settings_t* settings_tree = yyextra;
%}

WHITESPACE            ; /* Ignore this token. */

"/*"                  BEGIN(comment); /* Handle C-style comments. */

<comment>{
    [^*\n]*           ; /* Ignore anything that's not a '*'. */
    "*"+[^*/\n]*      ; /* Ignore '*'s not followed by a '/'. */
    "*"+"/"           BEGIN(INITIAL);
}
     
"{"                   return T_LBRACE;
"}"                   return T_RBRACE;
","                   return T_COMMA;

IDENTIFIER            %{
                          yylval->string_value = yytext;
                          return T_IDENTIFIER;
                      %}

DOUBLE                %{
                          yylval->double_value = atof(yytext);
                          return T_DOUBLE;
                      %}

INTEGER               %{
                          yylval->integer_value = atoi(yytext);
                          return T_INTEGER;
                      %}

.                     %{
                          printf("Unknown token in settings file.\n");
                          yyterminate();
                      %}

%%

/* EOF */
