/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** commands
*/

#include "commands.h"

const command_t COMMANDS_LIST[] = {
    {COMMAND_HELP, help},
    {COMMAND_LOGIN, login},
    {COMMAND_LOGOUT, logout},
    {COMMAND_USERS, users},
    {COMMAND_USER, user},
    {COMMAND_SEND, send},
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
