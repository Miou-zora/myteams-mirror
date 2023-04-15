/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_input_client
*/

#include "client.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int get_input_client(int client_fd)
{
    char buffer[1024];
    size_t BUFFER_SIZE = 1024;
    int read_bytes = 0;

    memset(buffer, 0, BUFFER_SIZE);
    read_bytes = read(0, buffer, BUFFER_SIZE);
    if (read_bytes == 0)
        return (1);
    buffer[read_bytes] = '\0';
    write(client_fd, buffer, strlen(buffer));
    return (0);
}
