/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** use
*/

#include "commands.h"
#include "lib.h"

void cmd_use(server_t *server, instance_t *current_instance, char **args)
{
    (void)server;
    if (uuid_is_null(current_instance->user_uuid)) {
        add_output(&current_instance->output, "EC01",
        "You must be logged in to use this command");
        return;
    }
    if (get_array_size(args) > 3) {
        add_output(&current_instance->output, "EC02",
        "Invalid number of arguments");
        return;
    }
    // select_item(server, current_instance, args);
}
