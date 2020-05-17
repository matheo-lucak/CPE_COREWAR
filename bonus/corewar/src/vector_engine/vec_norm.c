/*
** EPITECH PROJECT, 2020
** Vector_engine
** File description:
** vec_norm
*/

#include <math.h>
#include <SFML/System/Vector2.h>

float vec_mag(sfVector2f vec1);

sfVector2f vec_norm(sfVector2f vec1)
{
    sfVector2f res = {0, 0};
    float mag = vec_mag(vec1);

    if (mag) {
        res.x = vec1.x / mag;
        res.y = vec1.y / mag;
    }
    return (res);
}