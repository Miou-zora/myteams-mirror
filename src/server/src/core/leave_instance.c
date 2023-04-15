/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** leave_instance
*/

#include "server.h"

void leave_instance(instance_t *client)
{
    printf("Client disconnected\n");
    close(client->socket);
    client->socket = -1;
}
