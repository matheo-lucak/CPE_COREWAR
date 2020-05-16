/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** map_tiles
*/

#include "update_graphic.h"
#include "vector_engine.h"
#include "my.h"

void update_vertices(sfVertex vertices[7], sfVector3f point, presets_t map_sets)
{
    vertices[0].position = project_iso_point(VEC3F(point.x, point.y + 1, 0), map_sets.size, map_sets.angles);
    vertices[1].position = project_iso_point(VEC3F(point.x + 1, point.y + 1, 0), map_sets.size, map_sets.angles);
    vertices[2].position = project_iso_point(VEC3F(point.x, point.y + 1, point.z), map_sets.size, map_sets.angles);
    vertices[3].position = project_iso_point(VEC3F(point.x + 1, point.y + 1, point.z), map_sets.size, map_sets.angles);
    vertices[4].position = project_iso_point(VEC3F(point.x, point.y, point.z), map_sets.size, map_sets.angles);
    vertices[5].position = project_iso_point(VEC3F(point.x + 1, point.y, point.z), map_sets.size, map_sets.angles);
    vertices[6].position = project_iso_point(VEC3F(point.x + 1, point.y, 0), map_sets.size, map_sets.angles);
}

void update_tile(sfVertexArray *tile, sfVector3f point, int color,
                                                presets_t map_sets)
{
    sfVertex vertices[7] = {0};
    register size_t index = 0;

    if (!tile)
        return ;
    sfVertexArray_clear(tile);
    update_vertices(vertices, point, map_sets);
    for (; index < 7; index += 1) {
        vertices[index].color = sfGreen;
        vertices[index].texCoords = VEC2F(0, 0);
        sfVertexArray_append(tile, vertices[index]);
    }
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