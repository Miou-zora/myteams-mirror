/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_uuid
*/

#include "data_core.h"

#include <stdlib.h>

int add_uuid(struct uuid_list_head *head, uuid_t uuid)
{
    uuid_list_t *new_uuid = malloc(sizeof(uuid_list_t));

    if (!head || !new_uuid)
        return (-1);
    uuid_copy(new_uuid->uuid, uuid);
    LIST_INSERT_HEAD(head, new_uuid, next_uuid);
    return (0);
}
