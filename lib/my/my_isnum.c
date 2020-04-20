/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** checks if a char is numerical
*/

#include <stdbool.h>

bool my_isnum(const char c)
{
    return (c >= '0' && c <= '9') ? true : false;
}