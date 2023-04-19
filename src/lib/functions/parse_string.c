/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** parse_string
*/

#include "lib.h"
#include <stdio.h>

static int get_number_of_pos_of_return_not_in_string(const char *str)
{
    int number_of_pos = 0;
    bool is_in_string = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"')
            is_in_string = !is_in_string;
        if (str[i] == '\n' && str[i + 1] == '\0')
            break;
        if (str[i] == '\n' && !is_in_string)
            number_of_pos++;
    }
    return number_of_pos;
}

static int *get_pos_of_return_not_in_string(char *str)
{
    int nbr_of_pos = get_number_of_pos_of_return_not_in_string(str);
    int *pos = malloc(sizeof(int) * (nbr_of_pos + 1));
    bool is_in_string = false;
    int number_of_pos = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"')
            is_in_string = !is_in_string;
        if (str[i] == '\n' && str[i + 1] == '\0')
            break;
        if (str[i] == '\n' && !is_in_string) {
            pos[number_of_pos] = i;
            number_of_pos++;
        }
    }
    pos[number_of_pos] = -1;
    return pos;
}

void add_last_value(char *str, char **return_value, int number_of_pos, int j)
{
    int len_to_malloc = strlen(&str[j]);
    return_value[number_of_pos] = calloc(sizeof(char), (len_to_malloc + 1));
    strncpy(return_value[number_of_pos], &str[j], len_to_malloc);
    return_value[number_of_pos][len_to_malloc - 1] = '\0';
}

char **parse_string(char *str)
{
    int *pos = get_pos_of_return_not_in_string(str);
    char **return_value = malloc(sizeof(char *) * (pos[0] + 1));
    int number_of_pos = 0;
    int j = 0;
    int len_to_malloc = 0;

    for (int i = 0; pos[i] != -1; i++) {
        len_to_malloc = pos[i] - j;
        return_value[number_of_pos] = calloc(sizeof(char), (len_to_malloc + 1));
        strncpy(return_value[number_of_pos], &str[j], len_to_malloc);
        return_value[number_of_pos][len_to_malloc] = '\0';
        number_of_pos++;
        j = pos[i] + 1;
    }
    add_last_value(str, return_value, number_of_pos, j);
    number_of_pos++;
    return_value[number_of_pos] = NULL;
    free(pos);
    return return_value;
}
