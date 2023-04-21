/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_success_list_thread
*/

#include "response_server.h"
#include "logging_client.h"

void success_list_thread(char **args)
{
    struct tm tm;
    time_t time;

    if (args[5][strlen(args[5]) - 1] == '\n')
        args[5][strlen(args[5]) - 1] = '\0';
    strptime(args[3], "%a %b %d %H:%M:%S %Y", &tm);
    time = mktime(&tm);
    client_channel_print_threads(args[1], args[2], time, args[4], args[5]);
}
