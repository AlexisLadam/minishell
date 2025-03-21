/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** premier étape du printf
*/

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "printf.h"

int affichage_mini_printf(char *format, va_list list, int *i, int *comptchar)
{
    if (format[*i] == '%' && format[*i + 1] != 0) {
        if (format[*i] == '%' && format[*i + 1] == 'd' ||
            format[*i] == '%' && format[*i + 1] == 'i')
            my_put_nbrm(va_arg(list, int), comptchar);
        if (format[*i] == '%' && format[*i + 1] == 's')
            my_putstrm(va_arg(list, char *), comptchar);
        if (format[*i] == '%' && format[*i + 1] == 'c')
            my_putcharm((char) va_arg(list, int), comptchar);
        if (format[*i] == '%' && format[*i + 1] == '%')
            my_putcharm('%', comptchar);
        if (format[*i] == '%' && format[*i + 1] == 'n') {
            my_put_nbrm(1, *comptchar);
            va_arg(list, int) == *comptchar;
        }
    }
    va_end(list);
}

int affichage_flag_f(char *format, va_list list, int *i, int *comptchar)
{
    if (format[*i] == '%' && format[*i + 1] != 0) {
        if (format[*i + 1] == '.' && format[*i + 2] == 'f') {
            f_no_cond(format, list, i, comptchar);
        }
        if (format[*i] == '%' && format[*i + 1] == 'f') {
            f_6_chfr(format, list, i, comptchar);
        }
        if (format[*i] == '%' && format[*i + 1] == '.' &&
            format[*i + 2] > 47 && format[*i + 2] < 58) {
            flag_f(format, list, i, comptchar);
        }
    }
}

int appelall(char *format, va_list list, int *i, int *comptchar)
{
    affichage_mini_printf(format, list, i, comptchar);
    affichage_flag_f(format, list, i, comptchar);
    my_print_unsign(format, list, i, comptchar);
    my_print_scientifique(format, list, i, comptchar);
    test_flag(format, list, i, comptchar);
    test_flag_plus(format, list, i, comptchar);
}

int my_printf(char *format, ...)
{
    int comptchar = 0;
    va_list list;
    int i = 0;
    int c = 0;

    va_start(list, format);
    while (format[i] != 0) {
        if (format[i] == '%') {
            appelall(format, list, &i, &comptchar);
            i++;
        } else {
            my_putcharm(format[i], &comptchar);
            }
        i++;
    }
    return (0);
}
