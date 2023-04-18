/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_comment_from_thread
*/

#include "data_core.h"

int del_comment_from_thread(struct thread_head *threads_head,
    const char *thread_name, const char *comment_uuid)
{
    thread_t *thread = get_thread_by_name(threads_head, thread_name);
    uuid_t uuid;

    if (thread == NULL)
        return -1;
    uuid_parse(comment_uuid, uuid);
    return del_comment(&thread->comments_head, uuid);
}
