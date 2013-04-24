#ifndef _BALANCEMQ_LOG_H
#define _BALANCEMQ_LOG_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef enum {
    BALANCE_LOG_DBG = 5,
#define BALANCE_LOG_DBG BALANCE_LOG_DBG
    BALANCE_LOG_INFO = 4,
#define BALANCE_LOG_INFO BALANCE_LOG_INFO
    BALANCE_LOG_WARN = 3,
#define BALANCE_LOG_WARN BALANCE_LOG_WARN
    BALANCE_LOG_ERR = 2,
#define BALANCE_LOG_ERR BALANCE_LOG_ERR
    BALANCE_LOG_FATAL = 1,
#define BALANCE_LOG_FATAL BALANCE_LOG_FATAL
} BALANCE_loglevel;

#define LOG(context, level, ...) do {  \
        if (level <= context->log_level) { \
            fprintf(context->log_file, "%d:%s:%d:", (int)time(NULL), \
                    __FILE__, __LINE__); \
            fprintf(context->log_file, __VA_ARGS__); \
            fprintf(context->log_file, "\n"); \
            fflush(context->log_file); \
        } \
    } while (0)

#endif /* _BALANCEMQ_LOG_H */
