/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** logout
*/

#include "commands.h"
#include "response.h"
#include "lib.h"
#include "save.h"

void cmd_logout(server_t *server, instance_t *current_instance, char **args)
{
    char buffer[1019];
    user_t *user = NULL;
    char uuid[37];

    if (uuid_is_null(current_instance->user_uuid))
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
    else if (get_array_size(args) != 0) {
        add_output(&current_instance->output, "EC02",
            "Invalid number of arguments");
    } else {
        memset(buffer, 0, 1019);
        uuid_unparse(current_instance->user_uuid, uuid);
        user = get_user_by_uuid(&server->users, uuid);
        uuid_clear(current_instance->user_uuid);
        sprintf(buffer, "%s \"%s\"", uuid, user->username);
        send_message_every_users(server, "SU06", buffer);
        server_event_user_logged_out(uuid);
    }
}
