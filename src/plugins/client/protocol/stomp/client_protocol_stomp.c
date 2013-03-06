/* client_protocol_stomp.c
 *
 * This is the main entry point for the client stomp plugin.
 *
 * The design of this plugin is to create a simple socket server using
 * libev. Connections to the socket are managed by libev. Each request
 * is passed through a flex/bison based compliler. The AST is then traversed
 * to determine what action to perform based on the content of the request.
 */

#include "../../../../common/balancemq_plugin.h"

const char balancemq_plugin_name[]      = "Client protocol STOMP server";
const char balancemq_plugin_type[]      = "client/protocol";
const uint32_t balancemq_plugin_version = 0;

typedef struct {
} client_protocol_stomp_conf_t;

/* FIXME */
something_t client_protocol_stomp_handle = NULL;

void plugin_balancemq_initialize() {
    /* First determine what the configuration for the server should be. */
    client_protocol_stomp_conf_t conf = client_protocol_stomp_get_conf();

    /* Start up the server and begin handling requests. */
    client_protocol_stomp_handle = client_protocol_stomp_accept_requests();
}

void plugin_balancemq_finalize() {
    /* Reject incoming requests while allowing existing requests to complete. */
    client_protocol_stomp_shutdown(client_protocol_stomp_handle);
}

/* EOF */
