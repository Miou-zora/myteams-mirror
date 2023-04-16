/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_team_by_name
*/

#include "data_core.h"

#include <string.h>

team_t *get_team_by_name(struct team_head *teams_head, const char *team_name)
{
    team_t *team;

    LIST_FOREACH(team, teams_head, next_team) {
        if (strcmp(team->name, team_name) == 0)
            return team;
    }
    return NULL;
}
