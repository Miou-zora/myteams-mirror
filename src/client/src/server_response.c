/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** server_response
*/

#include "response_server.h"
#include "lib.h"

const response_t RESPONSE_LIST[] = {
    {"EC02", response_default},
    {"ES04", response_default},
    {"SU01", response_default},
    {"SU02", response_login},
    {"SU03", response_login},
    {"SU20", response_initialisation},
    {NULL, NULL}
};

void analyse_response(char *response)
{
    char **tab = data_to_array_str(response, " ");

    for (int i = 0; RESPONSE_LIST[i].code != NULL; i++) {
        if (strcmp(RESPONSE_LIST[i].code, tab[0]) == 0) {
            RESPONSE_LIST[i].func(tab);
            return;
        }
    }
}
