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
        if (sd > server->max_sd)
            server->max_sd = sd;
    }
}
