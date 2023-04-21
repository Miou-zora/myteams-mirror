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
    {"EC03", response_team_not_exist},
    {"EC04", response_channel_not_exist},
    {"EC05", response_thread_not_exist},
    {"EC06", response_create_already_exist},
    {"EC07", response_default},
    {"EC30", response_user_dont_exist},
    {"ES04", response_default},
    {"SU01", response_default},
    {"SU02", response_login},
    {"SU03", response_login},
    {"SU04", response_users},
    {"SU05", response_user_exist},
    {"SU06", response_logout},
    {"SU07", success_create_team},
    {"SU08", success_create_channel},
    {"SU09", success_create_thread},
    {"SU10", success_create_reply},
    {"SU11", success_subscribe},
    {"SU12", success_subscribed},
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
