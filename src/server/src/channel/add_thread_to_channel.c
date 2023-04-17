/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_thread_to_channel
*/

#include "data_core.h"

int add_thread_to_channel(struct channel_head *channels_head,
    const char *channel_name, const char *thread_name,
    const char *thread_description)
{
    channel_t *channel = get_channel_by_name(channels_head, channel_name);

    if (channel == NULL)
        return -1;
    return add_thread(&channel->threads_head, thread_name,
        thread_description);
}
