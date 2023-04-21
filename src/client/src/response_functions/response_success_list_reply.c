/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_success_list_reply
*/

#include "response_server.h"
#include "logging_client.h"

void success_list_reply(char **args)
{
    struct tm tm;
    time_t time;

    if (args[4][strlen(args[4]) - 1] == '\n')
        args[4][strlen(args[4]) - 1] = '\0';
    strptime(args[3], "%a %b %d %H:%M:%S %Y", &tm);
    time = mktime(&tm);
    client_thread_print_replies(args[1], args[2], time, args[4]);
}
