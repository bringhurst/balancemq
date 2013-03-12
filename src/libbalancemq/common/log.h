#ifndef _BALANCEMQ_LOG_H
#define _BALANCEMQ_LOG_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define BALANCEMQ_LOG_DBG   5
#define BALANCEMQ_LOG_INFO  4
#define BALANCEMQ_LOG_WARN  3
#define BALANCEMQ_LOG_ERR   2
#define BALANCEMQ_LOG_FATAL 1

#define LOG(level, ...) do {  \
        if (level <= BALANCEMQ_debug_level) { \
            fprintf(BALANCEMQ_debug_stream, "%d:%s:%d:", (int)time(NULL), \
                    __FILE__, __LINE__); \
            fprintf(BALANCEMQ_debug_stream, __VA_ARGS__); \
            fprintf(BALANCEMQ_debug_stream, "\n"); \
            fflush(BALANCEMQ_debug_stream); \
        } \
    } while (0)

extern FILE* BALANCEMQ_debug_stream;
extern int   BALANCEMQ_debug_level;

#endif /* _BALANCEMQ_LOG_H */
