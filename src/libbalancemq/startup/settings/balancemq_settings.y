/* Parser for a balancemq.conf file. */

%require "2.7"

%define api.prefix balancemq_settings_yy
%define api.pure full
%define api.push-pull push

%code top {
  #define _GNU_SOURCE
  #include <stdio.h>
}

%code requires {
  #include <log.h>
  #include <xlist.h>

  #include "settings.h"
  #include "balancemq_settings.h"
}

%code provides {
 extern int balancemq_settings_yylex(void);
}

%union {
    char* string_value;
    float double_value;
    int   integer_value;

    BALANCEMQ_settings_value_t*    balance_value;
    BALANCEMQ_settings_variable_t* variable_value;
    BALANCEMQ_settings_block_t*    block_value;
    BALANCEMQ_settings_t*          settings_value;
    BALANCEMQ_list_t*              list_value;
}

%token <string_value>  T_IDENTIFIER T_LBRACE T_RBRACE
%token <double_value>  T_DOUBLE
%token <integer_value> T_INTEGER

%type <balance_value>  value
%type <variable_value> var_decl
%type <block_value>    block
%type <settings_value> settings
%type <list_value>     blocks var_decls

/* TODO: define destructors */

%%

/* Build a BALANCEMQ_settings_t */
settings  : /* nothing */ {
                $$ = (BALANCEMQ_settings_t*) NULL;
            }
          | blocks {
                $$ = BALANCEMQ_settings_create_settings();
                BALANCEMQ_list_push($$->blocks, $1);
            }
          ;

/* Build a BALANCEMQ_list_t for BALANCEMQ_settings_block_t */
blocks    : block {
                $$ = BALANCEMQ_list_create();
                BALANCEMQ_list_push($$, $1);
            }
          | blocks block {
                BALANCEMQ_list_push($$, $2);
            }
          ;

/* Build a BALANCEMQ_settings_block_t */
block     : T_IDENTIFIER T_LBRACE var_decls T_RBRACE {
                $$ = BALANCEMQ_settings_create_block($1);
                BALANCEMQ_list_push($$->variables, $3);
            }
          ;

/* Build a BALANCEMQ_list_t for BALANCEMQ_settings_variable_t */
var_decls : var_decl {
                $$ = BALANCEMQ_list_create();
                BALANCEMQ_list_push($$, $1);
            }
          | var_decls var_decl {
                BALANCEMQ_list_push($$, $2);
            }
          ;

/* Build BALANCEMQ_settings_variable_t */
var_decl  : T_IDENTIFIER[key] value { $$ = BALANCEMQ_settings_create_variable($key, $value); }
          ;

/* Build BALANCEMQ_settings_value_t */
value     : T_IDENTIFIER { $$ = BALANCEMQ_settings_create_string_value($1); }
          | T_INTEGER    { $$ = BALANCEMQ_settings_create_integer_value($1); }
          | T_DOUBLE     { $$ = BALANCEMQ_settings_create_double_value($1); }
          ;

%%
