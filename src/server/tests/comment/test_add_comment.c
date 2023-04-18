/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_comment
*/

#include <criterion/criterion.h>

#include "data_core.h"

int get_len_of_lists(struct comment_head *head)
{
    int len = 0;
    comment_t *comment;
    LIST_FOREACH(comment, head, next_comment) {
        len++;
    }
    return len;
}

Test(add_comment, casual) {
    struct comment_head head = init_list_of_comments();
    uuid_t uuid;
    uuid_generate(uuid);
    int ret = add_comment(&head, "testcontent", uuid);
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len_of_lists(&head), 1);
}

Test(add_comment, multiple) {
    struct comment_head head = init_list_of_comments();
    uuid_t uuid;
    uuid_generate(uuid);
    int ret = add_comment(&head, "testcontent", uuid);
    cr_assert_eq(ret, 0);
    uuid_generate(uuid);
    ret = add_comment(&head, "testcontent2", uuid);
    cr_assert_eq(ret, 0);
    uuid_generate(uuid);
    ret = add_comment(&head, "testcontent3", uuid);
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len_of_lists(&head), 3);
}

Test(add_comment, null_head) {
    uuid_t uuid;
    uuid_generate(uuid);
    int ret = add_comment(NULL, "testcontent", uuid);
    cr_assert_eq(ret, -1);
}

Test(add_comment, null_content) {
    struct comment_head head = init_list_of_comments();
    uuid_t uuid;
    uuid_generate(uuid);
    int ret = add_comment(&head, NULL, uuid);
    cr_assert_eq(ret, -1);
}

Test(add_comment, null_uuid) {
    struct comment_head head = init_list_of_comments();
    int ret = add_comment(&head, "testcontent", NULL);
    cr_assert_eq(ret, -1);
}

Test(add_comment, null_all) {
    int ret = add_comment(NULL, NULL, NULL);
    cr_assert_eq(ret, -1);
}

Test(add_comment, empty_content) {
    struct comment_head head = init_list_of_comments();
    uuid_t uuid;
    uuid_generate(uuid);
    int ret = add_comment(&head, "", uuid);
    cr_assert_eq(ret, -1);
}

Test(add_comment, empty_uuid) {
    struct comment_head head = init_list_of_comments();
    uuid_t uuid;
    uuid_generate(uuid);
    int ret = add_comment(&head, "testcontent", uuid);
    cr_assert_eq(ret, 0);
    uuid_clear(uuid);
    ret = add_comment(&head, "testcontent2", uuid);
    cr_assert_eq(ret, -1);
}

Test(add_comment, too_long_body) {
    struct comment_head head = init_list_of_comments();
    char str[MAX_BODY_LENGTH + 2];
    uuid_t uuid;
    uuid_generate(uuid);
    memset(str, 'a', MAX_BODY_LENGTH + 1);
    str[MAX_BODY_LENGTH + 1] = '\0';
    int ret = add_comment(&head, str, uuid);
    cr_assert_eq(ret, -1);
}
