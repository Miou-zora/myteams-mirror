/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** private_shared_lib
*/

#pragma once

#include "shared_lib.h"
#include <stddef.h>

/**
 * @brief Load a library
 *
 * @param path Path to the library
 * @return void* Handle of the library, NULL if error.
 */
void *load_lib(char *path);

/**
 * @brief Load a function from a library
 *
 * @param handle Handle of the library
 * @param function_name Name of the function
 * @return void* Function pointer, NULL if error.
 */
void *load_function(void *handle, char *function_name);

/**
 * @brief Load a list of function from a library
 *
 * @param handler Handle of the library
 * @param functions_name List of function name
 * @param nbr_of_function Number of function
 * @return ptr_function_t* List of function pointer, NULL if error.
 */
ptr_function_t **load_functions(void *handler, char **functions_name,
    size_t nbr_of_function);

/**
 * @brief Unload a library
 *
 * @param functions List of function pointer
 */
void unload_functions(ptr_function_t **functions, size_t nbr_of_function);

/**
 * @brief Free a pointer and set it to NULL
 *
 * @param ptr Pointer to free
 */
void freen(void *ptr);
