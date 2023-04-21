/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_comment
*/

#include <criterion/criterion.h>

#include "data_core.h"

static int get_len_of_lists(struct comment_head *head)
{
    int len = 0;
    comment_t *comment;
    LIST_FOREACH(comment, head, next_comment) {
        len++;
    }
    return len;
}

Test(del_comment, casual) {
    struct comment_head head = init_list_of_comments();
    uuid_t author_uuid;
    uuid_generate(author_uuid);
    add_comment(&head, "testcontent", author_uuid);
    cr_assert_eq(get_len_of_lists(&head), 1);
    uuid_t uuid;
    uuid_copy(uuid, head.lh_first->uuid);
    int ret = del_comment(&head, uuid);
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len_of_lists(&head), 0);
}

Test(del_comment, multiple) {
    struct comment_head head = init_list_of_comments();
    uuid_t uuid;
    uuid_generate(uuid);
    add_comment(&head, "testcontent", uuid);
    uuid_t uuid2;
    uuid_generate(uuid2);
    add_comment(&head, "testcontent2", uuid2);
    uuid_t uuid3;
    uuid_generate(uuid3);
    add_comment(&head, "testcontent3", uuid3);
    cr_assert_eq(get_len_of_lists(&head), 3);
    uuid_t uuid_to_del;
    uuid_copy(uuid_to_del, head.lh_first->uuid);
    int ret = del_comment(&head, uuid_to_del);
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len_of_lists(&head), 2);
    uuid_copy(uuid_to_del, head.lh_first->uuid);
    ret = del_comment(&head, uuid_to_del);
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len_of_lists(&head), 1);
    uuid_copy(uuid_to_del, head.lh_first->uuid);
    ret = del_comment(&head, uuid_to_del);
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len_of_lists(&head), 0);
}

Test(del_comment, null_head) {
    uuid_t uuid;
    uuid_generate(uuid);
    int ret = del_comment(NULL, uuid);
    cr_assert_eq(ret, -1);
}

Test(del_comment, null_uuid) {
    struct comment_head head = init_list_of_comments();
    int ret = del_comment(&head, NULL);
    cr_assert_eq(ret, -1);
}

Test(del_comment, not_found) {
    struct comment_head head = init_list_of_comments();
    uuid_t uuid;
    uuid_generate(uuid);
    add_comment(&head, "testcontent", uuid);
    uuid_t uuid2;
    uuid_generate(uuid2);
    int ret = del_comment(&head, uuid2);
    cr_assert_eq(ret, 1);
}
