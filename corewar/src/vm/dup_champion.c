/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** dup_champion.c
*/

#include <stdlib.h>
#include "my.h"
#include "vm.h"
#include "champion.h"

static int check_used(champion_t *champions, int nbr_champions, int *id)
{
    int i = -1;

    if (!champions || !id)
        return 84;
    while (++i < nbr_champions) {
        if (champions[i].id == *id)
            ++*id;
    }
    return 0;
}

static int get_smallest_id(champion_t *champions, int nbr_champions,
        int *dest)
{
    int i = -1;
    int id = 0;

    if (!champions || !dest)
        return 84;
    while (++i < nbr_champions) {
        if (check_used(champions, nbr_champions, &id) == 84)
            return 84;
    }
    *dest = id;
    return 0;
}

int dup_champion(vm_t *vm, champion_t *champion, size_t index)
{
    program_t program = {0};

    if (!vm || !champion)
        return 84;
    program.load_address = index;
    if (get_smallest_id(vm->champions, vm->nbr_champions, &program.id) == 84)
        return 84;
    if (my_memcpy(champion->name, program.header.prog_name,
            PROG_NAME_LENGTH) == 84)
        return 84;
    ++vm->nbr_champions;
    ++vm->nbr_live_champions;
    if (!(vm->champions = realloc(vm->champions,
            sizeof(champion_t) * (vm->nbr_champions + 1))))
        return 84;
    my_memset(&vm->champions[vm->nbr_champions - 1], sizeof(champion_t), 0);
    if (get_champion(&vm->champions[vm->nbr_champions - 1], &program) == 84)
        return 84;
    return 0;
}
