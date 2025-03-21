/*
** EPITECH PROJECT, 2024
** zae
** File description:
** aze
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

static void exec_binary(struct shell_t *shell, char **envp)
{
    execve(shell->command[0], shell->command, envp);
    if (errno == ENOEXEC) {
        my_printf("%s: Exec format error. Wrong Architecture.\n", shell->command[0]);
    }
    if (errno == ENOENT) {
        my_printf("%s: Command not found.\n", shell->command[0]);
    }
}

void exec_with_dif_path(struct env_s *envs, struct shell_t *shell, char **envp)
{
    int i = 0;
    int exec_success = 1;

    if (shell->command[0] == NULL)
    return;
    while (shell->path[i] != NULL) {
        if (shell->command[0][0] == '.' || shell->command[0][0] == '/') {
            exec_binary(shell, envp);
            return;
        }
        shell->path[i] = my_strcat(shell->path[i], shell->command[0]);
        printf("%s\n", shell->path[i]);
        exec_success = execve(shell->path[i], shell->command, envp);
        if (exec_success == 0) {
            return;
        }
        i++;
    }
    my_printf("%s: Command not found.\n", shell->command[0]);
}

void exec_command2(struct env_s *envs, struct shell_t *shell)
{
    if (my_strcmp(shell->command[0], "setenv") == 0) {
        setenv_function(envs, shell);
    }
    if (my_strcmp(shell->command[0], "unsetenv") == 0) {
        unsetenv_function(envs, shell);
    }
    if (my_strcmp(shell->command[0], "cd") == 0) {
        cd_function(envs, shell);
    }
    if (my_strcmp(shell->command[0], "env") == 0) {
        env_function(envs, shell);
    }
    if (my_strcmp(shell->command[0], "exit") == 0) {
        exit_function(envs, shell);
    }
}

void fork_function(struct env_s *envs, struct shell_t *shell, char **envp)
{
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        exec_with_dif_path(envs, shell, envp);
        exit(2);
    } else {
        return_value(shell, pid);
    }
}

static int is_bin_executable2(struct shell_t *shell, struct stat path_stat)
{
    if (shell->command[0] != NULL && shell->command[0][0] == '/'
    && access(shell->command[0], X_OK) != 0) {
        my_printf("%s: Command not found.\n", shell->command[0]);
        return 84;
    }
    return 0;
}

int is_bin_executable(struct shell_t *shell)
{
    struct stat path_stat;

    if (shell->command[0] == NULL)
        return 84;
    stat(shell->command[0], &path_stat);
    if (shell->command[0] != NULL && shell->command[0][0] == '.'
    && shell->command[0][1] == '/' && access(shell->command[0], X_OK) != 0) {
        my_printf("%s: Command not found.\n", shell->command[0]);
        return 84;
    }
    if (shell->command[0] != NULL && shell->command[0][0] == '.'
    && shell->command[0][1] == '/' && S_ISDIR(path_stat.st_mode) ||
    shell->command[0] != NULL && shell->command[0][0] == '/'
    && S_ISDIR(path_stat.st_mode)) {
        my_printf("%s: Permission denied.\n", shell->command[0]);
        return 84;
    }
    if (is_bin_executable2(shell, path_stat) == 84)
        return 84;
    return 0;
}

void exec_command(struct env_s *envs, struct shell_t *shell, char **envp)
{
    if (shell->command[0] != NULL &&
    (my_strcmp(shell->command[0], "setenv") == 0 ||
    my_strcmp(shell->command[0], "unsetenv") == 0 ||
    my_strcmp(shell->command[0], "exit") == 0 ||
    my_strcmp(shell->command[0], "cd") == 0 ||
    my_strcmp(shell->command[0], "env") == 0)) {
        exec_command2(envs, shell);
        return;
    }
    if (is_bin_executable(shell) == 84) {
        return;
    }
    fork_function(envs, shell, envp);
}
