/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** get_last_output
*/

#include "response.h"

output_t *pop_output(struct output_head *head)
{
    output_t *output = TAILQ_FIRST(head);

    if (!output)
        return NULL;
    TAILQ_REMOVE(head, output, next_output);
    return output;
}
