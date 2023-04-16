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
/// @brief Define head struct for team list
LIST_HEAD(team_head, team_s);

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
 * @brief Get a user from its username
 *
 * @param head Head of list of users
 * @param username Username of the user
 * @return user_t* Pointer to the user if found, NULL otherwise
 */
struct user_head init_list_of_users(void);

/**
 * @brief Create a new user_t object
 *
 * @param head Head of list of users
 * @param username Username of the user
 * @return int 0 if success, 1 if user already exist, -1 for other error
 */
int add_user(struct user_head *head, const char *username);

/**
 * @brief Get a user from its username
 *
 * @param head Head of list of users
 * @param username Username of the user
 * @return user_t* Pointer to the user if found, NULL otherwise
 */
int add_user_with_uuid(struct user_head *head, const char *username,
    const char *uuid);

/**
 * @brief Get a user from its username
 *
 * @param head Head of list of users
 * @param username Username of the user
 * @return int 0 if success, 1 if user doesn't exist, -1 for other error
 */
int del_user(struct user_head *head, const char *username);

/**
 * @brief Get a user from its username
 *
 * @param head Head of list of users
 * @param username Username of the user
 * @return user_t* Pointer to the user if found, NULL otherwise
 */
void del_list_of_users(struct user_head *head);

// * Team functions

/**
 * @brief Create a list of teams
 *
 * @return struct team_head Head of list of teams
 */
struct team_head init_list_of_teams(void);

/**
 * @brief Add a team to the list of teams
 *
 * @param head Head of list of teams
 * @param name Name of the team
 * @param description Description of the team
 * @return int 0 if success, 1 if team already exist, -1 for other error
 */
int add_team(struct team_head *head, const char *name,
    const char *description);

/**
 * @brief Add a team to the list of teams with a specific uuid
 *
 * @param head Head of list of teams
 * @param name Name of the team
 * @param description Description of the team
 * @param uuid Uuid of the team
 * @return int 0 if success, 1 if team already exist, -1 for other error
 */
int add_team_with_uuid(struct team_head *head, const char *name,
    const char *description, const char *uuid);

/**
 * @brief Delete a team from the list of teams
 *
 * @param head Head of list of teams
 * @param name Name of the team
 * @return int 0 if success, 1 if team doesn't exist, -1 for other error
 */
int del_team(struct team_head *head, const char *name);

/**
 * @brief Delete a list of teams
 *
 * @param head Head of list of teams
 */
void del_list_of_teams(struct team_head *head);

/**
 * @brief Add a user to a team
 *
 * @param teams_head Head of list of teams
 * @param users_head Head of list of users
 * @param team_name Name of the team
 * @param user_name Name of the user
 */
void add_user_to_team(struct team_head *teams_head,
    struct user_head *users_head, const char *team_name,
    const char *user_name);

/**
 * @brief Delete a user from a team
 *
 * @param teams_head Head of list of teams
 * @param users_head Head of list of users
 * @param team_name Name of the team
 * @param user_name Name of the user
 */
void del_user_from_team(struct team_head *teams_head,
    struct user_head *users_head, const char *team_name,
    const char *user_name);

/**
 * @brief Add a channel to a team
 *
 * @param teams_head Head of list of teams
 * @param team_name Name of the team
 * @param channel_name Name of the channel
 * @param channel_description Description of the channel
 */
void add_channel_to_team(struct team_head *teams_head,
    const char *team_name, const char *channel_name,
    const char *channel_description);

/**
 * @brief Delete a channel from a team
 *
 * @param teams_head Head of list of teams
 * @param team_name Name of the team
 * @param channel_name Name of the channel
 */
void del_channel_from_team(struct team_head *teams_head,
    const char *team_name, const char *channel_name);
