##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

LIB_FOLDER 		=	functions
LIB 			=	bind_fd_addr.c		\
					connect_fd_addr.c	\
					create_addr.c		\

LIB 			:=	$(addprefix $(LIB_FOLDER)/, $(LIB))

SRC			=	$(LIB)

OBJ			=	$(SRC:.c=.o)

INCLUDE		=	-I./include

CFLAGS		=	-Wall -Wextra -Werror -Wshadow

CC			=	gcc

MV			=	mv -f

NAME	=	libnetwork.a

%.o:	%.c
		$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)


clean:
		$(RM) $(OBJ)
		$(RM) ../server/include/network_lib.h
		$(RM) ../client/include/network_lib.h

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
