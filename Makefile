##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

SRC		=

OBJ		=	$(SRC:.c=.o)

MAIN	=	main.c

NAME	=	myteams

INCLUDE	=	-I./include

CFLAGS	=	-Wall -Wextra -Werror $(INCLUDE)

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(MAIN) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
