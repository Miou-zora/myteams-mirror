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
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>

#include "instance.h"
#include "logging_server.h"

//! define list
#define MAX_INSTANCES 100
#define EPI_FAILURE 84

//! struct list
/**
 * @brief server attributes
 */
typedef struct server_s {
    int port;
    int master_socket;
    bool is_running;
    fd_set readfds;
    fd_set writefds;
    int max_sd;
    instance_t *instance[MAX_INSTANCES];
    struct user_head users;
} server_t;

/**
 * @brief client action working like a map
*/
typedef struct client_action_s {
    char *command;
    void (*action)(instance_t *client, char *command);
} client_action_t;

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

/**
 * @brief server loop
 *
 * @param server
 */
void server_loop(server_t *server);

/**
 * @brief remove client from server
 *
 * @param client
 */
void leave_instance(server_t *server, instance_t *client);

/**
 * @brief do client action based on command send by client
 *
 * @param server
 */
void do_client_action(server_t *server);

/**
 * @brief accept new connection
 *
 * @param server
 */
void accept_new_connection(server_t *server);

/**
 * @brief set actual client
 *
 * @param server
 */
void set_actual_instance(server_t *server);

/**
 * @brief exec command based on the client received message
 *
 * @param client
 * @param command
 */
void exec_command(server_t *server, instance_t *instance, char *command);

/**
 * @brief send message to every users
 *
 * @param server
 * @param code
 * @param args
 */
void send_message_every_users(server_t *server, char *code, char *args);
