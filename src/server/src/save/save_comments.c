/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** save_comments
*/

#include "server.h"

static void write_in_file(FILE *file, channel_t *channel, instance_t *instance)
{
    thread_t *thread;
    comment_t *comment;
    char tmp[37];

    LIST_FOREACH(thread, &channel->threads_head, next_thread) {
        LIST_FOREACH(comment, &thread->comments_head, next_comment) {
            uuid_unparse(thread->uuid, tmp);
            fprintf(file, "%s ", tmp);
            uuid_unparse(comment->uuid, tmp);
            fprintf(file, "%s ", tmp);
            uuid_unparse(instance->user_uuid, tmp);
            fprintf(file, "%s ", tmp);
            fprintf(file, "\"%s\" ", comment->body);
            fprintf(file, "\"%s\"", ctime(&comment->timestamp));
        }
    }
}

void save_comments(server_t *server, instance_t *instance)
{
    FILE *file = fopen("comments", "w+");
    channel_t *channel;
    team_t *team;

    if (file == NULL)
        file = fopen("comments", "w");
    printf("Saving comments...\n");
    LIST_FOREACH(team, &server->teams, next_team) {
        LIST_FOREACH(channel, &team->channels_head, next_channel) {
            write_in_file(file, channel, instance);
        }
    }
    fclose(file);
}
