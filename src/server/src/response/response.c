/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response
*/

#include "response.h"

const response_t RESPONSE_LIST[] = {
    {"SU00", "OK"},
    {"SU01", "help message"},
    {"SU02", "new logging success"},
    {"SU03", "login success"},
    {"SU20", "Service ready for new user"},
    {"EC00", "Bad Request"},
    {"EC01", "Unauthorized"},
    {"EC02", "Invalid number of arguments"},
    {"EC03", "Forbidden"},
    {"EC04", "Not Found"},
    {"EC05", "Method Not Allowed"},
    {"EC08", "Request Timeout"},
    {"EC19", "Page expired"},
    {"EC21", "Misdirected Request"},
    {"EC29", "Too Many Requests"},
    {"ES00", "Internal Server Error"},
    {"ES01", "Not Implemented"},
    {"ES03", "Service Unavailable"},
    {"ES04", "Unknown command"},
    {"ES20", "Unknown Error"},
    {NULL, NULL}
};

char *reply(char *str, const char *code)
{
    for (int i = 0; RESPONSE_LIST[i].code; i++) {
        if (strcmp(code, RESPONSE_LIST[i].code) == 0) {
            sprintf(str, "%s %s\n", code, RESPONSE_LIST[i].message);
            return (str);
        }
    }
    return (NULL);
}
