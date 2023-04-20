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
    uuid_clear(client->user_uuid);
    uuid_clear(client->team_uuid);
    uuid_clear(client->channel_uuid);
    uuid_clear(client->thread_uuid);
}
