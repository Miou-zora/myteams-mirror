/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_fcn_shared_lib
*/

#include "private_shared_lib.h"

#include <string.h>

void *get_fcn_shared_lib(shared_lib_t *lib, char *name)
{
    for (size_t i = 0; i < lib->nbr_of_function; i++)
        if (strcmp(lib->functions[i]->name, name) == 0)
            return (lib->functions[i]->func);
    return (NULL);
}
