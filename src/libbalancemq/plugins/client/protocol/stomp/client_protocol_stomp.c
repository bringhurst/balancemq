/* client_protocol_stomp.c
 *
 * This is the main entry point for the client stomp plugin.
 *
 * The design of this plugin is to create a simple socket server using
 * libev. Connections to the socket are managed by libev. Each request
 * is passed through a flex/bison based compliler. The AST is then traversed
 * to determine what action to perform based on the content of the request.
 */

#include "client_protocol_stomp.h"
#include "stomp_server.h"

const char balancemq_plugin_name[]      = "Client protocol STOMP server";
const char balancemq_plugin_type[]      = "client/protocol";
const uint32_t balancemq_plugin_version = 0;

/* A handle to the current state of the server. */
client_protocol_stomp_state_t* client_protocol_stomp_state = NULL;

void plugin_balancemq_initialize()
{
    client_protocol_stomp_state = (client_protocol_stomp_state_t*) \
        malloc(sizeof(client_protocol_stomp_state_t));

    /* Determine the configuration based on the balancemqd.conf. */
    client_protocol_stomp_state->conf = client_protocol_stomp_get_conf();
}

void plugin_balancemq_exec()
{
    /* Start up the server and begin handling requests. */
    client_protocol_stomp_server_loop(client_protocol_stomp_state);
}

void plugin_balancemq_finalize() {
    /* Reject incoming requests while allowing existing requests to complete. */
    client_protocol_stomp_shutdown(client_protocol_stomp_state);

    /* Free configuration and state. */
    free(client_protocol_stomp_state->conf);
    free(client_protocol_stomp_state);
}

/*
balancemq_plugin_status_t*
plugin_balancemq_query_status() {
    TODO: return a balancemq_plugin_status_t that contains things like how
          many clients are connected
}
 */

client_protocol_stomp_conf_t*
client_protocol_stomp_get_conf()
{
    client_protocol_stomp_conf_t* conf = \
        (client_protocol_stomp_conf_t*) malloc(\
            sizeof(client_protocol_stomp_conf_t));

    /* TODO: get these values from the balancemqd.conf file. */
    conf->port_number = 1625;

    return conf;
}

/* EOF */
