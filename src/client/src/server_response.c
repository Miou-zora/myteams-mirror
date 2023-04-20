/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** server_response
*/

#include "response_server.h"
#include "lib.h"

const response_t RESPONSE_LIST[] = {
    {"EC01", response_not_connected},
    {"EC02", response_default},
    {"EC03", response_default/*response_team_dont_exist*/},
    {"EC04", response_default/*response_channel_dont_exist*/},
    {"EC05", response_default/*response_thread_dont_exist*/},
    {"EC06", response_default/*response_already_exist*/},
    {"EC30", response_user_dont_exist},
    {"ES04", response_default},
    {"SU01", response_default},
    {"SU02", response_login},
    {"SU03", response_login},
    {"SU04", response_users},
    {"SU05", response_user_exist},
    {"SU06", response_logout},
    {"SU07", response_default/*resonse_team_created*/},
    {"SU08", response_default/*resonse_channel_created*/},
    {"SU09", response_default/*resonse_thread_created*/},
    {"SU10", response_default/*resonse_comment_created*/},
    {"SU20", response_initialisation},
    {NULL, NULL}
};

static void print_response(char **tab)
{
    for (int i = 0; RESPONSE_LIST[i].code != NULL; i++) {
        if (strcmp(RESPONSE_LIST[i].code, tab[0]) == 0) {
            RESPONSE_LIST[i].func(tab);
            return;
        }
    }
}

void analyse_response(char *response)
{
    char **tmp = parse_string(response);
    char **tab = NULL;

    for (int i = 0; tmp[i] != NULL; i++) {
        tab = split_line(tmp[i]);
        print_response(tab);
    }
}
