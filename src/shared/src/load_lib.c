/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load_lib
*/

#include <dlfcn.h>
#include <stddef.h>

void *load_lib(char *path)
{
    void *handle = dlopen(path, RTLD_LAZY);
    if (!handle) {
        return (NULL);
    }
    return (handle);
}
