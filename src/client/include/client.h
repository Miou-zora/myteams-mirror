/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** client
*/

#pragma once

#include "netinet/in.h"

int help(void);
int client(char *ip, char *port);
struct sockaddr_in create_addr(char *ip, char *port);
int bind_fd_addr(int fd, struct sockaddr_in addr);
int connect_fd_addr(int fd, struct sockaddr_in addr);
int init_client(char *ip, char *port);
int get_output_server(int client_fd);
int get_input_client(int client_fd);
int select_cycle(int client_fd);
void analyse_response(char *response);
