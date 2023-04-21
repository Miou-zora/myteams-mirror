/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load_channels
*/

#include "load.h"
#include "lib.h"

static int check_args(server_t *server, char **args)
{
    team_t *team = NULL;

    if (args == NULL) {
        printf("Error while loading channels\n");
        return (84);
    }
    team = get_team_by_uuid(&server->teams, args[0]);
    if (team == NULL) {
        printf("Error while loading channels, team not found\n");
        return (84);
    }
    if (add_channel_with_uuid(&team->channels_head, args[2],
    args[3], args[1]) == 84) {
        return (84);
    }
    return (0);
}

int load_channels(server_t *server)
{
    FILE *file = fopen("channels", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args = NULL;

    if (file == NULL) {
        printf("No channels found, creating new file\n");
        file = fopen("channels", "w");
        fclose(file);
        return (0);
    }
    while ((read = getline(&line, &len, file)) != -1) {
        args = split_line(line);
        if (check_args(server, args) == 84)
            return (84);
    }
    fclose(file);
    return (0);
}
