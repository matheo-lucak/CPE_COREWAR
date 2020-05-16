/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** vec_angle
*/

#include "math.h"
#include "vector_engine.h"

float vec_angle(sfVector2f vec1, sfVector2f vec2)
{
    float magn1 = vec_mag(vec1);
    float magn2 = vec_mag(vec2);
    float angle = 0;

    if (!magn1 || !magn2)
        return (0);
    angle = (vec_dot(vec1, vec2) / (magn1 * magn2));
    angle = acos(angle);
    return (angle * 180 / M_PI);
}