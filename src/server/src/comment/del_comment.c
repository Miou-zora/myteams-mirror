/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_comment
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

int del_comment(struct comment_head *head, uuid_t uuid)
{
    comment_t *comment;

    if (!head || !uuid)
        return (-1);
    LIST_FOREACH(comment, head, next_comment) {
        if (uuid_compare(comment->uuid, uuid) == 0) {
            LIST_REMOVE(comment, next_comment);
            free(comment);
            return (0);
        }
    }
    return (1);
}
