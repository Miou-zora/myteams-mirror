/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_channel_by_name
*/

#include "data_core.h"

#include <string.h>

channel_t *get_channel_by_name(struct channel_head *channels_head,
    const char *channel_name)
{
    channel_t *channel;

    LIST_FOREACH(channel, channels_head, next_channel) {
        if (strcmp(channel->name, channel_name) == 0)
            return channel;
    }
    return NULL;
}
