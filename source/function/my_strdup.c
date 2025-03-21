/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** fonction qui alloue de la memoire dunamiquement
*/

#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    str = malloc(my_strlen(src) + 1);
    while (src[i] != '\0'){
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
