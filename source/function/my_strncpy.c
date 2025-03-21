/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** mettre dans une chaine de caractere n nombre de char venant d'une autre
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

int *my_strcpy_chainlist_to_struct(struct shell_t *shell, struct env_s *tmp)
{
    int i = 0;
    int j = 0;

    shell->pathtmp = malloc(my_strlen(tmp->env_value) + 2);
    while (tmp->env_value[i] != '\0'){
        shell->pathtmp[j] = tmp->env_value[i];
        i++;
        j++;
    }
    shell->pathtmp[j] = '\0';
    return 0;
}
