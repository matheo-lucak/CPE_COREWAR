/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_is_header
*/

#include <criterion/criterion.h>
#include "header_info.h"

Test(is_header_tests, error_1)
{
    cr_assert(!is_header(NULL, NULL));
}

Test(is_header_tests, error_2)
{
    cr_assert(!is_header(NAME_CMD_STRING, NULL));
}

Test(is_header_tests, error_3)
{
    cr_assert(!is_header(NULL, ".name"));
}

Test(is_header_tests, not_a_header_1)
{
    cr_assert(!is_header(NAME_CMD_STRING, "Patate?"));
}

Test(is_header_tests, not_a_header_2)
{
    cr_assert(!is_header(NAME_CMD_STRING, ".name\""));
}

Test(is_header_tests, not_a_header_3)
{
    cr_assert(!is_header(COMMENT_CMD_STRING, ".comment?"));
}

Test(is_header_tests, no_space_or_tab_header_1)
{
    cr_assert(!is_header(NAME_CMD_STRING, ".name"));
}

Test(is_header_tests, no_space_or_tab_header_2)
{
    cr_assert(!is_header(COMMENT_CMD_STRING, ".comment"));
}

Test(is_header_tests, tab_header_1)
{
    cr_assert(!is_header(NAME_CMD_STRING, ".name\t"));
}

Test(is_header_tests, space_header_1)
{
    cr_assert(!is_header(NAME_CMD_STRING, ".name "));
}

Test(is_header_tests, space_header_2)
{
    cr_assert(!is_header(COMMENT_CMD_STRING, ".comment "));
}

Test(is_header_tests, tab_header_2)
{
    cr_assert(!is_header(COMMENT_CMD_STRING, ".comment\t"));
}