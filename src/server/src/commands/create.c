/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create
*/

#include "commands.h"
#include "lib.h"
#include "data_core.h"

static void create_comment(server_t *server, instance_t *current_instance,
    char **args)
{
    (void)server;
    (void)current_instance;
    (void)args;
    printf("create comment\n");
}

static void create_thread(server_t *server, instance_t *current_instance,
    char **args)
{
    (void)server;
    (void)current_instance;
    (void)args;
    printf("create thread\n");
}

static void create_channel(server_t *server, instance_t *current_instance,
    char **args)
{
    (void)server;
    (void)current_instance;
    (void)args;
    printf("create channel\n");
}

static void create_team(server_t *server, instance_t *current_instance,
    char **args)
{
    (void)server;
    (void)current_instance;
    (void)args;

    printf("create team\n");

    // int ret = 0;
    // if (get_array_size(args) != 2) {
    //     add_output(&current_instance->output, "EC02",
    //     "Invalid number of arguments");
    //     return;
    // }
    // if (strlen(args[0]) > MAX_NAME_LENGTH || strlen(args[1]) >
    // MAX_DESCRIPTION_LENGTH || strlen(args[0]) == 0 || strlen(args[1]) == 0) {
    //     add_output(&current_instance->output, "EC03",
    //         "Invalid arguments");
    //     return;
    // }
    // ret = add_team(&server->teams, args[0], args[1]);
    // if (ret == 1) {
    //     add_output(&current_instance->output, "EC04",
    //         "Team already exists");
    //     return;
    // }
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
                add_output(&current_instance->output, "EC03", buffer);
                return;
            }
            if (!uuid_is_null(current_instance->thread_uuid)) {
                uuid_unparse(current_instance->thread_uuid, uuid);
                thread = get_thread_by_uuid(&channel->threads_head, uuid);
                if (thread == NULL) {
                    sprintf(buffer, "%s", uuid);
                    add_output(&current_instance->output, "EC03", buffer);
                    return;
                } else {
                    create_comment(server, current_instance, args);
                    return;
                }
            } else {
                create_thread(server, current_instance, args);
                return;
            }
        } else {
            create_channel(server, current_instance, args);
            return;
        }
    } else {
        create_team(server, current_instance, args);
        return;
    }
}
