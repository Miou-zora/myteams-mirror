/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_list_of_teams
*/

#include "data_core.h"

#include <criterion/criterion.h>

static int get_len(struct team_head *head)
{
    int len = 0;
    team_t *team;
    LIST_FOREACH(team, head, next_team) {
        len++;
    }
    return len;
}

Test(del_list_of_teams, casual) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    ret = add_team(&head, "testname2", "testdescription2");
    cr_assert_eq(ret, 0);
    ret = add_team(&head, "testname3", "testdescription3");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 3);
    del_list_of_teams(&head);
    cr_assert_eq(get_len(&head), 0);
}

Test(del_list_of_teams, null_head) {
    del_list_of_teams(NULL);
}

Test(del_list_of_teams, empty) {
    struct team_head head = init_list_of_teams();
    del_list_of_teams(&head);
    cr_assert_eq(get_len(&head), 0);
}

Test(del_list_of_teams, one) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    cr_assert_eq(get_len(&head), 1);
    del_list_of_teams(&head);
    cr_assert_eq(get_len(&head), 0);
}
