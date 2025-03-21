/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell2-alexis.ladam
** File description:
** exec_pipe
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

////// objectif, avoir dans commandpipe[0] le gauche et dans 1 le droit du pipe
////// et dans shell->command[0] la commande a faire et ses parametres seront dans commandpipe
void exec_pipe(struct shell_t *shell, struct env_s *envs, char **envp)
{
    int fd[2];
    int pid1;
    int pid2;w

    if (pipe(fd) == -1) {
    -    return;
    }
    pid1 = fork();
    if (pid1 == 0) {
        dup2(fd[1], STDOUT_FILENO); 
        close(fd[0]);
        close(fd[1]);
        //execvp(shell->command[0], shell->command);
    }
    pid2 = fork() {
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);
        //execvp(shell->command[2], &shell->command[2]);
    }
}

int define_command_pipe(struct shell_t *shell)
{
    int i = 0;
    char *command_temp = strtok(shell->commandpipetmp[i], " ");

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

void prep_exec_pipe(struct shell_t *shell, struct env_s *envs, char **envp)
{
    int i = 0;

    ///////// séparer les commandes du pipes et les mettre dans ma structure
    ///////// exemple : ls -l | grep a -> ls -l dans pipe[0] et grep a dans pipe[1]
    ///////// dans commandpipetmp[0] j'ai la parti gauche du pipe et dans commandpipetmp[1] la partie droite du pipe 
    while (shell->commandpipetmp[i] != NULL) {
        shell->command = (char **) malloc
        ((compte_mot(shell->commandpipetmp[i]) + 3) * sizeof(char *));
        define_command_pipe(shell);
        get_pwd(envs, shell);
    }
}

int is_pipe(struct shell_t *shell, struct env_s *envs, char **envp)
{
    int i = 0;
    int compteur = 0;

    while (shell->commandtmp[i] != '\0') {
        if (shell->commandtmp[i] == '|') {
            compteur++;
        }
        i++;
    }
    if (compteur == 1) {
        shell->commandpipe = my_str_to_word_array_bis(shell->commandtmp, '|');
        printf("commandpipe[0] = %s\ncommandpipe[1] = %s\n", shell->commandpipe[0], shell->commandpipe[1]);
        exec_pipe(shell, envs, envp);
        return 1;
    }
    return 0;    
}

