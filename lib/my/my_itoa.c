/*
** EPITECH PROJECT, 2019
** template
** File description:
** my_itoa
*/

#include <stdio.h>
#include <stdlib.h>

int util_itoa(char *new_str, int *nb, int *plus)
{
    if (*nb == 0) {
        new_str[0] = '0';
        new_str[1] = '\0';
        return (1);
    }
    if (*nb < 0) {
        new_str[0] = '-';
        *plus = 1;
        *nb *= -1;
    }
    return (0);
}

char *my_itoa(int nb)
{
    char *new_str = malloc(sizeof(char) * 100);
    int nb_digit = 0;
    int multi = 1;
    int i = 0;
    int plus = 0;

    if (util_itoa(new_str, &nb, &plus) == 1)
        return (new_str);
    for (long nb_s = nb; nb_s > 0; nb_s /= 10, multi *= 10)
        nb_digit += 1;
    if (nb != 0)
        multi /= 10;
    for (i = plus; i != nb_digit + plus; i++, multi /= 10) {
        new_str[i] = (nb / multi % 10) + '0';
    }
    new_str[i] = '\0';
    return (new_str);
}