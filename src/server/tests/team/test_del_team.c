/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_team
*/

#include <criterion/criterion.h>

#include "data_core.h"

static int get_len(struct team_head *head)
{
    int len = 0;
    team_t *team;
    LIST_FOREACH(team, head, next_team) {
        len++;
    }
    return len;
}

Test(del_team, casual) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 1);
    ret = del_team(&head, "testname");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 0);
}

Test(del_team, multiple) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    ret = add_team(&head, "testname2", "testdescription2");
    cr_assert_eq(ret, 0);
    ret = add_team(&head, "testname3", "testdescription3");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 3);
    ret = del_team(&head, "testname2");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 2);
    ret = del_team(&head, "testname");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 1);
    ret = del_team(&head, "testname3");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 0);
}

Test(del_team, null_head) {
    int ret = del_team(NULL, "testname");
    cr_assert_eq(ret, -1);
}

Test(del_team, null_name) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    ret = del_team(&head, NULL);
    cr_assert_eq(ret, -1);
}

Test(del_team, not_found) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    ret = del_team(&head, "testname2");
    cr_assert_eq(ret, 1);
}
