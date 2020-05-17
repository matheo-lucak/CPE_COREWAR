/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_instruction_zjmp
*/

#include <criterion/criterion.h>
#include "op.h"
#include "my.h"
#include "instruction.h"

Test(instruction_zjmp, error_1)
{
    cr_assert(instruction_zjmp(NULL, NULL) == 84);
}

Test(instruction_zjmp, error_2)
{
    vm_t vm = {0};

    cr_assert(instruction_zjmp(&vm, NULL) == 84);
}

Test(instruction_zjmp, error_3)
{
    champion_t champion = {0};

    cr_assert(instruction_zjmp(NULL, &champion) == 84);
}

Test(instruction_zjmp, success_1)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.carry = 1;
    my_memcpy("\x09\x00\x05", vm.memory, 3);
    cr_assert(!instruction_zjmp(&vm, &champion));
}

Test(instruction_zjmp, success_1_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.carry = 1;
    my_memcpy("\x09\x00\x05", vm.memory, 3);
    if (instruction_zjmp(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(champion.pc == 5);
}

Test(instruction_zjmp, success_2_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.carry = 1;
    my_memcpy("\x09\xFF\xFD", vm.memory, 3);
    if (instruction_zjmp(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(champion.pc == MEM_SIZE - 3);
}

Test(instruction_zjmp, success_3_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.carry = 1;
    champion.pc = MEM_SIZE - 10;
    my_memcpy("\x09\x00\x0b", vm.memory + champion.pc, 3);
    if (instruction_zjmp(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert(champion.pc == 1);
}