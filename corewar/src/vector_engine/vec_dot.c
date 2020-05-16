/*
** EPITECH PROJECT, 2020
** Vector_engine
** File description:
** vec_dot
*/

#include <math.h>
#include <SFML/System/Vector2.h>

float vec_dot(sfVector2f vec1, sfVector2f vec2)
{
    return ((vec1.x * vec2.x) + (vec1.y * vec2.y));
}