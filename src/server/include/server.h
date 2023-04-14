/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** server
*/

#pragma once

//! includes
#include <stdbool.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//! define list
#define MAX_CLIENTS 10

//! struct list
/**
 * @brief client parameters
 */
typedef struct client_s {
    int socket;
    char *username;
} client_t;

/**
 * @brief server attributes
 */
typedef struct server_s {
    int port;
    int master_socket;
    fd_set readfds;
    int max_sd;
    client_t *clients[MAX_CLIENTS];
    bool is_running;
} server_t;


//! function list
/**
 * @brief init server
 * @param port
 * @return server_t
 */
server_t *server_init(char *port);

/**
 * @brief Create a socket object
 *
 * @param adress to listen
 * @param port to listen
 * @return socket fd
 */
int create_socket(in_addr_t adress, int port);

