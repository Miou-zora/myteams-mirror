/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** init_list_of_conversations
*/

#include "data_core.h"

struct conversation_head init_list_of_conversations(void)
{
    struct conversation_head head = LIST_HEAD_INITIALIZER(head);

    LIST_INIT(&head);
    return head;
}
