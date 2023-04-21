/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create_reply
*/

#include "server.h"
#include "data_core.h"
#include "lib.h"

static void send_reply_code(instance_t *instance, thread_t *thread,
    char **args, server_t *server)
{
    char uuid_thread[37];
    char user_uuid[37];
    char buffer[1019];
    char *timestamp;
    comment_t *comment;
    team_t *team;
    char team_uuid[37];

    uuid_unparse(instance->thread_uuid, uuid_thread);
    uuid_unparse(instance->user_uuid, user_uuid);
    comment = add_comment(&thread->comments_head, args[0],
    instance->user_uuid);
    server_event_reply_created(uuid_thread, user_uuid, args[0]);
    timestamp = ctime(&comment->timestamp);
    sprintf(buffer, "%s %s \"%s\" \"%s\"", uuid_thread, user_uuid,
    timestamp, args[0]);
    uuid_unparse(instance->team_uuid, team_uuid);
    team = get_team_by_uuid(&server->teams, team_uuid);
    send_message_to_team(server, "SU10", buffer, team);
}

static void reply(server_t *server, instance_t *instance, char **args,
        thread_t *thread)
{
    if (get_array_size(args) != 1) {
        add_output(&instance->output, "EC02", "Invalid number of arguments");
        return;
    }
    if (strlen(args[0]) > MAX_DESCRIPTION_LENGTH) {
        add_output(&instance->output, "EC07", "Invalid arguments size");
        return;
    }
    send_reply_code(instance, thread, args, server);
}

static bool check_team(team_t *team, instance_t *instance)
{
    char tmp1[37];
    char tmp2[37];
    char tmp3[37];

    if (team == NULL) {
        uuid_unparse(instance->team_uuid, tmp1);
        uuid_unparse(instance->channel_uuid, tmp2);
        uuid_unparse(instance->thread_uuid, tmp3);
        add_output(&instance->output, "EC03", tmp1);
        add_output(&instance->output, "EC04", tmp2);
        add_output(&instance->output, "EC05", tmp3);
        return false;
    }
    return true;
}

static bool check_channel(channel_t *channel, instance_t *instance)
{
    char tmp2[37];
    char tmp3[37];

    if (channel == NULL) {
        uuid_unparse(instance->channel_uuid, tmp2);
        uuid_unparse(instance->thread_uuid, tmp3);
        add_output(&instance->output, "EC04", tmp2);
        add_output(&instance->output, "EC05", tmp3);
        return false;
    }
    return true;
}

void check_before_reply(server_t *server, instance_t *instance,
    char **args, team_t *team)
{
    char tmp2[37];
    char tmp3[37];
    channel_t *channel;
    thread_t *thread;

    memset(tmp2, 0, 37);
    memset(tmp3, 0, 37);
    if (!check_team(team, instance))
        return;
    uuid_unparse(instance->channel_uuid, tmp2);
    channel = get_channel_by_uuid(&team->channels_head, tmp2);
    if (!check_channel(channel, instance))
        return;
    uuid_unparse(instance->thread_uuid, tmp3);
    thread = get_thread_by_uuid(&channel->threads_head, tmp3);
    if (thread == NULL) {
        add_output(&instance->output, "EC05", tmp3);
        return;
    }
    reply(server, instance, args, thread);
}
