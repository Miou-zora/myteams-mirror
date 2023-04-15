/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** data_core
*/

#pragma once

#include <sys/queue.h>
#include <uuid/uuid.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

/**
 * @brief List of uuid. Can be use to store all users registered to a team or a
 *  list of team registered by an user.
 */
typedef struct uuid_list_s {
    /// @brief Copy of an uuid of a user or a team etc.
    uuid_t uuid;
    LIST_ENTRY(user_registry_s) next_uuid;
} uuid_list_t;

/**
 * @brief User registered in the server
 */
typedef struct user_s {
    uuid_t uuid;
    char username[MAX_NAME_LENGTH];
    LIST_ENTRY(user_s) next_user;
    LIST_HEAD(, uuid_list_s) teams_registered_head;
} user_t;
/// @brief Define head struct for user list
LIST_HEAD(user_head, user_s);

/**
 * @brief Teams created in the server
 */
typedef struct team_s {
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    LIST_HEAD(, user_registry_s) users_uuid_registered_head;
    LIST_HEAD(, channel_s) channels_head;
    LIST_ENTRY(team_s) next_team;
} team_t;

/**
 * @brief Channels created in a team
 */
typedef struct channel_s {
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    LIST_HEAD(, thread_s) threads_head;
    LIST_ENTRY(channel_s) next_channel;
} channel_t;

/**
 * @brief Threads created in a channel
 */
typedef struct thread_s {
    uuid_t uuid;
    char title[MAX_NAME_LENGTH];
    char message[MAX_BODY_LENGTH];
    LIST_HEAD(, comment_s) threads_head;
    LIST_ENTRY(thread_s) next_channel;
} thread_t;

/**
 * @brief Comments created in a thread
 */
typedef struct comment_s {
    uuid_t author_uuid;
    char body[MAX_BODY_LENGTH];
    LIST_ENTRY(comment_s) next_comment;
} comment_t;

// * User functions

/**
 * @brief Create a new user_t object
 *
 * @param head Head of list of users
 * @param username Username of the user
 * @return int 0 if success, 1 if user already exist, -1 for other error
 */
int add_user(struct user_head *head, const char *username);


struct user_head init_user(void);

