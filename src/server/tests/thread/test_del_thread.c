/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_thread
*/

#include <criterion/criterion.h>

#include "data_core.h"

static int get_list_size(struct thread_head *head)
{
    thread_t *thread;
    int size = 0;

    LIST_FOREACH(thread, head, next_thread) {
        size++;
    }
    return size;
}

Test(del_thread, casual) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "test", "test");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_list_size(&head), 1);
    ret = del_thread(&head, "test");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_list_size(&head), 0);
}

Test(del_thread, multiple) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "test", "test");
    cr_assert_eq(ret, 0);
    ret = add_thread(&head, "test2", "test2");
    cr_assert_eq(ret, 0);
    ret = add_thread(&head, "test3", "test3");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_list_size(&head), 3);
    ret = del_thread(&head, "test2");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_list_size(&head), 2);
    ret = del_thread(&head, "test3");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_list_size(&head), 1);
    ret = del_thread(&head, "test");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_list_size(&head), 0);
}

Test(del_thread, null_head) {
    int ret = del_thread(NULL, "test");
    cr_assert_eq(ret, -1);
}

Test(del_thread, null_uuid) {
    struct thread_head head = init_list_of_threads();
    int ret = del_thread(&head, NULL);
    cr_assert_eq(ret, -1);
}

Test(del_thread, not_found) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "test", "test");
    cr_assert_eq(ret, 0);
    ret = del_thread(&head, "test2");
    cr_assert_eq(ret, 1);
}

Test(del_thread, empty_head) {
    struct thread_head head = init_list_of_threads();
    int ret = del_thread(&head, "test");
    cr_assert_eq(ret, 1);
}

Test(del_thread, empty_uuid) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "test", "test");
    cr_assert_eq(ret, 0);
    ret = del_thread(&head, "");
    cr_assert_eq(ret, -1);
}
