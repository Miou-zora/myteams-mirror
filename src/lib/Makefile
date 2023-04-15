##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

LIB_FOLDER 		=	functions
LIB 			=	str_to_word_array.c

LIB 			:=	$(addprefix $(LIB_FOLDER)/, $(LIB))

SRC			=	$(LIB)

OBJ			=	$(SRC:.c=.o)

INCLUDE		=	-I./include

CFLAGS		=	-Wall -Wextra -Werror -Wshadow

CC			=	gcc

MV			=	mv -f

NAME	=	libmy.a

%.o:	%.c
		$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all:	$(NAME)
		cp -r include/ ../server/
		cp -r include/ ../client/

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../server/
	$(MV) $(NAME) ../client/


clean:
		$(RM) $(OBJ)
		$(RM) ../server/include/lib.h
		$(RM) ../client/include/lib.h

fclean:	clean
		$(RM) ../server/$(NAME)
		$(RM) ../client/$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
