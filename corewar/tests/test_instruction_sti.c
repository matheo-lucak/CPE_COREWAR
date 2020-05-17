/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_instruction_sti
*/

#include <criterion/criterion.h>
#include "op.h"
#include "my.h"
#include "instruction.h"

Test(instruction_sti, error_1)
{
    cr_assert(instruction_sti(NULL, NULL) == 84);
}

Test(instruction_sti, error_2)
{
    vm_t vm = {0};

    cr_assert(instruction_sti(&vm, NULL) == 84);
}

Test(instruction_sti, error_3)
{
    champion_t champion = {0};

    cr_assert(instruction_sti(NULL, &champion) == 84);
}

Test(instruction_sti, success_1)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 3);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x03\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x0a\x00\x00\x00", champion.registers + (REG_SIZE * 2),
                                                                    REG_SIZE);
    my_memcpy("\x02\x00\x00\x00", vm.memory + 20, 4);
    my_memcpy("\x0b\x58\x01\x02\x00\x0a", vm.memory, 6);
    cr_assert(!instruction_sti(&vm, &champion));
}

Test(instruction_sti, success_1_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 3);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x0a\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x04\x00\x00\x00", champion.registers + (REG_SIZE * 2),
                                                                    REG_SIZE);
    my_memcpy("\x0b\x58\x01\x02\x00\x02", vm.memory, 6);
    if (instruction_sti(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(vm.memory + 6 + 6) == 10);
}

Test(instruction_sti, success_2_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 4);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x0a\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x04\x00\x00\x00", champion.registers + (REG_SIZE * 2),
                                                                    REG_SIZE);
    my_memcpy("\x04\x00\x00\x00", champion.registers + (REG_SIZE * 3),
                                                                    REG_SIZE);
    my_memcpy("\x0b\x54\x01\x02\x03", vm.memory, 5);
    if (instruction_sti(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(vm.memory + 8 + 5) == 10);
}

Test(instruction_sti, success_3_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x0a\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x04\x00\x00\x00", vm.memory + 20, 2);
    my_memcpy("\x0b\x78\x01\x00\x14\x00\x0a", vm.memory, 7);
    if (instruction_sti(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(vm.memory + 14 + 7) == 10);
}

Test(instruction_sti, success_4_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 3);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x0a\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x0a\x00\x00\x00", champion.registers + (REG_SIZE * 2),
                                                                    REG_SIZE);
    my_memcpy("\x04\x00\x00\x00", vm.memory + 20, 2);
    my_memcpy("\x0b\x74\x01\x00\x14\x02", vm.memory, 6);
    if (instruction_sti(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(vm.memory + 14 + 6) == 10);
}