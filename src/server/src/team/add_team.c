/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_team
*/

#include "data_core.h"

#include <string.h>
#include <stdlib.h>

static team_t *new_team(const char *name, const char *description)
{
    team_t *team = malloc(sizeof(*team));

    if (!team)
        return NULL;
    uuid_generate(team->uuid);
    strcpy(team->name, name);
    strcpy(team->description, description);
    LIST_INIT(&team->users_uuid_registered_head);
    LIST_INIT(&team->channels_head);
    return team;
}

int add_team(struct team_head *head, const char *name, const char *description)
{
    team_t *team;

    if (!head || !name || !description ||
        strlen(name) > MAX_NAME_LENGTH || strlen(name) == 0 ||
        strlen(description) > MAX_DESCRIPTION_LENGTH ||
        strlen(description) == 0)
        return (-1);
    LIST_FOREACH(team, head, next_team) {
        if (strcmp(team->name, name) == 0)
            return (1);
    }
    team = new_team(name, description);
    if (!team)
        return (-1);
    LIST_INSERT_HEAD(head, team, next_team);
    return (0);
}
