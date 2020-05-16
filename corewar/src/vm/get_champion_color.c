/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** get_champion_color.c
*/

#include "my.h"
#include "vm.h"

int get_champion_color(vm_t *vm, champion_t *champion, int *color)
{
    int i = -1;

    if (!vm || !champion || !color)
        return 84;
    while (++i < vm->nbr_champions) {
        if (!my_strcmp(vm->names[i], champion->name)) {
            *color = i;
            return 0;
        }
    }
    return 0;
}