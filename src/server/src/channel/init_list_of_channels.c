/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** init_list_of_channels
*/

#include "data_core.h"

#include <stdlib.h>

struct channel_head init_list_of_channels(void)
{
    struct channel_head head;

    LIST_INIT(&head);
    return head;
}
