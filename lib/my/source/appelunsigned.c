/*
** EPITECH PROJECT, 2023
** fonction
** File description:
** put
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "printf.h"

int my_print_unsign(char *format, va_list list, int *i, int *comptchar)
{
    if (format[*i] == '%' && format[*i + 1] == 'u')
        my_uns_nbr(va_arg(list, unsigned long), comptchar);
    if (format[*i] == '%' && format[*i + 1] == 'o')
        my_uns_oct(va_arg(list, unsigned long), comptchar);
    if (format[*i] == '%' && format[*i + 1] == 'x')
        my_uns_hex(va_arg(list, unsigned long), comptchar);
    if (format[*i] == '%' && format[*i + 1] == 'X')
        my_maj_hex(va_arg(list, unsigned long), comptchar);
    if (format[*i] == '%' && format[*i + 1] == 'p')
        my_pointer(va_arg(list, unsigned long), comptchar);
}
