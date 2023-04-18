/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response
*/

#include "response.h"

const response_t RESPONSE_LIST[] = {
    {"SU00", "OK"},
    {"SU01", "Help commands\n/help : show help\n/login [“user_name”] : \
set the user_name used by client\n/logout : disconnect the client from \
the server\n/users : get the list of all users that exist on the domain\n\
/user [“user_uuid”] : get details about the requested user\n\
/send [“user_uuid”] [“message_body”] : send a message to user\n\
/messages [“user_uuid”] : list messages exchanged with the specified user\n\
/subscribe [“team_uuid”] : subscribe to a team and its sub directories\n\
/subscribed ?[“team_uuid”] : list all subscribed teams or list all users \
subscribed to a team\n/unsubscribe [“team_uuid”] : unsubscribe from a team\n\
/use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : Sets the command \
context to a team/channel/thread\n/create : create the sub resource\n\
/list : list all the sub resources \n/info : display details of the \
current resource"},
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
