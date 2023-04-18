/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_list_of_comments
*/

#include <criterion/criterion.h>

#include "data_core.h"

static int get_size_of_lists(struct comment_head *head)
{
    int len = 0;
    comment_t *comment;
    LIST_FOREACH(comment, head, next_comment) {
        len++;
    }
    return len;
}

Test(del_list_of_comments, casual) {
    struct comment_head head = init_list_of_comments();
    uuid_t uuid;
    uuid_generate(uuid);
    int ret = add_comment(&head, "testcontent", uuid);
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_size_of_lists(&head), 1);
    del_list_of_comments(&head);
    cr_assert_eq(get_size_of_lists(&head), 0);
}

Test(del_list_of_comments, null_head) {
    del_list_of_comments(NULL);
}

Test(del_list_of_comments, empty) {
    struct comment_head head = init_list_of_comments();
    del_list_of_comments(&head);
    cr_assert_eq(get_size_of_lists(&head), 0);
}

Test(del_list_of_comments, multiple) {
    struct comment_head head = init_list_of_comments();
    uuid_t uuid;
    uuid_generate(uuid);
    int ret = add_comment(&head, "testcontent", uuid);
    cr_assert_eq(ret, 0);
    ret = add_comment(&head, "testcontent2", uuid);
    cr_assert_eq(ret, 0);
    ret = add_comment(&head, "testcontent3", uuid);
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_size_of_lists(&head), 3);
    del_list_of_comments(&head);
    cr_assert_eq(get_size_of_lists(&head), 0);
}
