/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** update
*/

#include "update_graphic.h"

void update_graphic(win_settings_t *sets, map_formatter_t *map)
{
    control_camera_view(*sets, map->map_settings);
    update_window_settings(sets);
    update_tile_map(map);
    draw_tile_map(sets, map);
    center_cam(sets, map);
}