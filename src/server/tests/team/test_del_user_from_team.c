/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_del_user_from_team
*/

#include <criterion/criterion.h>
#include "data_core.h"
#include <stdlib.h>

int get_len_of_uuid_list(struct uuid_list_head *head)
{
    uuid_list_t *uuid_list;
    int i = 0;

    if (!head)
        return (-1);
    LIST_FOREACH(uuid_list, head, next_uuid) {
        i++;
    }
    return (i);
}

Test(del_user_from_team, casual) {
    struct team_head team_head = init_list_of_teams();
    struct user_head user_head = init_list_of_users();
    add_user_with_uuid(&user_head, "test1",
        "00000000-0000-0000-0000-000000000000");
    add_user_with_uuid(&user_head, "test2",
        "00000000-0000-0000-0000-000000000001");
    add_team_with_uuid(&team_head, "testname", "testdescription",
        "00000000-0000-0000-0000-000000000002");
    add_user_to_team(&team_head, &user_head,
        "00000000-0000-0000-0000-000000000002",
        "00000000-0000-0000-0000-000000000000");
    int ret = del_user_from_team(&team_head, &user_head,
        "00000000-0000-0000-0000-000000000002",
        "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, 0);
    team_t *team = LIST_FIRST(&team_head);
    uuid_list_t *uuid = LIST_FIRST(&team->users_uuid_registered_head);
    cr_assert_null(uuid);
    cr_assert_eq(get_len_of_uuid_list(&team->users_uuid_registered_head), 0);
}

Test(del_user_from_team, null_team) {
    struct user_head user_head = init_list_of_users();
    add_user_with_uuid(&user_head, "test1",
        "00000000-0000-0000-0000-000000000000");
    add_user_with_uuid(&user_head, "test2",
        "00000000-0000-0000-0000-000000000001");
    int ret = del_user_from_team(NULL, &user_head,
        "00000000-0000-0000-0000-000000000002",
        "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, -1);
}

Test(del_user_from_team, null_user) {
    struct team_head team_head = init_list_of_teams();
    add_team_with_uuid(&team_head, "testname", "testdescription",
        "00000000-0000-0000-0000-000000000002");
    int ret = del_user_from_team(&team_head, NULL,
        "00000000-0000-0000-0000-000000000002",
        "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, -1);
}

Test(del_user_from_team, null_team_uuid) {
    struct team_head team_head = init_list_of_teams();
    struct user_head user_head = init_list_of_users();
    add_user_with_uuid(&user_head, "test1",
        "00000000-0000-0000-0000-000000000000");
    add_user_with_uuid(&user_head, "test2",
        "00000000-0000-0000-0000-000000000001");
    add_team_with_uuid(&team_head, "testname", "testdescription",
        "00000000-0000-0000-0000-000000000002");
    int ret = del_user_from_team(&team_head, &user_head,
        NULL,
        "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, -1);
}

Test(del_user_from_team, null_user_uuid) {
    struct team_head team_head = init_list_of_teams();
    struct user_head user_head = init_list_of_users();
    add_user_with_uuid(&user_head, "test1",
        "00000000-0000-0000-0000-000000000000");
    add_user_with_uuid(&user_head, "test2",
        "00000000-0000-0000-0000-000000000001");
    add_team_with_uuid(&team_head, "testname", "testdescription",
        "00000000-0000-0000-0000-000000000002");
    int ret = del_user_from_team(&team_head, &user_head,
        "00000000-0000-0000-0000-000000000002",
        NULL);
    cr_assert_eq(ret, -1);
}

Test(del_user_from_team, user_not_in_team) {
    struct team_head team_head = init_list_of_teams();
    struct user_head user_head = init_list_of_users();
    add_user_with_uuid(&user_head, "test1",
        "00000000-0000-0000-0000-000000000000");
    add_user_with_uuid(&user_head, "test2",
        "00000000-0000-0000-0000-000000000001");
    add_team_with_uuid(&team_head, "testname", "testdescription",
        "00000000-0000-0000-0000-000000000002");
    int ret = del_user_from_team(&team_head, &user_head,
        "00000000-0000-0000-0000-000000000002",
        "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, 3);
}

Test(del_user_from_team, no_user_in_team) {
    struct team_head team_head = init_list_of_teams();
    struct user_head user_head = init_list_of_users();
    add_user_with_uuid(&user_head, "test2",
        "00000000-0000-0000-0000-000000000001");
    add_team_with_uuid(&team_head, "testname", "testdescription",
        "00000000-0000-0000-0000-000000000002");
    int ret = del_user_from_team(&team_head, &user_head,
        "00000000-0000-0000-0000-000000000002",
        "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, 2);
}

Test(del_user_from_team, team_dont_exist) {
    struct team_head team_head = init_list_of_teams();
    struct user_head user_head = init_list_of_users();
    add_user_with_uuid(&user_head, "test1",
        "00000000-0000-0000-0000-000000000000");
    add_user_with_uuid(&user_head, "test2",
        "00000000-0000-0000-0000-000000000001");
    int ret = del_user_from_team(&team_head, &user_head,
        "00000000-0000-0000-0000-000000000002",
        "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, 1);
}
