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
#include "instruction_codes.h"

static int decrease_height(memory_3d_t *memory_3d, int cycle_to_die)
{
    float decrease_rate = 0;

    if (!memory_3d)
        return 84;
    if (cycle_to_die > 0)
        decrease_rate = MAX_TILE_HEIGHT / (float)cycle_to_die;
    else
        decrease_rate = 0.1;
    if (memory_3d->height > 0)
        memory_3d->height -= decrease_rate;
    return 0;
}

int decrease_memory_3d_height(map_formatter_t *map, vm_t *vm)
{
    int y = 0;
    int x = 0;

    for (y = 0; y < map->map_settings.size.y; y += 1) {
        for (x = 0; x < map->map_settings.size.x; x += 1) {
            if (decrease_height(&map->map_3d[y][x], vm->cycle_to_die) == 84)
                return 84;
            map->map_2d[y][x] = project_iso_point(
            VEC3F(x, y, map->map_3d[y][x].height),
                map->map_settings.size, map->map_settings.angles);
        }
    }
    return 0;
}

static int update_color_height(memory_3d_t *memory_3d, int color)
{
    if (!memory_3d)
        return 84;
    memory_3d->color = color;
    memory_3d->height = MAX_TILE_HEIGHT;
    return 0;
}

static int update_size_memory(map_formatter_t *map, sfVector2i pos,
        size_t size, int color)
{
    size_t i = -1;

    if (!map)
        return 84;
    pos = D1TOD2(size, map->map_settings.size.x);
    while (++i < size) {
        if (update_color_height(&map->map_3d[pos.y][pos.x], color) == 84)
            return 84;
        map->map_2d[pos.y][pos.x] = project_iso_point(
                VEC3F(pos.x, pos.y, map->map_3d[pos.y][pos.x].height),
                map->map_settings.size, map->map_settings.angles);
        if (pos.x == map->map_settings.size.x) {
            ++pos.y;
            pos.x = -1;
        }
        ++pos.x;
    }
    return 0;
}

int update_memory_3d(vm_t *vm, map_formatter_t *map, champion_t *champion,
        int tmp_pc)
{
    int color = 0;
    instr_code_t code = 0;
    size_t size = 0;
    sfVector2i pos = {0};

    if (!vm || !map || get_champion_color(vm, champion, &color) == 84)
        return 84;
    pos = D1TOD2(champion->pc, map->map_settings.size.x);
    if (pos.x >= map->map_settings.size.x || pos.y >= map->map_settings.size.y)
        return 0;
    code = (instr_code_t)vm->memory[tmp_pc] - 1;
    if (code == i_fork || code == i_lfork || code == i_zjmp)
        size = 1;
    else
        size = champion->pc - tmp_pc + ((champion->pc < tmp_pc) ? MEM_SIZE : 0);
    map->map_3d[pos.y][pos.x].is_live = (code == i_live) ? true : false;
    if (update_size_memory(map, pos, size, color) == 84)
        return 84;
    return 0;
}