/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_map
*/

#include <stdlib.h>
#include <math.h>
#include "op.h"
#include "my.h"
#include "init_graphic.h"

static bool init_map_3d(map_formatter_t *map)
{
    int index = 0;

    map->map_3d = malloc(sizeof(float) * map->map_settings.size.y);
    if (!(map->map_3d))
        return (false);
    for (; index < map->map_settings.size.y; index += 1) {
        map->map_3d[index] = malloc(sizeof(float) * map->map_settings.size.x);
        if (!(map->map_3d[index]))
            return (false);
        my_memset(map->map_3d[index], 0,
                                    sizeof(float) * map->map_settings.size.x);
    }
    return (true);
}

static bool init_map_2d(map_formatter_t *map)
{
    int index = 0;

    map->map_2d = malloc(sizeof(sfVector2f) * map->map_settings.size.y);
    if (!(map->map_2d))
        return (false);
    for (; index < map->map_settings.size.y; index += 1) {
        map->map_2d[index] = malloc(sizeof(sfVector2f) *
                                                    map->map_settings.size.x);
        if (!(map->map_2d[index]))
            return (false);
        my_memset(map->map_2d[index], 0,
                                    sizeof(sfVector2f) *
                                                    map->map_settings.size.x);
    }
    return (true);
}

static bool init_map_size(map_formatter_t *map)
{
    float side_lenght = sqrt((double)MEM_SIZE);

    map->map_settings.size.x = (int)side_lenght;
    map->map_settings.size.y = (int)side_lenght;
    return (true);
}

bool init_map(map_formatter_t *map)
{
    if (!map)
        return (sfFalse);
    my_memset((void *)map, sizeof(map_formatter_t), 0);
    init_map_size(map);
    if (!init_map_3d(map) ||
        !init_map_2d(map) ||
        !init_map_tiles(map))
        return (false);
    return (true);
}