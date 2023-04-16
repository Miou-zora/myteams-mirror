/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_channel
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

int del_channel(struct channel_head *head, const char *name)
{
    channel_t *channel;

    if (!head || !name ||
        strlen(name) > MAX_NAME_LENGTH || strlen(name) == 0)
        return (-1);
    LIST_FOREACH(channel, head, next_channel) {
        if (strcmp(channel->name, name) == 0) {
            LIST_REMOVE(channel, next_channel);
            free(channel);
            return (0);
        }
    }
    return (1);
}
