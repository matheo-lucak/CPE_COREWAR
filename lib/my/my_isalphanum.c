/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** checks if a char is alphanum
*/

#include "my.h"

bool my_isalphanum(const char c)
{
    return (my_isalpha(c) | my_isnum(c));
}