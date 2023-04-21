/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** add_conversations_with_uuid
*/

#include "data_core.h"
#include <string.h>
#include <stdlib.h>

static conversation_t *new_conversation(user_t *user1, user_t *user2)
{
    conversation_t *conversation = malloc(sizeof(conversation_t));

    if (!conversation)
        return NULL;
    uuid_generate(conversation->uuid_conv);
    uuid_copy(conversation->user1, user1->uuid);
    uuid_copy(conversation->user2, user2->uuid);
    LIST_INIT(&conversation->messages);
    return conversation;
}

int add_conversation_to_list(struct conversation_head *head,
    conversation_t *conv)
{
    conversation_t *conversation;

    LIST_FOREACH(conversation, head, next_conversation) {
        if ((uuid_compare(conversation->user1, conv->user1) == 0 &&
            uuid_compare(conversation->user2, conv->user2) == 0) ||
            (uuid_compare(conversation->user1, conv->user2) == 0 &&
            uuid_compare(conversation->user2, conv->user1) == 0))
            return (-1);
    }
    LIST_INSERT_HEAD(head, conv, next_conversation);
    return (0);
}

static bool is_in_contact(user_t *user1, user_t *user2)
{
    conversation_t *conv1;
    conversation_t *conv2;

    LIST_FOREACH(conv1, &user1->conversations, next_conversation) {
        LIST_FOREACH(conv2, &user2->conversations, next_conversation) {
            if (uuid_compare(conv1->uuid_conv, conv2->uuid_conv) == 0)
            return (true);
        }
    }
    return (false);
}

void create_users_conversation(user_t *user1, user_t *user2)
{
    conversation_t *conversation = new_conversation(user1, user2);

    if (!conversation)
        return;
    if (is_in_contact(user1, user2))
        return;
    add_conversation_to_list(&user1->conversations, conversation);
    add_conversation_to_list(&user2->conversations, conversation);
}

message_t *send_message_into_conv(user_t *userfrom, user_t *userto,
    char *message)
{
    conversation_t *convfrom;
    conversation_t *convto;

    create_users_conversation(userfrom, userto);
    LIST_FOREACH(convfrom, &userfrom->conversations, next_conversation) {
        LIST_FOREACH(convto, &userto->conversations, next_conversation) {
            if (uuid_compare(convfrom->uuid_conv, convto->uuid_conv) == 0)
                return (add_message(&convfrom->messages, message,
                    userfrom->uuid));
        }
    }
    return (NULL);
}
