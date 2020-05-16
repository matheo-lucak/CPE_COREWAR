/*
** EPITECH PROJECT, 2020
** csfml_physics
** File description:
** vector_cross
*/

#include <math.h>
#include <SFML/System/Vector2.h>

float vec_cross(sfVector2f vec1, sfVector2f vec2)
{
    return (vec1.x * vec2.y - vec1.y * vec2.x);
}