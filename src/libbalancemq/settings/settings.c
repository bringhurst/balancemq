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
    FILE* settings_file = NULL;

    BALANCE_scanner_t* scanner = (BALANCE_scanner_t*) malloc(sizeof(BALANCE_scanner_t));
    scanner->context = ctx;

    balance_settings_yylex_init(scanner->state);
    LOG(ctx, BALANCE_LOG_DBG, "Passed yylex_init.");

    balance_settings_yylex_init_extra(scanner, scanner->state);
    LOG(ctx, BALANCE_LOG_DBG, "Passed yylex_init_extra.");

    settings_file = fopen(path, "r");
    if(settings_file == NULL) {
        LOG(ctx, BALANCE_LOG_ERR, "Could not open config file `%s'. %s", \
                path, strerror(errno));
        return BALANCE_ERR;
    }
    LOG(ctx, BALANCE_LOG_DBG, "Opened settings_file.");

    balance_settings_yyset_in(settings_file, &(scanner->state));
    LOG(ctx, BALANCE_LOG_DBG, "Passed yyset_in.");

    balance_settings_yyparse(scanner);
    LOG(ctx, BALANCE_LOG_DBG, "Passed yyparse.");

    balance_settings_yylex_destroy(scanner->state);
    LOG(ctx, BALANCE_LOG_DBG, "Passed yylex_destroy.");

    //fclose(settings_file);
    return BALANCE_OK;
}

int balance_settings_yyerror(void *locp, BALANCE_scanner_t* context, const char* msg)
{
    /* TODO: Use settings somehow? */
    fprintf(stderr, "Configuration file parse error: `%s'\n", msg);
    return 0;
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
