/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_channel_to_team
*/

#include "data_core.h"

int add_channel_to_team(struct team_head *teams_head,
    const char *team_name, const char *channel_name,
    const char *channel_description)
{
    team_t *team = get_team_by_name(teams_head, team_name);

    if (team == NULL)
        return -1;
    return add_channel(&team->channels_head, channel_name,
        channel_description);
}
