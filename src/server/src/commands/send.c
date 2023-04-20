/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** send
*/

#include "commands.h"
#include "response.h"
#include "lib.h"
#include "save.h"

void cmd_send(server_t *server, instance_t *current_instance, char **args)
{
    char buffer[1019];
    user_t *user = NULL;
    char uuid[37];

    if (uuid_is_null(current_instance->uuid))
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
    else if (get_array_size(args) != 2) {
        add_output(&current_instance->output, "EC02",
            "Invalid number of arguments");
    } else if (get_user_by_uuid(&server->users, args[0]) == NULL) {
        add_output(&current_instance->output, "EC30",
            "User doesn't exist");
    }
    else {
        memset(buffer, 0, 1019);
        uuid_unparse(current_instance->uuid, uuid);
        user = get_user_by_uuid(&server->users, uuid);
        sprintf(buffer, "%s \"%s\" \"%s\"", uuid, user->username, args[1]);
        add_output(&current_instance->output, "SU07", buffer);
    }
}
