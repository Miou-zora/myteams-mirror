/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** use_select_uuid
*/

#include "commands.h"

void select_one_arg(server_t *server, instance_t *current_instance, char **args)
{
    user_t *user = get_user_by_uuid(&server->users, current_instance->user_uuid);
    team_t *team = get_team_by_uuid(&user->teams, current_instance->team_uuid);

    if (uuid_parse(args[0], current_instance->team_uuid) == -1) {
        add_output(&current_instance->output, "EC03",
        "Invalid UUID");
        uuid_clear(current_instance->team_uuid);
        return;
    }
    LIST_FOREACH
    uuid_clear(current_instance->channel_uuid);
    uuid_clear(current_instance->thread_uuid);
}

void select_two_args(server_t *server, instance_t *current_instance, char **args)
{
    select_one_arg(server, current_instance, args);
    if (uuid_parse(args[1], current_instance->channel_uuid) == -1) {
        add_output(&current_instance->output, "EC03",
        "Invalid UUID");
        uuid_clear(current_instance->team_uuid);
        uuid_clear(current_instance->channel_uuid);
        return;
    }
    uuid_clear(current_instance->thread_uuid);
}

void select_three_args(server_t *server, instance_t *current_instance, char **args)
{
    if (uuid_parse(args[0], current_instance->team_uuid) == -1) {
        add_output(&current_instance->output, "EC03",
        "Invalid UUID");
        uuid_clear(current_instance->team_uuid);
        return;
    }
    if (uuid_parse(args[1], current_instance->channel_uuid) == -1) {
        add_output(&current_instance->output, "EC03",
        "Invalid UUID");
        uuid_clear(current_instance->team_uuid);
        uuid_clear(current_instance->channel_uuid);
        return;
    }
    if (uuid_parse(args[2], current_instance->thread_uuid) == -1) {
        add_output(&current_instance->output, "EC03",
        "Invalid UUID");
        uuid_clear(current_instance->team_uuid);
        uuid_clear(current_instance->channel_uuid);
        uuid_clear(current_instance->thread_uuid);
    }
}

void select_no_args(server_t *server, instance_t *current_instance, char **args)
{
    uuid_clear(current_instance->team_uuid);
    uuid_clear(current_instance->channel_uuid);
    uuid_clear(current_instance->thread_uuid);
}
