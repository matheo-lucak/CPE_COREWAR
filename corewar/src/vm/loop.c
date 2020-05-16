/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** loop.c
*/

#include "graphic.h"
#include "vm.h"

static int check_cycle_to_die(int *count_live, int *cycle_to_die)
{
    if (!count_live || !cycle_to_die)
        return 84;
    if (*count_live >= NBR_LIVE) {
        *cycle_to_die -= CYCLE_DELTA;
        *count_live = 0;
    }
    return 0;
}

static int exec_loop(vm_t *vm, map_formatter_t *map, int cycle)
{
    if (cycle == vm->nbr_cycle_dump &&
        dump_memory(vm->memory) == 84)
        return 84;
    if (execute_instructions(vm, map) == 84)
        return 84;
    if (check_live_champions(vm) == 84)
        return 84;
    if (check_cycle_to_die(&vm->count_live, &vm->cycle_to_die) == 84)
        return 84;
    return (0);
}

int loop(vm_t *vm)
{
    int cycle = 0;
    win_settings_t sets;
    map_formatter_t map;

    if (!vm || !init_map(&map) || !init_win_settings(&sets))
        return 84;
    while (vm->nbr_live_champions > 0) {
        sfRenderWindow_clear(sets.window, sfBlack);
        if (exec_loop(vm, &map, cycle) == 84)
            return (84);
        ++cycle;
        update_graphic(&sets, &map);
        sfRenderWindow_display(sets.window);
    }
    free_ressources(&sets, &map);
    return 0;
}