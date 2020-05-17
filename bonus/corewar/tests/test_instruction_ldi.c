/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_instruction_ldi
*/

#include <criterion/criterion.h>
#include "op.h"
#include "my.h"
#include "instruction.h"

Test(instruction_ldi, error_1)
{
    cr_assert(instruction_ldi(NULL, NULL) == 84);
}

Test(instruction_ldi, error_2)
{
    vm_t vm = {0};

    cr_assert(instruction_ldi(&vm, NULL) == 84);
}

Test(instruction_ldi, error_3)
{
    champion_t champion = {0};

    cr_assert(instruction_ldi(NULL, &champion) == 84);
}

Test(instruction_ldi, success_1)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    my_memcpy("\x0a\xe4\x00\x03\x00\x04\x01", vm.memory, 7);
    if (!(champion.registers))
        cr_assert(0);
    cr_assert(!instruction_ldi(&vm, &champion));
}

Test(instruction_ldi, success_1_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x0a\xe4\x00\x07\x00\x0a\x01", vm.memory, 7);
    my_memcpy("\x02\x00\x00\x00", vm.memory + 7, 4);
    my_memcpy("\x05\x00\x00\x00", vm.memory + 12, 4);
    my_memcpy("\x01\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    if (instruction_ldi(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 1)) == 5);
}

Test(instruction_ldi, success_2_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x0a\xa4\x00\x0a\x00\x0b\x01", vm.memory, 7);
    my_memcpy("\x05\x00\x00\x00", vm.memory + 21, 4);
    my_memcpy("\x01\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    if (instruction_ldi(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 1)) == 5);
}

Test(instruction_ldi, success_3_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 3);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x0a\x94\x00\x03\x02\x01", vm.memory, 6);
    my_memcpy("\x12\x00\x00\x00", champion.registers + (REG_SIZE * 2),
                                                                REG_SIZE);
    my_memcpy("\x05\x00\x00\x00", vm.memory + 21, 4);
    my_memcpy("\x01\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    if (instruction_ldi(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(*(int *)(champion.registers + (REG_SIZE * 1)) == 5);
}