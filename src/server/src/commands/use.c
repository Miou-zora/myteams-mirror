/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** use
*/

#include "commands.h"
#include "lib.h"

static void clear_uuids(instance_t *current_instance)
{
    uuid_clear(current_instance->team_uuid);
    uuid_clear(current_instance->channel_uuid);
    uuid_clear(current_instance->thread_uuid);
}

static void select_item(instance_t *current_instance,
    char **args)
{
    switch (get_array_size(args)) {
        case 1:
            clear_uuids(current_instance);
            uuid_parse(args[0], current_instance->team_uuid);
            break;
        case 2:
            clear_uuids(current_instance);
            uuid_parse(args[0], current_instance->team_uuid);
            uuid_parse(args[1], current_instance->channel_uuid);
            break;
        case 3:
            clear_uuids(current_instance);
            uuid_parse(args[0], current_instance->team_uuid);
            uuid_parse(args[1], current_instance->channel_uuid);
            uuid_parse(args[2], current_instance->thread_uuid);
            break;
        default:
            clear_uuids(current_instance);
            break;
    }
}

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
    select_item(current_instance, args);
}
