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
    add_team(&team_head, "testname", "testdescription");
    add_user_to_team(&team_head, &user_head, "testname",
    "00000000-0000-0000-0000-000000000000");
    team_t *team = LIST_FIRST(&team_head);
    user_t *user = LIST_FIRST(&user_head);
    uuid_list_t *uuid = LIST_FIRST(&team->users_uuid_registered_head);
    cr_assert_str_eq(uuid->uuid, "00000000-0000-0000-0000-000000000000");
}
