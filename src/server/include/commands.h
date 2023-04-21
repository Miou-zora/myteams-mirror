/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** commands
*/

#pragma once

#include <stddef.h>

#include "instance.h"
#include "server.h"
#include "response.h"

#define COMMAND_HELP "/help"
#define COMMAND_LOGIN "/login"
#define COMMAND_LOGOUT "/logout"
#define COMMAND_USERS "/users"
#define COMMAND_USER "/user"
#define COMMAND_SEND "/send"
#define COMMAND_MESSAGES "/messages"
#define COMMAND_SUBSCRIBE "/subscribe"
#define COMMAND_SUBSCRIBED "/subscribed"
#define COMMAND_UNSUBSCRIBE "/unsubscribe"
#define COMMAND_USE "/use"
#define COMMAND_CREATE "/create"
#define COMMAND_LIST "/list"
#define COMMAND_INFO "/info"
#define COMMAND_QUIT "/quit"

void cmd_help(server_t *server, instance_t *current_instance, char **args);
void cmd_login(server_t *server, instance_t *current_instance, char **args);
void cmd_logout(server_t *server, instance_t *current_instance, char **args);
void cmd_user(server_t *server, instance_t *current_instance, char **args);
void cmd_users(server_t *server, instance_t *current_instance, char **args);
void cmd_send(server_t *server, instance_t *current_instance, char **args);
void cmd_messages(server_t *server, instance_t *current_instance, char **args);
void cmd_subscribe(server_t *server, instance_t *current_instance, char **args);
void cmd_subscribed(server_t *server, instance_t *instance, char **args);
void cmd_unsubscribe(server_t *server, instance_t *instance, char **args);
void cmd_use(server_t *server, instance_t *current_instance, char **args);
void cmd_create(server_t *server, instance_t *current_instance, char **args);
void cmd_list(server_t *server, instance_t *current_instance, char **args);
void cmd_info(server_t *server, instance_t *current_instance, char **args);
void cmd_quit(server_t *server, instance_t *current_instance, char **args);
void create_team(server_t *server, instance_t *instance, char **args);
void create_channel(server_t *server, instance_t *instance,
    char **args, team_t *team);
void check_before_create_thread(server_t *server, instance_t *instance,
    char **args, team_t *team);
void check_before_reply(server_t *server, instance_t *instance,
    char **args, team_t *team);

typedef struct command {
    const char *name;
    void (*func)(server_t *server, instance_t *current_instance, char **args);
} command_t;

extern const command_t COMMANDS_LIST[];
