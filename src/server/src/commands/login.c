/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** login
*/

#include "commands.h"
#include "response.h"
#include "lib.h"

bool already_logged(server_t *serv, instance_t *current_instance, char **args)
{
    user_t *user = find_user(&serv->users, args[0]);

    if (user != NULL) {
        server_event_user_logged_in(args[0]);
        reply(current_instance->buff_out, "SU03");
        uuid_copy(current_instance->uuid, user->uuid);
        return (true);
    }
    return (false);
}

void user_login(server_t *server, instance_t *current_instance, char *username)
{
    char tmp[37];
    user_t *user;

    add_user(&server->users, username);
    user = find_user(&server->users, username);
    if (user != NULL) {
        uuid_unparse(user->uuid, tmp);
        server_event_user_created(tmp, user->username);
        reply(current_instance->buff_out, "SU02");
        uuid_copy(current_instance->uuid, user->uuid);
        return;
    }
}

void cmd_login(server_t *server, instance_t *current_instance, char **args)
{

    if (get_array_size(args) != 1) {
        reply(current_instance->buff_out, "EC02");
        return;
    }
    args[0] = delete_quotes(args[0]);
    if (already_logged(server, current_instance, args) == true)
        return;
    user_login(server, current_instance, args[0]);
}
