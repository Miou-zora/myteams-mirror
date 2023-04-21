/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_create_already_exist
*/

#include "response_server.h"

void response_create_already_exist(char **args)
{
    (void)args;
    client_error_already_exist();
}
