/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_thread_by_name
*/

#include "data_core.h"

#include <string.h>

thread_t *get_thread_by_name(struct thread_head *threads_head,
    const char *thread_name)
{
    thread_t *thread;

    LIST_FOREACH(thread, threads_head, next_thread) {
        if (strcmp(thread->title, thread_name) == 0)
            return thread;
    }
    return NULL;
}
