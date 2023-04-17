/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** init_list_of_threads
*/

#include "data_core.h"

struct thread_head init_list_of_threads(void)
{
    struct thread_head head = LIST_HEAD_INITIALIZER(head);

    LIST_INIT(&head);
    return head;
}
