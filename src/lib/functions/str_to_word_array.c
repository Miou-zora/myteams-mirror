/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** str_to_word_array
*/

#include "lib.h"
#include <stdio.h>

static bool is_char_is_that(char c, char const *array)
{
    return ((array == NULL || *array == '\0') ?
    false : (*array == c) ?
    true : (is_char_is_that(c, array + 1)) ?
    true : false);
}

static size_t number_of_word_start(char const *str, char *sep)
{
    return ((sep == NULL || str == NULL) ?
    0 : (*str == '\0') ?
    0 : (
        (is_char_is_that(*str, sep)) ?
        1 : 0) + (number_of_word_start(str + 1, sep)));
}

char **data_to_array_str(char *str, char *sep)
{
    int len_all = strlen(str);
    size_t tmp = number_of_word_start(str, sep) + 2;
    char **array = calloc(tmp, sizeof(*array));
    int nbr_ptr = 0;
    int i = 0;

    for (; i < len_all; i++)
        if (is_char_is_that(str[i], sep))
            str[i] = '\0';
    for (i = 0; i < len_all; i++)
        if ((i == 0 || !str[i - 1]) && str[i]) {
            array[nbr_ptr] = &str[i];
            nbr_ptr = nbr_ptr + 1;
        }
    array[nbr_ptr] = NULL;
    if (nbr_ptr == 0) {
        free(array);
        return (NULL);
    }
    return (array);
}
