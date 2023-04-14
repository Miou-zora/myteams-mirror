/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** client
*/

#include "client.h"
#include "sys/socket.h"
#include "sys/types.h"
#include "netinet/in.h"
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <stddef.h>

struct sockaddr_in create_addr(char *ip, char *port)
{
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(atoi(port));
    return (addr);
}

int bind_fd_addr(int fd, struct sockaddr_in addr)
{
    if (bind(fd, (struct sockaddr*) &addr, sizeof(struct sockaddr_in)) != 0)
        return (84);
    return (0);
}

int connect_fd_addr(int fd, struct sockaddr_in addr)
{
    if (connect(fd, (struct sockaddr*) &addr, sizeof(struct sockaddr_in)) != 0)
        return (84);
    return (0);
}

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

int get_output_server(int client_fd)
{
    char buffer[1024];
    size_t BUFFER_SIZE = 1024;

    memset(buffer, 0, BUFFER_SIZE);
    int read_bytes = read(client_fd, buffer, BUFFER_SIZE);
    if (read_bytes == 0) {
        printf("Server Disconnected\n");
        return (1);
    }
    buffer[read_bytes] = '\0';
    printf("%s", buffer);
    return (0);
}

int get_input_client(int client_fd)
{
    char buffer[1024];
    size_t BUFFER_SIZE = 1024;

    memset(buffer, 0, BUFFER_SIZE);
    int read_bytes = read(0, buffer, BUFFER_SIZE);
    if (read_bytes == 0) {
        printf("Client Disconnected\n");
        return (1);
    }
    buffer[read_bytes] = '\0';
    write(client_fd, buffer, strlen(buffer));
    return (0);
}

int select_cycle(int client_fd)
{
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(client_fd, &readfds);
    FD_SET(0, &readfds);
    int max_fd = client_fd + 1;
    int activity = select(max_fd, &readfds, NULL, NULL, NULL);
    if (activity < 0)
        return (84);
    if (FD_ISSET(client_fd, &readfds)) {
        if (get_output_server(client_fd))
            return (1);
    }
    if (FD_ISSET(0, &readfds)) {
        if (get_input_client(client_fd))
            return (1);
    }
    return (0);
}

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
