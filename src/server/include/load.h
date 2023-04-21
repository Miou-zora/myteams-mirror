/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load
*/

#pragma once

#define _GNU_SOURCE

#include "server.h"
#include <time.h>

int load_users(server_t *server);
int load_teams(server_t *server);
int load_channels(server_t *server);
int load_threads(server_t *server);
int load_comments(server_t *server);
