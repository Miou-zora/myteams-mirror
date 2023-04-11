##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

COMMANDS_FOLDER	=	src/commands
COMMANDS 		=	help.c			\
					login.c			\
					logout.c		\
					user.c			\
					users.c			\
					send.c			\
					messages.c		\
					subscribe.c		\
					subscribed.c	\
					unsubscribe.c	\
					use.c			\
					create.c		\
					list.c			\
					info.c			\
					quit.c			\
					commands.c
COMMANDS		:=	$(addprefix $(COMMANDS_FOLDER)/, $(COMMANDS))

SRC			=	$(COMMANDS)

OBJ			=	$(SRC:.c=.o)

TESTS		=	tests/test.c

TESTS_OBJ	=	$(TESTS:.c=.o)

MAIN		=	main.c

NAME		=	../../myteams_server

INCLUDE		=	-I./include

CFLAGS		=	-Wall -Wextra -Werror -Wshadow

TEST_FLAGS	=	-lcriterion --coverage

TEST_BINARY	=	unit_tests

CC			=	gcc

%.o:	%.c
		$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(MAIN) $(CFLAGS) $(INCLUDE)

debug:	CFLAGS += -g
debug:	re

tests_run:	$(TESTS_OBJ)
		$(CC) -o $(TEST_BINARY) $(SRC) $(TESTS_OBJ) $(CFLAGS) $(TEST_FLAGS)
		./$(TEST_BINARY)
		gcovr -e tests
		gcovr -e tests -bu

clean:
		$(RM) $(OBJ)
		$(RM) $(TESTS_OBJ)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(TEST_BINARY)

tclean:
		$(RM) tests/*.gcno
		$(RM) tests/*.gcda
		$(RM) *.gcno
		$(RM) *.gcda
		$(RM) $(TEST_BINARY)

re:	fclean all

.PHONY:	all clean fclean re
