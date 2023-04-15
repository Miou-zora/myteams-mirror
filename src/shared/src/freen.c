/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** freen
*/

#include <stddef.h>
#include <stdlib.h>

void freen(void *ptr)
{
    void **tmp_ptr = (void **)ptr;
    free(*tmp_ptr);
    *tmp_ptr = NULL;
}
