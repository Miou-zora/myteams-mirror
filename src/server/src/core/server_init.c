/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** server_init
*/

#include "server.h"

server_t *server_init(char *port)
{
    server_t *server = malloc(sizeof(server_t));

    if (!server)
        return (NULL);
    for (size_t i = 0; i != strlen(port); i++)
        if (isdigit(port[i]) == false)
            return (NULL);
    server->port = atoi(port);
    if (server->port < 0 || server->port > 65535)
        return (NULL);
    server->master_socket = create_socket(inet_addr("127.0.0.1"), server->port);
    server->is_running = true;
    return (server);
}