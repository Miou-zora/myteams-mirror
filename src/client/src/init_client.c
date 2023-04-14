/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** init_client
*/

#include "client.h"

int init_client(char *ip, char *port)
{
    struct sockaddr_in client_addr = create_addr(ip, "0");
    struct sockaddr_in server_addr = create_addr(ip, port);
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0)
        return (84);
    if (bind_fd_addr(client_fd, client_addr) == 84)
        return (84);
    if (connect_fd_addr(client_fd, server_addr) == 84)
        return (84);
    return (client_fd);
}
