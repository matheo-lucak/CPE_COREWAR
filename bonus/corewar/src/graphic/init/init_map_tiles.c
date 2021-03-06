/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_map_tiles
*/

#include <stdlib.h>
#include <math.h>
#include "op.h"
#include "my.h"
#include "graphic.h"

static bool init_tiles(tile_t *tile_line, size_t width)
{
    size_t index = 0;

    if (!tile_line)
        return (false);
    for (; index < width; index += 1) {
        tile_line[index].color = sfWhite;
        tile_line[index].tile[0] = sfVertexArray_create();
        tile_line[index].tile[1] = sfVertexArray_create();
        tile_line[index].tile[2] = sfVertexArray_create();
        if (!(tile_line[index].tile[0]) ||
            !(tile_line[index].tile[1]) ||
            !(tile_line[index].tile[2]))
            return (false);
    }
    return (true);
}

bool init_map_tiles(map_formatter_t *map)
{
    int index = 0;

    map->tiles = malloc(sizeof(tile_t *) * map->map_settings.size.y);
    if (!(map->tiles))
        return (false);
    for (; index < map->map_settings.size.y; index += 1) {
        map->tiles[index] = malloc(sizeof(tile_t) * map->map_settings.size.x);
        if (!(map->tiles[index]) ||
            !init_tiles(map->tiles[index], map->map_settings.size.x))
            return (false);
    }
    return (true);
}