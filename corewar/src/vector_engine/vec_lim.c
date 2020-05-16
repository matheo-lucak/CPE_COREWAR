/*
** EPITECH PROJECT, 2020
** Vector_engine
** File description:
** vec_lim
*/

#include <math.h>
#include <SFML/System/Vector2.h>

sfVector2f vec_lim(sfVector2f vec1, sfVector2f top_lim, sfVector2f bottom_lim)
{
    sfVector2f res = vec1;

    if (res.x > top_lim.x)
        res.x = top_lim.x;
    else if (res.x < bottom_lim.x)
        res.x = bottom_lim.x;
    if (res.y > top_lim.y)
        res.y = top_lim.y;
    else if (res.y < bottom_lim.y)
        res.y = bottom_lim.y;
    return (res);
}