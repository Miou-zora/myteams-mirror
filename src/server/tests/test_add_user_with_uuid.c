/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_user_with_uuid
*/

#include <criterion/criterion.h>

#include "data_core.h"

Test(add_user_with_uuid, casual) {
    struct user_head head = init_list_of_users();
    int ret = add_user_with_uuid(&head, "test",
    "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, 0);
    int len = 0;
    user_t *user;
    char uuid[100];
    LIST_FOREACH(user, &head, next_user) {
        len++;
        cr_assert_str_eq(user->username, "test");
        uuid_unparse(user->uuid, uuid);
        cr_assert_str_eq(uuid, "00000000-0000-0000-0000-000000000000");
    }
    cr_assert_eq(len, 1);
}
