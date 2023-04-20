/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** send_message_every_users
*/

#include "server.h"

void send_message_every_users(server_t *server, char *code, char *args)
{
    for (size_t i = 0; i < MAX_INSTANCES; i++) {
        if (!uuid_is_null(server->instance[i]->user_uuid)) {
            add_output(&server->instance[i]->output, code, args);
        }
    }
}