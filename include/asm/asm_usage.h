/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** A header that defines asm usage.
*/

#ifndef ASM_USAGE_H_
#define ASM_USAGE_H_

static const char asm_usage[] = {
    "USAGE\n"
    "\t./asm file_name[.s]\n"
    "\n"
    "DESCRIPTION\n"
    "\tfile_name\t"
    "file in assembly language to be converted into file_name.cor, an\n"
    "\t         \texecutable in the Virtual Machine.\n"
};

//Prints done the usage onto the stdout. fd (1).
bool print_asm_usage(void);

#endif /* ASM_USAGE_H_ */