/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_user_with_uuid
*/

#include "data_core.h"

#include <string.h>
#include <stdlib.h>

static user_t *new_user_with_uuid(const char *username, const char *uuid)
{
    user_t *user = malloc(sizeof(user_t));

    if (!user)
        return NULL;
    uuid_parse(uuid, user->uuid);
    strcpy(user->username, username);
    LIST_INIT(&user->teams_registered_head);
    return user;
}

int add_user_with_uuid(struct user_head *head, const char *username,
    const char *uuid)
{
    user_t *user;

    if (!head || !username ||
        strlen(username) > MAX_NAME_LENGTH || strlen(username) == 0)
        return (-1);
    LIST_FOREACH(user, head, next_user) {
        if (strcmp(user->username, username) == 0)
            return (1);
    }
    user = new_user_with_uuid(username, uuid);
    if (!user)
        return (-1);
    LIST_INSERT_HEAD(head, user, next_user);
    return (0);
}
