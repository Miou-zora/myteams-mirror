/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load_threads
*/

#include "load.h"
#include "lib.h"

static int check_args(server_t *server, char **args)
{
    channel_t *channel = NULL;
    team_t *team = NULL;
    thread_t *thread = NULL;
    struct tm tm;
    time_t time;

    if (args == NULL) {
        printf("Error while loading channels\n");
        return (84);
    }
    LIST_FOREACH(team, &server->teams, next_team) {
        channel = get_channel_by_uuid(&team->channels_head, args[0]);
        if (channel != NULL) {
            strptime(args[4], "%a %b %d %H:%M:%S %Y", &tm);
            time = mktime(&tm);
            add_thread_with_uuid(&channel->threads_head, args[2],
            args[3], args[1]);
            thread = get_thread_by_uuid(&channel->threads_head, args[1]);
            thread->timestamp = time;
            return (0);
        }
    }
    return (0);
}

int load_threads(server_t *server)
{
    FILE *file = fopen("threads", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args = NULL;

    if (file == NULL) {
        printf("No threads found, creating new file\n");
        file = fopen("threads", "w");
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