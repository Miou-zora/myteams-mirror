/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** subscribed
*/

#include "commands.h"
#include "lib.h"

void subscribed_teams(server_t *server, instance_t *current_instance)
{
    team_t *team = NULL;
    user_t *user = NULL;
    char uuid_user[37];
    char uuid_team[37];
    uuid_list_t *team_uuid;
    char buffer[1019];

    uuid_unparse(current_instance->user_uuid, uuid_user);
    user = get_user_by_uuid(&server->users, uuid_user);
    LIST_FOREACH(team_uuid, &user->teams_registered_head, next_uuid) {
        uuid_unparse(team_uuid->uuid, uuid_team);
        team = get_team_by_uuid(&server->teams, uuid_team);
        if (is_user_subscribed(user, team)) {
            sprintf(buffer, "%s \"%s\" \"%s\"", uuid_team, team->name,
                team->description);
            add_output(&current_instance->output, "SU12", buffer);
        }
    }
}

void subscribed_users(server_t *server, instance_t *current_instance,
    char **args)
{
    (void)args;
    (void)server;
    (void)current_instance;
}

void cmd_subscribed(server_t *server, instance_t *current_instance, char **args)
{
    if (uuid_is_null(current_instance->user_uuid)) {
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
        return;
    }
    if (get_array_size(args) == 0) {
        subscribed_teams(server, current_instance);
    } else if (get_array_size(args) == 1) {
        subscribed_users(server, current_instance, args);
    } else {
        add_output(&current_instance->output, "EC02",
            "Invalid number of arguments");
    }
}
