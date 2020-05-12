/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** my.h
*/

#ifndef CPE_COREWAR_2019_MY_H
#define CPE_COREWAR_2019_MY_H

#include <stddef.h>

int my_atoi(char const *str);

void *my_cmalloc(size_t size);

int my_memcpy(void *src, void *dest, size_t size);

int my_putchar(char c);

int my_strcmp(char const *s1, char const *s2);

char *my_strdup(char const *src);

int my_strlen(const char *str);

int my_strlen_until(const char *str, char c);

int my_strncpy(char **dest, char const *src, int n);

char *my_strndup(char const *src, int n);

int my_swap_int_endian(int *value);

#endif //CPE_COREWAR_2019_MY_H
