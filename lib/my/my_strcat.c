/*
** EPITECH PROJECT, 2019
** library
** File description:
** Concats two strings.
*/

#include <stdlib.h>
#include "my.h"

static char *compute_concat(const char *first, const char *second,
                            const size_t len_fir, const size_t len_sec)
{
    char *result = NULL;
    int count_templates = 0;
    int count_res = 0;

    result = malloc(sizeof(char) * (len_fir + len_sec + 1));
    if (!result)
        return (NULL);
    while (first[count_templates]) {
        result[count_res] = first[count_templates];
        count_templates += 1;
        count_res += 1;
    }
    count_templates = 0;
    while (second[count_templates]) {
        result[count_res] = second[count_templates];
        count_templates += 1;
        count_res += 1;
    }
    result[count_res] = '\0';
    return (result);
}

char *my_strcat(char *first, char *second, const bool free_first,
                    const bool free_second)
{
    ssize_t len_fir = my_strlen(first);
    ssize_t len_sec = my_strlen(second);
    char *result = NULL;

    if (len_fir <= 0 || len_sec <= 0)
        result = (len_fir <= 0) ? my_strdup(second) : my_strdup(first);
    else
        result = compute_concat(first, second, len_fir, len_sec);
    if (first && free_first)
        free(first);
    if (second && free_second)
        free(second);
    return (result);
}