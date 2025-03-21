/*
** EPITECH PROJECT, 2023
** print encore un autre
** File description:
** aze
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "printf.h"

int moins_en_plus(int l)
{
    if (l < 0)
    l = l * (-1);
    return (l);
}

int flag_s(char *format, va_list list, int *i, int *comptchar)
{
    int nombre = calcul_nombre(format, list, i, comptchar);

    while (nombre != 0) {
        my_putcharm(' ', comptchar);
        nombre--;
    }
    my_putstrm(va_arg(list, char *), comptchar);
}

int appel_s(char *format, va_list list, int *i, int *comptchar)
{
    return (0);
}
