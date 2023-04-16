/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_add_user_to_team
*/

#include <criterion/criterion.h>

#include "data_core.h"

#include <stdlib.h>

Test(add_user_to_team, casual)
{
    struct team_head team_head = init_list_of_teams();
    struct user_head user_head = init_list_of_users();
    add_user_with_uuid(&user_head, "test1",
        "00000000-0000-0000-0000-000000000000");
    add_user_with_uuid(&user_head, "test2",
        "00000000-0000-0000-0000-000000000001");
    add_team_with_uuid(&team_head, "testname", "testdescription",
        "00000000-0000-0000-0000-000000000002");
    int ret = add_user_to_team(&team_head, &user_head,
        "00000000-0000-0000-0000-000000000002",
        "00000000-0000-0000-0000-000000000000");
    cr_assert_eq(ret, 0);
    team_t *team = LIST_FIRST(&team_head);
    user_t *user = LIST_NEXT(LIST_FIRST(&user_head), next_user);
    uuid_list_t *uuid = LIST_FIRST(&team->users_uuid_registered_head);
    cr_assert_not_null(uuid);
    cr_assert_eq(uuid_compare(uuid->uuid, user->uuid), 0);
}
