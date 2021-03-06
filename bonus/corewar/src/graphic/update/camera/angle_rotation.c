/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** angle_rotation
*/

#include "graphic.h"

void rotate_up(presets_t *map_settings, sfBool *changed)
{
    if (map_settings->angles.y == 90)
        return;
    map_settings->angles.y += map_settings->rotation_speed.y;
    *changed = sfTrue;
}

void rotate_down(presets_t *map_settings, sfBool *changed)
{
    if (map_settings->angles.y == 45)
        return;
    map_settings->angles.y -= map_settings->rotation_speed.y;
    *changed = sfTrue;
}

void rotate_left(presets_t *map_settings, sfBool *changed)
{
    if (map_settings->angles.x == 0)
        return;
    map_settings->angles.x -= map_settings->rotation_speed.x;
    *changed = sfTrue;
}

void rotate_right(presets_t *map_settings, sfBool *changed)
{
    if (map_settings->angles.x == 90)
        return;
    map_settings->angles.x += map_settings->rotation_speed.x;
    *changed = sfTrue;
}