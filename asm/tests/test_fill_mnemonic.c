/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_fill_mnemonic
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser.h"

Test(fill_mnemonic, error_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};

    cr_assert(!fill_mnemonic(reader_i, NULL, NULL, NULL));
}

Test(fill_mnemonic, error_2)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    instruct_t instruct;

    cr_assert(!fill_mnemonic(reader_i, &instruct, NULL, NULL));
}

Test(fill_mnemonic, error_3)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"ld", "r1", "patate"};

    cr_assert(!fill_mnemonic(reader_i, NULL, parsed_line, NULL));
}

Test(fill_mnemonic, error_4)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(!fill_mnemonic(reader_i, NULL, NULL, &asm_i));
}

Test(fill_mnemonic, error_5)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"ld", "r1", "patate"};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(!fill_mnemonic(reader_i, NULL, parsed_line, &asm_i));
}

Test(fill_mnemonic, error_6)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"ld", "r1", "patate"};
    instruct_t instruct;

    cr_assert(!fill_mnemonic(reader_i, &instruct, parsed_line, NULL));
}

Test(fill_mnemonic, error_7)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    instruct_t instruct;

    cr_assert(!fill_mnemonic(reader_i, &instruct, NULL, &asm_i));
}

Test(fill_mnemonic, bad_mnemonic_name_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"zjmpa", "r1", "patate"};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    instruct_t instruct;

    cr_assert(!fill_mnemonic(reader_i, &instruct, parsed_line, &asm_i));
}

Test(fill_mnemonic, bad_mnemonic_name_1_std1)
{
    reader_info_t reader_i = {.name = "bad mnemo",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"zjmpa", "r1", "patate"};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    instruct_t instruct;

    cr_redirect_stdout();
    fill_mnemonic(reader_i, &instruct, parsed_line, &asm_i);
    cr_assert_stdout_eq_str("asm, bad mnemo, line 1: "
                            "Invalid instruction.\n");
}

Test(fill_mnemonic, success_1)
{
    reader_info_t reader_i = {.name = ":)",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"zjmp", "r1", "patate"};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    instruct_t instruct;

    cr_assert(fill_mnemonic(reader_i, &instruct, parsed_line, &asm_i));
}

Test(fill_mnemonic, success_1_eq)
{
    reader_info_t reader_i = {.name = ":)",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"live", "r1", "patate"};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    instruct_t instruct;

    fill_mnemonic(reader_i, &instruct, parsed_line, &asm_i);
    cr_assert(instruct.code == 1 && instruct.param_nb == 1);
}