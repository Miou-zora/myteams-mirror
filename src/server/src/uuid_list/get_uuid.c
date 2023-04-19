/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_uuid
*/

#include "data_core.h"

uuid_t *get_uuid(struct uuid_list_head *head, uuid_t uuid)
{
    uuid_list_t *current_uuid;

    LIST_FOREACH(current_uuid, head, next_uuid) {
        if (uuid_compare(current_uuid->uuid, uuid) == 0)
            return (&current_uuid->uuid);
    }
    return (NULL);
}
