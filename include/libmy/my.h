/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdbool.h>
#include <unistd.h>

ssize_t my_strlen(const char *str);
ssize_t my_strnlen(const char *str, const ssize_t n);
ssize_t my_strlen_until_list_c(const char *str, const char list[]);

void my_strcpy(char *dest, char *template);
char *my_strdup(const char *template);
char *my_strdup_until_list_c(const char *template, const char list[]);
char *my_strdup_list_i(const char *template, const char list[], size_t *index);
char *my_strndup(const char *template, const ssize_t n);

bool my_str_eq_str(const char *s1, const char *s2);
bool my_mass_strcmp(const char *template, ...);
bool my_str_eq_str_n(const char *s1, const char *s2, const size_t n);

bool my_is_char_in_str(const char *str, const char c);

char **my_parse_str(char *sentence, const char splitters[], const bool freer);

void *my_memset(char *buffer, const char c, size_t nb_bytes);

char *my_strcat(char *first, char *second,
                const bool free_first,
                const bool free_second);

bool my_isnum(const char c);
bool my_isalpha(const char c);
bool my_isalphanum(const char c);
bool my_str_is_alphanum(const char *str);

size_t my_nb_char_in_str(const char *str, const char c);

bool my_loop_in_str_until_c(const char *str, const char c, size_t *index);

bool my_loop_in_str_until_list_c(const char *str, const char cmp[],
                                    size_t *index);

bool my_loop_in_str_while_c(const char *str, const char c, size_t *index);

bool my_loop_in_str_while_list_c(const char *str, const char cmp[],
                                    size_t *index);

ssize_t my_arrlen(char **array);

void my_arr_show(char **array);

char **my_append_to_array(char **array, char *string,
                            const bool free_array,
                            const bool free_str);

bool my_arr_eq_arr(char **first, char **second);

void my_arrcpy(char **dest, char **template);

char **my_arrdup(const char * const *template);

void my_free_2d(void **array);


/*
** *********************
** | File Manipulation |
** *********************
*/

//Gets the next line of a file.
char *get_next_line(const int fd, const size_t nb_bytes);

/*
** ***********
** | Writers |
** ***********
*/

int my_putchar(const char c);
int my_putstr(const char *str);

void my_put_nbr(int nb, const char *base);
void my_put_nbr_u(unsigned int nb, const char *base);
void my_put_nbr_s(short int nb, const char *base);
void my_put_nbr_su(unsigned short int nb, const char *base);
void my_put_nbr_l(long int nb, const char *base);
void my_put_nbr_lu(unsigned long int nb, const char *base);
void my_put_nbr_ll(long long int nb, const char *base);
void my_put_nbr_llu(unsigned long long int nb, const char *base);

int my_printf(const char *input, ...);

#endif /* MY_H_ */