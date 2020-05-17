/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_program_size
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser.h"
#include "my.h"

Test(get_program_size, size_0)
{
    cr_assert(!get_program_size(NULL));
}

Test(get_program_size, one_instruct)
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
    cr_assert(get_program_size(asm_i.instructs) == 7);
}

Test(get_program_size, two_instruct)
{
    char line[] = "label: ld %15 r4";
    char line2[] = "sub	r4, r5, r3";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    reader_i.line = line2;
    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    cr_assert(get_program_size(asm_i.instructs) == 12);
}