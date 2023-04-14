/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** accept_connexions
*/

#include "server.h"

void set_new_client(server_t *server, int new_socket)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->clients[i]->socket == -1) {
            server->clients[i]->socket = new_socket;
            break;
        }
    }
}

void accept_new_connection(server_t *server)
{
    int new_socket;

    if (FD_ISSET(server->master_socket, &(server->readfds))) {
        if ((new_socket = accept(server->master_socket,
        (struct sockaddr*)NULL, NULL)) < 0) {
            perror("accept failed\n");
            exit(EXIT_FAILURE);
        } else {
            printf("New connection, socket fd is %d\n", new_socket);
            write(new_socket, "SU20 Service ready for new user.\n", 32);
        }
        set_new_client(server, new_socket);
    }
}
