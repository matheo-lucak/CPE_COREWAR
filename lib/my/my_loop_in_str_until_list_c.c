/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my_loop_in_str_until_list_c.c
*/

#include "my.h"

bool my_loop_in_str_until_list_c(const char *str, const char cmp[],
                                    size_t *index)
{
    bool return_value = false;

    if (!str)
        return (false);
    while (str[(*index)] && !my_is_char_in_str(cmp, str[(*index)])) {
        return_value = true;
        (*index) += 1;
    }
    return (return_value);
}