/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_user
*/

#include <criterion/criterion.h>

#include "data_core.h"

Test(add_user, add_user) {
    struct user_head head = init_list_of_users();
    int ret = add_user(&head, "test");
    cr_assert_eq(ret, 0);
    int len = 0;
    user_t *user;
    LIST_FOREACH(user, &head, next_user) {
        len++;
    }
    cr_assert_eq(len, 1);
}

Test(add_user, already_exist) {
    struct user_head head = init_list_of_users();
    int ret = add_user(&head, "test");
    cr_assert_eq(ret, 0);
    ret = add_user(&head, "test");
    cr_assert_eq(ret, 1);
    int len = 0;
    user_t *user;
    LIST_FOREACH(user, &head, next_user) {
        len++;
    }
    cr_assert_eq(len, 1);
}

Test(add_user, multiple) {
    struct user_head head = init_list_of_users();
    int ret = add_user(&head, "test");
    cr_assert_eq(ret, 0);
    ret = add_user(&head, "test2");
    cr_assert_eq(ret, 0);
    ret = add_user(&head, "test3");
    cr_assert_eq(ret, 0);
    int len = 0;
    user_t *user;
    LIST_FOREACH(user, &head, next_user) {
        len++;
    }
    cr_assert_eq(len, 3);
}

Test(add_user, null_head) {
    int ret = add_user(NULL, "test");
    cr_assert_eq(ret, -1);
}

Test(add_user, null_username) {
    struct user_head head = init_list_of_users();
    int ret = add_user(&head, NULL);
    cr_assert_eq(ret, -1);
    int len = 0;
    user_t *user;
    LIST_FOREACH(user, &head, next_user) {
        len++;
    }
    cr_assert_eq(len, 0);
}

Test(add_user, no_character_name) {
    struct user_head head = init_list_of_users();
    int ret = add_user(&head, "");
    cr_assert_eq(ret, -1);
    int len = 0;
    user_t *user;
    LIST_FOREACH(user, &head, next_user) {
        len++;
    }
    cr_assert_eq(len, 0);
}

Test(add_user, to_long_name) {
    struct user_head head = init_list_of_users();
    char *str = malloc(sizeof(char) * (MAX_NAME_LENGTH + 2));
    memset(str, 'a', MAX_NAME_LENGTH + 1);
    int ret = add_user(&head, str);
    cr_assert_eq(ret, -1);
    int len = 0;
    user_t *user;
    LIST_FOREACH(user, &head, next_user) {
        len++;
    }
    cr_assert_eq(len, 0);
}
