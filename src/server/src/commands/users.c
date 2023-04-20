/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** users
*/

#include "commands.h"
#include "lib.h"

static void check_connected(char *buffer, server_t *server, user_t *user,
    char *uuid)
{
    for (size_t instance = 0; instance < MAX_INSTANCES; instance++) {
        if (uuid_compare(server->instance[instance]->user_uuid, user->uuid) == 0) {
            uuid_unparse(user->uuid, uuid);
            sprintf(buffer, "%s %s \"%s\"", "online", uuid, user->username);
            instance = MAX_INSTANCES;
        }
    }
}

void send_users_info(server_t *server, instance_t *current_instance)
{
    char buffer[1019];
    char uuid[37];
    user_t *user;

    LIST_FOREACH(user, &server->users, next_user) {
        memset(buffer, 0, 1019);
        memset(uuid, 0, 37);
        check_connected(buffer, server, user, uuid);
        if (strlen(buffer) == 0) {
            uuid_unparse(user->uuid, uuid);
            sprintf(buffer, "%s %s \"%s\"", "offline", uuid, user->username);
        }
        add_output(&current_instance->output, "SU04", buffer);
    }
}

void cmd_users(server_t *server, instance_t *current_instance, char **args)
{
    if (uuid_is_null(current_instance->user_uuid)) {
        add_output(&current_instance->output, "EC01",
        "You must be logged in to use this command");
        return;
    } else if (args[0] != NULL || get_array_size(args) != 0) {
        add_output(&current_instance->output, "EC02",
        "Invalid number of arguments");
        return;
    }
    send_users_info(server, current_instance);
}
