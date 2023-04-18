##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

SRC			=	src/help.c				\
				src/client.c			\
				src/init_client.c		\
				src/get_output_server.c	\
				src/get_input_client.c	\
				src/select_cycle.c		\
				src/server_response.c	\

RESPONSE_FOLDER 	=	src/response_functions
RESPONSE 			=	response_default.c 			\
						response_login.c 			\
						response_initialisation.c 	\

RESPONSE 			:=	$(addprefix $(RESPONSE_FOLDER)/, $(RESPONSE))

OBJ			=	$(SRC:.c=.o)
OBJ 		+=	$(RESPONSE:.c=.o)

TESTS		=	tests/test.c

TESTS_OBJ	=	$(TESTS:.c=.o)

MAIN		=	main.c

NAME		=	../../myteams_cli

INCLUDE		=	-I./include -I../network_lib/include \
-I../../libs/myteams -I../lib/include

CFLAGS		=	-Wall -Wextra -Werror $(INCLUDE)

TEST_FLAGS	=	-lcriterion --coverage

LIB_FLAGS   =   -L../network_lib -lnetwork -L../../libs/myteams/ -lmyteams \
-L../lib/ -lmy

TEST_BINARY	=	unit_tests

CC			=	gcc

RM			=	rm -f

MV			=	mv -f

%.o:	%.c
		$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $< $(LIB_FLAGS)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(MAIN) $(CFLAGS) $(LIB_FLAGS)

debug:	CFLAGS += -g
debug:	re

tests_run:	$(TESTS_OBJ)
		$(CC) -o $(TEST_BINARY) $(SRC) $(RESPONSE) $(TESTS_OBJ) $(CFLAGS) \
		$(TEST_FLAGS) $(LIB_FLAGS)
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
