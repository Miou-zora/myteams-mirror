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

#define MESSAGE_SIZE 1024

/**
 * @brief client parameters
 */
typedef struct instance_s {
    int socket;
    uuid_t uuid;
    char buff_in[MESSAGE_SIZE];
    char buff_out[MESSAGE_SIZE];
} instance_t;
