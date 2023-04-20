/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_team_by_uuid
*/

#include "data_core.h"

team_t *get_user_by_uuid(struct team_head *teams, const char *user_uuid)
{
    team_t *team;
    uuid_t uuid;

    if (!team || !user_uuid)
        return (NULL);
    uuid_parse(user_uuid, uuid);
    LIST_FOREACH(team, teams, next_teams) {
        if (uuid_compare(uuid, user->uuid) == 0)
            return user;
    }
    return NULL;
}
