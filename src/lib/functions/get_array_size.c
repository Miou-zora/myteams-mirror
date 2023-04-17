/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_array_size
*/

#include "lib.h"

size_t get_array_size(char **array)
{
    size_t size = 0;

    if (array == NULL)
        return (0);
    for (; array[size] != NULL; size++);
    return (size);
}
