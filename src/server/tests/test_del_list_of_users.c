/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_list_of_users
*/

#include <criterion/criterion.h>

#include "data_core.h"

static int get_len(struct user_head *head)
{
    int len = 0;
    user_t *user;
    LIST_FOREACH(user, head, next_user) {
        len++;
    }
    return len;
}

Test(del_list_of_users, casual)
{
    struct user_head head = init_list_of_users();
    add_user(&head, "test");
    add_user(&head, "test2");
    add_user(&head, "test3");
    cr_assert_eq(get_len(&head), 3);
    del_list_of_users(&head);
    cr_assert_eq(get_len(&head), 0);
}

Test(del_list_of_users, null_head)
{
    del_list_of_users(NULL);
}

Test(del_list_of_users, empty)
{
    struct user_head head = init_list_of_users();
    cr_assert_eq(get_len(&head), 0);
    del_list_of_users(&head);
    cr_assert_eq(get_len(&head), 0);
}

Test(del_list_of_users, one)
{
    struct user_head head = init_list_of_users();
    add_user(&head, "test");
    cr_assert_eq(get_len(&head), 1);
    del_list_of_users(&head);
    cr_assert_eq(get_len(&head), 0);
}
