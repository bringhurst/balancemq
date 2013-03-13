#include "settings.h"

#include "balancemq_settings.scanner.h"
#include "balancemq_settings.parser.h"

#include <log.h>

#include <errno.h>
#include <stdlib.h>
#include <string.h>

BALANCEMQ_settings_t* BALANCEMQ_parse_settings(char* path)
{
    FILE* settings_file;
    yyscan_t scanner;
    BALANCEMQ_settings_t* settings = NULL;

    balancemq_settings_yylex_init(&scanner);
    balancemq_settings_yylex_init_extra(settings, &scanner);

    settings_file = fopen(path, "r");
    if(settings_file == NULL) {
        LOG("Could not open config file `%s'. %s", path, strerror(errno));
        return NULL;
    }
    balancemq_settings_yyset_in(settings_file, scanner);

    balancemq_settings_yylex(NULL, scanner);

    balancemq_settings_yylex_destroy(scanner);
    return NULL;
}

void balancemq_settings_yyerror(const char* msg)
{
    LOG(BALANCEMQ_LOG_DBG, "settings yyerror reported `%s'", msg);
}

BALANCEMQ_settings_t* BALANCEMQ_settings_create_settings()
{
    BALANCEMQ_settings_t* settings = \
        (BALANCEMQ_settings_t*) malloc(sizeof(BALANCEMQ_settings_t));

    return settings;
}

BALANCEMQ_settings_block_t* BALANCEMQ_settings_create_block()
{
    BALANCEMQ_settings_block_t* block = \
        (BALANCEMQ_settings_block_t*) malloc(sizeof(BALANCEMQ_settings_block_t));

    return block;
}

BALANCEMQ_settings_variable_t* BALANCEMQ_settings_create_variable(char* key, BALANCEMQ_settings_value_t* value)
{
    BALANCEMQ_settings_variable_t* variable = \
        (BALANCEMQ_settings_variable_t*) malloc(sizeof(BALANCEMQ_settings_variable_t));

    variable->key = (char*) malloc(sizeof(char) * BALANCEMQ_SETTINGS_MAX_KEY_LENGTH);
    variable->value = value;

    strncpy(variable->key, key, BALANCEMQ_SETTINGS_MAX_KEY_LENGTH);
    variable->key[BALANCEMQ_SETTINGS_MAX_KEY_LENGTH - 1] = '\0';

    return variable;
}

BALANCEMQ_settings_value_t* BALANCEMQ_settings_create_string_value(char* value)
{
    BALANCEMQ_settings_value_t* settings_value = \
        (BALANCEMQ_settings_value_t*) malloc(sizeof(BALANCEMQ_settings_value_t));

    settings_value->type = BALANCEMQ_SETTINGS_STRING;
    settings_value->u.sval = value;

    return settings_value;
}

BALANCEMQ_settings_value_t* BALANCEMQ_settings_create_integer_value(int value)
{
    BALANCEMQ_settings_value_t* settings_value = \
        (BALANCEMQ_settings_value_t*) malloc(sizeof(BALANCEMQ_settings_value_t));

    settings_value->type = BALANCEMQ_SETTINGS_INTEGER;
    settings_value->u.ival = value;

    return settings_value;
}

BALANCEMQ_settings_value_t* BALANCEMQ_settings_create_double_value(double value)
{
    BALANCEMQ_settings_value_t* settings_value = \
        (BALANCEMQ_settings_value_t*) malloc(sizeof(BALANCEMQ_settings_value_t));

    settings_value->type = BALANCEMQ_SETTINGS_DOUBLE;
    settings_value->u.dval = value;

    return settings_value;
}

/* EOF */
