/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** user
*/

#include "commands.h"
#include "lib.h"

static void check_connected(char *buffer, server_t *server, user_t *user)
{
    char uuid[37];

    for (size_t instance = 0; instance < MAX_INSTANCES; instance++) {
        if (uuid_compare(server->instance[instance]->user_uuid,
        user->uuid) == 0) {
            uuid_unparse(user->uuid, uuid);
            sprintf(buffer, "%s %s \"%s\"", "online",
                uuid, user->username);
            instance = MAX_INSTANCES;
        }
    }
}

static void send_user_info(server_t *server, instance_t *current_instance,
    const char *user_uuid)
{
    char buffer[1019];
    user_t *user_info = get_user_by_uuid(&server->users, user_uuid);

    if (user_info == NULL) {
        add_output(&current_instance->output, "EC30",
        user_uuid);
        return;
    }
    memset(buffer, 0, 1019);
    check_connected(buffer, server, user_info);
    if (strlen(buffer) == 0) {
        sprintf(buffer, "%s %s \"%s\"", "offline",
            user_uuid, user_info->username);
    }
    add_output(&current_instance->output, "SU05", buffer);
}

void cmd_user(server_t *server, instance_t *current_instance, char **args)
{
    (void)server;
    if (uuid_is_null(current_instance->user_uuid)) {
        add_output(&current_instance->output, "EC01",
        "You must be logged in to use this command");
        return;
    } else if (get_array_size(args) != 1) {
        add_output(&current_instance->output, "EC02",
        "Invalid number of arguments");
        return;
    }
    send_user_info(server, current_instance, args[0]);
}
