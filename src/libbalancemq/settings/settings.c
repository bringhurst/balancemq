#include <balancemq/balancemq.h>
#include <balancemq/settings.h>

#include "balance_settings.scanner.h"
#include "balance_settings.parser.h"

#include <log.h>

#include <errno.h>
#include <stdlib.h>
#include <string.h>

int BALANCE_parse_settings(BALANCE_context_t* ctx, char* path)
{
    FILE* settings_file;
    yyscan_t scanner;
    BALANCE_settings_t* settings = NULL;

    balance_settings_yylex_init(&scanner);
    balance_settings_yylex_init_extra(settings, &scanner);

    settings_file = fopen(path, "r");
    if(settings_file == NULL) {
        LOG(ctx, BALANCE_LOG_ERR, "Could not open config file `%s'. %s", \
                path, strerror(errno));
        return BALANCE_ERR;
    }

    balance_settings_yyset_in(settings_file, scanner);

    balance_settings_yyparse(scanner);
    //balance_settings_yylex(NULL, scanner);

    balance_settings_yylex_destroy(scanner);

    ctx->settings = settings;

    return BALANCE_OK;
}

void balance_settings_yyerror(BALANCE_settings_t* settings, const char* msg)
{
    /* TODO: Use settings somehow? */
    fprintf(stderr, "Configuration file parse error: `%s'\n", msg);
}

BALANCE_settings_t* BALANCE_settings_create_settings()
{
    BALANCE_settings_t* settings = \
        (BALANCE_settings_t*) malloc(sizeof(BALANCE_settings_t));

    settings->blocks = NULL;

    return settings;
}

BALANCE_settings_block_t* BALANCE_settings_create_block()
{
    BALANCE_settings_block_t* block = \
        (BALANCE_settings_block_t*) malloc(sizeof(BALANCE_settings_block_t));

    block->blocks = NULL;
    block->variables = NULL;

    return block;
}

BALANCE_settings_variable_t* BALANCE_settings_create_variable(char* key, BALANCE_settings_value_t* value)
{
    BALANCE_settings_variable_t* variable = \
        (BALANCE_settings_variable_t*) malloc(sizeof(BALANCE_settings_variable_t));

    variable->key = (char*) malloc(sizeof(char) * BALANCE_SETTINGS_MAX_KEY_LENGTH);
    variable->value = value;

    strncpy(variable->key, key, BALANCE_SETTINGS_MAX_KEY_LENGTH);
    variable->key[BALANCE_SETTINGS_MAX_KEY_LENGTH - 1] = '\0';

    return variable;
}

BALANCE_settings_value_t* BALANCE_settings_create_string_value(char* value)
{
    BALANCE_settings_value_t* settings_value = \
        (BALANCE_settings_value_t*) malloc(sizeof(BALANCE_settings_value_t));

    settings_value->type = BALANCE_SETTINGS_STRING;
    settings_value->u.sval = value;

    return settings_value;
}

BALANCE_settings_value_t* BALANCE_settings_create_integer_value(int value)
{
    BALANCE_settings_value_t* settings_value = \
        (BALANCE_settings_value_t*) malloc(sizeof(BALANCE_settings_value_t));

    settings_value->type = BALANCE_SETTINGS_INTEGER;
    settings_value->u.ival = value;

    return settings_value;
}

BALANCE_settings_value_t* BALANCE_settings_create_double_value(double value)
{
    BALANCE_settings_value_t* settings_value = \
        (BALANCE_settings_value_t*) malloc(sizeof(BALANCE_settings_value_t));

    settings_value->type = BALANCE_SETTINGS_DOUBLE;
    settings_value->u.dval = value;

    return settings_value;
}

/* EOF */
