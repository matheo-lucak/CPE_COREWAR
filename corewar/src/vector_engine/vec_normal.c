/*
** EPITECH PROJECT, 2020
** Vector_engine
** File description:
** vec_norm
*/

#include <math.h>
#include <SFML/System/Vector2.h>

float vec_mag(sfVector2f vec1);

sfVector2f vec_normal(sfVector2f vec1)
{
    return ((sfVector2f) {-vec1.y, vec1.x});
}