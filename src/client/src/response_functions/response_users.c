/*
** EPITECH PROJECT, 2023
** client
** File description:
** response_users
*/

#include "response_server.h"
#include "logging_client.h"

void response_users(char **tab)
{
    if (tab[3][strlen(tab[3]) - 1] == '\n')
        tab[3][strlen(tab[3]) - 1] = '\0';
    if (strncmp(tab[1], "online", 6) == 0)
        client_print_users(tab[2], tab[3], 1);
    else
        client_print_users(tab[2], tab[3], 0);
}
