/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** send_message_to_team
*/

#include "server.h"

static void is_connected(server_t *server, uuid_t user_uuid,
    char *code, char *buffer)
{
    for (int i = 0; i < MAX_INSTANCES; i++) {
        if (!uuid_is_null(server->instance[i]->user_uuid) &&
            uuid_compare(server->instance[i]->user_uuid, user_uuid) == 0) {
            add_output(&server->instance[i]->output, code, buffer);
            return;
        }
    }
}

void send_message_to_team(server_t *server, char *code, char *buffer,
    team_t *team)
{
    uuid_list_t *user = NULL;

    LIST_FOREACH(user, &team->users_uuid_registered_head, next_uuid) {
        is_connected(server, user->uuid, code, buffer);
    }
}
