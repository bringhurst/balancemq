#ifndef _BALANCEMQ_LOG_H
#define _BALANCEMQ_LOG_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define BALANCE_LOG_DBG   5
#define BALANCE_LOG_INFO  4
#define BALANCE_LOG_WARN  3
#define BALANCE_LOG_ERR   2
#define BALANCE_LOG_FATAL 1

#define LOG(level, ...) do {  \
        if (level <= BALANCE_debug_level) { \
            fprintf(BALANCE_debug_stream, "%d:%s:%d:", (int)time(NULL), \
                    __FILE__, __LINE__); \
            fprintf(BALANCE_debug_stream, __VA_ARGS__); \
            fprintf(BALANCE_debug_stream, "\n"); \
            fflush(BALANCE_debug_stream); \
        } \
    } while (0)

extern FILE* BALANCE_debug_stream;
extern int   BALANCE_debug_level;

#endif /* _BALANCEMQ_LOG_H */
