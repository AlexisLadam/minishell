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

int define_command(struct shell_t *shell)
{
    char *command_temp = strtok(shell->commandtmp, " ");
    int i = 0;

    while (command_temp != NULL) {
        shell->command[i] = (char *) malloc(my_strlen(command_temp) + 1);
        if (shell->command[i] == NULL) {
            return -1;
        }
        shell->command[i] = command_temp;
        command_temp = strtok(NULL, " ");
        i++;
    }
    shell->command[i] = NULL;
}

void prep_for_exec_cmd
(struct shell_t *shell, char *input, struct env_s *envs, char **envp)
{
    char **multiple_cmd;

    shell->commandtmp = clean_str(input);
    multiple_cmd = my_str_to_word_array_bis(shell->commandtmp, ';');
    if (multiple_cmd[0] != NULL && multiple_cmd[1] == NULL) {
        // if (is_pipe(shell, envs, envp) == 1) {
        //     return;
        // }
        shell->command = (char **) malloc
        ((compte_mot(shell->commandtmp) + 3) * sizeof(char *));
        define_command(shell);
        get_pwd(envs, shell);
        exec_command(envs, shell, envp);
    }
    if (multiple_cmd[0] != NULL && multiple_cmd[1] != NULL) {
        exec_multiple_command(shell, multiple_cmd, envs, envp);
    }
}

void is_atty(int fd)
{
    if (isatty(fd))
        my_putstr("exit\n");
    exit(0);
}

int minishell1(struct shell_t *shell, struct env_s *envs, char **envp)
{
    char *input = NULL;
    size_t len = 0;
    ssize_t nread;
    int fd = 0;

    get_path(envs, shell);
    shell->path = my_str_to_word_array(shell->pathtmp, ':');
    while (1) {
        if (isatty(fd))
            my_printf("$> ");
        nread = getline(&input, &len, stdin);
        if (nread != -1) {
            prep_for_exec_cmd(shell, input, envs, envp);
        } else {
            is_atty(fd);
        }
    }
}
