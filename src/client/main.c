/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** main
*/

#include "client.h"
#include <string.h>

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        return (help());
    } else if (ac != 3) {
        help();
        return (84);
    }
    return (client(av[1], av[2]));
}
