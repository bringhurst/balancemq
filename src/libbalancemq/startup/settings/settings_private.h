#ifndef _BALANCEMQ_SETTINGS_H
#define _BALANCEMQ_SETTINGS_H

#include "../../common/list.h"

#define BALANCEMQ_SETTINGS_STRING  2
#define BALANCEMQ_SETTINGS_INTEGER 4
#define BALANCEMQ_SETTINGS_DOUBLE  8

typedef struct {
  int value_type;
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

#endif /* _BALANCEMQ_SETTINGS_H */
