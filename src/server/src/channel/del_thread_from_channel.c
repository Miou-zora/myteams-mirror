/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_thread_from_channel
*/

#include "data_core.h"

#include <stdlib.h>

void del_thread_from_channel(struct channel_head *channels_head,
    const char *channel_name, const char *thread_name)
{
    channel_t *channel = get_channel_by_name(channels_head, channel_name);
    thread_t *thread = get_thread_by_name(&channel->threads_head, thread_name);

    if (channel == NULL || thread == NULL)
        return;
    LIST_REMOVE(thread, next_thread);
    free(thread);
}
