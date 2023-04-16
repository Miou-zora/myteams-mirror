/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_channel
*/

#include <criterion/criterion.h>

#include "data_core.h"

static int get_list_size(struct channel_head *head)
{
    int size = 0;
    struct channel_s *channel;

    LIST_FOREACH(channel, head, next_channel) {
        size++;
    }
    return size;
}

Test(del_channel, casual)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, "name", "description");

    cr_assert_eq(ret, 0);
    ret = del_channel(&head, "name");
    cr_assert_eq(ret, 0);
    cr_assert_eq(LIST_EMPTY(&head), 1);
}

Test(del_channel, del_channel_with_empty_name)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, "name", "description");

    cr_assert_eq(ret, 0);
    ret = del_channel(&head, "");
    cr_assert_eq(ret, -1);
}

Test(del_channel, del_channel_with_null_name)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, "name", "description");

    cr_assert_eq(ret, 0);
    ret = del_channel(&head, NULL);
    cr_assert_eq(ret, -1);
}

Test(del_channel, del_channel_with_empty_list)
{
    struct channel_head head = init_list_of_channels();
    int ret = del_channel(&head, "name");

    cr_assert_eq(ret, 1);
}

Test(del_channel, del_channel_with_null_list)
{
    int ret = del_channel(NULL, "name");

    cr_assert_eq(ret, -1);
}

Test(del_channel, del_channel_with_null_list_and_name)
{
    int ret = del_channel(NULL, NULL);

    cr_assert_eq(ret, -1);
}

Test(del_channel, del_channel_with_empty_list_and_name)
{
    struct channel_head head = init_list_of_channels();
    int ret = del_channel(&head, "");

    cr_assert_eq(ret, -1);
}

Test(del_channel, del_channel_with_empty_list_and_null_name)
{
    struct channel_head head = init_list_of_channels();
    int ret = del_channel(&head, NULL);

    cr_assert_eq(ret, -1);
}

Test(del_channel, del_channel_with_null_list_and_empty_name)
{
    int ret = del_channel(NULL, "");

    cr_assert_eq(ret, -1);
}

Test(del_channel, multiple_channel)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, "name", "description");
    int ret2 = add_channel(&head, "name2", "description2");
    int ret3 = add_channel(&head, "name3", "description3");

    cr_assert_eq(ret, 0);
    cr_assert_eq(ret2, 0);
    cr_assert_eq(ret3, 0);
    ret = del_channel(&head, "name");
    cr_assert_eq(ret, 0);
    cr_assert_eq(LIST_EMPTY(&head), 0);
    cr_assert_eq(get_list_size(&head), 2);
    ret = del_channel(&head, "name2");
    cr_assert_eq(ret, 0);
    cr_assert_eq(LIST_EMPTY(&head), 0);
    cr_assert_eq(get_list_size(&head), 1);
    ret = del_channel(&head, "name3");
    cr_assert_eq(ret, 0);
    cr_assert_eq(LIST_EMPTY(&head), 1);
    cr_assert_eq(get_list_size(&head), 0);
}
