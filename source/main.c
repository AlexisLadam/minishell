/*
** EPITECH PROJECT, 2023
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

int main(int argc, char **argv, char **envp)
{
    struct env_s *envs = NULL;
    struct shell_t *shell = create_shell();

    if (envp[0] == NULL)
        return 84;
    envs = get_env(envp, envs);
    minishell1(shell, envs, envp);
    return shell->exit_value;
}
