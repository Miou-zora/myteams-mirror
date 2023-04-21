/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_success_unsubscribe
*/

#include "response_server.h"
#include "logging_client.h"

void success_unsubscribe(char **args)
{
    if (args[2][strlen(args[2]) - 1] == '\n')
        args[2][strlen(args[2]) - 1] = '\0';
    client_print_unsubscribed(args[1], args[2]);
}
