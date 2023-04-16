/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** init_list_of_users
*/

#include "data_core.h"

struct user_head init_list_of_users(void)
{
    struct user_head head = LIST_HEAD_INITIALIZER(head);

    LIST_INIT(&head);
    return head;
}
