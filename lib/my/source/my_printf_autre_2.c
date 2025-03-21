/*
** EPITECH PROJECT, 2023
** print encore un autre
** File description:
** aze
*/

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "printf.h"

int my_put_nbrm(int nb, int *comptchar)
{
    int n = 0;

    if (nb < 0){
        my_putcharm('-', comptchar);
        my_put_nbrm(nb * (-1), comptchar);
        return (0);
    }
    if (nb < 10){
        my_putcharm(nb + 48, comptchar);
    } else {
        my_put_nbrm(nb / 10, comptchar);
        n = nb % 10;
        my_putcharm(n + 48, comptchar);
    }
    return (0);
}

int f_no_cond(char *format, va_list list, int *i, int *comptchar)
{
    double d = va_arg(list, double);
    int k = (int)d;
    int j = (d - k) * 10;

    if (j > 4) {
        my_put_nbrm(k + 1, comptchar);
    } else {
        my_put_nbrm(k, comptchar);
    }
    *i += 1;
}

int f_6_chfr(char *format, va_list list, int *i, int *comptchar)
{
    double d = va_arg(list, double);
    int k = (int)d;
    int j = (d - k) * 10000000;
    int l = j % 10;

    j = j / 10;
    if (j < 0)
    j = j * (-1);
    if (l > 4) {
        my_put_nbrm(k, comptchar);
        my_putcharm('.', comptchar);
        my_put_nbrm(j + 1, comptchar);
    } else {
        my_put_nbrm(k, comptchar);
        my_putcharm('.', comptchar);
        my_put_nbrm(j, comptchar);
    }
}

int calcul_nombre(char *format, va_list list, int *i, int *comptchar)
{
    int nombre = 0;

    (*i) = (*i) + 2;
    nombre = format[*i] - 48;
    (*i)++;
    while (format[*i] >= '0' && format[*i] <= '9') {
        nombre = (nombre * 10) + (format[*i] - 48);
        (*i)++;
    }
    return (nombre);
}

int flag_f(char *format, va_list list, int *i, int *comptchar)
{
    int nombre = calcul_nombre(format, list, i, comptchar);
    double d = va_arg(list, double);
    int k = (int)d;
    int j = (d - k) * my_compute_power_rec(10, nombre);
    int temp = ((d - k) * my_compute_power_rec(10, nombre)) * 10;
    int l = temp % 10;

    if (j < 0)
    j = j * (-1);
    if (l > 4) {
        my_put_nbrm(k, comptchar);
        my_putcharm('.', comptchar);
        my_put_nbrm(j + 1, comptchar);
    } else {
        my_put_nbrm(k, comptchar);
        my_putcharm('.', comptchar);
        my_put_nbrm(j, comptchar);
    }
    (*i)--;
}
