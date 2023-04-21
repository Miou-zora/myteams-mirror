/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** save_team
*/

#include "server.h"
#include "data_core.h"

void save_team(server_t *server)
{
    FILE *file = fopen("teams", "w+");
    team_t *team;
    uuid_list_t *user;
    char tmp[37];

    if (file == NULL)
        file = fopen("teams", "w");
    printf("Saving teams...\n");
    LIST_FOREACH(team, &server->teams, next_team) {
        uuid_unparse(team->uuid, tmp);
        fprintf(file, "%s ", tmp);
        fprintf(file, "\"%s\" ", team->name);
        fprintf(file, "\"%s\" ", team->description);
        LIST_FOREACH(user, &team->users_uuid_registered_head, next_uuid) {
            uuid_unparse(user->uuid, tmp);
            fprintf(file, "%s ", tmp);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}
