/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** shared_lib
*/

#pragma once

#include <stddef.h>

/**
 * @brief Structure to store a function pointer with name of the function
 */
typedef struct ptr_function_s {
    /// @brief Name of the function
    char *name;
    /// @brief Function pointer
    void (*func)(char **args);
} ptr_function_t;

/**
 * @brief Structure to store a library
 * @details Handle of the handler and list of function pointer
 */
typedef struct shared_lib_s {
    /// @brief Handle of the library
    void *handler;
    /// @brief List of function pointer
    ptr_function_t **functions;
    /// @brief Number of function
    size_t nbr_of_function;
} shared_lib_t;

shared_lib_t *load_shared_lib(char *path, char **functions_name,
    size_t nbr_of_function);

void unload_shared_lib(shared_lib_t *lib);

void *get_function(shared_lib_t *lib, char *name);
