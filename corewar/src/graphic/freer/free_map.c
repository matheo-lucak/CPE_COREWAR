/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** free_map
*/

#include "free_graphic.h"
#include "my.h"

static void free_tile_map(map_formatter_t *map)
{
    int x = 0;
    int y = 0;

    if (!map)
        return ;
    for (y = 0; y < map->map_settings.size.y; y += 1) {
        for (x = 0; x < map->map_settings.size.x; x += 1) {
            sfVertexArray_destroy(map->tiles[y][x].tile[0]);
            sfVertexArray_destroy(map->tiles[y][x].tile[1]);
            sfVertexArray_destroy(map->tiles[y][x].tile[2]);
        }
        free(map->tiles[y]);
    }
    free(map->tiles);
}

void free_map(map_formatter_t *map)
{
    if (!map)
        return ;
    free_tile_map(map);
    my_free_array((void **)map->map_2d, map->map_settings.size.y);
    my_free_array((void **)map->map_3d, map->map_settings.size.y);
}