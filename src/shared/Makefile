##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

SRC			=	src/load_lib.c			\
				src/load_function.c		\
				src/load_functions.c

OBJ			=	$(SRC:.c=.o)

TESTS		=	tests/test.c

TESTS_OBJ	=	$(TESTS:.c=.o)

INCLUDE		=	-I./include

CFLAGS		=	-Wall -Wextra -Werror -Wshadow

TEST_FLAGS	=	-lcriterion --coverage

TEST_BINARY	=	unit_tests

CC			=	gcc

MV			=	mv -f

%.o:	%.c
		$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all:	$(OBJ)

debug:	CFLAGS += -g
debug:	re

tests_run:	$(TESTS_OBJ)
		$(CC) -o $(TEST_BINARY) $(SRC) $(TESTS_OBJ) $(CFLAGS) $(TEST_FLAGS) \
		$(INCLUDE)
		./$(TEST_BINARY)
		gcovr -e tests
		gcovr -e tests -bu
		find . -type f -name '*.gcda' -exec $(MV) {} ../../tests/ \;
		find . -type f -name '*.gcno' -exec $(MV) {} ../../tests/ \;

clean:
		$(RM) $(OBJ)
		$(RM) $(TESTS_OBJ)

fclean:	clean
		$(RM) $(TEST_BINARY)

tclean:
		@find . -type f -name '*.gcda' -exec $(RM) {} \;
		@find . -type f -name '*.gcno' -exec $(RM) {} \;
		$(RM) $(TEST_BINARY)

re:	fclean all

.PHONY:	all clean fclean re
