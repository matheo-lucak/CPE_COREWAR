/*
** EPITECH PROJECT, 2020
** Vector_engine
** File description:
** vector_mag
*/

#include <math.h>
#include <SFML/System/Vector2.h>

float vec_mag(sfVector2f vec1)
{
    float mag = 0;

    if (!vec1.x && !vec1.y)
        return (0);
    mag = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y));
    return (mag);
}