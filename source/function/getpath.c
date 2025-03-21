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

int get_path(struct env_s *envs, struct shell_t *shell)
{
    struct env_s *tmp = envs;

    if (tmp == NULL) {
        return 0;
    }
    while (tmp != NULL) {
        if (my_strcmp(tmp->env_var, "PATH") == 0) {
            my_strcpy_chainlist_to_struct(shell, tmp);
        }
        tmp = tmp->next;
    }
    get_home(envs, shell);
}
