/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_thead_with_uuid
*/

#include <criterion/criterion.h>

#include "data_core.h"

Test(add_thread_with_uuid, casual) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread_with_uuid(&head, "testname", "testdescription",
        "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, 0);
    int len = 0;
    thread_t *thread;
    char uuid[100];
    LIST_FOREACH(thread, &head, next_thread) {
        len++;
        cr_assert_str_eq(thread->title, "testname");
        cr_assert_str_eq(thread->message, "testdescription");
        uuid_unparse(thread->uuid, uuid);
        cr_assert_str_eq(uuid, "00000000-0000-0000-0000-000000000000");
    }
    cr_assert_eq(len, 1);
}
