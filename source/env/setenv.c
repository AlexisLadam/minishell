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

void setenv_simple(struct env_s *envs, struct shell_t *shell)
{
    struct env_s *tmp = envs;

    if (tmp == NULL) {
        return;
    }
    while (tmp != NULL) {
        if (my_strcmp(tmp->env_var, shell->command[1]) == 0) {
            tmp->env_value = NULL;
            envs = tmp;
            return;
        }
        tmp = tmp->next;
    }
    put_in_list(&envs, shell->command[1], shell->command[2]);
}

void setenv_all(struct env_s *envs, struct shell_t *shell)
{
    struct env_s *tmp = envs;

    if (tmp == NULL) {
        return;
    }
    while (tmp != NULL) {
        if (my_strcmp(tmp->env_var, shell->command[1]) == 0) {
            tmp->env_value = shell->command[2];
            envs = tmp;
            return;
        }
        tmp = tmp->next;
    }
    put_in_list(&envs, shell->command[1], shell->command[2]);
}

int verif_arg2(struct shell_t *shell)
{
    int i = 0;

    while (shell->command[2][i] != '\0') {
        if (!((shell->command[2][i] >= 'a' && shell->command[2][i] <= 'z') ||
            (shell->command[2][i] >= 'A' && shell->command[2][i] <= 'Z'))) {
            return 84;
        }
        i++;
    }
    return 0;
}

int verif_arg1(struct shell_t *shell)
{
    int i = 0;

    while (shell->command[1][i] != '\0') {
        if (!((shell->command[1][i] >= 'a' && shell->command[1][i] <= 'z') ||
            (shell->command[1][i] >= 'A' && shell->command[1][i] <= 'Z'))) {
            return 84;
        }
        i++;
    }
    return 0;
}

void setenv_function(struct env_s *envs, struct shell_t *shell)
{
    if (shell->command[1] == NULL) {
            disp(envs);
            shell->exit_value = 0;
    }
    if (shell->command[1] != NULL && shell->command[2] == NULL) {
        if (verif_arg1(shell) == 84) {
            my_printf("setenv: Variable name must ");
            my_printf("contain alphanumeric characters.\n");
            return;
        }
        setenv_simple(envs, shell);
    }
    if (shell->command[1] != NULL && shell->command[2] != NULL) {
        if (verif_arg1(shell) == 84) {
            my_printf("setenv: Variable name must ");
            my_printf("contain alphanumeric characters.\n");
            return;
        }
        setenv_all(envs, shell);
    }
}
