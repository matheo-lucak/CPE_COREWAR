/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** update_memory_3d.c
*/

#include "op.h"
#include "champion.h"
#include "graphic.h"
#include "update_graphic.h"
#include "vector_engine.h"
#include "vm.h"

static int update_color_height(char memory_diff,
        memory_3d_t *memory_3d, int color, int cycle_to_die)
{
    float decrease_rate = 0;

    if (!memory_3d)
        return 84;
    if (cycle_to_die > 0)
        decrease_rate = MAX_TILE_HEIGHT / (float)cycle_to_die;
    else
        decrease_rate = 0.1;
    if (memory_diff) {
        memory_3d->color = color;
        memory_3d->height = MAX_TILE_HEIGHT;
    } else if (memory_3d->height > 0)
        memory_3d->height -= decrease_rate;
    return 0;
}

int update_memory_3d(vm_t *vm, map_formatter_t *map, champion_t *champion)
{
    int x = 0;
    int y = 0;
    int color = 0;
    int i = 0;

    if (!vm || !map || get_champion_color(vm, champion, &color) == 84)
        return 84;
    for (y = 0; y < map->map_settings.size.y; y += 1) {
        for (x = 0; x < map->map_settings.size.x; x += 1) {
            i = D2TOD1(x, y, map->map_settings.size.x);
            if (update_color_height(vm->memory[i] - vm->memory_dup[i],
                &map->map_3d[y][x], color, vm->cycle_to_die) == 84)
            return 84;
            map->map_2d[y][x] = project_iso_point(
                VEC3F(x, y, map->map_3d[y][x].height),
                map->map_settings.size, map->map_settings.angles);
        }
    }
    return 0;
}