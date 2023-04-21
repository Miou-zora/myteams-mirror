/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** unsubscribe
*/

#include "commands.h"
#include "lib.h"

static void unsubscribe(server_t *server, instance_t *current_instance,
    team_t *team)
{
    char uuid_user[37];
    char buffer[1019];
    char uuid_team[37];

    uuid_unparse(current_instance->user_uuid, uuid_user);
    uuid_unparse(team->uuid, uuid_team);
    if (del_user_from_team(&server->teams, &server->users, uuid_team,
        uuid_user) == 0) {
        sprintf(buffer, "%s %s", uuid_team, uuid_user);
        add_output(&current_instance->output, "SU13", buffer);
        server_event_user_unsubscribed(uuid_team, uuid_user);
    }

}

void cmd_unsubscribe(server_t *server,
    instance_t *current_instance, char **args)
{
    team_t *team = NULL;

    if (uuid_is_null(current_instance->user_uuid)) {
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
        return;
    }
    if (get_array_size(args) != 1) {
        add_output(&current_instance->output, "EC02",
            "Invalid number of arguments");
        return;
    }
    team = get_team_by_uuid(&server->teams, args[0]);
    if (team == NULL) {
        add_output(&current_instance->output, "EC03", args[0]);
        return;
    }
    unsubscribe(server, current_instance, team);
}
