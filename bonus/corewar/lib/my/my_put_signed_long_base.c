/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_long_base.c
*/

int my_putchar(char c);

int my_strlen(char const *str);

int my_put_signed_long_base(long long nb, char const *base)
{
    unsigned int base_len = my_strlen(base);
    unsigned long long int digit = 1;
    unsigned long long int x = 0;

    if (base_len < 2)
        return 84;
    x = (nb < 0) ? nb * -1 : nb;
    while (x >= digit * base_len && x >= base_len)
        digit *= base_len;
    while (digit > 0) {
        if (my_putchar(base[x / digit]) == 84)
            return 84;
        x %= digit;
        digit /= base_len;
    }
    return 0;
}