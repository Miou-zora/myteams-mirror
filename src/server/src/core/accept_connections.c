/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** accept_connexions
*/

#include "server.h"

void set_new_instance(server_t *server, int new_socket)
{
    for (int i = 0; i < MAX_INSTANCES; i++) {
        if (server->instance[i]->socket == -1) {
            server->instance[i]->socket = new_socket;
            add_output(&server->instance[i]->output, "SU20",
            "Service ready for new user.");
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
            exit(EPI_FAILURE);
        } else {
            printf("New connection, socket fd is %d\n", new_socket);
            set_new_instance(server, new_socket);
        }
    }
}
