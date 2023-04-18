/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** EC02
*/

#include "response_server.h"

void response_default(char **args)
{
    int i = 1;

    for (; args[i + 1] != NULL; i++)
        printf("%s ", args[i]);
    printf("%s", args[i]);
}
