#ifndef _BALANCEMQ_SETTINGS_H
#define _BALANCEMQ_SETTINGS_H

#include <xlist.h>

#define BALANCEMQ_SETTINGS_STRING  2
#define BALANCEMQ_SETTINGS_INTEGER 4
#define BALANCEMQ_SETTINGS_DOUBLE  8

#define BALANCEMQ_SETTINGS_MAX_KEY_LENGTH 128

typedef struct {
  int type;
  union {
      int    ival;
      double dval;
      char*  sval;
  } u;
} BALANCEMQ_settings_value_t;

typedef struct {
    char* key;
    BALANCEMQ_settings_value_t* value;
} BALANCEMQ_settings_variable_t;

typedef struct {
    BALANCEMQ_list_t* blocks;
    BALANCEMQ_list_t* variables;
} BALANCEMQ_settings_block_t;

typedef struct {
    BALANCEMQ_list_t* blocks;
} BALANCEMQ_settings_t;


typedef union BALANCEMQ_SETTINGS_YYSTYPE
{
    char* string_value;
    float double_value;
    int   integer_value;

    BALANCEMQ_settings_value_t*    balance_value;
    BALANCEMQ_settings_variable_t* variable_value;
    BALANCEMQ_settings_block_t*    block_value;
    BALANCEMQ_settings_t*          settings_value;
    BALANCEMQ_list_t*              list_value;
} BALANCEMQ_SETTINGS_YYSTYPE;

BALANCEMQ_settings_t* BALANCEMQ_settings_create_settings();
BALANCEMQ_settings_block_t* BALANCEMQ_settings_create_block();
BALANCEMQ_settings_variable_t* BALANCEMQ_settings_create_variable();

BALANCEMQ_settings_value_t* BALANCEMQ_settings_create_string_value(char* value);
BALANCEMQ_settings_value_t* BALANCEMQ_settings_create_integer_value(int value);
BALANCEMQ_settings_value_t* BALANCEMQ_settings_create_double_value(double value);

#endif /* _BALANCEMQ_SETTINGS_H */
