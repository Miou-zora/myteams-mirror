/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** split_line
*/

#include "lib.h"

#include <stdio.h>

static char **compute(char **parsed_quotes, char **parsed_spaces, int *indice)
{
    char **buffer = calloc(sizeof(*buffer), 1000);

    for (int i = 0; parsed_quotes[i] != NULL; i++) {
        if (i % 2 != 0) {
            buffer[*indice] = parsed_quotes[i];
            (*indice)++;
            continue;
        }
        parsed_spaces = data_to_array_str(parsed_quotes[i], " ");
        if (parsed_spaces == NULL)
            continue;
        for (int j = 0; parsed_spaces[j] != NULL; j++) {
            buffer[*indice] = parsed_spaces[j];
            (*indice)++;
        }
    }
    return buffer;
}

char **split_line(char *str)
{
    char **parsed_quotes = data_to_array_str(str, "\"");
    char **parsed_spaces = NULL;
    char **return_value = NULL;
    int indice = 0;
    char **buffer = compute(parsed_quotes, parsed_spaces, &indice);

    buffer[indice] = NULL;
    return_value = calloc(sizeof(char *), (indice + 1));
    for (int i = 0; buffer[i] != NULL; i++)
        return_value[i] = strdup(buffer[i]);
    free(parsed_quotes);
    free(buffer);
    return return_value;
}
