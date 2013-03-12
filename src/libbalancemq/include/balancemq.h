#ifndef _BALANCEMQ_BALANCEMQ_H
#define _BALANCEMQ_BALANCEMQ_H

#include <stdint.h>

/* An item to be processed. */
typedef struct {

    /* The tag the user specified for this queue. */
    char* tag;

    /* The user specified options for this queue. */
    uint16_t options;

    /* The priority of this item (lower value is processed first). */
    uint16_t priority;

    /* The data size. */
    uint32_t data_size;

    /* The actual data. */
    void* data;

} BALANCE_item_t;

/**
 * The interface to the work queue. This can be accessed from within the
 * process work callback.
 */
typedef struct {

    /* Enqueue an item. */
    int8_t (*enqueue)(BALANCE_item_t* item);

    /* Dequeue an item. */
    int8_t (*dequeue)(BALANCE_item_t* item);

    /* Get the size of the local queue structure. */
    uint32_t (*internal_queue_size)();

} BALANCE_handle;

/**
 * The type for defining callbacks for processing.
 */
typedef void (*BALANCE_cb)(BALANCE_handle *handle);

/**
 * Begin accepting work requests. If requests are already being accepted,
 * this will be a no-op.
 */
void BALANCE_accept(void);

/**
 * Reject all new work and ensure all current work on this node has been
 * completed or passed to other workers.
 */
void BALANCE_shutdown(void);

/**
 * If not already accepting work, begin accepting new work items. Also, create
 * a new tagged queue with the specified item or, if the tagged queue already
 * exists, insert the item for processing.
 */
int BALANCE_insert(BALANCE_item_t* item);

/**
 * The callback that allows work to be processed.
 */
void BALANCE_process(BALANCE_cb func);

/**
 * Ensure all work for a specified persistent tagged queue has been completed
 * and destroy the tagged queue.
 */
void BALANCE_finalize_persistant(char* tag);

/**
 * Define a callback for when a transient queue has finished.
 */
void BALANCE_finalize_transient(BALANCE_cb func);

/**
 * Read/reread configuration file at the specified path.
 */
void BALANCE_read_config(char* path);

/**
 * Define the detail and location for logging.
 */
void BALANCE_setup_log(int fd, enum BALANCE_loglevel level);

#endif /* _BALANCEMQ_BALANCEMQ_H */
