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
    char user_uuid[37];
    char thread_uuid[37];
    char reply_uuid[37];
    char team_uuid[37];
    char channel_uuid[37];
    char buffer[1019];
    uuid_unparse(current_instance->user_uuid, user_uuid);
    user_t *user = get_user_by_uuid(&server->users, user_uuid);
    team_t *team = check_team(server, current_instance, team_uuid, user);
    channel_t *channel = check_channel(team, current_instance, channel_uuid);
    thread_t *thread = check_thread(channel, current_instance, thread_uuid);
    comment_t *reply = NULL;

    if (!thread)
        return;
    LIST_FOREACH(reply, &thread->comments_head, next_comment) {
        uuid_unparse(reply->uuid, reply_uuid);
        sprintf(buffer, "%s %s \"%s\" \"%s\"", thread_uuid, user_uuid,
            ctime(&reply->timestamp), reply->body);
        add_output(&current_instance->output, "SU16", buffer);}
}

void list_threads(server_t *server, instance_t *current_instance)
{
    thread_t *thread;
    char team_uuid[37];
    char channel_uuid[37];
    char thread_uuid[37];
    char user_uuid[37];
    char buffer[1019];
    uuid_unparse(current_instance->user_uuid, user_uuid);
    user_t *user = get_user_by_uuid(&server->users, user_uuid);
    team_t *team = check_team(server, current_instance, team_uuid, user);
    channel_t *channel = check_channel(team, current_instance, channel_uuid);

    if (!channel)
        return;
    LIST_FOREACH(thread, &channel->threads_head, next_thread) {
        uuid_unparse(thread->uuid, thread_uuid);
        sprintf(buffer, "%s %s \"%s\" \"%s\" \"%s\"", thread_uuid, user_uuid,
            ctime(&thread->timestamp), thread->title, thread->message);
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
    team = check_team(server, current_instance, team_uuid, user);
    if (!team)
        return;
    LIST_FOREACH(channel, &team->channels_head, next_channel) {
        uuid_unparse(channel->uuid, channel_uuid);
        sprintf(buffer, "%s \"%s\" \"%s\"", channel_uuid, channel->name,
            channel->description);
        add_output(&current_instance->output, "SU17", buffer);
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
    } else if (get_array_size(args) != 0) {
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
    } else if (uuid_is_null(current_instance->thread_uuid)) {
        list_threads(server, current_instance);
    } else {
        list_reply(server, current_instance);
    }
}
