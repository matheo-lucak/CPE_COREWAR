/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_fill_label
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser.h"

Test(fill_label, error_1)
{
    reader_info_t reader_i = {.name = "error",
                                .line = ":)",
                                .line_nb = 1};

    cr_assert(!fill_label(reader_i, NULL, NULL));
}

Test(fill_label, error_2)
{
    reader_info_t reader_i = {.name = "error",
                                .line = ":)",
                                .line_nb = 1};

    cr_assert(!fill_label(reader_i, "patate", NULL));
}

Test(fill_label, error_3)
{
    reader_info_t reader_i = {.name = "error",
                                .line = ":)",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(!fill_label(reader_i, NULL, &asm_i));
}

Test(fill_label, already_existing_label)
{
    reader_info_t reader_i = {.name = "error",
                                .line = ":(",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    label_t node = {.name = "patate",
                    .address = 1};

    ENQUEUE(&(asm_i.labels), &node, label_t);
    cr_assert(!fill_label(reader_i, "patate", &asm_i));
}

Test(fill_label, already_existing_label_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    label_t node = {.name = "patate",
                    .address = 1};

    ENQUEUE(&(asm_i.labels), &node, label_t);
    cr_redirect_stdout();
    fill_label(reader_i, "patate", &asm_i);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                            "Multiple definition of the same label.\n");
}

Test(fill_label, success_1)
{
    reader_info_t reader_i = {.name = "success",
                                .line = ":)",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(fill_label(reader_i, "patate", &asm_i));
}

Test(fill_label, success_2)
{
    reader_info_t reader_i = {.name = "success",
                                .line = ":)",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    label_t node = {.name = "patate1",
                    .address = 1};

    ENQUEUE(&(asm_i.labels), &node, label_t);
    cr_assert(fill_label(reader_i, "patate", &asm_i));
}