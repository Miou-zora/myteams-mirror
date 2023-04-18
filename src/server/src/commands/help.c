/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** help
*/

#include "commands.h"

void cmd_help(server_t *server, instance_t *current_instance, char **args)
{
    (void)server;
    if (args[0] != NULL) {
        reply(current_instance->buff_out, "EC02");
        return;
    }
    reply(current_instance->buff_out, "SU01");
}
