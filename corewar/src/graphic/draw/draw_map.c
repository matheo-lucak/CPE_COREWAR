/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** draw_map
*/

#include "graphic.h"

static void tile_change_color(sfVertexArray *tile)
{
    register size_t size = sfVertexArray_getVertexCount(tile);
    register size_t index = 0;
    sfVertex *vertex = NULL;

    for (index = 0; index < size; index++) {
        vertex = sfVertexArray_getVertex(tile, index);
        if (!vertex)
            break;
        vertex->color = sfWhite;
    }
}

static void draw_tile(win_settings_t *sets, tile_t tile)
{
    size_t side = 0;

    if (!sets)
        return ;
    for (side = 0; side < 3; side += 1) {
        sfVertexArray_setPrimitiveType(tile.tile[side], sfQuads);
        sfRenderWindow_drawVertexArray(sets->window, tile.tile[side], NULL);
    }
    for (side = 0; side < 3; side += 1) {
        tile_change_color(tile.tile[side]);
        sfVertexArray_setPrimitiveType(tile.tile[side], sfLineStrip);
        sfRenderWindow_drawVertexArray(sets->window, tile.tile[side], NULL);
    }
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