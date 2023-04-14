/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** client
*/

#include "client.h"

int client(char *ip, char *port)
{
    int client_fd = init_client(ip, port);
    int output_cycle = 0;

    if (client_fd == 84)
        return (84);
    while (1) {
        output_cycle = select_cycle(client_fd);
        if (output_cycle == 1)
            return (0);
        if (output_cycle == 84)
            return (84);
    }
    return (0);
}
