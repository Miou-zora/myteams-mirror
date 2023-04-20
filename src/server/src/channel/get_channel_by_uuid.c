/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_channel_by_uuid
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

channel_t *get_channel_by_uuid(struct channel_head *channels_head,
    const char *channel_uuid)
{
    channel_t *channel;
    uuid_t uuid;

    if (!channels_head || !channel_uuid)
        return (NULL);
    uuid_parse(channel_uuid, uuid);
    LIST_FOREACH(channel, channels_head, next_channel) {
        if (uuid_compare(uuid, channel->uuid) == 0)
            return channel;
    }
    return NULL;
}
