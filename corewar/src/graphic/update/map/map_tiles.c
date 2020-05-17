/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** map_tiles
*/

#include "update_graphic.h"
#include "vector_engine.h"
#include "tiles_template.h"
#include "colors.h"
#include "my.h"

static sfColor fade_color(sfColor color, float height)
{
    float ratio = height / MAX_TILE_HEIGHT;

    if (ratio <= 0.5)
        ratio = 0.5;
    color.r *= ratio;
    color.g *= ratio;
    color.b *= ratio;
    return (color);
}

static void update_tile(tile_t *tile, sfVector3f point, memory_3d_t mem_3d,
                                                        presets_t map_sets)
{
    sfVertex vertices[3][4] = {0};
    register size_t index = 0;
    register size_t side = 0;
    sfColor color = get_color_from_index(mem_3d.color);

    if (!tile)
        return;
    color = fade_color(color, point.z);
    tile->is_live = mem_3d.is_live;
    for (side = 0; side < 3; side++) {
        sfVertexArray_clear(tile->tile[side]);
        for (index = 0; index < 4; index += 1) {
            vertices[side][index].position = compute_vertex_pos(point, map_sets,
                                                                side, index);
            vertices[side][index].color = color;
            vertices[side][index].texCoords = VEC2F(0, 0);
            sfVertexArray_append(tile->tile[side], vertices[side][index]);
        }
    }
}

void update_tile_map(map_formatter_t *map)
{
    register int x = 0;
    register int y = 0;

    for (y = 0; y < map->map_settings.size.y; y += 1) {
        for (x = 0; x < map->map_settings.size.x; x += 1) {
            update_tile(&(map->tiles[y][x]),
                        VEC3F(x, y, map->map_3d[y][x].height),
                        map->map_3d[y][x], map->map_settings);
        }
    }
}