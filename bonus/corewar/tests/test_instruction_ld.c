/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_instruction_ld
*/

#include <criterion/criterion.h>
#include "op.h"
#include "my.h"
#include "instruction.h"

Test(instruction_ld, error_1)
{
    cr_assert(instruction_ld(NULL, NULL) == 84);
}

Test(instruction_ld, error_2)
{
    vm_t vm = {0};

    cr_assert(instruction_ld(&vm, NULL) == 84);
}

Test(instruction_ld, error_3)
{
    champion_t champion = {0};

    cr_assert(instruction_ld(NULL, &champion) == 84);
}

Test(instruction_ld, success_1)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    my_memcpy("\x02\xd0\x00\x00\x01", vm.memory, 5);
    if (!(champion.registers))
        cr_assert(0);
    cr_assert(!instruction_ld(&vm, &champion));
}

Test(instruction_ld, success_1_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x02\x00\x00\x00", vm.memory + 5, 4);
    my_memcpy("\x05\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x02\xd0\x00\x05\x01", vm.memory, 5);
    if (instruction_ld(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 1)) == 2);
}

Test(instruction_ld, success_2)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    my_memcpy("\x02\x90\x00\x00\x00\x01\x01", vm.memory, 7);
    if (!(champion.registers))
        cr_assert(0);
    cr_assert(!instruction_ld(&vm, &champion));
}

Test(instruction_ld, success_2_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x05\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x02\x90\x00\x00\x00\x01\x01", vm.memory, 7);
    if (instruction_ld(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 1)) == 1);
}