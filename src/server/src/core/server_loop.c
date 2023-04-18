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
        FD_ZERO(&(server->writefds));
        FD_SET(server->master_socket, &(server->readfds));
        server->max_sd = server->master_socket;
        set_actual_instance(server);
        activity = select(server->max_sd + 1,
        &(server->readfds), &(server->writefds), NULL, NULL);
        if ((activity < 0)) {
            perror("select error");
            exit(EPI_FAILURE);
        }
        accept_new_connection(server);
        do_client_action(server);
    }
}
