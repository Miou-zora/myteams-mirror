/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** save_channels
*/

#include "server.h"
#include "data_core.h"

void save_channels(server_t *server)
{
    FILE *file = fopen("channels", "w+");
    channel_t *channel;
    team_t *team;
    char tmp[37];

    if (file == NULL)
        file = fopen("channels", "w");
    printf("Saving channels...\n");
    LIST_FOREACH(team, &server->teams, next_team) {
        LIST_FOREACH(channel, &team->channels_head, next_channel) {
            uuid_unparse(team->uuid, tmp);
            fprintf(file, "%s ", tmp);
            uuid_unparse(channel->uuid, tmp);
            fprintf(file, "%s ", tmp);
            fprintf(file, "\"%s\" ", channel->name);
            fprintf(file, "\"%s\"\n", channel->description);
        }
    }
    fclose(file);
}