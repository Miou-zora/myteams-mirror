/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** init_user
*/

#include "data_core.h"

struct user_head init_user(void)
{
    struct user_head head = LIST_HEAD_INITIALIZER(head);

    LIST_INIT(&head);
    return head;
}
