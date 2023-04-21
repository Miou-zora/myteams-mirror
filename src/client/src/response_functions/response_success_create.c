/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** success_create
*/

#include "response_server.h"
#include <time.h>

void success_create_team(char **args)
{
    if (args[1] == NULL || args[2] == NULL || args[3] == NULL)
        return;
    client_print_team_created(args[1], args[2], args[3]);
}

void success_create_channel(char **args)
{
    if (args[1] == NULL || args[2] == NULL || args[3] == NULL)
        return;
    client_print_channel_created(args[1], args[2], args[3]);
}

void success_create_thread(char **args)
{
    struct tm tm;
    time_t time;

    if (args[1] == NULL || args[2] == NULL || args[3] == NULL
    || args[4] == NULL || args[5] == NULL)
        return;
    strptime(args[3], "%a %b %d %H:%M:%S %Y", &tm);
    time = mktime(&tm);
    client_print_thread_created(args[1], args[2], time, args[4], args[5]);
}

void success_create_reply(char **args)
{
    struct tm tm;
    time_t time;

    if (args[1] == NULL || args[2] == NULL || args[3] == NULL
    || args[4] == NULL)
        return;
    strptime(args[3], "%a %b %d %H:%M:%S %Y", &tm);
    time = mktime(&tm);
    client_print_reply_created(args[1], args[2], time, args[4]);
}
