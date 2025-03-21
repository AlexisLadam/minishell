##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

SRC	=	source/appelunsigned.c		\
		source/my_printf_autre_2.c	\
		source/my_printf_autre.c	\
		source/my_printf.c		\
		source/number.c			\
		source/unsigned.c		\
		source/float.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp source/printf.h include

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
