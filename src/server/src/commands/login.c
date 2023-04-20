/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** login
*/

#include "commands.h"
#include "response.h"
#include "lib.h"
#include "save.h"

char *get_login_infos(char *uuid, char *username)
{
    char *save = calloc(strlen(uuid) + strlen((username)) + 4, sizeof(char));

    save = strcpy(save, uuid);
    save = strcat(save, " \"");
    save = strcat(save, username);
    save = strcat(save, "\"");
    return (save);
}

bool already_logged(server_t *serv, instance_t *current_instance, char **args)
{
    user_t *user = find_user(&serv->users, args[0]);
    char tmp[37];

    if (user != NULL) {
        uuid_unparse(user->uuid, tmp);
        server_event_user_logged_in(tmp);
        uuid_copy(current_instance->user_uuid, user->uuid);
        send_message_every_users(serv, "SU03",
        get_login_infos(tmp, user->username));
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
        uuid_copy(current_instance->user_uuid, user->uuid);
        server_event_user_logged_in(tmp);
        send_message_every_users(server, "SU02",
        get_login_infos(tmp, user->username));
        save_users(server);
        return;
    }
}

void cmd_login(server_t *server, instance_t *current_instance, char **args)
{

    if (get_array_size(args) != 1) {
        add_output(&current_instance->output, "EC02",
        "Invalid number of arguments");
        return;
    }
    args[0] = delete_quotes(args[0]);
    if (already_logged(server, current_instance, args) == true)
        return;
    user_login(server, current_instance, args[0]);
}
