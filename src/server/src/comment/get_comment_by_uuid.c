/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_comment_by_uuid
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

comment_t *get_comment_by_uuid(struct comment_head *comments_head,
    uuid_t uuid)
{
    comment_t *comment;

    if (!comments_head || !uuid)
        return (NULL);
    LIST_FOREACH(comment, comments_head, next_comment) {
        if (uuid_compare(uuid, comment->uuid) == 0)
            return comment;
    }
    return NULL;
}
