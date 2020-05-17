/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_redirect_body
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser.h"
#include "my.h"

Test(redirect_body, error_1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = NULL,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(!redirect_body(reader_i, &asm_i));
}

Test(redirect_body, error_2)
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

Test(redirect_body, error_3)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = NULL,
                                .line_nb = 1};

    cr_assert(!redirect_body(reader_i, NULL));
}

Test(redirect_body, invalid_label_1)
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

Test(redirect_body, invalid_label_1_std1)
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

Test(redirect_body, invalid_label_2)
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

Test(redirect_body, invalid_label_2_std1)
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

Test(redirect_body, only_label)
{
    char line[] = "label:";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(redirect_body(reader_i, &asm_i));
}

Test(redirect_body, only_label_eq)
{
    char line[] = "label:";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    cr_assert(asm_i.labels && !my_strcmp(asm_i.labels->name, "label"));
}

Test(redirect_body, only_instruct)
{
    char line[] = "ld %15 r4";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(redirect_body(reader_i, &asm_i));
}

Test(redirect_body, only_instruct_eq)
{
    char line[] = "ld %15 r4";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    cr_assert(asm_i.instructs && asm_i.instructs->code == 0x02);
}

Test(redirect_body, label_and_instruct)
{
    char line[] = "label: ld %15 r4";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(redirect_body(reader_i, &asm_i));
}

Test(redirect_body, label_and_instruct_eq)
{
    char line[] = "label: ld %15 r4";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    cr_assert(asm_i.instructs && asm_i.instructs->code == 0x02 &&
                asm_i.labels && !my_strcmp(asm_i.labels->name, "label"));
}