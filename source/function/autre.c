/*
** EPITECH PROJECT, 2023
** aez
** File description:
** ae
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/printf.h"
#include "struct.h"

int end_charstar(char *str)
{
    int i = 0;

    while (str[i] != '\n') {
        i++;
    }
    str[i] = '\0';
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int finp = 0;
    char *result = malloc(my_strlen(dest) + my_strlen(src) + 1);

    while (dest[finp] != '\0'){
        result[finp] = dest[finp];
        finp++;
    }
    while (src[i] != '\0'){
        result[finp] = src[i];
        i++;
        finp++;
    }
    result[finp] = '\0';
    return result;
}

int compte_mot(char *str)
{
    int compteur = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ';') {
            compteur++;
        }
        i++;
    }
    return (compteur);
}

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
