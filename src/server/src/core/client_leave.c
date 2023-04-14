/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** client_leave
*/

#include "server.h"

void client_leave(client_t *client)
{
    printf("Client disconnected\n");
    close(client->socket);
    client->socket = -1;
    free(client->username);
}
