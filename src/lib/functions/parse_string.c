/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** parse_string
*/

#include "lib.h"

char **parse_string(char *str)
{
    char *all_args_parsed[1000] = { NULL };
    char **args = data_to_array_str(str, "\"");
    char **return_args = NULL;

    for (int i = 0; args[i]; i++) {
        if (i % 2 == 0) {
            char **args2 = data_to_array_str(args[i], " \r\n");
            for (int j = 0; args2[j]; j++) {
                all_args_parsed[i] = args2[j];
            }
        } else {
            all_args_parsed[i] = args[i];
        }
    }
    return_args = calloc(sizeof(*return_args),
        (get_array_size(all_args_parsed) + 1));
    for (int i = 0; all_args_parsed[i]; i++)
        return_args[i] = all_args_parsed[i];
    return return_args;
}
