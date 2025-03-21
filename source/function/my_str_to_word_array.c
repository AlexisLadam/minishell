/*
** EPITECH PROJECT, 2023
** aez
** File description:
** aze
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/printf.h"
#include "struct.h"

int len_tab(char *str, int i, char separator)
{
    int compteur = 0;

    while (str[i] != '\0' && str[i] != separator) {
        compteur++;
        i++;
    }
    return compteur;
}

int nb_tableau(char *str, char separator)
{
    int compteur = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == separator) {
            compteur++;
        }
        i++;
    }
    return (compteur);
}

char **my_str_to_word_array2(char **dest, int *j, int *i)
{
    (*i)++;
    (*j)++;
    return (dest);
}

char **my_str_to_word_array(char *str, char separ)
{
    char **dest;
    int i = 0;
    int j = 0;
    int k = 0;

    dest = (char **) malloc((nb_tableau(str, separ) + 2) * sizeof(char *));
    while (i <= my_strlen(str)) {
        k = 0;
        dest[j] = (char *) malloc((len_tab(str, i, separ) + 2) * sizeof(char));
        while (str[i] != '\0' && str[i] != separ) {
            dest[j][k] = str[i];
            k++;
            i++;
        }
        dest[j][k] = '/';
        dest[j][k + 1] = '\0';
        my_str_to_word_array2(dest, &j, &i);
    }
    dest[j] = NULL;
    return (dest);
}
