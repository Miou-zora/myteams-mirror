/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_channel_to_team
*/

#include <criterion/criterion.h>

#include "data_core.h"

Test(add_channel_to_team, add_channel_to_team) {
    struct team_head teams_head = LIST_HEAD_INITIALIZER(teams_head);

    add_team(&teams_head, "team", "description");
    cr_assert_eq(add_channel_to_team(&teams_head, "team", "channel",
        "description"), 0);
    struct channel_head *head = &LIST_FIRST(&teams_head)->channels_head;
    cr_assert_eq(LIST_EMPTY(head), 0);
    cr_assert_str_eq(LIST_FIRST(head)->name, "channel");
    cr_assert_str_eq(LIST_FIRST(head)->description, "description");
}

Test(add_channel_to_team, add_channel_to_team_with_same_name) {
    struct team_head teams_head = LIST_HEAD_INITIALIZER(teams_head);

    add_team(&teams_head, "team", "description");
    cr_assert_eq(add_channel_to_team(&teams_head, "team", "channel",
        "description"), 0);
    cr_assert_eq(add_channel_to_team(&teams_head, "team", "channel",
        "description"), 1);
}
