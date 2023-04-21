/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_resource_not_exist
*/

#include "response_server.h"

void response_thread_not_exist(char **args)
{
    client_error_unknown_thread(args[1]);
}

void response_channel_not_exist(char **args)
{
    client_error_unknown_channel(args[1]);
}

void response_team_not_exist(char **args)
{
    client_error_unknown_team(args[1]);
}
