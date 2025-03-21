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

void cd_oldpwd(struct env_s *envs, struct shell_t *shell)
{
    struct env_s *tmp = envs;
    struct env_s *tmpp = envs;

    while (tmp != NULL) {
        if (my_strcmp(tmp->env_var, "OLDPWD") == 0) {
            tmp->env_value = shell->pwd;
            envs = tmp;
            break;
        }
        tmp = tmp->next;
    }
    while (tmpp != NULL) {
        if (my_strcmp(tmpp->env_var, "PWD") == 0) {
            tmpp->env_value = shell->oldpwd;
            envs = tmpp;
            break;
        }
        tmpp = tmpp->next;
    }
    shell->oldpwd = shell->oldpwdtemp;
}

void cd_with_path(struct env_s *envs, struct shell_t *shell)
{
    struct env_s *tmp = envs;
    struct env_s *tmpp = envs;
    char *c = NULL;

    while (tmp != NULL) {
        if (my_strcmp(tmp->env_var, "OLDPWD") == 0) {
            tmp->env_value = shell->pwd;
            envs = tmp;
        }
        tmp = tmp->next;
    }
    while (tmpp != NULL) {
        if (my_strcmp(tmpp->env_var, "PWD") == 0) {
            tmpp->env_value = getcwd(c, 500);
            envs = tmpp;
            break;
        }
        tmpp = tmpp->next;
    }
    shell->oldpwd = shell->oldpwdtemp;
}

void cd_basic(struct env_s *envs, struct shell_t *shell)
{
    struct env_s *tmp = envs;
    struct env_s *tmpp = envs;

    while (tmp != NULL) {
        if (my_strcmp(tmp->env_var, "OLDPWD") == 0) {
            tmp->env_value = shell->pwd;
            envs = tmp;
        }
        tmp = tmp->next;
    }
    while (tmpp != NULL) {
        if (my_strcmp(tmpp->env_var, "PWD") == 0) {
            tmpp->env_value = shell->home;
            envs = tmpp;
            break;
        }
        tmpp = tmpp->next;
    }
    shell->oldpwd = shell->oldpwdtemp;
}

static void error_cd_with_path(struct env_s *envs, struct shell_t *shell)
{
    if (access(shell->command[1], F_OK) == 0) {
        my_printf("%s: Not a directory.\n", shell->command[1]);
        return;
    }
    my_printf("%s: No such file or directory.\n", shell->command[1]);
}

void cd_function2(struct env_s *envs, struct shell_t *shell)
{
    if (shell->command[1] != NULL && my_strcmp(shell->command[1], "~") == 0) {
        if (chdir(shell->home) == 0) {
            cd_basic(envs, shell);
        }
        return;
    }
    if (shell->command[1] != NULL && shell->command[2] == NULL) {
        if (chdir(shell->command[1]) == 0) {
            cd_with_path(envs, shell);
        } else {
            error_cd_with_path(envs, shell);
        }
    }
    if (shell->command[1] != NULL && shell->command[2] != NULL) {
        my_printf("cd: Too many arguments.");
    }
}

static void cd_old_not_working(struct env_s *envs, struct shell_t *shell)
{
    if (shell->oldpwd == NULL) {
        my_printf(": No such file or directory.\n");
    } else {
        my_printf(("%s: No such file or directory.\n"), shell->oldpwd);
    }
}

void cd_function(struct env_s *envs, struct shell_t *shell)
{
    get_oldpwd(envs, shell);
    if (shell->command[1] == NULL) {
        if (chdir(shell->home) == 0)
            cd_basic(envs, shell);
    }
    if (shell->command[1] != NULL && my_strcmp(shell->command[1], "-") == 0) {
        if (shell->oldpwd != NULL && chdir(shell->oldpwd) == 0) {
            cd_oldpwd(envs, shell);
        } else {
            cd_old_not_working(envs, shell);
            return;
        }
        return;
    }
    cd_function2(envs, shell);
}
