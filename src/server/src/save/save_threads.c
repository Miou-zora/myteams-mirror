/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** save_threads
*/

#include "server.h"

static void write_in_file(FILE *file, channel_t *channel)
{
    thread_t *thread;
    char tmp[37];

    LIST_FOREACH(thread, &channel->threads_head, next_thread) {
        uuid_unparse(channel->uuid, tmp);
        fprintf(file, "%s ", tmp);
        uuid_unparse(thread->uuid, tmp);
        fprintf(file, "%s ", tmp);
        fprintf(file, "\"%s\" ", thread->title);
        fprintf(file, "\"%s\" ", thread->message);
        fprintf(file, "%s", ctime(&thread->timestamp));
    }
}

void save_threads(server_t *server)
{
    FILE *file = fopen("threads", "w+");
    channel_t *channel;
    team_t *team;

    if (file == NULL)
        file = fopen("threads", "w");
    printf("Saving threads...\n");
    LIST_FOREACH(team, &server->teams, next_team) {
        LIST_FOREACH(channel, &team->channels_head, next_channel) {
            write_in_file(file, channel);
        }
    }
    fclose(file);
}
