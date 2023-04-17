/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load_shared_lib
*/

#include "private_shared_lib.h"

#include <stdlib.h>

shared_lib_t *load_shared_lib(char *path, const char **functions_name,
    size_t nbr_of_function)
{
    shared_lib_t *shared_lib = calloc(1, sizeof(*shared_lib));

    if (shared_lib == NULL)
        return (NULL);
    shared_lib->handler = load_lib(path);
    if (shared_lib->handler == NULL)
        return (NULL);
    shared_lib->functions = load_functions(shared_lib->handler, functions_name,
        nbr_of_function);
    if (shared_lib->functions == NULL)
        return (NULL);
    shared_lib->nbr_of_function = nbr_of_function;
    return (shared_lib);
}
