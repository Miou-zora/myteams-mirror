/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** response
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct response_s {
    char *code;
    char *message;
} response_t;

/**
 * @brief reply to a client with a code and a message
 *
 * @param socket the socket of the client
 * @param code the code to send cf RFC documentation
 * @param mess the message to send
 */

void reply(int socket, const char *code);
