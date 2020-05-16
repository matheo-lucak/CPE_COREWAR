/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** draw_map
*/

#include "graphic.h"

static void tile_change_color(sfVertexArray *tile)
{
    sfVertex *vertex;
    size_t size = sfVertexArray_getVertexCount(tile);
    size_t index = 0;

    for (index = 0; index < size; index++) {
        vertex = sfVertexArray_getVertex(tile, index);
        if (!vertex)
            break;
        vertex->color = sfWhite;
    }
}

static void draw_tile(win_settings_t *sets, sfVertexArray *tile)
{
    if (!sets || !tile)
        return ;
    sfVertexArray_setPrimitiveType(tile, sfTriangleStrip);
    sfRenderWindow_drawVertexArray(sets->window, tile, NULL);
    tile_change_color(tile);
    sfVertexArray_setPrimitiveType(tile, sfLineStrip);
    sfRenderWindow_drawVertexArray(sets->window, tile, NULL);
}

void draw_tile_map(win_settings_t *sets, map_formatter_t *map)
{
    register int x = 0;
    register int y = 0;

    for (y = 0; y < map->map_settings.size.y; y += 1) {
        for (x = 0; x < map->map_settings.size.x; x += 1) {
            draw_tile(sets, map->tiles[y][x]);
        }
    }
}