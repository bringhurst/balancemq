#ifndef _BALANCE_PRIVATE_SETTINGS_H
#define _BALANCE_PRIVATE_SETTINGS_H

#include <balancemq/balancemq.h>

typedef struct {
    void* scanner;
    BALANCE_context_t* context;
} BALANCE_scanner_t;

#endif /* _BALANCE_PRIVATE_SETTINGS_H */
