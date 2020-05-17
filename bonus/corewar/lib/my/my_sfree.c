/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** Created by croquette
*/

#include <stdlib.h>

void *my_sfree(void *ptr)
{
    if (ptr)
        free(ptr);
    return NULL;
}
