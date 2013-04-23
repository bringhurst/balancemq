#ifndef _BALANCE_BALANCEMQ_H
#define _BALANCE_BALANCEMQ_H

#include <balancemq/settings.h>

#include <stdint.h>
#include <sys/types.h>

#define BALANCE_ERR -1
#define BALANCE_OK 0

/** Permission denied error. */
#define BALANCE_ERR_PERM 2

/** An item to be processed. */
typedef struct {

    /** The name of the channel this item will be sent to. */
    char* channel_name;

    /**
     * The priority of this item relative to others in the same channel (lower
     * value is processed first).
     */
    int8_t priority;

    /** The data size. */
    size_t data_size;

    /** The actual data. */
    void* data;

} BALANCE_item_t;

/**
 * The interface to the local work queue. This is passed to appropriate
 * context callbacks.
 */
typedef struct {

    /* Enqueue an item. */
    int (*enqueue)(BALANCE_item_t* item);

    /* Dequeue an item. */
    int (*dequeue)(BALANCE_item_t* item);

    /* Get the size of the local queue structure. */
    int (*size)(size_t* size);

} BALANCE_handle_t;

/**
 * The type for defining callbacks for processing.
 */
typedef void (*BALANCE_cb)(BALANCE_handle_t *handle);

/**
 * The definition of a channel.
 */
typedef struct {

    /** The user who has full permissions to this channel. */
    uid_t user_owner;

    /** The group who has full permissions to this channel. */
    gid_t group_owner;

    char* name;
    char* description;

    /** The behavior of termination. */
    int type;

} BALANCE_channel_t;

/**
 * The description of how a group of channels are created and destroyed.
 */
typedef struct {

    /** The last reported error code. */
    int err;

    /**
     * If available, a string representation of the last reported error
     * code.
     */
    char* errstr;

    /** The file descriptor to log errors to. */
    struct FILE* log_stream;

    /** The log level to report. */
    int log_level;

    /** Context specific configuration settings. */
    BALANCE_settings_t settings;

    struct {

        /** Callback performed for when a queue is created. */
        BALANCE_cb startup_func;

        /** Callback performed for each queue work item. */
        BALANCE_cb process_func;

        /** Callback performed before termination when the local queue is empty. */
        BALANCE_cb empty_func;

        /** A callback performed after successful termination detection. */
        BALANCE_cb terminate_func;

    } events;

} BALANCE_context_t;

/**
 * Initialize a basic context with null callbacks, default logging and
 * default settings.
 */
int BALANCE_init_context(BALANCE_context_t* context);

/**
 * Free an allocated context structure.
 */
int BALANCE_free_context(BALANCE_context_t* context);

/**
 * Create a transient channel using default settings, the specified process
 * callback, and an initial seed item. This function is a wrapper for several
 * API function calls. If an application requires additional options to be set,
 * this function should not be used.
 */
int BALANCE_simple_startup(BALANCE_cb process_callback, \
                           BALANCE_item_t* seed_item);

/**
 * Begin accepting new work requests for channels using the options specified
 * by context. If items do not already exist for a transient channel, the
 * channel will immediately terminate.
 */
int BALANCE_accept(BALANCE_context_t* context, \
                   BALANCE_channel_t** channels);

/**
 * Perform an expensive broadcast operation to obtain a global list of all
 * active channels.
 */
int BALANCE_query_channels(BALANCE_context_t* context, \
                           BALANCE_channel_t** channels);

/**
 * Insert an item into the local queue to be processed by a callback
 * registered to the appropriate channel.
 */
int BALANCE_insert(BALANCE_context_t* context, \
                   BALANCE_item_t* item);

/**
 * Permanently enable distributed termination detection on the specified
 * persistent channel name, effectively turning it into a transient channel.
 */
int BALANCE_enable_termination(BALANCE_context_t* context, \
                               char* channel_name);

/**
 * Set the context configuration to the file specified at path.
 */
int BALANCE_set_configuration(BALANCE_context_t* context, \
                              char* path);

/**
 * Set the detail and location for logging for the specified context.
 */
void BALANCE_set_logging(BALANCE_context_t* context, \
                         int fd, \
                         int level);

/**
 * Set a callback to be used when the channel is registered.
 */
int BALANCE_set_startup_callback(BALANCE_context_t* context, \
                                 BALANCE_cb func);

/**
 * Set a callback to be used for processing items.
 */
int BALANCE_set_process_callback(BALANCE_context_t* context, \
                                 BALANCE_cb func);

/**
 * Set a callback to be used for when the local queue is empty, but before the
 * global termination detection has been performed.
 */
int BALANCE_set_empty_callback(BALANCE_context_t* context, \
                               BALANCE_cb func);

/**
 * Set a callback to be used after the global termination detection algorithm
 * has determined the channel will be terminated.
 */
int BALANCE_set_terminate_callback(BALANCE_context_t* context, \
                                   BALANCE_cb func);

#endif /* _BALANCEMQ_BALANCEMQ_H */
