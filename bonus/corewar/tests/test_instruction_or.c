/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_instruction_or
*/

#include <criterion/criterion.h>
#include "op.h"
#include "my.h"
#include "instruction.h"

Test(instruction_or, error_1)
{
    cr_assert(instruction_or(NULL, NULL) == 84);
}

Test(instruction_or, error_2)
{
    vm_t vm = {0};

    cr_assert(instruction_or(&vm, NULL) == 84);
}

Test(instruction_or, error_3)
{
    champion_t champion = {0};

    cr_assert(instruction_or(NULL, &champion) == 84);
}

Test(instruction_or, success_1)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x07\xa4\x00\x00\x00\x00\x00\x00\x00\x01\x01", vm.memory, 11);
    cr_assert(!instruction_or(&vm, &champion));
}

Test(instruction_or, success_1_1_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x05\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x07\xa4\x00\x00\x00\x00\x00\x00\x00\x01\x01", vm.memory, 11);
    if (instruction_or(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 1)) == 1);
}

Test(instruction_or, success_1_2_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x05\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x07\xa4\x00\x00\x00\x05\x00\x00\x00\x04\x01", vm.memory, 11);
    if (instruction_or(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 1)) == 5);
}

Test(instruction_or, success_2)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x05\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x05\x00\x00\x00", vm.memory + 9, REG_SIZE);
    my_memcpy("\x07\xb4\x00\x00\x00\x00\x00\x09\x01", vm.memory, 9);
    cr_assert(!instruction_or(&vm, &champion));
}

Test(instruction_or, success_2_1_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x05\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x05\x00\x00\x00", vm.memory + 9, REG_SIZE);
    my_memcpy("\x07\xb4\x00\x00\x00\x00\x00\x09\x01", vm.memory, 9);
    if (instruction_or(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 1)) == 5);
}

Test(instruction_or, success_2_2_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};
    champion.registers = malloc(REG_SIZE * 2);

    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x05\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    my_memcpy("\x05\x00\x00\x00", vm.memory + 9, REG_SIZE);
    my_memcpy("\x07\xb4\x00\x00\x00\x04\x00\x09\x01", vm.memory, 9);
    if (instruction_or(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 1)) == 5);
}