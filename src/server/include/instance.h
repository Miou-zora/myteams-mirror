/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** instance
*/

#pragma once

#include <unistd.h>
#include <stdbool.h>
#include "data_core.h"

/**
 * @brief client parameters
 */
typedef struct instance_s {
    int socket;
    uuid_t uuid;
} instance_t;
