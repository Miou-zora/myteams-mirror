/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_message
*/

#include "data_core.h"
#include <string.h>
#include <stdlib.h>

static message_t *new_message(const char *mess, uuid_t author)
{
    message_t *message = malloc(sizeof(message_t));

    if (!message)
        return NULL;
    uuid_generate(message->uuid);
    strcpy(message->message, mess);
    message->time_stamp = time(NULL);
    uuid_copy(message->author_uuid, author);
    return message;
}

message_t *add_message(struct message_head *head, const char *mess,
    uuid_t author)
{
    message_t *message;

    if (!head || !mess ||
        strlen(mess) > MAX_BODY_LENGTH || strlen(mess) == 0)
        return (NULL);
    message = new_message(mess, author);
    if (!message)
        return (NULL);
    LIST_INSERT_HEAD(head, message, next_message);
    return (message);
}
