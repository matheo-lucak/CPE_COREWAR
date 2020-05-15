/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_instruction_aff
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "op.h"
#include "my.h"
#include "instruction.h"

Test(instruction_aff, error_1)
{
    cr_assert(instruction_aff(NULL, NULL) == 84);
}

Test(instruction_aff, error_2)
{
    vm_t vm = {0};

    cr_assert(instruction_aff(&vm, NULL) == 84);
}

Test(instruction_aff, error_3)
{
    champion_t champion = {0};

    cr_assert(instruction_aff(NULL, &champion) == 84);
}

Test(instruction_aff, success_1)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    my_memcpy("\x10\x40\x01", vm.memory, 3);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x41\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    cr_assert(!instruction_aff(&vm, &champion));
}

Test(instruction_aff, success_1_eq)
{
    vm_t vm = {0};
    champion_t champion = {0};

    champion.registers = malloc(REG_SIZE * 2);
    my_memcpy("\x10\x40\x01", vm.memory, 3);
    if (!(champion.registers))
        cr_assert(0);
    my_memcpy("\x41\x00\x00\x00", champion.registers + REG_SIZE, REG_SIZE);
    cr_redirect_stdout();
    if (instruction_aff(&vm, &champion) == 84)
        cr_assert(0);
    cr_assert_stdout_eq_str("\x41");
}