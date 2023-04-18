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
#include <sys/queue.h>

#define MESSAGE_SIZE 1024

/**
 * @brief client output
 */
typedef struct output_s {
    char *message;
    TAILQ_ENTRY(output_s) next_output;
} output_t;
TAILQ_HEAD(output_head, output_s);

/**
 * @brief init list of outputs
 *
 * @return struct output_head
 */
struct output_head init_list_of_outputs(void);

/**
 * @brief add output to list
 *
 * @param head
 * @param code
 * @param message
 * @return int 0 if success, -1 if error
 */
int add_output(struct output_head *head, const char *code,
    const char *message);

/**
 * @brief get and remove output from list
 *
 * @param head
 * @return output_t* to display
 */
output_t *pop_output(struct output_head *head);
