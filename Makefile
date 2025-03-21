##
## EPITECH PROJECT, 2023
## aze
## File description:
## aze
##

NAME =  mysh

SRC =   source/main.c \
		source/function/create_shell.c \
		source/function/my_str_to_word_array.c \
        source/function/autre.c \
		source/function/clean_str.c \
		source/env/create_env.c \
		source/function/my_strcmp.c \
		source/function/my_strncpy.c \
		source/function/my_strdup.c \
		source/function/getpath.c \
		source/exec/exec_command.c \
		source/env/setenv.c \
		source/env/unsetenv.c \
		source/cd/cd.c \
		source/env/env.c \
		source/exec/minishell.c \
		source/return/exit.c \
		source/cd/get_pwd_oldpwd.c \
		source/cd/get_home.c \
		source/exec/exec_multiple_command.c \
		source/return/segfault_and_return.c \
		#source/exec/exec_pipe.c \

OBJ =   $(SRC:.c=.o)

CFLAGS = -I./include -I. -g

all:    makelib $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L ./lib/my/ -lmy -g

clean:
	rm -f $(OBJ)

makelib:
	make -C ./lib/my

fclean: clean
	rm -f $(NAME)

re: fclean all
