/*
** EPITECH PROJECT, 2023
** struct
** File description:
** struct
*/

#ifndef STRUCT_H
    #define STRUCT_H

struct env_s {
    char *env_var;
    char *env_value;
    struct env_s *next;
};

struct shell_t {
    char *pwd;
    char *oldpwd;
    char *home;
    char **command;
    char *commandtmp;
    char *pathtmp;
    char **path;
    int i;
    char *oldpwdtemp;
    int exit_value;
    char **commandpipetmp;
    char **commandpipe;
};

#endif /* STRUCT_H */
