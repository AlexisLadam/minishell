/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell2-alexis.ladam
** File description:
** segfault_and_return
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

void return_value2(struct shell_t *shell, pid_t status)
{
    int term_sig = WTERMSIG(status);

    if (term_sig == SIGSEGV) {
        shell->exit_value = -1;
        my_printf("Segmentation fault");
        if (WCOREDUMP(status)) {
            my_printf(" (core dumped)");
        }
        my_printf("\n");
    }
}

void return_value(struct shell_t *shell, pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
        shell->exit_value = WEXITSTATUS(status);
    } else if (WIFSIGNALED(status)) {
        return_value2(shell, status);
    }
}
