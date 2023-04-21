/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** subscribe
*/

#include "commands.h"
#include "lib.h"

void subscribe_to_team(server_t *server, instance_t *current_instance,
    char *team_uuid)
{
    char uuid_user[37];
    int ret = 0;
    char buffer[1019] = {0};

    uuid_unparse(current_instance->user_uuid, uuid_user);
    ret = add_user_to_team(&server->teams, &server->users, team_uuid,
        uuid_user);
    if (ret == 1) {
        add_output(&current_instance->output, "EC03", team_uuid);
    } else if (ret == 0) {
        sprintf(buffer, "%s %s", uuid_user, team_uuid);
        send_message_to_team(server, "SU11", buffer,
            get_team_by_uuid(&server->teams, team_uuid));
        server_event_user_subscribed(team_uuid, uuid_user);
    }
}

void cmd_subscribe(server_t *server, instance_t *current_instance, char **args)
{
    if (uuid_is_null(current_instance->user_uuid)) {
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
        return;
    }
    if (get_array_size(args) != 1) {
        add_output(&current_instance->output, "EC02",
            "Missing argument: team_uuid");
        return;
    }
    subscribe_to_team(server, current_instance, args[0]);
}
