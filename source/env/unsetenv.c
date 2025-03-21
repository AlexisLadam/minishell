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

struct env_s *delete_node
(struct env_s *envs, struct env_s *prev, struct env_s *tmp)
{
    if (prev == NULL) {
        envs = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    return envs;
}

struct env_s *del_in_list(struct env_s *envs, struct shell_t *shell, int i)
{
    struct env_s *tmp = envs;
    struct env_s *prev = NULL;

    if (tmp == NULL) {
        return 0;
    }
    while (tmp != NULL) {
        if (my_strcmp(tmp->env_var, shell->command[i]) == 0) {
            envs = delete_node(envs, prev, tmp);
            return envs;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return envs;
}

void unsetenv_function(struct env_s *envs, struct shell_t *shell)
{
    int i = 1;

    if (shell->command[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        return;
    }
    while (shell->command[i] != NULL) {
        del_in_list(envs, shell, i);
        i++;
    }
    return;
}
