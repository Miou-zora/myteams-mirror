/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_unload_functions
*/

#include <criterion/criterion.h>

#include "private_shared_lib.h"

Test(test_unload_functions, casual) {
    ptr_function_t **functions = malloc(sizeof(ptr_function_t *) * 2);

    functions[0] = malloc(sizeof(ptr_function_t));
    functions[0]->name = strdup("test");
    functions[0]->func = NULL;
    unload_functions(functions, 1);
    cr_assert(true);
}

Test(test_unload_functions, null) {
    unload_functions(NULL, 0);
    cr_assert(true);
}
