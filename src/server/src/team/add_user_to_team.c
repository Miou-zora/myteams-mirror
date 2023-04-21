/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_user_to_team
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

static bool is_already_in_team(team_t *team, user_t *user)
{
    uuid_list_t *tmp;

    if (!team || !user)
        return false;
    LIST_FOREACH(tmp, &team->users_uuid_registered_head, next_uuid) {
        if (uuid_compare(tmp->uuid, user->uuid) == 0)
            return true;
    }
    return false;
}

static int is_error(team_t *team, user_t *user)
{
    if (!team)
        return (1);
    if (!user)
        return (2);
    if (is_already_in_team(team, user))
        return (3);
    return (0);
}

int add_user_to_team(struct team_head *teams_head,
    struct user_head *users_head, char *team_uuid,
    char *user_uuid)
{
    team_t *team = NULL;
    user_t *user = NULL;
    uuid_t user_uuid_tmp;
    uuid_t team_uuid_tmp;

    if (!teams_head || !users_head || !team_uuid || !user_uuid)
        return (-1);
    uuid_parse(team_uuid, team_uuid_tmp);
    uuid_parse(user_uuid, user_uuid_tmp);
    LIST_FOREACH(team, teams_head, next_team)
        if (uuid_compare(team->uuid, team_uuid_tmp) == 0)
            break;
    LIST_FOREACH(user, users_head, next_user)
        if (uuid_compare(user->uuid, user_uuid_tmp) == 0)
            break;
    if (is_error(team, user))
        return (is_error(team, user));
    add_uuid(&team->users_uuid_registered_head, user->uuid);
    add_uuid(&user->teams_registered_head, team->uuid);
    return (0);
}
