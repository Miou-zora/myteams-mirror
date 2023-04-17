/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create_socket
*/

#include "server.h"
#include "network_lib.h"

int create_socket(in_addr_t adress, int port)
{
    struct sockaddr_in addr;
    int sock = 0;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = adress;
    addr.sin_port = htons(port);
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return (EPI_FAILURE);
    }
    if (bind_fd_addr(sock, addr) == 84) {
        perror("bind failed");
        return (EPI_FAILURE);
    }
    if (listen(sock, 1) < 0) {
        perror("listen failed");
        return (EPI_FAILURE);
    } else
        printf("Listening on port %d\n", port);
    return (sock);
}
