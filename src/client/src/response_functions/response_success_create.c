/*
** EPITECH PROJECT, 2023
** myteams-mirror
** File description:
** success_create
*/

#include "response_server.h"
#include <time.h>

void success_create_team(char **args)
{
    if (args[1] == NULL || args[2] == NULL || args[3] == NULL)
        return;
    client_print_team_created(args[1], args[2], args[3]);
}

void success_create_channel(char **args)
{
    if (args[1] == NULL || args[2] == NULL || args[3] == NULL)
        return;
    printf("channel created\n");
    client_print_channel_created(args[1], args[2], args[3]);
}

int parse_ctime_string(const char *ctime_str, struct tm *tm)
{
    const char *months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    char month_str[4];
    int month, day, hour, minute, second, year;
    int res = sscanf(ctime_str, "%*s %3s %d %d:%d:%d %d",
        month_str, &day, &hour, &minute, &second, &year);
    if (res != 6)
        return -1;
    for (month = 0; month < 12; ++month)
        if (strncmp(months[month], month_str, 3) == 0)
            break;
    if (month == 12)
        return -1;
    tm->tm_year = year - 1900;
    tm->tm_mon = month;
    tm->tm_mday = day;
    tm->tm_hour = hour;
    tm->tm_min = minute;
    tm->tm_sec = second;
    return 0;
}

void success_create_thread(char **args)
{
    struct tm tm;
    time_t timestamp;

    if (args[1] == NULL || args[2] == NULL || args[3] == NULL
    || args[4] == NULL || args[5] == NULL)
        return;
    if (parse_ctime_string(args[3], &tm) == 0) {
        timestamp = mktime(&tm);
        if (timestamp != (time_t)(-1)) {
            printf("time_t: %ld\n", (long)timestamp);
        } else {
            printf("Erreur lors de la conversion en time_t\n");
        }
    } else {
        printf("Erreur lors de l'analyse de la chaîne ctime\n");
    }

    client_print_thread_created(args[1], args[2], timestamp, args[4], args[5]);
}

void success_create_reply(char **args)
{
    struct tm tm;
    time_t timestamp;

    if (args[1] == NULL || args[2] == NULL || args[3] == NULL
    || args[4] == NULL)
        return;
    if (parse_ctime_string(args[3], &tm) == 0) {
        timestamp = mktime(&tm);
        if (timestamp != (time_t)(-1)) {
            printf("time_t: %ld\n", (long)timestamp);
        } else {
            printf("Erreur lors de la conversion en time_t\n");
        }
    } else {
        printf("Erreur lors de l'analyse de la chaîne ctime\n");
    }

    client_print_reply_created(args[1], args[2], timestamp, args[4]);
}
