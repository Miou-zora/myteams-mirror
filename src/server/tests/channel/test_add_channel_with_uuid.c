/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_channel_with_uuid
*/

#include <criterion/criterion.h>

#include "data_core.h"

Test(add_channel_with_uuid, casual) {
    struct channel_head head = init_list_of_channels();
    int ret = add_channel_with_uuid(&head, "testname", "testdescription",
    "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, 0);
    int len = 0;
    channel_t *channel;
    char uuid[100];
    LIST_FOREACH(channel, &head, next_channel) {
        len++;
        cr_assert_str_eq(channel->name, "testname");
        cr_assert_str_eq(channel->description, "testdescription");
        uuid_unparse(channel->uuid, uuid);
        cr_assert_str_eq(uuid, "00000000-0000-0000-0000-000000000000");
    }
    cr_assert_eq(len, 1);
}
