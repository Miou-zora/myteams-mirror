/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_list_of_channels
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

Test(del_list_of_channels, casual)
{
    struct channel_head head = init_list_of_channels();
    add_channel(&head, "name", "description");
    add_channel(&head, "name2", "description2");
    add_channel(&head, "name3", "description3");
    cr_assert_eq(get_list_size(&head), 3);
    del_list_of_channels(&head);
    cr_assert_eq(LIST_EMPTY(&head), 1);
}

Test(del_list_of_channels, empty_list)
{
    struct channel_head head = init_list_of_channels();
    cr_assert_eq(LIST_EMPTY(&head), 1);
    del_list_of_channels(&head);
    cr_assert_eq(LIST_EMPTY(&head), 1);
}
