/*
** EPITECH PROJECT, 2020
** My_lib
** File description:
** my_strdup_word
*/

#include "my.h"

static size_t get_first_letter(const char *src)
{
    register size_t index = 0;

    while (src[index] && !my_is_alpha_num(src[index])) {
        index += 1;
    }
    return (index);
}

static size_t get_word_len(const char *src)
{
    register size_t index = 0;

    while (src[index] && my_is_alpha_num(src[index])) {
        index += 1;
    }
    return (index);
}

char *my_strdup_word(const char *src)
{
    register size_t index = 0;
    register size_t len = 0;

    if (!src)
        return (NULL);
    index = get_first_letter(src);
    len = get_word_len(src + index);
    if (!len)
        return (NULL);
    return (my_strndup(src + index, len));
}