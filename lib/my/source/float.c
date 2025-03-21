/*
** EPITECH PROJECT, 2023
** test flag e
** File description:
** test
*/
#include "printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

void my_print_scientifique(char *format, va_list list, int *i, int *comptchar)
{
    if (format[*i] == '%' && format[*i + 1] == 'e')
        dec_to_sci(va_arg(list, double), 0, comptchar);
    if (format[*i] == '%' && format[*i + 1] == 'E')
        dec_to_sci(va_arg(list, double), 1, comptchar);
}

void dec_to_sci(double decimal, int majuscule, int *comptchar)
{
    long ssvirg = 0;
    int virg = 0;

    if (decimal < 0) {
        my_putcharm('-', comptchar);
        decimal = decimal * (-1);
    }
    while (decimal > 10 || decimal < -10) {
        decimal = decimal / 10;
        virg++;
    }
    ssvirg = decimal;
    decimal = decimal - ssvirg;
    my_put_nbrm(ssvirg, comptchar);
    my_putcharm('.', comptchar);
    decimal *= 1000000;
    my_put_nbrm(decimal, comptchar);
    espacesupp(majuscule, virg, comptchar);
}

void espacesupp(int majuscule, int virg, int *comptchar)
{
    if (majuscule == 1) {
        my_putcharm('E', comptchar);
    } else {
        my_putcharm('e', comptchar);
    }
    my_putcharm('+', comptchar);
    if (virg < 10)
        my_putcharm('0', comptchar);
    my_put_nbrm(virg, comptchar);
}

void test_flag(char *format, va_list list, int *i, int *comptchar)
{
    if (format[*i] == '%' && format[*i + 1] == ' ') {
        if (format[*i + 2] == 'e') {
            my_putcharm(' ', comptchar);
            dec_to_sci(va_arg(list, double), 0, comptchar);
            *i += 1;
        }
        if (format[*i + 2] == 'E') {
            my_putcharm(' ', comptchar);
            dec_to_sci(va_arg(list, double), 1, comptchar);
            *i += 1;
        }
    }
}

void test_flag_plus(char *format, va_list list, int *i, int *comptchar)
{
    if (format[*i] == '%' && format[*i + 1] == '+') {
        if (format[*i + 2] == 'e') {
            my_putcharm('+', comptchar);
            dec_to_sci(va_arg(list, double), 0, comptchar);
            *i += 1;
        }
        if (format[*i + 2] == 'E') {
            my_putcharm('+', comptchar);
            dec_to_sci(va_arg(list, double), 1, comptchar);
            *i += 1;
        }
    }
}
