/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_is_header_complete
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser.h"

Test(is_header_complete, error_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};

    cr_assert(!is_header_complete(reader_i, NULL));
}

Test(is_header_complete, comment_not_set_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    header_info_t header_i = {
                        .name_set = true,
                        .comment_set = false};

    asm_i.header_info = header_i;
    cr_assert(!is_header_complete(reader_i, &asm_i));
}

Test(is_header_complete, comment_not_set_1_std1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":(",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    header_info_t header_i = {
                        .name_set = true,
                        .comment_set = false};

    asm_i.header_info = header_i;
    cr_redirect_stdout();
    if (is_header_complete(reader_i, &asm_i))
        cr_assert(0);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                            "Warning: No comment specified.\n");
}

Test(is_header_complete, name_not_set_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    header_info_t header_i = {
                        .name_set = false,
                        .comment_set = true};

    asm_i.header_info = header_i;
    cr_assert(!is_header_complete(reader_i, &asm_i));
}

Test(is_header_complete, name_not_set_1_std1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":(",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    header_info_t header_i = {
                        .name_set = false,
                        .comment_set = true};

    asm_i.header_info = header_i;
    cr_redirect_stdout();
    if (is_header_complete(reader_i, &asm_i))
        cr_assert(0);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                            "No name specified.\n");
}