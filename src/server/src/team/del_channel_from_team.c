/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_channel_from_team
*/

#include "data_core.h"

void del_channel_from_team(struct team_head *teams_head,
    const char *team_name, const char *channel_name)
{
    team_t *team = get_team_by_name(teams_head, team_name);
    channel_t *channel = get_channel_by_name(&team->channels_head,
        channel_name);

    if (team == NULL || channel == NULL)
        return;
    LIST_REMOVE(channel, next_channel);
    free(channel);
}
