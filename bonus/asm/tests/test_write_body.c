/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_write_body
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "open.h"
#include "writing.h"
#include "my.h"

Test(write_body, error_1)
{
    cr_assert(!write_body(-1, NULL));
}

Test(write_body, bad_fd_error_1)
{
    char line[] = "label: ld %15 r4";
    char line2[] = "add	r6, r7, r7";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    reader_i.line = line2;
    if (!redirect_body(reader_i, &asm_i) ||
        !(asm_i.instructs))
        cr_assert(0);
    cr_assert(!write_body(-1, asm_i.instructs));
}

Test(write_body, corrupted_fd)
{
    char line[] = "label: ld %15 r4";
    char line2[] = "add	r6, r7, r7";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    reader_i.line = line2;
    if (!redirect_body(reader_i, &asm_i) ||
        !(asm_i.instructs))
        cr_assert(0);
    close(1);
    cr_assert(!write_body(1, asm_i.instructs));
}

Test(write_body, success_1)
{
    char line[] = "label: ld %15 r4";
    char line2[] = "add	r6, r7, r7";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    reader_i.line = line2;
    if (!redirect_body(reader_i, &asm_i) ||
        !(asm_i.instructs))
        cr_assert(0);
    cr_assert(write_body(1, asm_i.instructs));
}

Test(write_body, success_1_eq)
{
    char buffer[] = {0x02, 0x90, 0x00, 0x00, 0x00, 0x0f, 0x04};
    char res[sizeof(buffer)];
    char line[] = "label: ld %15 r4";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 0};
    int fd[2];

    if (pipe(fd) == -1)
        cr_assert(0);
    if (!redirect_body(reader_i, &asm_i) ||
        !(asm_i.instructs) ||
        !write_body(fd[1], asm_i.instructs) ||
        read(fd[0], res, sizeof(buffer)) != sizeof(buffer))
        cr_assert(0);
    cr_assert(!my_mem_cmp(buffer, res, sizeof(buffer)));
}