/*
** EPITECH PROJECT, 2023
** aze
** File description:
** aze
*/

#ifndef MY_H_
    #define MY_H_

    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <struct.h>

void env_function(struct env_s *envs, struct shell_t *shell);
void exit_function(struct env_s *envs, struct shell_t *shell);
void get_home(struct env_s *envs, struct shell_t *shell);
int len_tab(char *str, int i, char separator);
void return_value(struct shell_t *shell, pid_t pid);
int nb_tableau(char *str, char separator);
struct shell_t *create_shell(void);
void get_oldpwd(struct env_s *envs, struct shell_t *shell);
void get_pwd(struct env_s *envs, struct shell_t *shell);
int define_command(struct shell_t *shell);
char **my_str_to_word_array2(char **dest, int *j, int *i);
void exec_multiple_command(struct shell_t *shell, char **multiple_cmd,
    struct env_s *envs, char **envp);
int compte_mot(char *str);
int is_pipe(struct shell_t *shell, struct env_s *envs, char **envp);
char **my_str_to_word_array(char *str, char separ);
void cd_function(struct env_s *envs, struct shell_t *shell);
void setenv_function(struct env_s *envs, struct shell_t *shell);
char **my_str_to_word_array_bis(char *str, char separ);
int minishell1(struct shell_t *shell, struct env_s *envs, char **envp);
void unsetenv_function(struct env_s *envs, struct shell_t *shell);
char *my_strcpy(char *dest, char const *src);
void exec_command(struct env_s *envs, struct shell_t *shell, char **envp);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
char *clean_str(char *str);
int my_printf(char *format, ...);
struct env_s *put_in_list(struct env_s **envs, char *var, char *value);
int end_charstar(char *str);
int disp(struct env_s *envs);
int my_putstr(char const *str);
int my_strlen(char const *str);
int get_path(struct env_s *envs, struct shell_t *shell);
int my_putchar(char c);
struct env_s *get_env(char **env, struct env_s *envs);
int *my_strcpy_chainlist_to_struct(struct shell_t *shell, struct env_s *tmp);
#endif
