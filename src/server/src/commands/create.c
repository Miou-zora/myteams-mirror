/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create_team
*/

#include "server.h"
#include "data_core.h"
#include "lib.h"

void create_team(server_t *server, instance_t *instance, char **args)
{
    team_t *team;
    char uuid_team[37];
    char uuid_user[37];
    char buffer[1019];

    if (get_array_size(args) != 2) {
        add_output(&instance->output, "EC02", "Invalid number of arguments");
        return;
    }
    if (strlen(args[0]) > MAX_NAME_LENGTH || strlen(args[1]) > MAX_DESCRIPTION_LENGTH) {
        add_output(&instance->output, "EC07", "Invalid arguments size");
        return;
    }
    if (add_team(&server->teams, args[0], args[1]) == 1) {
        add_output(&instance->output, "EC06", "Team already exists");
        return;
    }
    team = get_team_by_name(&server->teams, args[0]);
    uuid_unparse(team->uuid, uuid_team);
    uuid_unparse(instance->user_uuid, uuid_user);
    server_event_team_created(uuid_team, args[0], uuid_user);
    sprintf(buffer, "%s \"%s\" \"%s\"", uuid_team, args[0], args[1]);
    send_message_every_users(server, "SU07", buffer);
}

void create_channel(server_t *server, instance_t *instance, char **args, team_t *team)
{
    char uuid_team[37];
    char uuid_channel[37];
    channel_t *channel;
    char buffer[1019];

    memset(uuid_team, 0, 37);
    if (team == NULL) {
        uuid_unparse(instance->team_uuid, uuid_team);
        add_output(&instance->output, "EC03", uuid_team);
        return;
    }
    if (get_array_size(args) != 2) {
        add_output(&instance->output, "EC02", "Invalid number of arguments");
        return;
    }
    if (strlen(args[0]) > MAX_NAME_LENGTH || strlen(args[1]) > MAX_DESCRIPTION_LENGTH) {
        add_output(&instance->output, "EC07", "Invalid arguments size");
        return;
    }
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
}

void create_thread(server_t *server, instance_t *instance, char **args, channel_t *channel)
{
    thread_t *thread;
    char team_uuid[37];
    char channel_uuid[37];
    char thread_uuid[37];
    char user_uuid[37];
    char buffer[1019];
    char *timestamp;
    team_t *team;

    if (get_array_size(args) != 2) {
        add_output(&instance->output, "EC02", "Invalid number of arguments");
        return;
    }
    if (strlen(args[0]) > MAX_NAME_LENGTH || strlen(args[1]) > MAX_DESCRIPTION_LENGTH) {
        add_output(&instance->output, "EC07", "Invalid arguments size");
        return;
    }
    if (add_thread(&channel->threads_head, args[0], args[1]) == 1) {
        add_output(&instance->output, "EC06", "Thread already exists");
        return;
    }
    uuid_unparse(instance->channel_uuid, channel_uuid);
    thread = get_thread_by_name(&channel->threads_head, args[0]);
    uuid_unparse(thread->uuid, thread_uuid);
    uuid_unparse(instance->user_uuid, user_uuid);
    timestamp = ctime(&thread->timestamp);
    server_event_thread_created(channel_uuid, thread_uuid, user_uuid, args[0], args[1]);
    sprintf(buffer, "%s %s %s \"%s\" \"%s\"", thread_uuid, user_uuid, timestamp, args[0], args[1]);
    uuid_unparse(instance->team_uuid, team_uuid);
    team = get_team_by_uuid(&server->teams, team_uuid);
    send_message_to_team(server, "SU09", buffer, team);
}

void check_before_create_thread(server_t *server, instance_t *instance, char **args, team_t *team)
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

void reply(server_t *server, instance_t *instance, char **args, thread_t *thread)
{
    char uuid_thread[37];
    char user_uuid[37];
    char buffer[1019];
    char *timestamp;
    comment_t *comment;
    team_t *team;
    char team_uuid[37];

    if (get_array_size(args) != 1) {
        add_output(&instance->output, "EC02", "Invalid number of arguments");
        return;
    }
    if (strlen(args[0]) > MAX_DESCRIPTION_LENGTH) {
        add_output(&instance->output, "EC07", "Invalid arguments size");
        return;
    }
    uuid_unparse(instance->thread_uuid, uuid_thread);
    uuid_unparse(instance->user_uuid, user_uuid);
    comment = add_comment(&thread->comments_head, args[0], instance->user_uuid);
    server_event_reply_created(uuid_thread, user_uuid, args[0]);
    timestamp = ctime(&comment->timestamp);
    sprintf(buffer, "%s %s %s \"%s\"", uuid_thread, user_uuid, timestamp, args[0]);
    uuid_unparse(instance->team_uuid, team_uuid);
    team = get_team_by_uuid(&server->teams, team_uuid);
    send_message_to_team(server, "SU10", buffer, team);
}

void check_before_reply(server_t *server, instance_t *instance, char **args, team_t *team)
{
    char tmp1[37];
    char tmp2[37];
    char tmp3[37];
    channel_t *channel;
    thread_t *thread;

    memset(tmp1, 0, 37);
    memset(tmp2, 0, 37);
    memset(tmp3, 0, 37);
    if (team == NULL) {
        uuid_unparse(instance->team_uuid, tmp1);
        uuid_unparse(instance->channel_uuid, tmp2);
        uuid_unparse(instance->thread_uuid, tmp3);
        add_output(&instance->output, "EC03", tmp1);
        add_output(&instance->output, "EC04", tmp2);
        add_output(&instance->output, "EC05", tmp3);
        return;
    }
    uuid_unparse(instance->channel_uuid, tmp2);
    channel = get_channel_by_uuid(&team->channels_head, tmp2);
    if (channel == NULL) {
        uuid_unparse(instance->thread_uuid, tmp3);
        add_output(&instance->output, "EC04", tmp2);
        add_output(&instance->output, "EC05", tmp3);
        return;
    }
    uuid_unparse(instance->thread_uuid, tmp3);
    thread = get_thread_by_uuid(&channel->threads_head, tmp3);
    if (thread == NULL) {
        add_output(&instance->output, "EC05", tmp3);
        return;
    }
    reply(server, instance, args, thread);
}

void cmd_create(server_t *server, instance_t *instance, char **args)
{
    team_t *team;
    char team_uuid[37];

    if (uuid_is_null(instance->team_uuid)) {
        create_team(server, instance, args);
        return;
    }
    if (uuid_is_null(instance->channel_uuid)) {
        uuid_unparse(instance->team_uuid, team_uuid);
        team = get_team_by_uuid(&server->teams, team_uuid);
        create_channel(server, instance, args, team);
        return;
    }
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