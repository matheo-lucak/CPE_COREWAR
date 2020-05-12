/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** vm.h
*/

#ifndef CPE_COREWAR_2019_VM_H
#define CPE_COREWAR_2019_VM_H

#include "op.h"
#include "setup.h"
#include "champion.h"

typedef struct virtual_machine_s
{
    int cycle_to_die;
    int count_live;
    int nbr_cycle_dump;
    char memory[MEM_SIZE];
    int nbr_champions;
    champion_t *champions;
    char **names;
} vm_t;

int get_names(char ***names, int nbr_champions,
        champion_t *champions, program_t *programs);

int get_champions(champion_t **champions, int nbr_champions,
        program_t *programs);

int init_vm(vm_t *vm, setup_t *setup);

int copy_memory_n_bytes(const char *memory, int *pc, void *dest, int n);

int write_memory_n_bytes(char *memory, int *pc, void *src, int n);

#endif //CPE_COREWAR_2019_VM_H
