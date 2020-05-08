/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_is_label
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "labels.h"

Test(is_label, is_label_error_1)
{
    cr_assert(!is_label(NULL));
}

Test(is_label, is_label_error_2)
{
    cr_assert(!is_label(""));
}

Test(is_label, not_a_label_1)
{
    cr_assert(!is_label("Im not a label"));
}

Test(is_label, not_a_label_2)
{
    cr_assert(!is_label("Im not a label :)"));
}

Test(is_label, a_label_1)
{
    cr_assert(is_label("Im a label :) :"));
}

Test(is_label, a_label_2)
{
    cr_assert(is_label(":"));
}