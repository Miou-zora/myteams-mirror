/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** client_actions
*/

#include "server.h"

void catch_client_message(int index, server_t *server)
{
    int valread;
    char command[1024];
    int sd = server->instance[index]->socket;

    memset(command, 0, sizeof(command));
    if ((valread = read(sd, command, sizeof(command))) == 0) {
        leave_instance(server->instance[index]);
    } else {
        exec_command(server, server->instance[index], command);
    }
    memset(command, 0, sizeof(command));
}

void do_client_action(server_t *server)
{
    for (int i = 0; i < MAX_INSTANCES; i++) {
        if (FD_ISSET(server->instance[i]->socket, &(server->readfds))) {
            catch_client_message(i, server);
        }
    }
}
