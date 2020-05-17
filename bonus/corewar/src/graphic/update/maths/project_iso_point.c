/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** project_iso_point
*/

#include "update_graphic.h"
#include "vector_engine.h"

sfVector2f project_iso_point(const sfVector3f pos_3d,
                            const sfVector2i map_size,
                            const sfVector2i angles)
{
    sfVector2f pos_2d;
    sfVector3f coeff = pos_3d;

    coeff.x = (pos_3d.x - (map_size.x / 2));
    coeff.y = (pos_3d.y - (map_size.y / 2));
    pos_2d.x = cos(RAD(angles.x)) * coeff.x;
    pos_2d.x -= sin(RAD(angles.x)) * coeff.y;
    pos_2d.y = sin(RAD(angles.y) + RAD(90)) * coeff.y;
    pos_2d.y += cos(RAD(angles.y)) * coeff.x - coeff.z;
    return (pos_2d);
}