/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_fill_instruction
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser.h"

Test(fill_instruction, error1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};

    cr_assert(!fill_instruction(reader_i, NULL, NULL));
}

Test(fill_instruction, error2)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    char *parsed_line[] = {"add", "r6", "r7", "r7", NULL};

    cr_assert(!fill_instruction(reader_i, parsed_line, NULL));
}

Test(fill_instruction, error3)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    cr_assert(!fill_instruction(reader_i, NULL, &asm_i));
}

Test(fill_instruction, invalid_instruction_1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"ad", "r6", "r7", "r7", NULL};

    cr_assert(!fill_instruction(reader_i, NULL, &asm_i));
}

Test(fill_instruction, invalid_instruction_1_std1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"ad", "r6", "r7", "r7", NULL};

    cr_redirect_stdout();
    fill_instruction(reader_i, parsed_line, &asm_i);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                            "Invalid instruction.\n");
}

Test(fill_instruction, invalid_param_nb_1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"add", "r6", "r7", NULL};

    cr_assert(!fill_instruction(reader_i, NULL, &asm_i));
}

Test(fill_instruction, invalid_param_nb_1_std1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"add", "r6", "r7", NULL};

    cr_redirect_stdout();
    fill_instruction(reader_i, parsed_line, &asm_i);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(fill_instruction, invalid_param_nb_2)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"add", "r6", "r7", "r7", "r8", NULL};

    cr_assert(!fill_instruction(reader_i, NULL, &asm_i));
}

Test(fill_instruction, invalid_param_nb_2_std1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"add", "r6", "r7", "r7", "r8", NULL};

    cr_redirect_stdout();
    fill_instruction(reader_i, parsed_line, &asm_i);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                        "Too many arguments given to the instruction.\n");
}

Test(fill_instruction, invalid_param_type_1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"add", "r6", "%:label", NULL};

    cr_assert(!fill_instruction(reader_i, NULL, &asm_i));
}

Test(fill_instruction, invalid_param_type_1_std1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"add", "r6", "%:label", NULL};

    cr_redirect_stdout();
    fill_instruction(reader_i, parsed_line, &asm_i);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(fill_instruction, invalid_param_type_2)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"zjmp", "r6", NULL};

    cr_assert(!fill_instruction(reader_i, NULL, &asm_i));
}

Test(fill_instruction, invalid_param_type_2_std1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"zjmp", "r6", NULL};

    cr_redirect_stdout();
    fill_instruction(reader_i, parsed_line, &asm_i);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(fill_instruction, invalid_param_type_3)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"zjmp", "r6", NULL};

    cr_assert(!fill_instruction(reader_i, NULL, &asm_i));
}

Test(fill_instruction, invalid_param_type_3_std1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"zjmp", "r6", NULL};

    cr_redirect_stdout();
    fill_instruction(reader_i, parsed_line, &asm_i);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(fill_instruction, invalid_param_type_4)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"zjmp", "6", NULL};

    cr_assert(!fill_instruction(reader_i, NULL, &asm_i));
}

Test(fill_instruction, invalid_param_type_4_std1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"zjmp", "6", NULL};

    cr_redirect_stdout();
    fill_instruction(reader_i, parsed_line, &asm_i);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(fill_instruction, invalid_param_type_5)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"zjmp", ":label", NULL};

    cr_assert(!fill_instruction(reader_i, NULL, &asm_i));
}

Test(fill_instruction, invalid_param_type_5_std1)
{
    reader_info_t reader_i = {.name = "fail",
                                .line = ":c",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"zjmp", ":label", NULL};

    cr_redirect_stdout();
    fill_instruction(reader_i, parsed_line, &asm_i);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(fill_instruction, special_instruction_size_1)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"zjmp", "%:label", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 3);
}

Test(fill_instruction, special_instruction_size_2)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"fork", "%:label", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 3);
}

Test(fill_instruction, special_instruction_size_3)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"lfork", "%:label", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 3);
}

Test(fill_instruction, special_instruction_size_4)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"live", "%:label", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 5);
}

Test(fill_instruction, special_instruction_size_5)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"ldi", "r1", "r2", "r3", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 5);
}

Test(fill_instruction, special_instruction_size_6)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"ldi", "%1", "r2", "r3", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 6);
}

Test(fill_instruction, special_instruction_size_7)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"ldi", "1", "r2", "r3", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 6);
}

Test(fill_instruction, special_instruction_size_8)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"sti", "r1", "r2", "r3", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 5);
}

Test(fill_instruction, special_instruction_size_9)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"sti", "r1", "%1", "r3", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 6);
}

Test(fill_instruction, special_instruction_size_10)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"sti", "r1", "1", "r3", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 6);
}

Test(fill_instruction, special_instruction_size_11)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"lldi", "r1", "r2", "r3", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 5);
}

Test(fill_instruction, special_instruction_size_12)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"lldi", "%1", "r1", "r3", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 6);
}

Test(fill_instruction, special_instruction_size_13)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"lldi", "1", "r1", "r3", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 6);
}

Test(fill_instruction, common_instruction_size_1)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"sub", "r4", "r5", "r3", NULL};

    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 5);
}

Test(fill_instruction, common_instruction_size_2)
{
    reader_info_t reader_i = {.name = "test",
                                .line = "c;",
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    char *parsed_line[] = {"ld", "%15", "r4",  NULL};
    if (!fill_instruction(reader_i, parsed_line, &asm_i) || !(asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs->size == 7);
}