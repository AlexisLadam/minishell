/*
** EPITECH PROJECT, 2023
** autre mini printf
** File description:
** aze
*/

#include <unistd.h>
#include "printf.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int my_strlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++){
        count++;
    }
    return count;
}

int my_putcharm(char c, int *comptchar)
{
    write(1, &c, 1);
    *comptchar += 1;
}

int my_putstrm(char const *str, int *comptchar)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putcharm(str[i], comptchar);
        i++;
    }
}

int my_compute_power_rec(int nb, int p)
{
    unsigned int res;

    if (p < 0){
        return (0);
    }
    if (p == 0){
        return (1);
    }
    res = nb * my_compute_power_rec(nb, p - 1);
    return (res);
}
