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

void response_default(char **args);
void response_login(char **args);
void response_initialisation(char **args);
void response_users(char **args);
void response_user_exist(char **args);
void response_user_dont_exist(char **args);

typedef struct response_s {
    const char *code;
    void (*func)(char **args);
} response_t;

extern const response_t RESPONSE_LIST[];
