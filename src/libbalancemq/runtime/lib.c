/* This is the internal implementation of each api hook. */

#include "balancemq/balancemq.h"
#include "log.h"

#include <stdlib.h>
#include <stdio.h>

int BALANCE_init_context(BALANCE_context_t* context)
{
    int ret = BALANCE_OK;

    if(context != NULL) {
        ret = BALANCE_ERR;

        /* Since we don't have a valid context, just log to stderr. */
        fprintf(stderr, "Attempted to initialize a non-null context. "
                "Possible bug detected at `%s:%d'.\n",
                __FILE__, __LINE__);
    }

    context = (BALANCE_context_t*) malloc(sizeof(BALANCE_context_t));

    if(context == NULL) {
        /* Since we don't have a valid context, just log to stderr. */
        fprintf(stderr, "Allocating memory for a new context failed. "
                "Possible bug detected at `%s:%d'.\n",
                __FILE__, __LINE__);
        ret = BALANCE_ERR;
    }

    ret = BALANCE_set_logging(context, stdout, BALANCE_LOG_DBG);

    return ret;
}

int BALANCE_free_context(BALANCE_context_t* context)
{
    /* TODO: not completely implemented yet? */
    free(context);
    return BALANCE_OK;
}

int BALANCE_simple_startup(BALANCE_cb process_callback, \
                           BALANCE_item_t* seed_item)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
} 

int BALANCE_accept(BALANCE_context_t* context, \
                   BALANCE_channel_t** channels)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
}

int BALANCE_query_channels(BALANCE_context_t* context, \
                           BALANCE_channel_t** channels)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
}

int BALANCE_insert(BALANCE_context_t* context, \
                   BALANCE_item_t* item)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
}

int BALANCE_enable_termination(BALANCE_context_t* context, \
                               char* channel_name)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
}

int BALANCE_set_configuration(BALANCE_context_t* context, \
                              char* path)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
}

int BALANCE_set_logging(BALANCE_context_t* context, \
                        FILE* file, \
                        int level)
{
    /* TODO: more error checking here. */

    context->log_file = file;
    context->log_level = level;

    return BALANCE_OK;
}

int BALANCE_set_startup_callback(BALANCE_context_t* context, \
                                 BALANCE_cb func)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
}

int BALANCE_set_process_callback(BALANCE_context_t* context, \
                                 BALANCE_cb func)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
}

int BALANCE_set_empty_callback(BALANCE_context_t* context, \
                               BALANCE_cb func)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
}

int BALANCE_set_terminate_callback(BALANCE_context_t* context, \
                                   BALANCE_cb func)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
}

/* EOF */
