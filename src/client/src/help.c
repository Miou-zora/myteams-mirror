/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** help command
*/

#include "client.h"
#include <unistd.h>
#include <string.h>

int help(void)
{
    char message_to_display[] = "USAGE:\t./myteams_cli ip port\n"
    "\tip\tis the server ip address on which the server socket listens\n"
    "\tport\tis the port number on which the server socket listens\n";
    if (write(1, message_to_display, strlen(message_to_display)) == -1) {
        return (84);
    } else {
        return (0);
    }
}
