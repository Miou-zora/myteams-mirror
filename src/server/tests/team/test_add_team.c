/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_team
*/

#include <criterion/criterion.h>

#include "data_core.h"

Test(add_team, casual) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    int len = 0;
    team_t *team;
    LIST_FOREACH(team, &head, next_team) {
        len++;
        cr_assert_str_eq(team->name, "testname");
        cr_assert_str_eq(team->description, "testdescription");
    }
    cr_assert_eq(len, 1);
}

Test(add_team, multiple) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "testname", "testdescription");
    cr_assert_eq(ret, 0);
    ret = add_team(&head, "testname2", "testdescription2");
    cr_assert_eq(ret, 0);
    ret = add_team(&head, "testname3", "testdescription3");
    cr_assert_eq(ret, 0);
    int len = 0;
    team_t *team;
    LIST_FOREACH(team, &head, next_team) {
        len++;
        if (len == 1) {
            cr_assert_str_eq(team->name, "testname3");
            cr_assert_str_eq(team->description, "testdescription3");
        }
        if (len == 2) {
            cr_assert_str_eq(team->name, "testname2");
            cr_assert_str_eq(team->description, "testdescription2");
        }
        if (len == 3) {
            cr_assert_str_eq(team->name, "testname");
            cr_assert_str_eq(team->description, "testdescription");
        }
    }
    cr_assert_eq(len, 3);
}

Test(add_team, null_head) {
    int ret = add_team(NULL, "testname", "testdescription");
    cr_assert_eq(ret, -1);
}

Test(add_team, null_name) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, NULL, "testdescription");
    cr_assert_eq(ret, -1);
}

Test(add_team, null_description) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "testname", NULL);
    cr_assert_eq(ret, -1);
}

Test(add_team, empty_name) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "", "testdescription");
    cr_assert_eq(ret, -1);
}

Test(add_team, empty_description) {
    struct team_head head = init_list_of_teams();
    int ret = add_team(&head, "testname", "");
    cr_assert_eq(ret, -1);
}

Test(add_team, too_long_name) {
    struct team_head head = init_list_of_teams();
    char name[MAX_NAME_LENGTH + 2];
    memset(name, 'a', MAX_NAME_LENGTH + 2);
    name[MAX_NAME_LENGTH + 1] = '\0';
    int ret = add_team(&head, name, "testdescription");
    cr_assert_eq(ret, -1);
}

Test(add_team, too_long_description) {
    struct team_head head = init_list_of_teams();
    char description[MAX_DESCRIPTION_LENGTH + 2];
    memset(description, 'a', MAX_DESCRIPTION_LENGTH + 2);
    description[MAX_DESCRIPTION_LENGTH + 1] = '\0';
    int ret = add_team(&head, "testname", description);
    cr_assert_eq(ret, -1);
}
