/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load_users
*/

#include "load.h"
#include "lib.h"

static int check_args(server_t *server, char **args)
{
    if (args == NULL) {
        printf("Error while loading user\n");
        return (84);
    }
    if (add_user_with_uuid(&server->users, args[1], args[0]) == 84) {
        printf("Error while loading user %s %s\n", args[1], args[0]);
        return (84);
    }
    for (int i = 2; args[i] != NULL; i++)
        add_user_to_team(&server->teams, &server->users, args[i], args[0]);
    return (0);
}

int load_users(server_t *server)
{
    FILE *file = fopen("users", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args = NULL;

    if (file == NULL) {
        printf("No users found, creating new file\n");
        file = fopen("users", "w");
        fclose(file);
        return (0);
    }
    while ((read = getline(&line, &len, file)) != -1) {
        args = split_line(line);
        if (check_args(server, args) == 84)
            return (84);
        server_event_user_loaded(args[0], args[1]);
    }
    fclose(file);
    return (0);
}
