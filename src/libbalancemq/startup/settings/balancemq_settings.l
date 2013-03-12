%top {
  /* A lexer for balancemq.conf */
}

%option noyywrap nounput
%option reentrant
%option bison-bridge

WHITESPACE [ \t\n]
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
DOUBLE     [0-9]+\.[0-9]*
INTEGER    [0-9]+

%%

WHITESPACE ; /* Ignore this token. */

"/*"       %{  /* Allow C-style comments. */
               register int c;
     
               for(;;) {
                   while((c = input()) != '*' && c != EOF)  {
                       ; /* Do nothing. */
                   }
     
                   if(c == '*') {
                       while ( (c = input()) == '*' ) {
                           ; /* Do nothing. */
                       }

                       if ( c == '/' ) {
                           break; /* The end of the comment. */
                       }
                   }
     
                   if(c == EOF) {
                       error("An EOF was found in a comment.");
                       break;
                   }
               }
           %}

"{"        return T_LBRACE;
"}"        return T_RBRACE;
","        return T_COMMA;

IDENTIFIER %{
               balancemq_settings_yylval = balancemq_settings_yytext;
               return T_IDENTIFIER;
           %}

DOUBLE     %{
               balancemq_settings_yylval = atof(balancemq_settings_yytext);
               return T_DOUBLE;
           %}

INTEGER    %{
               balancemq_settings_yylval = atoi(balancemq_settings_yytext);
               return T_INTEGER;
           %}

.          printf("Unknown token in settings file.\n"); balancemq_settings_yyterminate();

%%

/* EOF */
