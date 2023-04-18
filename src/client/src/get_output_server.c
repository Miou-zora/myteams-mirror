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
    int read_bytes = 0;

    memset(buffer, 0, BUFFER_SIZE);
    read_bytes = read(client_fd, buffer, BUFFER_SIZE);
    if (read_bytes == 0)
        return (1);
    buffer[read_bytes] = '\0';
    analyse_response(buffer);
    return (0);
}
