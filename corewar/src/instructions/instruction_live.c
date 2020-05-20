/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instr_live.c
*/

#include "my.h"
#include "vm.h"
#include "champion.h"

static int print_name(char *name)
{
    int i = -1;

    while (++i < PROG_NAME_LENGTH && name[i]) {
        if (my_putchar(name[i]) == 84)
            return 84;
    }
    return 0;
}

static int print_live(champion_t *champion)
{
    if (!champion)
        return 0;
    champion->last_live = 0;
    if (my_putstr("The player ") == 84)
        return 84;
    if (my_put_signed_long_base(champion->id, "0123456789") == 84)
        return 84;
    if (my_putchar('(') == 84)
        return 84;
    if (print_name(champion->name) == 84)
        return 84;
    if (my_putstr(") is alive.\n") == 84)
        return 84;
    return 0;
}

static int get_live_champion(champion_t *champions, int nbr_champions,
        champion_t **live, int id)
{
    int i = -1;

    if (!champions)
        return 84;
    while (++i < nbr_champions) {
        if (champions[i].id == id)
            *live = &champions[i];
    }
    return 0;
}

int instruction_live(vm_t *vm, champion_t *champion)
{
    int id = 0;
    champion_t *live = NULL;

    if (!vm || !champion)
        return 84;
    champion->pc = increment_pc(champion->pc, 1);
    if (copy_memory_n_bytes(vm->memory, &champion->pc, &id, 4) == 84)
        return 84;
    if (get_live_champion(vm->champions, vm->nbr_champions, &live, id) == 84)
        return 84;
    if (print_live(live) == 84)
        return 84;
    ++vm->count_live;
    vm->last_live = champion->id;
    return 0;
}