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
#include "response.h"

/**
 * @brief client parameters
 */
typedef struct instance_s {
    int socket;
    uuid_t user_uuid;
    uuid_t team_uuid;
    uuid_t channel_uuid;
    uuid_t thread_uuid;
    char buff_in[MESSAGE_SIZE];
    struct output_head output;
} instance_t;
