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

void env_function(struct env_s *envs, struct shell_t *shell)
{
    if (shell->command[0] != NULL && shell->command[1] == NULL) {
        disp(envs);
        return;
    }
}
