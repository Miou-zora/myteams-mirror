/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** set_actual_instance
*/

#include "server.h"

void set_actual_instance(server_t *server)
{
    int sd;

    for (int i = 0; i < MAX_INSTANCES; i++) {
        sd = server->instance[i]->socket;
        if (sd > 0)
            FD_SET(sd, &(server->readfds));
        if (server->instance[i]->buff_out[0] != '\0' && sd > 0)
            FD_SET(sd, &(server->writefds));
        if (sd > server->max_sd)
            server->max_sd = sd;
    }
}
