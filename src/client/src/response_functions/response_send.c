/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response_send
*/

#include "response_server.h"
#include "logging_client.h"


void response_send(char **tab)
{
    if (tab[2][strlen(tab[2]) - 1] == '\n')
        tab[2][strlen(tab[2]) - 1] = '\0';
    client_event_private_message_received(tab[1], tab[3]);
}
