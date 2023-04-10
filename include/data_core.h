/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** data_core
*/

#pragma once

#include <sys/queue.h>
#include <uuid/uuid.h>

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

typedef struct team_entry_s {
    char *name[MAX_NAME_LENGTH];
    char *description[MAX_DESCRIPTION_LENGTH];

    LIST_ENTRY(team_entry_s) next_team;
} team_entry_t;

LIST_HEAD(team_list, team_entry_s);
