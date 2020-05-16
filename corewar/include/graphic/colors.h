/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** colors
*/

#ifndef COLORS_H_
#define COLORS_H_

#include <SFML/Graphics/Color.h>

static const sfColor color_table[] =
{
    {255, 0, 0, 255},
    {0, 255, 0, 255},
    {0, 0, 255, 255},
    {255, 255, 0, 255},
    {255, 0, 255, 255},
    {0, 255, 255, 255},
    {255, 255, 255, 255},
};

static inline sfColor get_color_from_index(int index)
{
    int size = (int)(sizeof(color_table) / sizeof(sfColor));

    if (index >= size)
        return (sfWhite);
    return (color_table[index]);
}

#endif /* !COLORS_H_ */