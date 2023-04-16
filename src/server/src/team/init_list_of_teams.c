/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** init_list_of_teams
*/

#include "data_core.h"

#include <stdlib.h>

struct team_head init_list_of_teams(void)
{
    struct team_head head = LIST_HEAD_INITIALIZER(head);

    LIST_INIT(&head);
    return head;
}
