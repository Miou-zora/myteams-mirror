/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load_function
*/

#include <dlfcn.h>
#include <stddef.h>

void *load_function(void *handle, const char *function_name)
{
    void *function = dlsym(handle, function_name);
    if (!function) {
        return (NULL);
    }
    return (function);
}
