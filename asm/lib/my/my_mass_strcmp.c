/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_mass_strcmp
*/

#include "my.h"

int my_mass_strcmp(char *template, char *comparators[])
{
    register size_t index = 0;

    while (comparators && comparators[index]) {
        if (!my_strcmp(template, comparators[index])) {
            return (index);
        }
        index += 1;
    }
    return (-1);
}

int my_mass_strncmp(char *template, char *comparators[])
{
    register size_t index = 0;

    while (comparators && comparators[index]) {
        if (!my_strncmp(template, comparators[index],
                    my_strlen(comparators[index]))) {
            return (index);
        }
        index += 1;
    }
    return (-1);
}