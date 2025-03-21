/*
** EPITECH PROJECT, 2024
** aze
** File description:
** aze
*/

#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *modif2(char *str, char *dest, int *j, int i)
{
    if (str[i] == ';' && dest != NULL && dest[*j - 1] == ';') {
        return dest;
    }
    if (str[i] == ';' && dest != NULL && dest[*j - 1] == ' '
    && dest[*j - 2] == ';') {
        return dest;
    }
    if (str[i] == ' ' && dest[*j - 1] != '\0' && dest[*j - 1] == ';') {
        return dest;
    }
    dest[*j] = str[i];
    (*j)++;
    return dest;
}

char *modif(char *str, char *dest, int *j, int i)
{
    if (str[i] == '\t') {
        if (dest[*j - 1] != '\0' && dest[*j - 1] != ' ' &&
        str[i + 1] != '\0' && str[i + 1] != ' ' && str[i + 1] != '\t') {
            dest[*j] = ' ';
            (*j)++;
            return dest;
        }
        return dest;
    }
    if (str[i] == '\n') {
        return dest;
    }
    if (str[i] == ' ' && dest[*j - 1] != '\0' && dest[*j - 1] == ' ') {
        return dest;
    }
    dest = modif2(str, dest, j, i);
    return dest;
}

char *clean_str(char *str)
{
    int i = 0;
    int j = 0;
    char *dest = (char *) malloc((my_strlen(str) + 2) * sizeof(char));

    while (str[i] != '\0') {
        dest = modif(str, dest, &j, i);
        i++;
    }
    dest[j] = '\0';
    return dest;
}
