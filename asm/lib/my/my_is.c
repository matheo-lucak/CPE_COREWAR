/*
** EPITECH PROJECT, 2019
** env
** File description:
** func for env
*/

#include "my.h"

bool my_is_num(char c)
{
    if (c >= '0' && c <= '9' || c == '-' || c == '+')
        return (true);
    return (false);
}

bool my_is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (true);
    return (false);
}

bool my_is_caps_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (true);
    return (false);
}

bool my_is_alpha_num(char c)
{
    if (my_is_num(c) ||
        my_is_alpha(c) ||
        my_is_caps_alpha(c))
        return (true);
    return (false);
}

bool my_str_is(const char *str, bool (*func)(char))
{
    register size_t index = 0;

    if (!str || !func)
        return (false);
    while (str[index]) {
        if (!func(str[index]))
            return (false);
        index += 1;
    }
    return (true);
}