/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** create_addr
*/

#include "client.h"
#include <arpa/inet.h>
#include <stdlib.h>

struct sockaddr_in create_addr(char *ip, char *port)
{
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(atoi(port));
    return (addr);
}
