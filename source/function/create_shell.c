/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell2-alexis.ladam
** File description:
** create_shell
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

struct shell_t *create_shell(void)
{
    struct shell_t *shell = malloc(sizeof(struct shell_t));

    shell->path = NULL;
    shell->oldpwd = NULL;
    shell->oldpwdtemp = NULL;
    shell->pwd = NULL;
    shell->pathtmp = NULL;
    shell->home = NULL;
    shell->command = NULL;
    shell->commandtmp = NULL;
    shell->exit_value = 0;
    shell->commandpipe = NULL;
    shell->commandpipetmp = NULL;
    shell->i = 0;
}
