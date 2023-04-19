/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** lib
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char **data_to_array_str(char *str, char *sep);
size_t get_array_size(char **array);
char *delete_quotes(char *str);
char **parse_string(char *str);
