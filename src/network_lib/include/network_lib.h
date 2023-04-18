/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** network_lib
*/

#pragma once

#include <arpa/inet.h>
#include <stdlib.h>

int bind_fd_addr(int fd, struct sockaddr_in addr);
int connect_fd_addr(int fd, struct sockaddr_in addr);
struct sockaddr_in create_addr(char *ip, char *port);
