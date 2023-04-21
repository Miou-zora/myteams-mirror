/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_thread_by_uuid
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

thread_t *get_thread_by_uuid(struct thread_head *threads_head,
    const char *thread_uuid)
{
    thread_t *thread;
    uuid_t uuid;

    if (!threads_head || !thread_uuid)
        return (NULL);
    uuid_parse(thread_uuid, uuid);
    LIST_FOREACH(thread, threads_head, next_thread) {
        if (uuid_compare(uuid, thread->uuid) == 0)
            return thread;
    }
    return NULL;
}
