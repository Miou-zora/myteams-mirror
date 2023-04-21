/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** list_check
*/

#include "commands.h"
#include "lib.h"

team_t *check_team(server_t *server, instance_t *current_instance,
    char *team_uuid, user_t *user)
{
    team_t *team = NULL;

    uuid_unparse(current_instance->team_uuid, team_uuid);
    team = get_team_by_uuid(&server->teams, team_uuid);
    if (team == NULL) {
        add_output(&current_instance->output, "EC03", team_uuid);
        return (NULL);
    }
    if (!is_user_subscribed(user, team)) {
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
        return (NULL);
    }
    return (team);
}

channel_t *check_channel(team_t *team, instance_t *current_instance,
    char *channel_uuid)
{
    channel_t *channel = NULL;

    if (team == NULL)
        return NULL;
    uuid_unparse(current_instance->channel_uuid, channel_uuid);
    channel = get_channel_by_uuid(&team->channels_head, channel_uuid);
    if (channel == NULL) {
        add_output(&current_instance->output, "EC04", channel_uuid);
        return (NULL);
    }
    return (channel);
}

thread_t *check_thread(channel_t *channel, instance_t *current_instance,
    char *thread_uuid)
{
    thread_t *thread = NULL;

    if (channel == NULL)
        return NULL;
    uuid_unparse(current_instance->thread_uuid, thread_uuid);
    thread = get_thread_by_uuid(&channel->threads_head, thread_uuid);
    if (thread == NULL) {
        add_output(&current_instance->output, "EC05", thread_uuid);
        return (NULL);
    }
    return (thread);
}
