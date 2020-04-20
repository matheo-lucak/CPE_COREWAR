/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** Appends a string to an array.
*/

#include <stdlib.h>
#include "my_inlines.h"

static char **get_new_array(char *to_append, const bool free_str)
{
    char **new = NULL;
    bool is_to_append = (to_append) ? true : false;

    new = malloc(sizeof(char *) * (is_to_append + 1));
    if (!new) {
        if (to_append && free_str)
            free(to_append);
        return (NULL);
    }
    if (is_to_append)
        new[0] = my_strdup(to_append);
    new[is_to_append] = NULL;
    if (to_append && free_str)
        free(to_append);
    return (new);
}

char **my_append_to_array(char **array, char *to_append,
                            const bool free_array,
                            const bool free_str)
{
    char **new = NULL;
    ssize_t len = my_arrlen(array);

    if (!array)
        return (get_new_array(to_append, free_str));
    if (!to_append)
        return (array);
    new = malloc(sizeof(char *) * (len + 2));
    if (!new)
        return (NULL);
    new[len + 1] = NULL;
    my_arrcpy(new, array);
    if (array && free_array)
        my_free_char_array(array);
    new[len] = my_strdup(to_append);
    if (to_append && free_str)
        free(to_append);
    return (new);
}