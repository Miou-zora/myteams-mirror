/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_channel_with_uuid
*/

#include "data_core.h"

#include <string.h>
#include <stdlib.h>

static channel_t *new_channel_with_uuid(const char *name, const char *description,
    const char *uuid)
{
    channel_t *channel = malloc(sizeof(*channel));

    if (!channel)
        return NULL;
    uuid_parse(uuid, channel->uuid);
    strcpy(channel->name, name);
    strcpy(channel->description, description);
    LIST_INIT(&channel->threads_head);
    return channel;
}

int add_channel_with_uuid(struct channel_head *head, const char *name,
    const char *description, const char *uuid)
{
    channel_t *channel;

    if (!head || !name || !description ||
        strlen(name) > MAX_NAME_LENGTH || strlen(name) == 0 ||
        strlen(description) > MAX_DESCRIPTION_LENGTH ||
        strlen(description) == 0)
        return (-1);
    LIST_FOREACH(channel, head, next_channel) {
        if (strcmp(channel->name, name) == 0)
            return (1);
    }
    channel = new_channel_with_uuid(name, description, uuid);
    if (!channel)
        return (-1);
    LIST_INSERT_HEAD(head, channel, next_channel);
    return (0);
}
