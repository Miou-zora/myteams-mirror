/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_list_of_comments
*/

#include "data_core.h"

#include <stdlib.h>

void del_list_of_comments(struct comment_head *head)
{
    comment_t *comment;

    if (!head)
        return;
    while (!LIST_EMPTY(head)) {
        comment = LIST_FIRST(head);
        del_comment(head, comment->uuid);
    }
}
