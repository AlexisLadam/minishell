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

int *my_strcpy_home(struct shell_t *shell, struct env_s *tmp)
{
    int i = 0;
    int j = 0;

    shell->home = malloc(my_strlen(tmp->env_value) + 3);
    while (tmp->env_value[i] != '\0'){
        shell->home[j] = tmp->env_value[i];
        i++;
        j++;
    }
    shell->home[j] = '/';
    shell->home[j + 1] = '\0';
    return 0;
}

void get_home(struct env_s *envs, struct shell_t *shell)
{
    struct env_s *tmp = envs;

    if (tmp == NULL) {
        return;
    }
    while (tmp != NULL) {
        if (my_strcmp(tmp->env_var, "HOME") == 0) {
            my_strcpy_home(shell, tmp);
        }
        tmp = tmp->next;
    }
}
