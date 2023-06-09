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
#include "response.h"

const command_t COMMANDS_LIST[] = {
    {COMMAND_HELP, cmd_help},
    {COMMAND_LOGIN, cmd_login},
    {COMMAND_LOGOUT, cmd_logout},
    {COMMAND_USERS, cmd_users},
    {COMMAND_USER, cmd_user},
    {COMMAND_SEND, cmd_send},
    {COMMAND_MESSAGES, cmd_messages},
    {COMMAND_SUBSCRIBE, cmd_subscribe},
    {COMMAND_SUBSCRIBED, cmd_subscribed},
    {COMMAND_UNSUBSCRIBE, cmd_unsubscribe},
    {COMMAND_USE, cmd_use},
    {COMMAND_CREATE, cmd_create},
    {COMMAND_LIST, cmd_list},
    {COMMAND_INFO, cmd_info},
    {COMMAND_QUIT, cmd_quit},
    {NULL, NULL}
};

void exec_command(server_t *server, instance_t *current_instance, char *command)
{
    char **args = NULL;

    if (command == NULL || command[0] == '\0') {
        add_output(&current_instance->output, "ES04", "Unknown command");
        return;
    }
    args = split_line(command);
    for (int i = 0; COMMANDS_LIST[i].name; i++) {
        if (strcmp(args[0], COMMANDS_LIST[i].name) == 0) {
            COMMANDS_LIST[i].func(server, current_instance, &args[1]);
            return;
        }
    }
    add_output(&current_instance->output, "ES04", "Unknown command");
}
