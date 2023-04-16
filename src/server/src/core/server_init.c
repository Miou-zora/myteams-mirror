/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** server_init
*/

#include "server.h"

const char *function_names[] = {
    "server_event_team_created",
    "server_event_channel_created",
    "server_event_thread_created",
    "server_event_reply_created",
    "server_event_user_subscribed",
    "server_event_user_unsubscribed",
    "server_event_user_created",
    "server_event_user_loaded",
    "server_event_user_logged_in",
    "server_event_user_logged_out",
    "server_event_private_message_sended",
    NULL
};

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
    serv->shared_lib = load_shared_lib("../libs/myteams/libmyteams.so",
    function_names, 11);
    serv->is_running = true;
    return (serv);
}
