/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** select_cycle
*/

#include "client.h"
#include <stddef.h>
#include <sys/select.h>

int select_cycle(int client_fd)
{
    fd_set readfds;
    int max_fd = client_fd + 1;
    int activity = select(max_fd, &readfds, NULL, NULL, NULL);

    FD_ZERO(&readfds);
    FD_SET(client_fd, &readfds);
    FD_SET(0, &readfds);
    if (activity < 0)
        return (84);
    if (FD_ISSET(client_fd, &readfds))
        if (get_output_server(client_fd))
            return (1);
    if (FD_ISSET(0, &readfds))
        if (get_input_client(client_fd))
            return (1);
    return (0);
}
