/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_list_of_channels
*/

#include "data_core.h"

#include <stdlib.h>

void del_list_of_channels(struct channel_head *head)
{
    channel_t *channel;

    if (!head)
        return;
    while (!LIST_EMPTY(head)) {
        channel = LIST_FIRST(head);
        LIST_REMOVE(channel, next_channel);
        free(channel);
    }
}
