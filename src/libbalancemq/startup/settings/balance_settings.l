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

WHITESPACE            [ \t\n]*
IDENTIFIER            [a-zA-Z_/\.][a-zA-Z0-9_/\.]*
DOUBLE                [0-9]+\.[0-9]*
INTEGER               [0-9]+

%x                    IN_COMMENT

%%

{WHITESPACE}          { }

<INITIAL>{
"/*"                  BEGIN(IN_COMMENT);
}
<IN_COMMENT>{
"*/"                  BEGIN(INITIAL);
[^*\n]+               /* Ignore entire lines at a time. */
"*"                   /* Ignore solo stars. */
\n                    yylineno++;
}

"{"                   %{
                         printf("Found block start.\n");
                         return T_LBRACE;
                      %}

"}"                   %{
                         printf("Found block end.\n");
                         return T_RBRACE;
                      %}

{IDENTIFIER}          %{
                          printf("Found identifier: `%s'\n", yytext);
                          yylval->string_value = yytext;
                          return T_IDENTIFIER;
                      %}

{DOUBLE}              %{
                          printf("Found double value of: `%s'\n", yytext);
                          yylval->double_value = atof(yytext);
                          return T_DOUBLE;
                      %}

{INTEGER}             %{
                          printf("Found integer value of: `%s'\n", yytext);
                          yylval->integer_value = atoi(yytext);
                          return T_INTEGER;
                      %}

.                     %{
                          printf("Unknown character found in configuration file: `%s' at line `%d'\n", yytext, yylineno);
                      %}

%%

/* EOF */
