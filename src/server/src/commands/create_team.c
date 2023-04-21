/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create_team
*/

#include "server.h"
#include "data_core.h"
#include "lib.h"

static bool check_args(char **args, instance_t *instance)
{
    if (get_array_size(args) != 2) {
        add_output(&instance->output, "EC02", "Invalid number of arguments");
        return false;
    }
    if (strlen(args[0]) > MAX_NAME_LENGTH ||
    strlen(args[1]) > MAX_DESCRIPTION_LENGTH) {
        add_output(&instance->output, "EC07", "Invalid arguments size");
        return false;
    }
    return true;
}

void create_team(server_t *server, instance_t *instance, char **args)
{
    team_t *team;
    char uuid_team[37];
    char uuid_user[37];
    char buffer[1019];


    if (add_team(&server->teams, args[0], args[1]) == 1) {
        add_output(&instance->output, "EC06", "Team already exists");
        return;
    }
    if (!check_args(args, instance))
        return;
    team = get_team_by_name(&server->teams, args[0]);
    uuid_unparse(team->uuid, uuid_team);
    uuid_unparse(instance->user_uuid, uuid_user);
    server_event_team_created(uuid_team, args[0], uuid_user);
    sprintf(buffer, "%s \"%s\" \"%s\"", uuid_team, args[0], args[1]);
    send_message_every_users(server, "SU07", buffer);
}
