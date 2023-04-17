/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** find_user
*/

#include "data_core.h"

#include <string.h>

user_t *find_user(struct user_head *users, char *username)
{
    user_t *user = NULL;

    if (users == NULL || username == NULL)
        return (NULL);
    LIST_FOREACH(user, users, next_user) {
        if (strcmp(user->username, username) == 0) {
            return (user);
        }
    }
    return (NULL);
}
