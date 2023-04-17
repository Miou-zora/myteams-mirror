/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** bind_fd_addr
*/

#include "network_lib.h"

int bind_fd_addr(int fd, struct sockaddr_in addr)
{
    if (bind(fd, (struct sockaddr*) &addr, sizeof(struct sockaddr_in)) != 0)
        return (84);
    return (0);
}
