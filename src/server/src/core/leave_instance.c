/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** leave_instance
*/

#include "server.h"

void leave_instance(server_t *server, instance_t *instance)
{
    char buffer[1019];
    user_t *user;
    char uuid[37];

    printf("Client disconnected\n");
    memset(buffer, 0, 1019);
    uuid_unparse(instance->user_uuid, uuid);
    user = get_user_by_uuid(&server->users, uuid);
    sprintf(buffer, "%s \"%s\"", uuid, user->username);
    server_event_user_logged_out(uuid);
    close(instance->socket);
    instance->socket = -1;
    uuid_clear(instance->user_uuid);
    uuid_clear(instance->team_uuid);
    uuid_clear(instance->channel_uuid);
    uuid_clear(instance->thread_uuid);
    send_message_every_users(server, "201", buffer);
}
