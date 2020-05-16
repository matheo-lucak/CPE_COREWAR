/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** draw_map
*/

#include "graphic.h"

void draw_tile_map(win_settings_t *sets, map_formatter_t *map)
{
    register int x = 0;
    register int y = 0;

    while (y < map->map_settings.size.y) {
        for (x = 0; x < map->map_settings.size.x; x += 1) {
            sfRenderWindow_drawVertexArray(sets->window,
                                map->tiles[y][x], NULL);
        }
        y += 1;
    }
}