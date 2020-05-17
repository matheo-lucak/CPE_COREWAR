/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_is_label
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser.h"

Test(is_valid_label, is_label_valid_error_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};

    cr_assert(!is_valid_label(reader_i, NULL));
}

Test(is_valid_label, not_a_valid_label_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char label[] = "Im not a valid label :( :";

    cr_assert(!is_valid_label(reader_i, label));
}

Test(is_valid_label, not_a_valid_label_1_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char label[] = "Im not a valid label :( :";

    cr_redirect_stdout();
    is_valid_label(reader_i, label);
    cr_assert_stdout_eq_str("asm, file, line 1: Invalid label name.\n");
}

Test(is_valid_label, valid_label_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char label[] = "amalabel:";

    cr_assert(is_valid_label(reader_i, label));
}