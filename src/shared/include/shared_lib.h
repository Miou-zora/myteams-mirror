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

/**
 * @brief Load a library
 *
 * @param path Path to the library
 * @param functions_name List of function name
 * @param nbr_of_function Number of function
 * @return shared_lib_t* Structure of the library, NULL if error.
 */
shared_lib_t *load_shared_lib(char *path, const char **functions_name,
    size_t nbr_of_function);

/**
 * @brief Unload a library
 *
 * @param lib Structure of the library
 */
void unload_shared_lib(shared_lib_t *lib);

/**
 * @brief Get a function pointer from a library
 *
 * @param lib Structure of the library
 * @param name Name of the function
 * @return void* Function pointer, NULL if error.
 */
void *get_fcn_shared_lib(shared_lib_t *lib, char *name);
