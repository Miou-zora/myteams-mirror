/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create
*/

#include "commands.h"
#include "lib.h"
#include "data_core.h"

static void create_comment(thread_t *thread, instance_t *current_instance,
    char **args)
{
    char buffer[1019];
    char uuid_channel[37];
    char uuid_thread[37];
    char uuid_user[37];
    int ret = 0;

    if (get_array_size(args) != 1) {
        add_output(&current_instance->output, "EC02",
            "Invalid number of arguments");
        return;
    }
    if (strlen(args[0]) > MAX_NAME_LENGTH || strlen(args[0]) == 0) {
        add_output(&current_instance->output, "EC02",
            "Invalid arguments");
        return;
    }
    ret = add_comment(&thread->comments_head, args[0], current_instance->user_uuid);
    if (ret == 1) {
        add_output(&current_instance->output, "EC06",
            "Comment already exists");
        return;
    }
    uuid_unparse(current_instance->user_uuid, uuid_user);
    uuid_unparse(current_instance->channel_uuid, uuid_channel);
    uuid_unparse(current_instance->thread_uuid, uuid_thread);
    sprintf(buffer, "%s %s %s \"%s\"", uuid_thread, uuid_user, "timestamp",
        args[0]);
    server_event_reply_created(uuid_thread, uuid_user, args[0]);
    add_output(&current_instance->output, "SU10", buffer); // Send that to all
}

static void create_thread(channel_t *channel, instance_t *current_instance,
    char **args)
{
    char buffer[1019];
    char uuid_channel[37];
    char uuid_thread[37];
    char uuid_user[37];
    int ret = 0;

    if (get_array_size(args) != 2) {
        add_output(&current_instance->output, "EC02",
            "Invalid number of arguments");
        return;
    }
    if (strlen(args[0]) > MAX_NAME_LENGTH || strlen(args[1]) >
    MAX_DESCRIPTION_LENGTH || strlen(args[0]) == 0 || strlen(args[1]) == 0) {
        add_output(&current_instance->output, "EC02",
            "Invalid arguments");
        return;
    }
    ret = add_thread(&channel->threads_head, args[0], args[1]);
    if (ret == 1) {
        add_output(&current_instance->output, "EC06",
            "Thread already exists");
        return;
    }
    uuid_unparse(get_thread_by_name(&channel->threads_head,
        args[0])->uuid, uuid_thread);
    uuid_unparse(channel->uuid, uuid_channel);
    uuid_unparse(current_instance->user_uuid, uuid_user);
    sprintf(buffer, "%s \"%s\" \"%s\"", uuid_thread, args[0], args[1]);
    printf("thread created\n");
    server_event_thread_created(uuid_channel, uuid_thread, uuid_user, args[0],
        args[1]);
    add_output(&current_instance->output, "SU09", buffer); // Send that to all
}

static void create_channel(team_t *teams, instance_t *current_instance,
    char **args)
{
    char buffer[1019];
    char uuid_channel[37];
    char uuid_user[37];
    int ret = 0;

    if (get_array_size(args) != 2) {
        add_output(&current_instance->output, "EC02",
            "Invalid number of arguments");
        return;
    }
    if (strlen(args[0]) > MAX_NAME_LENGTH || strlen(args[1]) >
    MAX_DESCRIPTION_LENGTH || strlen(args[0]) == 0 || strlen(args[1]) == 0) {
        add_output(&current_instance->output, "EC02",
            "Invalid arguments");
        return;
    }
    ret = add_channel(&teams->channels_head, args[0], args[1]);
    if (ret == 1) {
        add_output(&current_instance->output, "EC06",
            "Already exists");
        return;
    }
    uuid_unparse(get_channel_by_name(&teams->channels_head, args[0])->uuid, uuid_channel);
    uuid_unparse(current_instance->user_uuid, uuid_user);
    sprintf(buffer, "%s \"%s\" \"%s\"", uuid_channel, args[0], args[1]);
    server_event_channel_created(uuid_channel, args[0], uuid_user);
    add_output(&current_instance->output, "SU08", buffer); // Send that to all
}

static void create_team(server_t *server, instance_t *current_instance,
    char **args)
{
    char buffer[1019];
    char uuid_team[37];
    char uuid_user[37];

    int ret = 0;
    if (get_array_size(args) != 2) {
        add_output(&current_instance->output, "EC02",
        "Invalid number of arguments");
        return;
    }
    if (strlen(args[0]) > MAX_NAME_LENGTH || strlen(args[1]) >
    MAX_DESCRIPTION_LENGTH || strlen(args[0]) == 0 || strlen(args[1]) == 0) {
        add_output(&current_instance->output, "EC02",
            "Invalid arguments");
        return;
    }
    ret = add_team(&server->teams, args[0], args[1]);
    if (ret == 1) {
        add_output(&current_instance->output, "EC06",
            "Already exists");
        return;
    }
    uuid_unparse(get_team_by_name(&server->teams, args[0])->uuid, uuid_team);
    uuid_unparse(current_instance->user_uuid, uuid_user);
    sprintf(buffer, "%s \"%s\" \"%s\"", uuid_team, args[0], args[1]);
    server_event_team_created(uuid_team, args[0], uuid_user);
    add_output(&current_instance->output, "SU07", buffer); // Send that to all
}

void cmd_create(server_t *server, instance_t *current_instance, char **args)
{
    team_t *team = NULL;
    channel_t *channel = NULL;
    thread_t *thread = NULL;
    char uuid[37];
    char buffer[1019];

    if (uuid_is_null(current_instance->user_uuid)) {
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
        return;
    }
    if (!uuid_is_null(current_instance->team_uuid)) {
        uuid_unparse(current_instance->team_uuid, uuid);
        team = get_team_by_uuid(&server->teams, uuid);
        if (team == NULL) {
            sprintf(buffer, "%s", uuid);
            add_output(&current_instance->output, "EC03", buffer);
            return;
        }
        if (!uuid_is_null(current_instance->channel_uuid)) {
            uuid_unparse(current_instance->channel_uuid, uuid);
            channel = get_channel_by_uuid(&team->channels_head, uuid);
            if (channel == NULL) {
                sprintf(buffer, "%s", uuid);
                add_output(&current_instance->output, "EC04", buffer);
                return;
            }
            if (!uuid_is_null(current_instance->thread_uuid)) {
                uuid_unparse(current_instance->thread_uuid, uuid);
                thread = get_thread_by_uuid(&channel->threads_head, uuid);
                if (thread == NULL) {
                    sprintf(buffer, "%s", uuid);
                    add_output(&current_instance->output, "EC05", buffer);
                    return;
                } else {
                    create_comment(thread, current_instance, args);
                    return;
                }
            } else {
                printf("create thread\n");
                create_thread(channel, current_instance, args);
                return;
            }
        } else {
            printf("create channel\n");
            create_channel(team, current_instance, args);
            return;
        }
    } else {
        printf("create team\n");
        create_team(server, current_instance, args);
        return;
    }
}
