/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create_channel
*/

#include "server.h"
#include "data_core.h"
#include "lib.h"
#include "save.h"

static bool check_args(char **args, instance_t *instance, team_t *team)
{
    char uuid_team[37];

    if (team == NULL) {
        uuid_unparse(instance->team_uuid, uuid_team);
        add_output(&instance->output, "EC03", uuid_team);
        return false;
    }
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

void create_channel(server_t *server, instance_t *instance,
    char **args, team_t *team)
{
    char uuid_team[37];
    char uuid_channel[37];
    channel_t *channel;
    char buffer[1019];

    memset(uuid_team, 0, 37);
    if (!check_args(args, instance, team))
        return;
    if (add_channel(&team->channels_head, args[0], args[1]) == 1) {
        add_output(&instance->output, "EC06", "Channel already exists");
        return;
    }
    uuid_unparse(instance->team_uuid, uuid_team);
    channel = get_channel_by_name(&team->channels_head, args[0]);
    uuid_unparse(channel->uuid, uuid_channel);
    server_event_channel_created(uuid_team, uuid_channel, args[0]);
    sprintf(buffer, "%s \"%s\" \"%s\"", uuid_channel, args[0], args[1]);
    send_message_to_team(server, "SU08", buffer, team);
    save_channels(server);
}
