/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** init_list_of_comments
*/

#include "data_core.h"

#include <stdlib.h>

struct comment_head init_list_of_comments(void)
{
    struct comment_head head;

    LIST_INIT(&head);
    return head;
}
