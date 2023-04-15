/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** unload_shared_lib
*/

#include "private_shared_lib.h"

#include <dlfcn.h>

void unload_shared_lib(shared_lib_t *lib)
{
    if (lib == NULL)
        return;
    if (lib->handler != NULL)
        dlclose(lib->handler);
    if (lib->functions != NULL)
        unload_functions(lib->functions, lib->nbr_of_function);
    freen(&lib);
}
