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

void find_instance(instance_t *instances[100], uuid_t *uuid_to_find,
    char *buffer)
{
    for (int i = 0; i < 100; i++) {
        if (uuid_compare(instances[i]->uuid, *uuid_to_find) == 0)
            add_output(&instances[i]->output, "SU07", buffer);
    }
}

void cmd_send(server_t *server, instance_t *current_instance, char **args)
{
    char buffer[1019];
    user_t *user = NULL;
    char uuid[37];
    message_t *message;
    uuid_t tmp;
    user_t *userto;

    if (uuid_is_null(current_instance->uuid))
        add_output(&current_instance->output, "EC01",
            "You must be logged in to use this command");
    else if (get_array_size(args) != 2) {
        add_output(&current_instance->output, "EC02",
            "Invalid number of arguments");
    } else if (get_user_by_uuid(&server->users, args[0]) == NULL) {
        add_output(&current_instance->output, "EC30",
            "User doesn't exist");
    }
    else {
        memset(buffer, 0, 1019);
        uuid_unparse(current_instance->uuid, uuid);
        uuid_parse(args[0], tmp);
        user = get_user_by_uuid(&server->users, uuid);
        userto = get_user_by_uuid(&server->users, uuid);
        sprintf(buffer, "%s \"%s\" \"%s\"", uuid, userto->username, args[1]);
        message = send_message_into_conv(user, userto, args[2]);
        find_instance(server->instance, &userto->uuid, buffer);
        //add_output(&instance_userto->output, "SU07", buffer);
        (void) message;
    }
}
