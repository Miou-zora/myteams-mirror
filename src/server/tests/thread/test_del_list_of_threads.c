/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_list_of_threads
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

Test(del_list_of_threads, casual) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "test", "test");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_list_size(&head), 1);
    del_list_of_threads(&head);
    cr_assert_eq(get_list_size(&head), 0);
}

Test(del_list_of_threads, multiple) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "test", "test");
    cr_assert_eq(ret, 0);
    ret = add_thread(&head, "test2", "test2");
    cr_assert_eq(ret, 0);
    ret = add_thread(&head, "test3", "test3");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_list_size(&head), 3);
    del_list_of_threads(&head);
    cr_assert_eq(get_list_size(&head), 0);
}

Test(del_list_of_threads, null_head) {
    del_list_of_threads(NULL);
}

Test(del_list_of_threads, null_uuid) {
    struct thread_head head = init_list_of_threads();
    del_list_of_threads(&head);
}
