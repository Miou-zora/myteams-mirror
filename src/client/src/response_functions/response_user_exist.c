/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_user
*/

#include "response_server.h"
#include "logging_client.h"

void response_user_exist(char **args)
{
    if (args[3][strlen(args[3]) - 1] == '\n')
        args[3][strlen(args[3]) - 1] = '\0';
    if (strncmp(args[1], "online", 6) == 0)
        client_print_user(args[2], args[3], 1);
    else
        client_print_user(args[2], args[3], 0);
}
