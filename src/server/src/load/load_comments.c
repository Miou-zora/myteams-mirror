/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load_comments
*/

#include "load.h"
#include "save.h"
#include "server.h"
#include "data_core.h"
#include "lib.h"

static void analyse_thread(thread_t *thread, char **args)
{
    comment_t *comment = NULL;
    comment_t *comment_tmp = NULL;
    struct tm tm;
    time_t time;
    uuid_t uuid;
    uuid_t uuid_comment;

    strptime(args[4], "%a %b %d %H:%M:%S %Y", &tm);
    time = mktime(&tm);
    uuid_parse(args[1], uuid);
    LIST_FOREACH(comment, &thread->comments_head, next_comment) {
        if (uuid_compare(comment->uuid, uuid) == 0) {
            printf("Comment already exists\n");
            return;
        }
        uuid_parse(args[2], uuid_comment);
        add_comment(&thread->comments_head, args[3], uuid_comment);
        comment_tmp = get_comment_by_uuid(&thread->comments_head, uuid);
        comment_tmp->timestamp = time;
    }

}

static int check_args(server_t *server, char **args)
{
    channel_t *channel = NULL;
    team_t *team = NULL;
    thread_t *thread = NULL;

    if (args == NULL) {
        printf("Error while loading comments\n");
        return (84);
    }
    LIST_FOREACH(team, &server->teams, next_team) {
        LIST_FOREACH(channel, &team->channels_head, next_channel) {
            thread = get_thread_by_uuid(&channel->threads_head, args[0]);
            if (thread != NULL)
                analyse_thread(thread, args);
        }
    }
    return (0);
}

int load_comments(server_t *server)
{
    FILE *file = fopen("comments", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args = NULL;

    if (file == NULL) {
        printf("No threads found, creating new file\n");
        file = fopen("comments", "w");
        fclose(file);
        return (0);
    }
    while ((read = getline(&line, &len, file)) != -1) {
        args = split_line(line);
        if (check_args(server, args) == 84)
            return (84);
    }
    fclose(file);
    return (0);
}
