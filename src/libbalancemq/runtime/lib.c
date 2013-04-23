/* This is the internal implementation of each api hook. */

#include "balancemq/balancemq.h"
#include "log.h"

#include <stdio.h>

int BALANCE_init_context(BALANCE_context_t* context)
{
    int ret = BALANCE_OK;

    if(context == NULL) {
        context = (BALANCE_context_t*) malloc(sizeof(BALANCE_context_t));
    } else {
        ret = BALANCE_ERR;
    }

    context->log_level = BALANCE_LOG_DBG;
    context->log_stream = stdout;

    return ret;
}

int BALANCE_free_context(BALANCE_context_t* context)
{
    /* TODO: not implemented yet. */
    return BALANCE_ERR;
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

void BALANCE_set_logging(BALANCE_context_t* context, \
                         int fd, \
                         int level)
{
    /* TODO; not implemented yet */
    return BALANCE_ERR;
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
