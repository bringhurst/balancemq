#ifndef _STOMP_SERVER
#define _STOMP_SERVER

#define LIBEV_READ_BUFFER_SIZE (1024)

#include <stdio.h>
//#include <stdlib.h>
#include <netinet/in.h>
#include <ev.h>
#include <strings.h>

#include "client_protocol_stomp.h"

void client_protocol_stomp_server_loop(client_protocol_stomp_state_t* state);

void client_protocol_stomp_accept_cb(struct ev_loop* loop, struct ev_io* watcher, int revents);
void client_protocol_stomp_read_cb(struct ev_loop* loop, struct ev_io* watcher, int revents);

#endif /* _STOMP_SERVER */
