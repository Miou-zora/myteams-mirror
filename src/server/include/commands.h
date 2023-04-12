/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** commands
*/

#pragma once

#include <stddef.h>

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

void help(/* TODO: Server, Client */ char **args);
void login(/* TODO: Server, Client */ char **args);
void logout(/* TODO: Server, Client */ char **args);
void user(/* TODO: Server, Client */ char **args);
void users(/* TODO: Server, Client */ char **args);
void send(/* TODO: Server, Client */ char **args);
void messages(/* TODO: Server, Client */ char **args);
void subscribe(/* TODO: Server, Client */ char **args);
void subscribed(/* TODO: Server, Client */ char **args);
void unsubscribe(/* TODO: Server, Client */ char **args);
void use(/* TODO: Server, Client */ char **args);
void create(/* TODO: Server, Client */ char **args);
void list(/* TODO: Server, Client */ char **args);
void info(/* TODO: Server, Client */ char **args);
void quit(/* TODO: Server, Client */ char **args);

typedef struct command {
    const char *name;
    void (*func)(char **args);
} command_t;

extern const command_t COMMANDS_LIST[];
