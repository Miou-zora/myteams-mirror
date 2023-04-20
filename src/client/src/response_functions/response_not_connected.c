/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_not_connected
*/

#include "response_server.h"
#include "logging_client.h"

void response_not_connected(char **args)
{
    (void)args;
    client_error_unauthorized();
}
