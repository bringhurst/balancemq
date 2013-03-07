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
%token <string> T_IDENTIFIER T_LBRACE T_RBRACE T_COMMA
%token <double_type> T_DOUBLE
%token <integer_type> T_INTEGER

%union {
    char* string;
    float double_type;
    int integer_type;
}

%type <block> config
%type <statement> stmt
%type <decl> var_decl
%type <block> block

%%
config : blocks { configBlock = $1; }
       ;

blocks : block
       | blocks block
       ;

block : T_IDENTIFIER T_LBRACE var_decls T_RBRACE { $$ = $2; }
      | T_IDENTIFIER T_LBRACE T_RBRACE { $$ = balancemq_config_create_block(); }
      ;

var_decls : var_decl { $$ = balancemq_config_create_block(); $$->statements.push($<stmt>1); }
          | var_decls T_COMMA var_decl { $1->statements.push($<stmt>2); }
          ;

var_decl : ident value { $$ = balancemq_config_create_keyvalue(*$1, *$2); }
         ;

value : T_IDENTIFIER { $$ = balancemq_config_create_string_identifier(*$1); }
      | TINTEGER { $$ = balancemq_config_create_integer_identifier(atol($1->c_str())); }
      | TDOUBLE { $$ = balancemq_config_create_double_identifier(atof($1->c_str())); }
      ;
%%
