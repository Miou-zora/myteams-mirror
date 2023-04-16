/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_uuid
*/

#include "data_core.h"

#include <stdlib.h>

int del_uuid(struct uuid_list_head *head, uuid_t uuid)
{
    uuid_list_t *uuid_list;

    if (!head)
        return (-1);
    LIST_FOREACH(uuid_list, head, next_uuid) {
        if (uuid_compare(uuid_list->uuid, uuid) == 0) {
            LIST_REMOVE(uuid_list, next_uuid);
            free(uuid_list);
            return (0);
        }
    }
    return (1);
}
