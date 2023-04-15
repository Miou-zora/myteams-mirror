/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** commands
*/

#pragma once

#include <stddef.h>

#include "instance.h"

#define COMMAND_HELP "help"
#define COMMAND_LOGIN "login"
#define COMMAND_LOGOUT "logout"
#define COMMAND_USERS "users"
#define COMMAND_USER "user"
#define COMMAND_SEND "send"
#define COMMAND_MESSAGES "messages"
#define COMMAND_SUBSCRIBE "subscribe"
#define COMMAND_SUBSCRIBED "subscribed"
#define COMMAND_UNSUBSCRIBE "unsubscribe"
#define COMMAND_USE "use"
#define COMMAND_CREATE "create"
#define COMMAND_LIST "list"
#define COMMAND_INFO "info"
#define COMMAND_QUIT "quit"

void help(char **args);
void login(char **args);
void logout(char **args);
void user(char **args);
void users(char **args);
// void send(char **args);
void messages(char **args);
void subscribe(char **args);
void subscribed(char **args);
void unsubscribe(char **args);
void use(char **args);
void create(char **args);
void list(char **args);
void info(char **args);
void quit(char **args);

typedef struct command {
    const char *name;
    void (*func)(char **args);
} command_t;

extern const command_t COMMANDS_LIST[];
