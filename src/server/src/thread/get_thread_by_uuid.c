/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_thread_by_uuid
*/

#include "data_core.h"

#include <string.h>

thread_t *get_thread_by_uuid(struct thread_head *threads_head,
    uuid_t thread_uuid)
{
    thread_t *thread;

    LIST_FOREACH(thread, threads_head, next_thread) {
        if (uuid_compare(thread->uuid, thread_uuid) == 0)
            return thread;
    }
    return NULL;
}
