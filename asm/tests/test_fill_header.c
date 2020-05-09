/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_fill_header
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header_error.h"

Test(is_header_tests, wrong_instruction_1)
{
    reader_info_t reader_i = {.name = "wrong_instruction",
                                .line = " .name",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(!redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, wrong_instruction_1_std1)
{
    reader_info_t reader_i = {.name = "wrong_instruction",
                                .line = " .name",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_redirect_stdout();
    redirect_fill_header(reader_i, &header_i);
    cr_assert_stdout_eq_str("asm, wrong_instruction, line 1: "
                            "Invalid instruction.\n");
}

Test(is_header_tests, name_no_first_line)
{
    reader_info_t reader_i = {.name = "first_line",
                                .line = ".name \"abc\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = true};

    cr_assert(!redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, name_no_first_line_std1)
{
    reader_info_t reader_i = {.name = "first_line",
                                .line = ".name \"abc\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = true};

    cr_redirect_stdout();
    redirect_fill_header(reader_i, &header_i);
    cr_assert_stdout_eq_str("asm, first_line, line 1: "
                            "The name of your program must be "
                            "the first line.\n");
}

Test(is_header_tests, comment_before_name)
{
    reader_info_t reader_i = {.name = "comment_before_name",
                                .line = ".comment \"a\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(!redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, comment_before_name_std1)
{
    reader_info_t reader_i = {.name = "comment_before_name",
                                .line = ".comment \"a\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_redirect_stdout();
    redirect_fill_header(reader_i, &header_i);
    cr_assert_stdout_eq_str("asm, comment_before_name, line 1: "
                            "The comment must be just after the name.\n");
}

Test(is_header_tests, name_declared_twice_1)
{
    reader_info_t reader_i = {.name = "name_declared_twice",
                                .line = ".name \"a\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = true,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(!redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, name_declared_twice_1_std1)
{
    reader_info_t reader_i = {.name = "name_declared_twice",
                                .line = ".name \"a\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = true,
                                .comment_set = false,
                                .parsing_core = false};

    cr_redirect_stdout();
    redirect_fill_header(reader_i, &header_i);
    cr_assert_stdout_eq_str("asm, name_declared_twice, line 1: "
                            "The name can only be defined once.\n");
}

Test(is_header_tests, comment_declared_twice_1)
{
    reader_info_t reader_i = {.name = "comm_declared_twice",
                                .line = ".comment \"a\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = true,
                                .comment_set = true,
                                .parsing_core = false};

    cr_assert(!redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, wrong_syntax_1_std1)
{
    reader_info_t reader_i = {.name = "wrong syntax 1",
                                .line = ".name a\"a\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_redirect_stdout();
    redirect_fill_header(reader_i, &header_i);
    cr_assert_stdout_eq_str("asm, wrong syntax 1, line 1: "
                            "Syntax error.\n");
}

Test(is_header_tests, wrong_syntax_1)
{
    reader_info_t reader_i = {.name = "wrong syntax 1",
                                .line = ".name a\"a\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(!redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, wrong_syntax_2)
{
    reader_info_t reader_i = {.name = "wrong syntax 2",
                                .line = ".name \"\"a\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(!redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, wrong_syntax_3)
{
    reader_info_t reader_i = {.name = "wrong syntax 3",
                                .line = ".name \"a\"a",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(!redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, wrong_syntax_4)
{
    reader_info_t reader_i = {.name = "wrong syntax 3",
                                .line = ".name \"a\"a   ",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(!redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, wrong_syntax_5)
{
    reader_info_t reader_i = {.name = "wrong syntax 5",
                                .line = ".name \"a\"\"\t\t",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(!redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, succes_1)
{
    reader_info_t reader_i = {.name = "success1",
                                .line = ".name \"a\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, succes_1_strcmp)
{
    reader_info_t reader_i = {.name = "success1",
                                .line = ".name \"a\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    redirect_fill_header(reader_i, &header_i);
    cr_assert(!my_strcmp(header_i.header.prog_name, "a"));
}

Test(is_header_tests, succes_2)
{
    reader_info_t reader_i = {.name = "success2",
                                .line = "\t.comment \"abc\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = true,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, succes_2_strcmp)
{
    reader_info_t reader_i = {.name = "success2",
                                .line = "\t.comment \"abc\"",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = true,
                                .comment_set = false,
                                .parsing_core = false};

    redirect_fill_header(reader_i, &header_i);
    cr_assert(!my_strcmp(header_i.header.comment, "abc"));
}


Test(is_header_tests, succes_3)
{
    reader_info_t reader_i = {.name = "success3",
                                .line = "    .name \t\"a   \" ",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    cr_assert(redirect_fill_header(reader_i, &header_i));
}

Test(is_header_tests, succes_3_strcmp)
{
    reader_info_t reader_i = {.name = "success3",
                                .line = "    .name \t\"a   \" ",
                                .line_nb = 1};
    header_info_t header_i = {.name_set = false,
                                .comment_set = false,
                                .parsing_core = false};

    redirect_fill_header(reader_i, &header_i);
    cr_assert(!my_strcmp(header_i.header.prog_name, "a   "));
}