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

static int update_color_height(char memory, char memory_dup,
        memory_3d_t *memory_3d, int color)
{
    if (!memory_3d)
        return 84;
    if (memory != memory_dup) {
        memory_3d->color = color;
        memory_3d->height = MAX_TILE_HEIGHT;
    } else
        --memory_3d->height;
    return 0;
}

int update_memory_3d(vm_t *vm, map_formatter_t *ter, champion_t *champion)
{
    int i = -1;
    int x = -1;
    int y = 0;
    int color = 0;

    if (!vm || !ter || get_champion_color(vm, champion, &color) == 84)
        return 84;
    while (++i < MEM_SIZE) {
        if (update_color_height(vm->memory[i], vm->memory_dup[i],
                &ter->map_3d[y][x], color) == 84)
            return 84;
        ter->map_2d[y][x] = project_iso_point(
                VEC3F(x, y, ter->map_3d[y][x].height),
                ter->map_settings.size, ter->map_settings.angles);
        if (i % ter->map_settings.size.x == 0) {
            x = -1;
            ++y;
        }
        ++x;
    } return 0;
}