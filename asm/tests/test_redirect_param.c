/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_redirect_param
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "parser_params.h"
#include "my.h"

Test(redirect_param, error_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = 0;
    parameters_t param;

    cr_assert(!redirect_param(reader_i, types, &param, NULL));
}

Test(redirect_param, error_2)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = 0;
    char line[] = "patate";

    cr_assert(!redirect_param(reader_i, types, NULL, line));
}

Test(redirect_param, no_type_register_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_DIR | T_IND;
    parameters_t param;
    char line[] = "r1";

    cr_assert(!redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, no_type_register_1_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_DIR | T_IND;
    parameters_t param;
    char line[] = "r1";

    cr_redirect_stdout();
    redirect_param(reader_i, types, &param, line);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(redirect_param, bad_register_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "r0";

    cr_assert(!redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, bad_register_1_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "r0";

    cr_redirect_stdout();
    redirect_param(reader_i, types, &param, line);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                            "Invalid register number.\n");
}

Test(redirect_param, bad_register_2)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "r-5";

    cr_assert(!redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, bad_register_2_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "r-5";

    cr_redirect_stdout();
    redirect_param(reader_i, types, &param, line);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                            "Invalid register number.\n");
}

Test(redirect_param, bad_register_3)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "r254";

    cr_assert(!redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, bad_register_3_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "r254";

    cr_redirect_stdout();
    redirect_param(reader_i, types, &param, line);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                            "Invalid register number.\n");
}

Test(redirect_param, bad_direct_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_DIR;
    parameters_t param;
    char line[] = "%142a";

    cr_assert(!redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, bad_direct_1_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_DIR;
    parameters_t param;
    char line[] = "%142a";

    cr_redirect_stdout();
    redirect_param(reader_i, types, &param, line);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(redirect_param, no_type_direct_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "%142";

    cr_assert(!redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, no_type_direct_1_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "%142";

    cr_redirect_stdout();
    redirect_param(reader_i, types, &param, line);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(redirect_param, bad_indirect_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_IND;
    parameters_t param;
    char line[] = "142a";

    cr_assert(!redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, bad_indirect_1_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_IND;
    parameters_t param;
    char line[] = "142a";

    cr_redirect_stdout();
    redirect_param(reader_i, types, &param, line);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(redirect_param, no_type_indirect_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "142";

    cr_assert(!redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, no_type_indirect_1_std1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":(",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "142";

    cr_redirect_stdout();
    redirect_param(reader_i, types, &param, line);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                        "The argument given to the instruction is invalid.\n");
}

Test(redirect_param, register_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "r12";

    cr_assert(redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, register_1_eq)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "r12";

    redirect_param(reader_i, types, &param, line);
    cr_assert(param.has_label == false && param.size == 1 &&
                param.type == T_REG && param.value.reg == 12);
}

Test(redirect_param, indirect_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char types = T_IND;
    parameters_t param;
    char line[] = "12";

    cr_assert(redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, indirect_1_eq)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char types = T_IND;
    parameters_t param;
    char line[] = "12";

    redirect_param(reader_i, types, &param, line);
    cr_assert(param.has_label == false && param.size == IND_SIZE &&
                param.type == T_IND && param.value.ind == 12);
}

Test(redirect_param, direct_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char types = T_DIR;
    parameters_t param;
    char line[] = "%12";

    cr_assert(redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, direct_1_eq)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char types = T_DIR;
    parameters_t param;
    char line[] = "%12";

    redirect_param(reader_i, types, &param, line);
    cr_assert(param.has_label == false && param.size == DIR_SIZE &&
                param.type == T_DIR && param.value.dir == 12);
}

Test(redirect_param, direct_label_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char types = T_DIR;
    parameters_t param;
    char line[] = "%:live";

    cr_assert(redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, direct_label_1_eq)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char types = T_DIR;
    parameters_t param;
    char line[] = "%:live";

    redirect_param(reader_i, types, &param, line);
    cr_assert(param.has_label && !my_strcmp(param.label_name, "live") &&
                param.size == DIR_SIZE && param.type == T_DIR);
}

Test(redirect_param, indirect_label_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char types = T_IND;
    parameters_t param;
    char line[] = ":live";

    cr_assert(redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, indirect_label_1_eq)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":)",
                                .line_nb = 1};
    char types = T_IND;
    parameters_t param;
    char line[] = ":live";

    redirect_param(reader_i, types, &param, line);
    cr_assert(param.has_label && !my_strcmp(param.label_name, "live") &&
                param.size == IND_SIZE && param.type == T_IND);
}

Test(redirect_param, register_label_1)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":c",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "r:live";

    cr_assert(!redirect_param(reader_i, types, &param, line));
}

Test(redirect_param, register_label_1_eq)
{
    reader_info_t reader_i = {.name = "file",
                                .line = ":c",
                                .line_nb = 1};
    char types = T_REG;
    parameters_t param;
    char line[] = "r:live";


    cr_redirect_stdout();
    redirect_param(reader_i, types, &param, line);
    cr_assert_stdout_eq_str("asm, file, line 1: "
                        "Invalid register number.\n");
}