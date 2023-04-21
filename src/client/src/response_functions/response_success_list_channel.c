/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_success_list_channel
*/

#include "response_server.h"
#include "logging_client.h"

void success_list_channel(char **args)
{
    if (args[3][strlen(args[3]) - 1] == '\n')
        args[3][strlen(args[3]) - 1] = '\0';
    client_team_print_channels(args[1], args[2], args[3]);
}
