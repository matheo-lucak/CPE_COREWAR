/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_fill_param
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser.h"

Test(fill_params, error_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};

    cr_assert(!fill_params(reader_i, NULL, NULL, NULL));
}

Test(fill_params, error_2)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    instruct_t instruct;

    cr_assert(!fill_params(reader_i, &instruct, NULL, NULL));
}

Test(fill_params, error_3)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"ld", "r1", "patate"};

    cr_assert(!fill_params(reader_i, NULL, parsed_line, NULL));
}

Test(fill_params, error_4)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(!fill_params(reader_i, NULL, NULL, &asm_i));
}

Test(fill_params, error_5)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"ld", "r1", "patate"};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(!fill_params(reader_i, NULL, parsed_line, &asm_i));
}

Test(fill_params, error_6)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"ld", "r1", "patate"};
    instruct_t instruct;

    cr_assert(!fill_params(reader_i, &instruct, parsed_line, NULL));
}

Test(fill_params, error_7)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    instruct_t instruct;

    cr_assert(!fill_params(reader_i, &instruct, NULL, &asm_i));
}

Test(fill_params, too_much_param)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"ld", "1", "r2", "r1"};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    instruct_t instruct;

    fill_mnemonic(reader_i, &instruct, parsed_line, &asm_i);
    cr_assert(!fill_params(reader_i, &instruct, parsed_line + 1, &asm_i));
}

Test(fill_params, too_much_param_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char *parsed_line[] = {"ld", "1", "r2", "r1"};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    instruct_t instruct;

    fill_mnemonic(reader_i, &instruct, parsed_line, &asm_i);
    cr_redirect_stdout();
    fill_params(reader_i, &instruct, parsed_line + 1, &asm_i);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                            "Too many arguments given to the instruction.\n");
}