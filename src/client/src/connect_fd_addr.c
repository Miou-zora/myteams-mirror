/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** connect_fd_addr
*/

#include "client.h"

int connect_fd_addr(int fd, struct sockaddr_in addr)
{
    if (connect(fd, (struct sockaddr*) &addr, sizeof(struct sockaddr_in)) != 0)
        return (84);
    return (0);
}
