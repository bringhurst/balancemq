#ifndef _PROTOCOL_STOMP_H
#define _PROTOCOL_STOMP_H

#include <stdlib.h>
#include <stdint.h>

#include "../../../../common/balancemq_plugin.h"

/* The basic node of the protocol AST. */
typedef struct stomp_node_t {

} stomp_node_t;

/* The server configuration. */
typedef struct {
    uint32_t port_number;
} client_protocol_stomp_conf_t;

/* The current state of a running server. */
typedef struct {
    /* The configuration used. */
    client_protocol_stomp_conf_t* conf;

    /* The server socket. */
    int server_socket;
} client_protocol_stomp_state_t;

void plugin_balancemq_initialize();
void plugin_balancemq_exec();
void plugin_balancemq_finalize();

client_protocol_stomp_conf_t* client_protocol_stomp_get_conf();

#endif /* _PROTOCOL_STOMP_H */
