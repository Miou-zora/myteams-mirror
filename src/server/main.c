/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** main
*/

#include "server.h"

void print_help()
{
    printf("USAGE: ./myteams_server port\n\n");
    printf("\tport is the port number on which the server socket listens.\n");
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("Usage: ./myteams_server port\n");
        return (84);
    }
    if (strcmp(av[1], "-help") == 0) {
        print_help();
        return (0);
    }
    server_t *server = server_init(av[1]);
    if (!server)
        return (84);
    // server_loop();
    return (0);
}
