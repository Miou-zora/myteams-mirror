##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

SRC			=	src/load_lib.c				\
				src/load_function.c			\
				src/load_functions.c		\
				src/unload_lib.c			\
				src/unload_functions.c		\
				src/load_shared_lib.c		\
				src/unload_shared_lib.c		\
				src/get_fcn_shared_lib.c	\
				src/freen.c

OBJ			=	$(SRC:.c=.o)

TESTS		=	tests/test_unload_functions.c

TESTS_OBJ	=	$(TESTS:.c=.o)

INCLUDE		=	-I./include

CFLAGS		=	-Wall -Wextra -Werror -Wshadow

TEST_FLAGS	=	-lcriterion --coverage

TEST_BINARY	=	unit_tests

NAME		=	libshared.a

CC			=	gcc

MV			=	mv -f

%.o:	%.c
		$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

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
		$(RM) $(NAME)
		$(RM) $(TEST_BINARY)

tclean:
		@find . -type f -name '*.gcda' -exec $(RM) {} \;
		@find . -type f -name '*.gcno' -exec $(RM) {} \;
		$(RM) $(TEST_BINARY)

re:	fclean all

.PHONY:	all clean fclean re
