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
        return 84;
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

static int reset_live(champion_t *champions, int nbr_champions, int id)
{
    int i = -1;

    if (!champions)
        return 84;
    while (++i < nbr_champions) {
        if (champions[i].id == id)
            champions[i].last_live = 0;
    }
    return 0;
}

int instruction_live(vm_t *vm, champion_t *champion)
{
    int id = 0;

    if (!vm || !champion)
        return 84;
    ++champion->pc;
    champion->pc %= MEM_SIZE;
    if (my_memcpy(&vm->memory[champion->pc], &id, 4) == 84)
        return 84;
    if (reset_live(vm->champions, vm->nbr_champions, id) == 84)
        return 84;
    if (print_live(champion) == 84)
        return 84;
    ++vm->count_live;
    vm->last_live = champion->id;
    champion->pc += 4;
    champion->pc %= MEM_SIZE;
    return 0;
}