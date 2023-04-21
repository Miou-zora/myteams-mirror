/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** list
*/

#include "commands.h"
#include "lib.h"

void list_reply(server_t *server, instance_t *current_instance)
{
    user_t *user = NULL;
    team_t *team = NULL;
    channel_t *channel = NULL;
    thread_t *thread = NULL;
    comment_t *reply = NULL;
    char user_uuid[37];
    char team_uuid[37];
    char channel_uuid[37];
    char thread_uuid[37];
    char reply_uuid[37];
    char buffer[1019];
    char *timestamp;

    uuid_unparse(current_instance->user_uuid, user_uuid);
    uuid_unparse(current_instance->team_uuid, team_uuid);
    uuid_unparse(current_instance->channel_uuid, channel_uuid);
    uuid_unparse(current_instance->thread_uuid, thread_uuid);
    user = get_user_by_uuid(&server->users, user_uuid);
    team = get_team_by_uuid(&server->teams, team_uuid);
    if (team == NULL) {
        add_output(&current_instance->output, "EC03", team_uuid);
        return;
    }
    if (!is_user_subscribed(user, team)) {
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
        return;
    }
    channel = get_channel_by_uuid(&team->channels_head, channel_uuid);
    if (channel == NULL) {
        add_output(&current_instance->output, "EC04", channel_uuid);
        return;
    }
    thread = get_thread_by_uuid(&channel->threads_head, thread_uuid);
    if (thread == NULL) {
        add_output(&current_instance->output, "EC05", thread_uuid);
        return;
    }
    LIST_FOREACH(reply, &thread->comments_head, next_comment) {
        uuid_unparse(reply->uuid, reply_uuid);
        timestamp = ctime(&reply->timestamp);
        sprintf(buffer, "%s %s \"%s\" \"%s\"", thread_uuid, user_uuid, timestamp,
            reply->body);
        add_output(&current_instance->output, "SU16", buffer);
    }
}

void list_threads(server_t *server, instance_t *current_instance)
{
    thread_t *thread;
    char team_uuid[37];
    char channel_uuid[37];
    char thread_uuid[37];
    char user_uuid[37];
    char buffer[1019];
    char *timestamp;
    team_t *team;
    channel_t *channel;
    user_t *user;

    uuid_unparse(current_instance->team_uuid, team_uuid);
    uuid_unparse(current_instance->channel_uuid, channel_uuid);
    uuid_unparse(current_instance->user_uuid, user_uuid);
    user = get_user_by_uuid(&server->users, user_uuid);
    team = get_team_by_uuid(&server->teams, team_uuid);
    if (team == NULL) {
        add_output(&current_instance->output, "EC03", team_uuid);
        return;
    }
    if (!is_user_subscribed(user, team)) {
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
        return;
    }
    channel = get_channel_by_uuid(&team->channels_head, channel_uuid);
    if (channel == NULL) {
        add_output(&current_instance->output, "EC04", channel_uuid);
        return;
    }
    LIST_FOREACH(thread, &channel->threads_head, next_thread) {
        uuid_unparse(thread->uuid, thread_uuid);
        timestamp = ctime(&thread->timestamp);
        sprintf(buffer, "%s %s \"%s\" \"%s\" \"%s\"", thread_uuid, user_uuid, timestamp,
            thread->title, thread->message);
        add_output(&current_instance->output, "SU15", buffer);
    }
}

void list_channels(server_t *server, instance_t *current_instance)
{
    channel_t *channel;
    char team_uuid[37];
    char channel_uuid[37];
    char user_uuid[37];
    char buffer[1019];
    team_t *team;
    user_t *user;

    uuid_unparse(current_instance->team_uuid, team_uuid);
    uuid_unparse(current_instance->user_uuid, user_uuid);
    user = get_user_by_uuid(&server->users, user_uuid);
    team = get_team_by_uuid(&server->teams, team_uuid);
    if (team == NULL) {
        add_output(&current_instance->output, "EC03", team_uuid);
        return;
    }
    if (!is_user_subscribed(user, team)) {
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
        return;
    }
    LIST_FOREACH(channel, &team->channels_head, next_channel) {
        uuid_unparse(channel->uuid, channel_uuid);
        sprintf(buffer, "%s \"%s\" \"%s\"", channel_uuid, channel->name,
            channel->description);
        add_output(&current_instance->output, "SU14", buffer);
    }
}

void list_teams(server_t *server, instance_t *current_instance)
{
    team_t *team;
    char team_uuid[37];
    char buffer[1019];

    LIST_FOREACH(team, &server->teams, next_team) {
        uuid_unparse(team->uuid, team_uuid);
        sprintf(buffer, "%s \"%s\" \"%s\"", team_uuid, team->name,
            team->description);
        add_output(&current_instance->output, "SU12", buffer);
    }
}

void cmd_list(server_t *server, instance_t *current_instance, char **args)
{
    if (uuid_is_null(current_instance->user_uuid)) {
        add_output(&current_instance->output, "EC01",
        "You must be logged in to use this command");
        return;
    }
    if (get_array_size(args) != 0) {
        add_output(&current_instance->output, "EC02",
        "Too many arguments");
        return;
    }
    if (uuid_is_null(current_instance->team_uuid)) {
        list_teams(server, current_instance);
        return;
    }
    if (uuid_is_null(current_instance->channel_uuid)) {
        list_channels(server, current_instance);
        return;
    }
    if (uuid_is_null(current_instance->thread_uuid)) {
        list_threads(server, current_instance);
        return;
    }
    list_reply(server, current_instance);
}
