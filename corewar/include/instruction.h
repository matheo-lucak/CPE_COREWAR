/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** instruction.h
*/

#ifndef CPE_COREWAR_2019_INSTRUCTION_H
#define CPE_COREWAR_2019_INSTRUCTION_H

#include "vm.h"
#include "champion.h"

int instruction_add(vm_t *vm, champion_t *champion);

int instruction_aff(vm_t *vm, champion_t *champion);

int instruction_and(vm_t *vm, champion_t *champion);

int instruction_fork(vm_t *vm, champion_t *champion);

int instruction_ld(vm_t *vm, champion_t *champion);

int instruction_ldi(vm_t *vm, champion_t *champion);

int instruction_lfork(vm_t *vm, champion_t *champion);

int instruction_live(vm_t *vm, champion_t *champion);

int instruction_lld(vm_t *vm, champion_t *champion);

int instruction_lldi(vm_t *vm, champion_t *champion);

int instruction_or(vm_t *vm, champion_t *champion);

int instruction_st(vm_t *vm, champion_t *champion);

int instruction_sti(vm_t *vm, champion_t *champion);

int instruction_sub(vm_t *vm, champion_t *champion);

int instruction_xor(vm_t *vm, champion_t *champion);

int instruction_zjmp(vm_t *vm, champion_t *champion);

typedef int(*instruction_func_t)(vm_t *vm, champion_t *champion);

#endif //CPE_COREWAR_2019_INSTRUCTION_H
