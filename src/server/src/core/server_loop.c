/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** server_loop
*/

#include "server.h"

void server_loop(server_t *server)
{
    int activity;

    while (server->is_running) {
        FD_ZERO(&(server->readfds));
        FD_SET(server->master_socket, &(server->readfds));
        server->max_sd = server->master_socket;
        set_actual_client(server);
        activity = select(server->max_sd + 1,
        &(server->readfds), NULL, NULL, NULL);
        if ((activity < 0)) {
            printf("select error");
            exit(EXIT_FAILURE);
        }
        accept_new_connection(server);
        do_client_action(server);
    }
}
