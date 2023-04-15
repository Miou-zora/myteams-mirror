/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** load_functions
*/

#include "private_shared_lib.h"
#include <stdlib.h>
#include <string.h>

ptr_function_t **load_functions(void *handler, char **functions_name,
    size_t nbr_of_function)
{
    ptr_function_t **list_of_ptr_functions = calloc(nbr_of_function,
        sizeof(*list_of_ptr_functions));

    if (list_of_ptr_functions == NULL)
        return (NULL);
    for (size_t i = 0; i < nbr_of_function; i++) {
        list_of_ptr_functions[i]->name = strdup(functions_name[i]);
        if (list_of_ptr_functions[i]->name == NULL)
            return (NULL);
        list_of_ptr_functions[i]->func = load_function(handler,
            functions_name[i]);
        if (list_of_ptr_functions[i]->func == NULL)
            return (NULL);
    }
    return (list_of_ptr_functions);
}
