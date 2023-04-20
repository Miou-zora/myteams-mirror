/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** leave_instance
*/

#include "server.h"

static void clear_instance(instance_t *instance)
{
    close(instance->socket);
    instance->socket = -1;
    uuid_clear(instance->user_uuid);
    uuid_clear(instance->team_uuid);
    uuid_clear(instance->channel_uuid);
    uuid_clear(instance->thread_uuid);
}

void leave_instance(server_t *server, instance_t *instance)
{
    char buffer[1019];
    user_t *user;
    char uuid[37];

    printf("Client disconnected\n");
    if (uuid_is_null(instance->user_uuid)) {
        close(instance->socket);
        instance->socket = -1;
        return;
    }
    memset(buffer, 0, 1019);
    uuid_unparse(instance->user_uuid, uuid);
    user = get_user_by_uuid(&server->users, uuid);
    sprintf(buffer, "%s \"%s\"", uuid, user->username);
    server_event_user_logged_out(uuid);
    clear_instance(instance);
    send_message_every_users(server, "SU06", buffer);
}
