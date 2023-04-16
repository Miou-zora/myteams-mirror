/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_channel
*/

#include "data_core.h"

#include <string.h>
#include <stdlib.h>

static channel_t *new_channel(const char *name, const char *description)
{
    channel_t *channel = malloc(sizeof(*channel));

    if (!channel)
        return NULL;
    uuid_generate(channel->uuid);
    strcpy(channel->name, name);
    strcpy(channel->description, description);
    LIST_INIT(&channel->threads_head);
    return channel;
}

int add_channel(struct channel_head *head, const char *name,
    const char *description)
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
    channel = new_channel(name, description);
    if (!channel)
        return (-1);
    LIST_INSERT_HEAD(head, channel, next_channel);
    return (0);
}
