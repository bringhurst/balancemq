#ifndef _BALANCE_SETTINGS_H
#define _BALANCE_SETTINGS_H

#define BALANCE_SETTINGS_STRING  2
#define BALANCE_SETTINGS_INTEGER 4
#define BALANCE_SETTINGS_DOUBLE  8

#define BALANCE_SETTINGS_MAX_KEY_LENGTH 128

typedef struct {
  int type;
  union {
      int    ival;
      double dval;
      char*  sval;
  } u;
} BALANCE_settings_value_t;

typedef struct BALANCE_settings_variable_t {
    char* key;
    BALANCE_settings_value_t* value;
    struct BALANCE_settings_variable_t* next;
} BALANCE_settings_variable_t;

typedef struct BALANCE_settings_block_t {
    struct BALANCE_settings_block_t* blocks;
    BALANCE_settings_variable_t* variables;
    struct BALANCE_settings_block_t* next;
} BALANCE_settings_block_t;

typedef struct {
    BALANCE_settings_block_t* blocks;
} BALANCE_settings_t;

BALANCE_settings_t* BALANCE_settings_create_settings();
BALANCE_settings_block_t* BALANCE_settings_create_block();
BALANCE_settings_variable_t* BALANCE_settings_create_variable();

BALANCE_settings_value_t* BALANCE_settings_create_string_value(char* value);
BALANCE_settings_value_t* BALANCE_settings_create_integer_value(int value);
BALANCE_settings_value_t* BALANCE_settings_create_double_value(double value);

#endif /* _BALANCE_SETTINGS_H */
