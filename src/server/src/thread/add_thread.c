/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_thread
*/

#include "data_core.h"

#include <string.h>
#include <stdlib.h>

static thread_t *new_thread(const char *title, const char *body)
{
    thread_t *thread = malloc(sizeof(thread_t));

    if (!thread)
        return NULL;
    uuid_generate(thread->uuid);
    strcpy(thread->title, title);
    strcpy(thread->message, body);
    thread->timestamp = time(NULL);
    LIST_INIT(&thread->comments_head);
    return thread;
}

int add_thread(struct thread_head *head, const char *title, const char *message)
{
    thread_t *thread;

    if (!head || !title || !message ||
        strlen(title) > MAX_NAME_LENGTH || strlen(title) == 0 ||
        strlen(message) > MAX_BODY_LENGTH || strlen(message) == 0)
        return (-1);
    LIST_FOREACH(thread, head, next_thread) {
        if (strcmp(thread->title, title) == 0)
            return (1);
    }
    thread = new_thread(title, message);
    if (!thread)
        return (-1);
    LIST_INSERT_HEAD(head, thread, next_thread);
    return (0);
}
