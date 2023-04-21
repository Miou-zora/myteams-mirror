/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create_thread
*/

#include "server.h"
#include "data_core.h"
#include "lib.h"

static void send_data(server_t *server, instance_t *instance,
char **args, channel_t *channel)
{
    thread_t *thread;
    char team_uuid[37];
    char cha[37];
    char thread_uuid[37];
    char user_uuid[37];
    char buffer[1019];
    char *timestamp;
    team_t *team;

    uuid_unparse(instance->channel_uuid, cha);
    thread = get_thread_by_name(&channel->threads_head, args[0]);
    uuid_unparse(thread->uuid, thread_uuid);
    uuid_unparse(instance->user_uuid, user_uuid);
    timestamp = ctime(&thread->timestamp);
    server_event_thread_created(cha, thread_uuid, user_uuid, args[0], args[1]);
    sprintf(buffer, "%s %s \"%s\" \"%s\" \"%s\"", thread_uuid, user_uuid,
    timestamp, args[0], args[1]);
    uuid_unparse(instance->team_uuid, team_uuid);
    team = get_team_by_uuid(&server->teams, team_uuid);
    send_message_to_team(server, "SU09", buffer, team);
}

static void create_thread(server_t *server, instance_t *instance,
    char **args, channel_t *channel)
{
    if (get_array_size(args) != 2) {
        add_output(&instance->output, "EC02", "Invalid number of arguments");
        return;
    }
    if (strlen(args[0]) > MAX_NAME_LENGTH ||
    strlen(args[1]) > MAX_DESCRIPTION_LENGTH) {
        add_output(&instance->output, "EC07", "Invalid arguments size");
        return;
    }
    if (add_thread(&channel->threads_head, args[0], args[1]) == 1) {
        add_output(&instance->output, "EC06", "Thread already exists");
        return;
    }
    send_data(server, instance, args, channel);
}

void check_before_create_thread(server_t *server, instance_t *instance,
    char **args, team_t *team)
{
    char tmp1[37];
    char tmp2[37];
    channel_t *channel;

    memset(tmp1, 0, 37);
    memset(tmp2, 0, 37);
    if (team == NULL) {
        uuid_unparse(instance->team_uuid, tmp1);
        uuid_unparse(instance->channel_uuid, tmp2);
        add_output(&instance->output, "EC03", tmp1);
        add_output(&instance->output, "EC04", tmp2);
        return;
    }
    uuid_unparse(instance->channel_uuid, tmp2);
    channel = get_channel_by_uuid(&team->channels_head, tmp2);
    if (channel == NULL) {
        add_output(&instance->output, "EC04", tmp2);
        return;
    }
    create_thread(server, instance, args, channel);
}
