/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** unload_lib
*/

#include "private_shared_lib.h"

#include <dlfcn.h>

int unload_lib(void *handle)
{
    if (dlclose(handle) != 0)
        return (84);
    return (0);
}
