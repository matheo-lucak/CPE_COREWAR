/*
** EPITECH PROJECT, 2019
** Libmy Guillaume BOGARD-COQUARD 2019
** File description:
** Inlines for libmy.
*/

#ifndef MY_INLINES_H_
#define MY_INLINES_H_

#include "my.h"

static inline void my_free_char_array(char **array)
{
    my_free_2d((void **)array);
}

static inline void my_free_int_array(int **array)
{
    my_free_2d((void **)array);
}


#endif /* MY_INLINES_H_ */