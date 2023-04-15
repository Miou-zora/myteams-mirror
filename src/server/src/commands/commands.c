/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** commands
*/

#include "commands.h"
#include "instance.h"
#include "server.h"
#include "lib.h"

const command_t COMMANDS_LIST[] = {
    {COMMAND_HELP, help},
    {COMMAND_LOGIN, login},
    {COMMAND_LOGOUT, logout},
    {COMMAND_USERS, users},
    {COMMAND_USER, user},
    // {COMMAND_SEND, send},
    {COMMAND_MESSAGES, messages},
    {COMMAND_SUBSCRIBE, subscribe},
    {COMMAND_SUBSCRIBED, subscribed},
    {COMMAND_UNSUBSCRIBE, unsubscribe},
    {COMMAND_USE, use},
    {COMMAND_CREATE, create},
    {COMMAND_LIST, list},
    {COMMAND_INFO, info},
    {COMMAND_QUIT, quit},
    {NULL, NULL}
};

void exec_command(server_t *server, instance_t *current_instance, char *command)
{
    (void)command;
    (void)server;
    char **args = data_to_array_str(command, " ");
    (void)args;
    // for (int i = 0; i < 4; i++) {
    //     if (strcmp(args[0], COMMANDS_LIST[i].name) == 0) {
    //         COMMANDS_LIST[i].func(args);
    //         return;
    //     }
    // }
    write(current_instance->socket, "ES00 Unknown command.\n", 21);
}
