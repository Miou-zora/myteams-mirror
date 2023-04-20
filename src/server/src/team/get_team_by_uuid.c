/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_team_by_uuid
*/

#include "data_core.h"

team_t *get_team_by_uuid(struct team_head *teams, const char *team_uuid)
{
    team_t *team;
    uuid_t uuid;

    if (!teams || !team_uuid)
        return (NULL);
    uuid_parse(team_uuid, uuid);
    LIST_FOREACH(team, teams, next_team) {
        if (uuid_compare(uuid, team->uuid) == 0)
            return team;
    }
    return NULL;
}
