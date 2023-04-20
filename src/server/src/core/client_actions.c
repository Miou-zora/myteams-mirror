/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** client_actions
*/

#include "server.h"

void catch_client_message(int index, server_t *server)
{
    char command[1024];
    int sd = server->instance[index]->socket;

    memset(command, 0, 1024);
    if (read(sd, command, sizeof(command)) == 0) {
        leave_instance(server, server->instance[index]);
    } else {
        if (strlen(server->instance[index]->buff_in) +
        strlen(command) >= MESSAGE_SIZE) {
            leave_instance(server, server->instance[index]);
            return;
        }
        strcat(server->instance[index]->buff_in, command);
    }
}

void select_command(server_t *server, instance_t *instance)
{
    char *command = strdup(instance->buff_in);
    char *tmp = strdup(instance->buff_in);
    size_t i = 0;

    tmp = strstr(tmp, "\n");
    memset(instance->buff_in, 0, 1024);
    strcpy(instance->buff_in, tmp + 1);
    for (; command[i] != '\n'; i++);
    command[i] = 0;
    exec_command(server, instance, command);
    free(command);
}

void send_message(instance_t *instance)
{
    char message[1024];
    output_t *current_output;

    if (TAILQ_FIRST(&instance->output) == NULL)
        return;
    current_output = pop_output(&instance->output);
    if (current_output == NULL)
        return;
    sprintf(message, "%s\n", current_output->message);
    write(instance->socket, message, strlen(message));
    free(current_output->message);
    free(current_output);
}

void do_client_action(server_t *server)
{
    for (int i = 0; i < MAX_INSTANCES; i++) {
        if (FD_ISSET(server->instance[i]->socket, &(server->readfds))) {;
            catch_client_message(i, server);
        }
    }
    for (int i = 0; i < MAX_INSTANCES; i++) {
        if (strstr(server->instance[i]->buff_in, "\n") != NULL) {
            select_command(server, server->instance[i]);
        }
    }
    for (int i = 0; i < MAX_INSTANCES; i++) {
        if (FD_ISSET(server->instance[i]->socket, &(server->writefds))) {
            send_message(server->instance[i]);
        }
    }
}
