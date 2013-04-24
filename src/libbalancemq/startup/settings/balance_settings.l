%top {
  /* A lexer for balancemq.conf */

  /* Needed for extra type BALANCE_settings_t and YYSTYPE. */
  #include <balancemq/settings.h>
  #define YYSTYPE BALANCE_SETTINGS_YYSTYPE

  /* Include for token constants. */
  #include "balance_settings.parser.h"
}

%option 8bit reentrant warn
%option bison-bridge nounput
%option align read perf-report
%option noyywrap yylineno

%option prefix="balance_settings_yy"
%option outfile="balance_settings.scanner.c"

WHITESPACE            [ \t\n]
IDENTIFIER            [a-zA-Z_][a-zA-Z0-9_]*
DOUBLE                [0-9]+\.[0-9]*
INTEGER               [0-9]+

%x                    COMMENT

%%

{WHITESPACE}          ; /* Ignore this token. */

"/*"                  { BEGIN(COMMENT); }
<COMMENT>"*/"         { BEGIN(INITIAL); }
<COMMENT>.            { }

"{"                   return T_LBRACE;
"}"                   return T_RBRACE;
","                   return T_COMMA;

{IDENTIFIER}          %{
                          printf("Found identifier: `%s'\n", yytext);
                          yylval->string_value = yytext;
                          return T_IDENTIFIER;
                      %}

{DOUBLE}              %{
                          yylval->double_value = atof(yytext);
                          return T_DOUBLE;
                      %}

{INTEGER}             %{
                          yylval->integer_value = atoi(yytext);
                          return T_INTEGER;
                      %}

.                     %{
                          printf("Unknown character found in configuration file: `%s'\n", yytext);
                      %}

%%

/* EOF */
