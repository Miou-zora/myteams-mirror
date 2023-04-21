/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load_teams
*/

#include "load.h"
#include "lib.h"

static int check_args(server_t *server, char **args)
{
    if (args == NULL) {
        printf("Error while loading teams\n");
        return (84);
    }
    if (add_team_with_uuid(&server->teams, args[1], args[2], args[0]) == 84) {
        return (84);
    }
    return (0);
}

int load_teams(server_t *server)
{
    FILE *file = fopen("teams", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args = NULL;

    if (file == NULL) {
        printf("No teams found, creating new file\n");
        file = fopen("teams", "w");
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
