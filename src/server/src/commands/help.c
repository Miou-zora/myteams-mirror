/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** help
*/

#include "commands.h"
#include "lib.h"

const char *help = "Help commands\n/help : show help\n/login [“user_name”] : \
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
current resource";
add_last_valueadd_last_value
void cmd_help(server_t *server, instance_t *current_instance, char **args)
{
    (void)server;
    char **list_of_line_of_help = NULL;

    if (args[0] != NULL) {
        add_output(&current_instance->output, "EC02",
        "Invalid number of arguments");
        return;
    }
    list_of_line_of_help = data_to_array_str(strdup(help), "\n");
    for (size_t i = 0; list_of_line_of_help[i]; i++) {
        add_output(&current_instance->output, "SU01", list_of_line_of_help[i]);
    }
}
