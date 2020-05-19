/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_instruction_st
*/

#include <criterion/criterion.h>
#include "op.h"
#include "my.h"
#include "instruction.h"

Test(instruction_st, error_1)
{
    cr_assert(instruction_st(NULL, NULL) == 84);
}

Test(instruction_st, error_2)
{
    vm_t vm = {0};

    cr_assert(instruction_st(&vm, NULL) == 84);
}

Test(instruction_st, error_3)
{
    champion_t champion = {0};

    cr_assert(instruction_st(NULL, &champion) == 84);
}

Test(instruction_st, success_1)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 3);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x00\x00\x00\x03", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x01\x0d\x05\x00", champion.registers + (REG_SIZE * 2),
                                                                    REG_SIZE);
    my_memcpy("\x03\x50\x01\x02", vm.memory, 4);
    cr_assert(!instruction_st(&vm, &champion));
}

Test(instruction_st, success_1_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 3);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x03\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x01\x0d\x05\x00", champion.registers + (REG_SIZE * 2),
                                                                    REG_SIZE);
    my_memcpy("\x03\x50\x01\x02", vm.memory, 4);
    if (instruction_st(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 2)) == 3);
}

Test(instruction_st, success_2_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x09\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x03\x70\x01\x00\x05", vm.memory, 5);
    if (instruction_st(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(vm.memory + 5) == 9);
}