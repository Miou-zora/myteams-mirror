/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** delete_list_of_users
*/

#include "data_core.h"

#include <stdlib.h>

void del_list_of_users(struct user_head *head)
{
    user_t *user;

    if (!head)
        return;
    while (!LIST_EMPTY(head)) {
        user = LIST_FIRST(head);
        LIST_REMOVE(user, next_user);
        free(user);
    }
}
