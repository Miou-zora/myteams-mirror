/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_comment
*/

#include "data_core.h"

#include <string.h>
#include <stdlib.h>

static comment_t *new_comment(const char *comment_content,
    uuid_t author_uuid)
{
    comment_t *comment = malloc(sizeof(comment_t));

    if (comment == NULL)
        return NULL;
    memset(comment, 0, sizeof(comment_t));
    strncpy(comment->body, comment_content, MAX_BODY_LENGTH);
    uuid_copy(comment->author_uuid, author_uuid);
    uuid_generate(comment->uuid);
    comment->timestamp = time(NULL);
    return comment;
}

comment_t *add_comment(struct comment_head *head, const char *comment_content,
    uuid_t author_uuid)
{
    comment_t *comment;

    if (head == NULL || comment_content == NULL ||
        strlen(comment_content) > MAX_BODY_LENGTH ||
        strlen(comment_content) == 0 || author_uuid == NULL ||
        uuid_is_null(author_uuid))
        return NULL;
    comment = new_comment(comment_content, author_uuid);
    if (comment == NULL)
        return NULL;
    LIST_INSERT_HEAD(head, comment, next_comment);
    return comment;
}
