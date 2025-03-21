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

int disp(struct env_s *envs)
{
    struct env_s *tmp = envs;

    while (tmp != NULL) {
        if (tmp->env_value != NULL) {
            my_printf("%s=%s\n", tmp->env_var, tmp->env_value);
        } else {
            my_printf("%s=\n", tmp->env_var);
        }
        tmp = tmp->next;
    }
    return 0;
}

struct env_s *put_in_list(struct env_s **envs, char *var, char *value)
{
    struct env_s *element = malloc(sizeof(struct env_s));
    struct env_s *last = *envs;

    if (element == NULL)
        return NULL;
    element->env_var = var;
    if (value != NULL)
        element->env_value = value;
    else
        element->env_value = "";
    element->next = NULL;
    if (*envs == NULL) {
        *envs = element;
        return 0;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = element;
    return 0;
}

char *get_var(char **env, int i)
{
    char *var;
    int j = 0;
    int compteur = 0;

    while (env[i][j] != '=') {
        j++;
        compteur++;
    }
    j = 0;
    var = (char *) malloc((compteur + 1) * sizeof(char));
    while (env[i][j] != '=') {
        var[j] = env[i][j];
        j++;
    }
    var[j] = '\0';
    return var;
}

char *get_value(char **env, int i)
{
    char *value;
    int k = 0;
    int j = 0;
    int compteur = 1;

    while (env[i][j] != '=') {
        j++;
        compteur++;
    }
    j++;
    value = (char *) malloc((my_strlen(env[i]) - compteur + 1) * sizeof(char));
    while (env[i][j] != '\0') {
        value[k] = env[i][j];
        j++;
        k++;
    }
    value[k] = '\0';
    return value;
}

struct env_s *get_env(char **env, struct env_s *envs)
{
    char *var;
    char *value;
    int i = 0;

    while (env[i] != NULL) {
        var = get_var(env, i);
        value = get_value(env, i);
        put_in_list(&envs, var, value);
        i++;
    }
    return envs;
}
