/*
** EPITECH PROJECT, 2023
** unsigned flag
** File description:
** printf
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "printf.h"

int my_uns_hex(unsigned long decimal, int *comptchar)
{
    long temp = decimal;
    long quotient = 0;
    char rem;
    char str[300];
    int i = 0;

    while (decimal != 0) {
        decimal = decimal / 16;
        quotient = decimal;
        rem = temp - (quotient * 16);
        temp = decimal;
        rem += 48;
        i++;
        rem_to_char_min(rem, str, i, comptchar);
        i++;
        str[i] = '\0';
    }
    for (int y = i; y != 0; y--) {
        my_putcharm(str[y], comptchar);
    }
}

int my_maj_hex(unsigned long decimal, int *comptchar)
{
    long temp = decimal;
    long quotient = 0;
    char rem;
    char str[300];
    int i = 0;

    while (decimal != 0) {
        decimal = decimal / 16;
        quotient = decimal;
        rem = temp - (quotient * 16);
        temp = decimal;
        rem += 48;
        i++;
        rem_to_char(rem, str, i, comptchar);
        i++;
        str[i] = '\0';
    }
    for (int y = i - 1; y != 0; y--) {
        my_putcharm(str[y], comptchar);
    }
}

int rem_to_char(char rem, char *str, int i, int *comptchar)
{
    if (rem >= 48 && rem <= 57)
        str[i] = rem;
    if (rem >= 58 && rem <= 63)
        str[i] = rem + 7;
    return (rem);
}

int rem_to_char_min(char rem, char *str, int i, int *comptchar)
{
    if (rem >= 48 && rem <= 57)
        str[i] = rem;
    if (rem >= 58 && rem <= 63)
        str[i] = rem + 39;
    return (rem);
}

int my_uns_nbr(unsigned long nb, int *comptchar)
{
    unsigned int modulo;

    if (nb < 0) {
        nb = nb * (- 1);
        nb = 4294967295 - nb;
    }
    if (nb <= 9 && nb >= 0)
        my_putcharm(nb + 48, comptchar);
    if (nb > 9) {
        modulo = nb % 10;
        my_uns_nbr(nb / 10, comptchar);
        my_putcharm(modulo + '0', comptchar);
    }
    return (0);
}
