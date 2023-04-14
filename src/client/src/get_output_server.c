/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_output_server
*/

#include "client.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
