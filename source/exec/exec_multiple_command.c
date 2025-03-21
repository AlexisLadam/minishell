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

char **my_str_to_word_array_bis(char *str, char separ)
{
    char **dest;
    int i = 0;
    int j = 0;
    int k = 0;

    dest = (char **) malloc((nb_tableau(str, separ) + 2) * sizeof(char *));
    while (i <= my_strlen(str)) {
        k = 0;
        dest[j] = (char *) malloc((len_tab(str, i, separ) + 2) * sizeof(char));
        while (str[i] != '\0' && str[i] != separ) {
            dest[j][k] = str[i];
            k++;
            i++;
        }
        dest[j][k] = '\0';
        my_str_to_word_array2(dest, &j, &i);
    }
    dest[j] = NULL;
    return (dest);
}

int define_command2(struct shell_t *shell, char *multiple_cmd)
{
    char *command_temp = strtok(multiple_cmd, " ");
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

void exec_multiple_command(struct shell_t *shell, char **multiple_cmd,
    struct env_s *envs, char **envp)
{
    int i = 0;

    while (multiple_cmd[i] != NULL) {
        shell->command = (char **) malloc
        ((compte_mot(multiple_cmd[i]) + 3) * sizeof(char *));
        define_command2(shell, multiple_cmd[i]);
        get_pwd(envs, shell);
        exec_command(envs, shell, envp);
        i++;
    }
}
