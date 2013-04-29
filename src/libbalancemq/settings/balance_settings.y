/* Parser for a balancemq.conf file. */

%require "2.7"

%define api.prefix balance_settings_yy
%define api.pure

%file-prefix "balance_settings.parser"

%locations

%lex-param { yyscan_t scanner }
%parse-param { BALANCE_scanner_t* bscanner }

%code top {
}

%code requires {
  #include <log.h>
  #include <balancemq/settings.h>
  #include "private_settings.h"

  #include <stdio.h>

  int yyerror(void *locp, BALANCE_scanner_t* bscanner, const char* msg);

  typedef union BALANCE_SETTINGS_YYSTYPE
  {
      char* string_value;
      float double_value;
      int   integer_value;

      BALANCE_settings_value_t*     balance_value;
      BALANCE_settings_variable_t*  variable_value;
      BALANCE_settings_block_t*     block_value;
      BALANCE_settings_t*           settings_value;
  } BALANCE_SETTINGS_YYSTYPE;

//  #define scanner bscanner->state
}

%token <string_value>  T_IDENTIFIER T_LBRACE T_RBRACE
%token <double_value>  T_DOUBLE
%token <integer_value> T_INTEGER

%type <balance_value>  value
%type <variable_value> var_decl var_decls
%type <block_value>    block blocks
%type <settings_value> settings

%start settings

/* TODO: define destructors */

%%

/* Build a BALANCE_settings_t */
settings  : /* nothing */ {
                printf("Creating null settings.\n");
                $$ = (BALANCE_settings_t*) NULL;
            }
          | blocks {
                printf("Creating settings.\n");
                $$ = BALANCE_settings_create_settings();
                $$->blocks = $blocks;
            }
          ;

/* Build list of BALANCE_settings_block_t** */
blocks    : block {
                printf("Creating block list.\n");
                $$ = $block;
            }
          | blocks block {
                printf("Appending to block list.\n");
                BALANCE_settings_block_t* next = $1->next;
                $block->next = next;
                $$->next = $block;
            }
          ;

/* Build a BALANCE_settings_block_t */
block     : T_IDENTIFIER T_LBRACE var_decls T_RBRACE {
                printf("Creating block.\n");
                $$ = BALANCE_settings_create_block();
                $$->variables = $var_decls;
            }
          | T_IDENTIFIER T_LBRACE blocks T_RBRACE {
                printf("Creating subblocks.\n");
                $$ = BALANCE_settings_create_block();
                $$->blocks = $blocks;
            }
          ;

/* Build list of BALANCE_settings_variable_t** */
var_decls : var_decl {
                printf("Creating variable list.\n");
                $$ = $var_decl;
            }
          | var_decls var_decl {
                printf("Appending to variable list.\n");
                BALANCE_settings_variable_t* next = $1->next;
                $var_decl->next = next;
                $$ = $var_decl;
            }
          ;

/* Build BALANCE_settings_variable_t */
var_decl  : T_IDENTIFIER[key] value {
                printf("Creating variable.\n");
                $$ = BALANCE_settings_create_variable($key, $value);
            }
          ;

/* Build BALANCE_settings_value_t */
value     : T_IDENTIFIER {
                printf("Creating string variable value.\n");
                $$ = BALANCE_settings_create_string_value($1);
            }
          | T_INTEGER    {
                printf("Creating integer variable value.\n");
                $$ = BALANCE_settings_create_integer_value($1);
            }
          | T_DOUBLE     {
                printf("Creating double variable value.\n");
                $$ = BALANCE_settings_create_double_value($1);
             }
          ;

%%

/* EOF */
