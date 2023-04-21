/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create_team
*/

#include "server.h"
#include "data_core.h"
#include "lib.h"
#include "commands.h"

static bool create_team_or_channel(instance_t *instance, char **args,
    server_t *server)
{
    team_t *team;
    char team_uuid[37];

    if (uuid_is_null(instance->team_uuid)) {
        create_team(server, instance, args);
        return (true);
    }
    if (uuid_is_null(instance->channel_uuid)) {
        uuid_unparse(instance->team_uuid, team_uuid);
        team = get_team_by_uuid(&server->teams, team_uuid);
        create_channel(server, instance, args, team);
        return (true);
    }
    return false;
}

void cmd_create(server_t *server, instance_t *instance, char **args)
{
    team_t *team;
    char team_uuid[37];

    if (uuid_is_null(instance->user_uuid)) {
        add_output(&instance->output, "EC01",
        "You must be logged in to use this command");
        return;
    }
    if (create_team_or_channel(instance, args, server))
        return;
    if (uuid_is_null(instance->thread_uuid)) {
        uuid_unparse(instance->team_uuid, team_uuid);
        team = get_team_by_uuid(&server->teams, team_uuid);
        check_before_create_thread(server, instance, args, team);
        return;
    }
    uuid_unparse(instance->team_uuid, team_uuid);
    team = get_team_by_uuid(&server->teams, team_uuid);
    check_before_reply(server, instance, args, team);
}
