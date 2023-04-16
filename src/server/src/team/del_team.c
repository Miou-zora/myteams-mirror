/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_team
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

int del_team(struct team_head *head, const char *name)
{
    team_t *team;

    if (!head || !name ||
        strlen(name) > MAX_NAME_LENGTH || strlen(name) == 0)
        return (-1);
    LIST_FOREACH(team, head, next_team) {
        if (strcmp(team->name, name) == 0) {
            LIST_REMOVE(team, next_team);
            free(team);
            return (0);
        }
    }
    return (1);
}
