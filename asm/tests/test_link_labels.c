/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_link_labels
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"
#include "parser.h"

Test(link_labels, nothing_to_link)
{
    cr_assert(link_labels(NULL, NULL));
}

Test(link_labels, nothink_to_link_with_only_label)
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
    cr_assert(link_labels(asm_i.labels, asm_i.instructs));
}

Test(link_labels, nothink_to_link_with_only_instruct)
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
    cr_assert(link_labels(asm_i.labels, asm_i.instructs));
}

Test(link_labels, nothink_to_link_with_label_and_instruct)
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
    cr_assert(link_labels(asm_i.labels, asm_i.instructs));
}

Test(link_labels, link_label_and_instruct)
{
    char line[] = "live: zjmp %:live";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 12};

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    cr_assert(link_labels(asm_i.labels, asm_i.instructs));
}

Test(link_labels, link_label_and_instruct_eq)
{
    char line[] = "live: zjmp %:live";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 12};

    if (!redirect_body(reader_i, &asm_i) ||
        !link_labels(asm_i.labels, asm_i.instructs))
        cr_assert(0);
    cr_assert(asm_i.instructs && asm_i.instructs->params[0].value.dir == 0);
}

Test(link_labels, link_label_and_instruct_different_line)
{
    char line[] = "live: live %123";
    char line2[] = "zjmp %:live";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 12};

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    reader_i.line = line2;
    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    cr_assert(link_labels(asm_i.labels, asm_i.instructs));
}

Test(link_labels, link_label_and_instruct_different_line_eq)
{
    char line[] = "live: live %123";
    char line2[] = "zjmp %:live";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 12};
    instruct_t *scnd_instruct = NULL;

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    reader_i.line = line2;
    if (!redirect_body(reader_i, &asm_i) ||
        !link_labels(asm_i.labels, asm_i.instructs))
        cr_assert(0);
    scnd_instruct = asm_i.instructs->next;
    cr_assert(scnd_instruct && scnd_instruct->params[0].value.dir == -5);
}

Test(link_labels, link_label_undefined_label_1)
{
    char line[] = "live: live %123";
    char line2[] = "zjmp %:patate";
    reader_info_t reader_i = {.name = "test",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 12};
    instruct_t *scnd_instruct = NULL;

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    reader_i.line = line2;
    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    cr_assert(!link_labels(asm_i.labels, asm_i.instructs));
}

Test(link_labels, link_label_undefined_label_1_std1)
{
    char line[] = "live: live %123";
    char line2[] = "zjmp %:patate";
    reader_info_t reader_i = {.name = "fail",
                                .line = line,
                                .line_nb = 1};
    asm_info_t asm_i = {.instructs = NULL,
                        .labels = NULL,
                        .writing_address = 12};
    instruct_t *scnd_instruct = NULL;

    if (!redirect_body(reader_i, &asm_i))
        cr_assert(0);
    reader_i.line = line2;
    cr_redirect_stdout();
    if (!redirect_body(reader_i, &asm_i) ||
        link_labels(asm_i.labels, asm_i.instructs))
        cr_assert(0);
    cr_assert_stdout_eq_str("asm, fail, line 1: "
                            "Undefined label.\n");
}