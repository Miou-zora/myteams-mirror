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

TESTS_FOLDER	=	tests
TESTS			=	test_split_line.c

TESTS			:=	$(addprefix $(TESTS_FOLDER)/, $(TESTS))

TESTS_OBJ		=	$(TESTS:.c=.o)

LIB 			:=	$(addprefix $(LIB_FOLDER)/, $(LIB))

SRC			=	$(LIB)

OBJ			=	$(SRC:.c=.o)

INCLUDE		=	-I./include

CFLAGS		=	-Wall -Wextra -Werror -Wshadow

CC			=	gcc

MV			=	mv -f

TEST_FLAGS	=	-lcriterion --coverage

NAME	=	libmy.a

TEST_BINARY	=	unit_tests

%.o:	%.c
		$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

debug:	CFLAGS += -g
debug:	re

tests_run: $(TESTS_OBJ)
		$(CC) -o $(TEST_BINARY) $(TESTS_OBJ) $(TEST_FLAGS) $(CFLAGS) \
		$(INCLUDE) $(SRC)
		./$(TEST_BINARY)
		gcovr -e tests
		gcovr -e tests -bu
		find . -type f -name '*.gcda' -exec $(MV) {} ../../tests/ \;
		find . -type f -name '*.gcno' -exec $(MV) {} ../../tests/ \;

clean:
		$(RM) $(OBJ)
		$(RM) ../server/include/lib.h
		$(RM) ../client/include/lib.h
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
