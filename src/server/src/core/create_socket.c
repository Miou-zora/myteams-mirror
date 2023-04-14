/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create_socket
*/

#include "server.h"

int create_socket(in_addr_t adress, int port)
{
    struct sockaddr_in addr;
    int sock = 0;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = adress;
    addr.sin_port = htons(port);
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed\n");
        exit(EXIT_FAILURE);
    }
    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind failed: ");
        exit(EXIT_FAILURE);
    }
    if (listen(sock, 1) < 0) {
        perror("listen failed\n");
        exit(EXIT_FAILURE);
    } else
        printf("Listening on port %d\n", port);
    return (sock);
}
