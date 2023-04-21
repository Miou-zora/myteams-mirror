/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response
*/

#pragma once

#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "logging_client.h"

void response_default(char **args);
void response_login(char **args);
void response_initialisation(char **args);
void response_users(char **args);
void response_user_exist(char **args);
void response_user_dont_exist(char **args);
void response_not_connected(char **args);
void response_logout(char **tab);
void response_create_already_exist(char **args);
void response_thread_not_exist(char **args);
void response_channel_not_exist(char **args);
void response_team_not_exist(char **args);
void success_create_reply(char **args);
void success_create_thread(char **args);
void success_create_channel(char **args);
void success_create_team(char **args);
void success_subscribe(char **args);

typedef struct response_s {
    const char *code;
    void (*func)(char **args);
} response_t;

extern const response_t RESPONSE_LIST[];
