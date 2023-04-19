/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_user_by_uuid
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

user_t *get_user_by_uuid(struct user_head *users, const char *user_uuid)
{
    user_t *user;
    uuid_t uuid;

    if (!users || !user_uuid)
        return (NULL);
    uuid_parse(user_uuid, uuid);
    LIST_FOREACH(user, users, next_user) {
        if (uuid_compare(uuid, user->uuid) == 0)
            return user;
    }
    return NULL;
}
