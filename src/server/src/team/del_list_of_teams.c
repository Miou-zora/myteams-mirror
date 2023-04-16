/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_list_of_teams
*/

#include "data_core.h"

#include <stdlib.h>

void del_list_of_teams(struct team_head *head)
{
    team_t *team;

    if (!head)
        return;
    while (!LIST_EMPTY(head)) {
        team = LIST_FIRST(head);
        del_team(head, team->name);
    }
}
