/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_list_of_threads
*/

#include "data_core.h"

#include <stdlib.h>

void del_list_of_threads(struct thread_head *head)
{
    thread_t *thread;

    if (!head)
        return;
    while (!LIST_EMPTY(head)) {
        thread = LIST_FIRST(head);
        del_thread(head, thread->title);
    }
}
