/* Parser for a balancemq.conf file. */

%require "2.7"

%define api.pure full
%define api.push-pull push

%code top {
  #define _GNU_SOURCE
  #include <stdio.h>
}

%code requires {
  #include "balancemq_conf.h"
}

%code provides {
 void yyerror(const char *str) {
     fprintf(stderr,"error: %s\n",str);
 }
 
 int yywrap() {
     return 1;
 }

 extern int yylex(void);
}

%union {
    const char* string_value;
    float double_value;
    int integer_value;

    BALANCEMQ_config_value_t*    balance_value;
    BALANCEMQ_config_variable_t* variable_value;
    BALANCEMQ_config_block_t*    block_value;
    BALANCEMQ_config_t*          config_value;
    BALANCEMQ_config_list_t*     list_value;
}

%token <string>        T_IDENTIFIER T_LBRACE T_RBRACE
%token <double_type>   T_DOUBLE
%token <integer_type>  T_INTEGER

%type <balance_value>  value
%type <variable_value> var_decl
%type <block_value>    block
%type <config_value>   config
%type <list_value>     blocks var_decls

%%
config    : /* nothing */ {
                $$ = (BALANCEMQ_config_t*) NULL;
               }
          | blocks {
                $$ = BALANCEMQ_config_create_config();
                $$->push($1);
            }
          ;

blocks    : block {
                $$ = BALANCEMQ_config_create_blocklist();
                $$->push($1);
            }
          | blocks block {
                $$->push($2);
            }
          ;

block     : T_IDENTIFIER T_LBRACE var_decls T_RBRACE {
                $$ = BALANCEMQ_config_create_block($1);
                $$->push($3);
            }
          ;

var_decls : var_decl {
                $$ = BALANCEMQ_config_create_variable_list();
                $$->push($1);
            }
          | var_decls var_decl {
                $$->push($2);
            }
          ;

/* Build BALANCEMQ_config_variable_t */
var_decl  : T_IDENTIFIER[key] value { $$ = balancemq_config_create_variable($key, $value); }
          ;

/* Build BALANCEMQ_config_value_t */
value     : T_IDENTIFIER { $$ = BALANCEMQ_config_create_string_value($1); }
          | T_INTEGER    { $$ = BALANCEMQ_config_create_integer_value($1); }
          | T_DOUBLE     { $$ = BALANCEMQ_config_create_double_value($1); }
          ;

%%
