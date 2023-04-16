/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_channel
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

Test(add_channel, add_channel)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, "name", "description");

    cr_assert_eq(ret, 0);
    cr_assert_eq(LIST_EMPTY(&head), 0);
    cr_assert_str_eq(LIST_FIRST(&head)->name, "name");
    cr_assert_str_eq(LIST_FIRST(&head)->description, "description");
}

Test(add_channel, add_channel_with_same_name)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, "name", "description");

    cr_assert_eq(ret, 0);
    ret = add_channel(&head, "name", "description");
    cr_assert_eq(ret, 1);
}

Test(add_channel, add_channel_with_empty_name)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, "", "description");

    cr_assert_eq(ret, -1);
}

Test(add_channel, add_channel_with_empty_description)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, "name", "");

    cr_assert_eq(ret, -1);
}

Test(add_channel, add_channel_with_null_name)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, NULL, "description");

    cr_assert_eq(ret, -1);
}

Test(add_channel, add_channel_with_null_description)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, "name", NULL);

    cr_assert_eq(ret, -1);
}

Test(add_channel, multiple_channel)
{
    struct channel_head head = init_list_of_channels();
    int ret = add_channel(&head, "name", "description");

    cr_assert_eq(ret, 0);
    ret = add_channel(&head, "name2", "description2");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_list_size(&head), 2);
    cr_assert_str_eq(LIST_FIRST(&head)->name, "name2");
    cr_assert_str_eq(LIST_FIRST(&head)->description, "description2");
    cr_assert_str_eq(LIST_NEXT(LIST_FIRST(&head), next_channel)->name, "name");
    cr_assert_str_eq(LIST_NEXT(LIST_FIRST(&head), next_channel)->description,
        "description");
}
