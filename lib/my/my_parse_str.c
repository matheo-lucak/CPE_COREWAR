/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** converts a string into an array from its words
*/

#include <stdlib.h>
#include "my.h"

static size_t get_nb_words(const char *sentence, const char splitters[])
{
    size_t nb_words = 0;
    size_t idx = 0;

    while (sentence[idx] && my_is_char_in_str(splitters, sentence[idx]))
        idx += 1;
    while (sentence[idx]) {
        while (sentence[idx] && !my_is_char_in_str(splitters, sentence[idx]))
            idx += 1;
        while (sentence[idx] && my_is_char_in_str(splitters, sentence[idx]))
            idx += 1;
        nb_words += 1;
    }
    return (nb_words);
}

static char **fill_result(char *sentence, const char splitters[],
                            char **res, const bool freer)
{
    size_t idx = 0;
    size_t idx_res = 0;

    while (sentence[idx] && my_is_char_in_str(splitters, sentence[idx]))
        idx += 1;
    while (sentence[idx]) {
        res[idx_res] = my_strdup_until_list_c(&sentence[idx], splitters);
        while (sentence[idx] && !my_is_char_in_str(splitters, sentence[idx]))
            idx += 1;
        while (sentence[idx] && my_is_char_in_str(splitters, sentence[idx]))
            idx += 1;
        idx_res += 1;
    }
    if (sentence && freer)
        free(sentence);
    return (res);
}

char **my_parse_str(char *sentence, const char splitters[], const bool freer)
{
    char **res = NULL;
    size_t nb_words = 0;

    if (!sentence)
        return (NULL);
    nb_words = get_nb_words(sentence, splitters);
    if (!nb_words)
        return (NULL);
    res = malloc(sizeof(char *) * (nb_words + 1));
    if (!res)
        return (NULL);
    res[nb_words] = NULL;
    return (fill_result(sentence, splitters, res, freer));
}