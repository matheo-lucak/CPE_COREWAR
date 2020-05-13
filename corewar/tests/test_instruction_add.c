/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_instruction_add
*/

#include <criterion/criterion.h>
#include "op.h"
#include "my.h"
#include "instruction.h"

Test(instruction_add, error_1)
{
    cr_assert(instruction_add(NULL, NULL) == 84);
}

Test(instruction_add, error_2)
{
    vm_t vm = {0};

    cr_assert(instruction_add(&vm, NULL) == 84);
}

Test(instruction_add, error_3)
{
    champion_t champion = {0};

    cr_assert(instruction_add(NULL, &champion) == 84);
}

Test(instruction_add, success_1)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 3);
    my_memcpy("\x04\x54\x01\x02\x03", vm.memory, 5);
    if (!(champion.registers))
        cr_assert(0);
    cr_assert(!instruction_add(&vm, &champion));
}

Test(instruction_add, success_1_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 3);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x00\x00\x00\x05", champion.registers, REG_SIZE);
    my_memcpy("\x00\x00\x00\x02", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x00\x00\x00\x00", champion.registers + (REG_SIZE * 2),
                                                                    REG_SIZE);
    my_memcpy("\x04\x54\x01\x02\x03", vm.memory, 5);
    if (instruction_add(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 2)) == 7);
}