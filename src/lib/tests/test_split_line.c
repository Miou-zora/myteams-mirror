/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** test_split_line
*/

#include <criterion/criterion.h>

#include "lib.h"

Test(split_line, casual) {
    char *str = strdup("bonsoir \"coucou coucou\" \"salut\"");
    char **parsed = split_line(str);
    char *expected[] = {"bonsoir", "coucou coucou", "salut", NULL};

    for (int i = 0; parsed[i] != NULL; i++)
        cr_assert_str_eq(parsed[i], expected[i]);
}
