/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_comment_to_thread
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

comment_t *add_comment_to_thread(struct thread_head *threads_head,
    const char *thread_name, const char *message, uuid_t user_uuid)
{
    thread_t *thread = get_thread_by_name(threads_head, thread_name);

    if (thread == NULL)
        return NULL;
    return add_comment(&thread->comments_head, message, user_uuid);
}
