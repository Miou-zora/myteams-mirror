/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_user
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

Test(del_user, casual) {
    struct user_head head = init_list_of_users();
    int ret = add_user(&head, "test");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 1);
    ret = del_user(&head, "test");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 0);
}

Test(del_user, multiple) {
    struct user_head head = init_list_of_users();
    int ret = add_user(&head, "test");
    cr_assert_eq(ret, 0);
    ret = add_user(&head, "test2");
    cr_assert_eq(ret, 0);
    ret = add_user(&head, "test3");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 3);
    ret = del_user(&head, "test2");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 2);
    ret = del_user(&head, "test3");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 1);
    ret = del_user(&head, "test");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 0);
}

Test(del_user, null_head) {
    int ret = del_user(NULL, "test");
    cr_assert_eq(ret, -1);
}

Test(del_user, null_username) {
    struct user_head head = init_list_of_users();
    int ret = del_user(&head, NULL);
    cr_assert_eq(ret, -1);
}

Test(del_user, empty_username) {
    struct user_head head = init_list_of_users();
    int ret = del_user(&head, "");
    cr_assert_eq(ret, -1);
}

Test(del_user, too_long_username) {
    struct user_head head = init_list_of_users();
    char *str = malloc(sizeof(char) * (MAX_NAME_LENGTH + 2));
    memset(str, 'a', MAX_NAME_LENGTH + 1);
    str[MAX_NAME_LENGTH + 1] = '\0';
    int ret = del_user(&head, str);
    cr_assert_eq(ret, -1);
}

Test(del_user, not_exist) {
    struct user_head head = init_list_of_users();
    int ret = del_user(&head, "test");
    cr_assert_eq(ret, 1);
}
