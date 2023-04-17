/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_thread
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

int del_thread(struct thread_head *head, const char *name)
{
    thread_t *thread;

    if (!head || !name ||
        strlen(name) > MAX_NAME_LENGTH || strlen(name) == 0)
        return (-1);
    LIST_FOREACH(thread, head, next_thread) {
        if (strcmp(thread->title, name) == 0) {
            LIST_REMOVE(thread, next_thread);
            free(thread);
            return (0);
        }
    }
    return (1);
}
