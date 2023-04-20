/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_user_dont_exist
*/

#include "response_server.h"
#include "logging_client.h"

void response_user_dont_exist(char **args)
{
    if (args[1][strlen(args[1]) - 1] == '\n')
        args[1][strlen(args[1]) - 1] = '\0';
    client_error_unknown_user(args[1]);
}
