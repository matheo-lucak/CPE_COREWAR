/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_param_is
*/

#include <criterion/criterion.h>
#include "parser.h"

Test(param_is, register_error_1)
{
    cr_assert(!param_is_register(NULL));
}

Test(param_is, no_register_1)
{
    cr_assert(!param_is_register("b12"));
}

Test(param_is, register_1)
{
    cr_assert(param_is_register("r2"));
}

Test(param_is, direct_error_1)
{
    cr_assert(!param_is_direct(NULL));
}

Test(param_is, no_direct_1)
{
    cr_assert(!param_is_direct("b12"));
}

Test(param_is, direct_1)
{
    cr_assert(param_is_direct("%2"));
}

Test(param_is, label_error_1)
{
    cr_assert(!param_is_label(NULL));
}

Test(param_is, no_label_1)
{
    cr_assert(!param_is_label("b12"));
}

Test(param_is, label_1)
{
    cr_assert(param_is_label(":2"));
}