/* Parser for a balancemq.conf file. */

%require "2.7"

%define api.prefix balance_settings_yy
%define api.pure

%file-prefix "balance_settings.parser"

%lex-param {void* scanner}
%parse-param { void* scanner }

%code top {
/*  #define _GNU_SOURCE */
}

%code requires {
  #include <balancemq/settings.h>
  #include <log.h>
  #include <stdio.h>

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

  int yyerror(BALANCE_settings_t* settings, const char* msg);
//  int yylex(void* scanner);
}

%token <string_value>  T_IDENTIFIER T_LBRACE T_RBRACE T_COMMA
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
                $$ = (BALANCE_settings_t*) NULL;
            }
          | blocks {
                $$ = BALANCE_settings_create_settings();
                $$->blocks = $blocks;
            }
          ;

/* Build list of BALANCE_settings_block_t** */
blocks    : block {
                $$ = $block;
            }
          | blocks block {
                BALANCE_settings_block_t* next = $1->next;
                $block->next = next;
                $$->next = $block;
            }
          ;

/* Build a BALANCE_settings_block_t */
block     : T_IDENTIFIER T_LBRACE var_decls T_RBRACE {
                $$ = BALANCE_settings_create_block($1);
                $$->variables = $var_decls;
            }
          | T_IDENTIFIER T_LBRACE blocks T_RBRACE {
                $$ = BALANCE_settings_create_block($1);
                $$->blocks = $blocks;
            }
          ;

/* Build list of BALANCE_settings_variable_t** */
var_decls : var_decl {
                $$ = $var_decl;
            }
          | var_decls var_decl {
                BALANCE_settings_variable_t* next = $1->next;
                $var_decl->next = next;
                $$ = $var_decl;
            }
          ;

/* Build BALANCE_settings_variable_t */
var_decl  : T_IDENTIFIER[key] value { $$ = BALANCE_settings_create_variable($key, $value); }
          ;

/* Build BALANCE_settings_value_t */
value     : T_IDENTIFIER { $$ = BALANCE_settings_create_string_value($1); }
          | T_INTEGER    { $$ = BALANCE_settings_create_integer_value($1); }
          | T_DOUBLE     { $$ = BALANCE_settings_create_double_value($1); }
          ;

%%

/* EOF */
