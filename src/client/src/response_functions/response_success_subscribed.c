/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_success_subscribed
*/

#include "response_server.h"
#include "logging_client.h"

void success_subscribed(char **args)
{
    if (args[3][strlen(args[3]) - 1] == '\n')
        args[3][strlen(args[3]) - 1] = '\0';
    client_print_teams(args[1], args[2], args[3]);
}
