/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** del_user
*/

#include "data_core.h"

#include <stdlib.h>
#include <string.h>

int del_user(struct user_head *head, const char *username)
{
    user_t *user;

    if (!head || !username ||
        strlen(username) > MAX_NAME_LENGTH || strlen(username) == 0)
        return (-1);
    LIST_FOREACH(user, head, next_user) {
        if (strcmp(user->username, username) == 0) {
            LIST_REMOVE(user, next_user);
            free(user);
            return (0);
        }
    }
    return (1);
}
