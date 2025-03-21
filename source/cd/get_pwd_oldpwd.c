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

int *my_strcpy_pwd(struct shell_t *shell, struct env_s *tmp)
{
    int i = 0;
    int j = 0;

    shell->pwd = malloc(my_strlen(tmp->env_value) + 2);
    while (tmp->env_value[i] != '\0'){
        shell->pwd[j] = tmp->env_value[i];
        i++;
        j++;
    }
    shell->pwd[j] = '\0';
    return 0;
}

void get_pwd(struct env_s *envs, struct shell_t *shell)
{
    struct env_s *tmp = envs;

    if (tmp == NULL) {
        return;
    }
    while (tmp != NULL) {
        if (my_strcmp(tmp->env_var, "PWD") == 0) {
            my_strcpy_pwd(shell, tmp);
        }
        tmp = tmp->next;
    }
}

int *my_strcpy_oldpwd(struct shell_t *shell, struct env_s *tmp)
{
    int i = 0;
    int j = 0;

    shell->oldpwd = malloc(my_strlen(tmp->env_value) + 3);
    while (tmp->env_value[i] != '\0'){
        shell->oldpwd[j] = tmp->env_value[i];
        i++;
        j++;
    }
    shell->oldpwd[j] = '/';
    shell->oldpwd[j + 1] = '\0';
    return 0;
}

void get_oldpwd(struct env_s *envs, struct shell_t *shell)
{
    char *c = NULL;

    shell->oldpwdtemp = getcwd(c, 500);
}
