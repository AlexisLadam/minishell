/*
** EPITECH PROJECT, 2023
** number printf
** File description:
** oct hex dec
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "printf.h"

int my_uns_oct(unsigned long decimalnum, int *comptchar)
{
    unsigned long long octalnum = 0;
    unsigned long temp = 1;

    while (decimalnum != 0) {
        octalnum = octalnum + (decimalnum % 8) * temp;
        decimalnum = decimalnum / 8;
        temp = temp * 10;
    }
    my_uns_nbr(octalnum, comptchar);
    return (0);
}

int my_pointer(unsigned long decimal, int *comptchar)
{
    my_putcharm('0', comptchar);
    my_putcharm('x', comptchar);
    my_uns_hex(decimal, comptchar);
}

int my_putnbr(int nb)
{
    int n = 0;

    if (nb < 0){
        my_putchar('-');
        my_putnbr(nb * (-1));
        return (0);
    }
    if (nb < 10){
        my_putchar(nb + 48);
    } else {
        my_putnbr(nb / 10);
        n = nb % 10;
        my_putchar(n + 48);
    }
    return (0);
}
