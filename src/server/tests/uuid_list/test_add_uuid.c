/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_uuid
*/

#include <criterion/criterion.h>

#include "data_core.h"

#include <stdlib.h>

Test(add_uuid, casual) {
    struct uuid_list_head head = init_list_of_uuids();
    uuid_t uuid;
    uuid_generate(uuid);
    add_uuid(&head, uuid);
    uuid_list_t *uuid_list = LIST_FIRST(&head);
    cr_assert_not_null(uuid_list);
    cr_assert_eq(uuid_compare(uuid_list->uuid, uuid), 0);
}
