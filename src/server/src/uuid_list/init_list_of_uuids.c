/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** init_list_of_uuid
*/

#include "data_core.h"

#include <stdlib.h>

struct uuid_list_head init_list_of_uuids(void)
{
    struct uuid_list_head head;

    LIST_INIT(&head);
    return (head);
}
