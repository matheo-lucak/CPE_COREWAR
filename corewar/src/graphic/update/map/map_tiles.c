/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** map_tiles
*/

#include "update_graphic.h"
#include "vector_engine.h"

void update_tile(sfVertexArray *tile, sfVector3f point, int color,
                                                presets_t map_sets)
{

}

void update_tile_map(map_formatter_t *map)
{
    register size_t x = 0;
    register size_t y = 0;

    for (y = 0; y < map->map_settings.size.y; y += 1) {
        for (x = 0; x < map->map_settings.size.x; x += 1) {
            update_tile(map->tiles[y][x], VEC3F(x, y, map->map_3d[y][x].height),
                                    map->map_3d[y][x].color, map->map_settings);
        }
    }
}