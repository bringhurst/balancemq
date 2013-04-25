#ifndef _BALANCE_PRIVATE_SETTINGS_H
#define _BALANCE_PRIVATE_SETTINGS_H

#include <balancemq/balancemq.h>

typedef struct {
    struct BALANCE_context_t* context;
    void* state;
} BALANCE_scanner_t;

#endif /* _BALANCE_PRIVATE_SETTINGS_H */
