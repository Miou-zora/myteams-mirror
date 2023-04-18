/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create_output
*/

#include "response.h"

static output_t *new_output(const char *code, const char *message)
{
    output_t *output = malloc(sizeof(*output));

    if (!output)
        return NULL;
    output->message = malloc(sizeof(char) * 1024);
    strcpy(output->message, code);
    strcat(output->message, " ");
    strcat(output->message, message);
    return output;
}

int add_output(struct output_head *head, const char *code, const char *message)
{
    output_t *output;

    if (!head || !code || !message)
        exit(84);
    output = new_output(code, message);
    if (!output)
        exit(84);
    TAILQ_INSERT_TAIL(head, output, next_output);
    return (0);
}
