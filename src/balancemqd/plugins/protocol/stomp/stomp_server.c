/* stomp_server.c
 *
 * This file contains the stomp server launch.
 */

#include "stomp_server.h"

void client_protocol_stomp_server_loop(client_protocol_stomp_state_t* state)
{
    struct ev_loop* loop = ev_default_loop(0);
    struct sockaddr_in addr;
    int addr_len = sizeof(addr);
    struct ev_io w_accept;

    /* Create a server socket. */
    if((state->server_socket = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        return;
    }

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(state->conf->port_number);
    addr.sin_addr.s_addr = INADDR_ANY;

    /* Bind the server socket to an address. */
    if(bind(state->server_socket, (struct sockaddr*) &addr, sizeof(addr)) != 0) {
        perror("bind error");
    }

    /* Start listening on the socket. */
    if(listen(state->server_socket, 2) < 0) {
        perror("listen error");
        return;
    }

    /* Initialize and start a libev watcher to accept client requests. */
    ev_io_init(&w_accept, client_protocol_stomp_accept_cb, state->server_socket, EV_READ);
    ev_io_start(loop, &w_accept);

    /* Start the libev event loop. */
    while(1) {
        ev_loop(loop, 0);
    }
}

/* Accept client requests */
void client_protocol_stomp_accept_cb(struct ev_loop* loop, struct ev_io* watcher, int revents)
{
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sd;
    struct ev_io* w_client = (struct ev_io*) malloc(sizeof(struct ev_io));

    if(EV_ERROR & revents) {
        perror("got invalid event");
        return;
    }

    /* Accept a client request */
    client_sd = accept(watcher->fd, (struct sockaddr*)&client_addr, &client_len);

    if(client_sd < 0) {
        perror("accept error");
        return;
    }

    printf("Successfully connected with client.\n");

    /* Initialize and start a libev watcher to read client requests */
    ev_io_init(w_client, client_protocol_stomp_read_cb, client_sd, EV_READ);
    ev_io_start(loop, w_client);
}

/* Read client message */
void client_protocol_stomp_read_cb(struct ev_loop* loop, struct ev_io* watcher, int revents)
{
    char buffer[LIBEV_READ_BUFFER_SIZE];
    ssize_t read;

    if(EV_ERROR & revents) {
        perror("got invalid event");
        return;
    }

    /* Receive a message from the client's socket. */
    read = recv(watcher->fd, buffer, LIBEV_READ_BUFFER_SIZE, 0);

    if(read < 0) {
        perror("read error");
        return;
    }

    if(read == 0) {
        /* If the client socket is closing, stop and free the watcher. */
        ev_io_stop(loop, watcher);
        free(watcher);

        perror("Client socket is closing.");
        return;
    }
    else {
        /*
         * TODO: Parse the client's stomp request which should be
         * stored in buffer.
         */

        printf("Stomp protocol client server received message `%s'\n", buffer);
    }

    /* FIXME: Send a response back to the client. */
    send(watcher->fd, buffer, read, 0);
    bzero(buffer, read);
}

/* EOF */
