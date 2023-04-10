##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

SRC			=

OBJ			=	$(SRC:.c=.o)

TESTS		=	tests/test.c

TESTS_OBJ	=	$(TESTS:.c=.o)

MAIN		=	main.c

NAME		=	myteams

INCLUDE		=	-I./include

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDE)

TEST_FLAGS	=	-lcriterion --coverage

TEST_BINARY	=	unit_tests

CC			=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(MAIN) $(CFLAGS)

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
