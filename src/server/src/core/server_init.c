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

bool init_instance(server_t *server)
{
    for (size_t i = 0; i != MAX_INSTANCES; i++) {
        server->instance[i] = malloc(sizeof(instance_t));
        if (!server->instance[i])
            return (false);
        server->instance[i]->socket = -1;
        uuid_clear(server->instance[i]->uuid);
        memset(server->instance[i]->buff_in, 0,
        sizeof(server->instance[i]->buff_in));
        memset(server->instance[i]->buff_out, 0,
        sizeof(server->instance[i]->buff_out));
    }
    return (true);
}

server_t *server_init(char *port)
{
    server_t *serv = malloc(sizeof(server_t));

    if (!serv)
        return (NULL);
    if (set_port(port, serv) == false) {
        free(serv);
        return (NULL);
    }
    serv->master_socket = create_socket(inet_addr("127.0.0.1"), serv->port);
    if (serv->master_socket == EPI_FAILURE || init_instance(serv) == false) {
        free(serv);
        return (NULL);
    }
    serv->users = init_list_of_users();
    serv->is_running = true;
    return (serv);
}
