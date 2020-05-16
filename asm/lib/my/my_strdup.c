/*
** EPITECH PROJECT, 2019
** str dup
** File description:
** str dup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *src)
{
    char *str = NULL;

    if (!src)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (!str)
        return (NULL);
    my_strcpy(str, src);
    return (str);
}

char *my_quoted_strdup(const char *src, char quote)
{
    int frst_quote_idx = 0;
    int scnd_quote_idx = 0;

    if (!src)
        return (NULL);
    frst_quote_idx = my_find_char(src, quote);
    if (frst_quote_idx == -1)
        return (NULL);
    scnd_quote_idx = my_find_char(src + frst_quote_idx + 1, quote);
    if (scnd_quote_idx == -1 || scnd_quote_idx == frst_quote_idx)
        return (NULL);
    return (my_strndup(src + frst_quote_idx + 1,
            scnd_quote_idx - frst_quote_idx));
}