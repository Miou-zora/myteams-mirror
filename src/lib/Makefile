##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

LIB_FOLDER 		=	functions
LIB 			=	str_to_word_array.c		\
					get_array_size.c		\
					delete_quotes.c			\
					parse_string.c			\
					split_line.c

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

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)


clean:
		$(RM) $(OBJ)
		$(RM) ../server/include/lib.h
		$(RM) ../client/include/lib.h

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
