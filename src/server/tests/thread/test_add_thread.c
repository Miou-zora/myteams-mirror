/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_thread
*/

#include <criterion/criterion.h>

#include "data_core.h"

static int get_len_of_list(struct thread_head *head)
{
    int len = 0;
    thread_t *thread;

    LIST_FOREACH(thread, head, next_thread) {
        len++;
    }
    return len;
}

Test(add_thread, casual) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len_of_list(&head), 1);
}

Test(add_thread, already_exist) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    ret = add_thread(&head, "testname", "testdescription");
    cr_assert_eq(ret, 1);
    cr_assert_eq(get_len_of_list(&head), 1);
}

Test(add_thread, multiple) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    ret = add_thread(&head, "testname2", "testdescription2");
    cr_assert_eq(ret, 0);
    ret = add_thread(&head, "testname3", "testdescription3");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len_of_list(&head), 3);
}

Test(add_thread, null_head) {
    int ret = add_thread(NULL, "testname", "testdescription");
    cr_assert_eq(ret, -1);
}

Test(add_thread, null_name) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, NULL, "testdescription");
    cr_assert_eq(ret, -1);
}

Test(add_thread, null_description) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "testname", NULL);
    cr_assert_eq(ret, -1);
}

Test(add_thread, null_name_and_description) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, NULL, NULL);
    cr_assert_eq(ret, -1);
}

Test(add_thread, empty_name) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "", "testdescription");
    cr_assert_eq(ret, -1);
}

Test(add_thread, empty_description) {
    struct thread_head head = init_list_of_threads();
    int ret = add_thread(&head, "testname", "");
    cr_assert_eq(ret, -1);
}
