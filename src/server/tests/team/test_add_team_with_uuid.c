/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_team_with_uuid
*/

#include <criterion/criterion.h>

#include "data_core.h"

Test(add_team_with_uuid, casual) {
    struct team_head head = init_list_of_teams();
    int ret = add_team_with_uuid(&head, "testname", "testdescription",
    "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, 0);
    int len = 0;
    team_t *team;
    char uuid[100];
    LIST_FOREACH(team, &head, next_team) {
        len++;
        cr_assert_str_eq(team->name, "testname");
        cr_assert_str_eq(team->description, "testdescription");
        uuid_unparse(team->uuid, uuid);
        cr_assert_str_eq(uuid, "00000000-0000-0000-0000-000000000000");
    }
    cr_assert_eq(len, 1);
}
