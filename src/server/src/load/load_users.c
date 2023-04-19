/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load_users
*/

#include "load.h"
#include "lib.h"

int load_users(server_t *server)
{
    FILE *file = fopen("data/users", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args = NULL;

    if (file == NULL) {
        printf("No users found, creating new file\n");
        file = fopen("data/users", "w");
    }
    while ((read = getline(&line, &len, file)) != -1) {
        args = data_to_array_str(line, " ");
        if (args == NULL) {
            printf("Error while loading user\n");
            return (84);
        }
        if (add_user_with_uuid(&server->users, args[0], args[1]) == 84) {
            printf("Error while loading user %s %s\n", args[0], args[1]);
            return (84);
        }
        server_event_user_loaded(args[1], args[0]);
    }
    fclose(file);
    return (0);
}