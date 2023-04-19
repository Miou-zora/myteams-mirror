/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** save_users
*/

#include "server.h"
#include "data_core.h"

void save_users(server_t *server)
{
    FILE *file = fopen("data/users", "w+");
    user_t *user;
    uuid_list_t *team;
    char tmp[37];

    if (file == NULL)
        return;
    printf("Saving users...\n");
    LIST_FOREACH(user, &server->users, next_user) {
        printf("Saving user %s\n", user->username);
        uuid_unparse(user->uuid, tmp);
        fprintf(file, "%s ", tmp);
        fprintf(file, "\"%s\" ", user->username);
        LIST_FOREACH(team, &user->teams_registered_head, next_uuid) {
            uuid_unparse(team->uuid, tmp);
            fprintf(file, "%s ", tmp);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}
