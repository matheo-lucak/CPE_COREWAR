/*
** EPITECH PROJECT, 2019
** my
** File description:
** my header file
*/

#ifndef MY_H
#define MY_H

#include <stdbool.h>
#include <stddef.h>

int my_getnbr(char *nb_str);

char *my_int_to_str(int nb);
bool my_is_num(char c);
bool my_is_alpha(char c);
bool my_is_caps_alpha(char c);
bool my_is_alpha_num(char c);
bool my_str_is(const char *str, bool (*func)(char));
bool my_str_is_template(const char *str, const char *template);
int my_count_char(const char *str, char c);

int my_pow(int nb, int p);
float my_powf(float nb, float p);

int my_put_address(void *ptr);
void my_put_char(char nb, char *base, int sizebase);
void my_put_int(int nb, char *base, int sizebase);
void my_put_long_long(long long nb, char *base, int sizebase);
void my_put_long(long nb, char *base, int sizebase);
void my_put_short(short nb, char *base, int sizebase);
void my_put_uchar(unsigned char nb, char *base, int sizebase);
void my_put_uint(unsigned int nb, char *base, int sizebase);
void my_put_ulong_long(unsigned long long nb, char *base, int sizebase);
void my_put_ulong(unsigned long int nb, char *base, int sizebase);
void my_put_ushort(unsigned short nb, char *base, int sizebase);
void my_putchar(char c);
int my_putstr(char const *str);

char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, int n);
char *my_mass_strcat(char *src, size_t arg_nb, bool do_free, ...);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, int n);
char *my_strdup(const char *src);
char *my_strndup(const char *src, int n);
char *my_strdup_word(const char *src);
char *my_quoted_strdup(const char *src, char quote);
void my_memset(char *str, char c, int len);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_rev_memcpy(void *src, size_t n);

bool my_skip_chars(char **src, char const *template);
bool my_skip_str(char **src, char *str);
bool my_skip_is(char **src, bool (*func)(char));

int my_strlen(char const *str);
int my_find_char(const char *str, char to_find);
int my_find_last_char(const char *str, char to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char *to_find);
int my_hay_needle(char *str, char *to_find);
int my_mass_strcmp(char *template, char *comparators[]);
int my_mass_strncmp(char *template, char *comparators[]);

char **my_str_to_word_array(char const *str, char *sep, bool do_free);
int my_arrlen(char **str);
void my_free_arr(void **array);

int my_show_word_array(char * const *tab);
int my_printf(const char *src, ...);
char *get_next_line(int fd);

#endif
