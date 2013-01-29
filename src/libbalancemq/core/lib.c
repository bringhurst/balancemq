/* This is the internal implementation of each api hook. */

#include <balancemq.h>
#include <stdio.h>

/**
 * If not already accepting work, begin accepting new work items. Also, create
 * a new tagged queue with the specified item or, if the tagged queue already
 * exists, insert the item for processing.
 */
int BALANCE_insert(BALANCE_item_t* item)
{
    printf("BalanceMQ BALANCE_insert is not implemented yet.");
    return -1;
}

/**
 * The callback that allows work to be processed.
 */
void BALANCE_process(BALANCE_cb func)
{
    printf("BalanceMQ BALANCE_process is not implemented yet.");
    return;
}

/**
 * Ensure all work for a specified persistant tagged queue has been completed
 * and destroy the tagged queue.
 */
void BALANCE_finalize_persistant(char* tag)
{
    printf("BalanceMQ BALANCE_finalize_persistant is not implemented yet.");
    return;
}

/**
 * Define a callback for when a transient queue has finished.
 */
void BALANCE_finalize_transient(BALANCE_cb func)
{
    printf("BalanceMQ BALANCE_finalize_transient is not implemented yet.");
    return;
}

/**
 * Reject all new work and ensure all current work on this node has been
 * completed or passed to other workers.
 */
void BALANCE_shutdown(void)
{
    printf("BalanceMQ BALANCE_shutdown is not implemented yet.");
    return;
}

/**
 * Read/reread configuration file at the specified path.
 */
void BALANCE_read_config(char* path)
{
    printf("BalanceMQ BALANCE_read_config is not implemented yet.");
    return;
}

/**
 * Define the detail and location for logging.
 */
void BALANCE_setup_log(int fd, enum BALANCE_loglevel level)
{
    printf("BalanceMQ BALANCE_setup_log is not implemented yet.");
    return;
}

/* EOF */
