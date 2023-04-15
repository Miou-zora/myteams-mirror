/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** unload_functions
*/

#include "private_shared_lib.h"

#include <stdlib.h>

void unload_functions(ptr_function_t **functions, size_t nbr_of_function)
{
    if (functions == NULL)
        return;
    for (size_t i = 0; i < nbr_of_function; i++) {
        freen(&functions[i]->name);
        freen(&functions[i]);
    }
    freen(&functions);
}
