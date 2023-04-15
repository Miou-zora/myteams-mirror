/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** server_init
*/

#include "server.h"

bool set_port(char *port, server_t *server)
{
    for (size_t i = 0; i != strlen(port); i++)
        if (isdigit(port[i]) == false) {
            perror("Port must be a number");
            return (false);
        }
    server->port = atoi(port);
    if (server->port < 0 || server->port > 65535) {
        perror("Port must be between 0 and 65535");
        return (false);
    }
    return (true);
}

server_t *server_init(char *port)
{
    server_t *server = malloc(sizeof(server_t));

    if (!server)
        return (NULL);
    if (set_port(port, server) == false) {
        free(server);
        return (NULL);
    }
    server->master_socket = create_socket(inet_addr("127.0.0.1"), server->port);
    if (server->master_socket == EPI_FAILURE) {
        free(server);
        return (NULL);
    }
    for (size_t i = 0; i != MAX_INSTANCES; i++) {
        server->instance[i] = malloc(sizeof(instance_t));
        server->instance[i]->socket = -1;
    }
    server->is_running = true;
    return (server);
}
