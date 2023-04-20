/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_logout
*/


#include "response_server.h"
#include "logging_client.h"

void response_logout(char **tab)
{
    if (tab[2][strlen(tab[2]) - 1] == '\n')
        tab[2][strlen(tab[2]) - 1] = '\0';
    client_event_logged_out(tab[1], tab[2]);
}
