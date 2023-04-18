/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** SU02
*/

#include "response_server.h"
#include "logging_client.h"

void response_login(char **tab)
{
    tab[2][strlen(tab[2]) - 1] = '\0';
    client_event_logged_in(tab[1], tab[2]);
}
