/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** send
*/

#include "commands.h"
#include "response.h"
#include "lib.h"
#include "save.h"

static void find_instance(instance_t *instances[100], uuid_t *uuid_to_find,
    char *buffer)
{
    for (int i = 0; i < 100; i++) {
        if (uuid_compare(instances[i]->user_uuid, *uuid_to_find) == 0)
            add_output(&instances[i]->output, "SU14", buffer);
    }
}

void send_mess(server_t *server, instance_t *current_instance, char **args)
{
    char buffer[1019];
    user_t *user = NULL;
    char uuid[37];
    uuid_t tmp;
    user_t *userto;

    uuid_unparse(current_instance->user_uuid, uuid);
    uuid_parse(args[0], tmp);
    user = get_user_by_uuid(&server->users, uuid);
    userto = get_user_by_uuid(&server->users, args[0]);
    sprintf(buffer, "%s \"%s\" \"%s\"", uuid, user->username, args[1]);
    send_message_into_conv(user, userto, args[1]);
    find_instance(server->instance, &userto->uuid, buffer);
    server_event_private_message_sended(args[0],
        uuid, args[1]);
}

void cmd_send(server_t *server, instance_t *current_instance, char **args)
{

    if (uuid_is_null(current_instance->user_uuid)) {
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
            return;
    }
    if (get_array_size(args) != 2) {
        add_output(&current_instance->output, "EC02",
            "Invalid number of arguments");
            return;
    }
    if (get_user_by_uuid(&server->users, args[0]) == NULL) {
        add_output(&current_instance->output, "EC30",
            "User doesn't exist");
    } else {
        send_mess(server, current_instance, args);
    }
}
