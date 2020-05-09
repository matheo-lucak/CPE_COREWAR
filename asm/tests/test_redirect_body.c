/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_redirect_body
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser.h"

Test(fill_label, invalid_label_1)
{
    char line[] = "label add r6 r7 r7";
    reader_info_t reader_i = {.name = "fail",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(!redirect_body(reader_i, &asm_i));
}

Test(fill_label, invalid_label_1_std1)
{
    char line[] = "label add r6 r7 r7";
    reader_info_t reader_i = {.name = "fail",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_redirect_stdout();
    redirect_body(reader_i, &asm_i);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                            "Invalid instruction.\n");
}

Test(fill_label, invalid_label_2)
{
    char line[] = "lLbeL: add, r6  r7 r7";
    reader_info_t reader_i = {.name = "fail",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(!redirect_body(reader_i, &asm_i));
}

Test(fill_label, invalid_label_2_std1)
{
    char line[] = "lLbeL: add, r6  r7 r7";
    reader_info_t reader_i = {.name = "fail",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_redirect_stdout();
    redirect_body(reader_i, &asm_i);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                            "Invalid label name.\n");
}
