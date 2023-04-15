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

CORE_FOLDER 	=	src/core
CORE 			=	server_init.c 		\
					create_socket.c 	\
					server_loop.c 		\
					accept_connections.c \
					client_actions.c 	\
					leave_instance.c 		\
					set_actual_instance.c \

CORE 			:=	$(addprefix $(CORE_FOLDER)/, $(CORE))

SRC			=	$(COMMANDS)
SRC 		+=	$(CORE)

OBJ			=	$(SRC:.c=.o)

TESTS		=	tests/test.c

TESTS_OBJ	=	$(TESTS:.c=.o)

MAIN		=	main.c

OBJ_MAIN	=	$(MAIN:.c=.o)

NAME		=	../../myteams_server

INCLUDE		=	-I./include

CFLAGS		=	-Wall -Wextra -Werror -Wshadow

TEST_FLAGS	=	-lcriterion --coverage

LIB_FLAGS	=	-L./ -lmy

TEST_BINARY	=	unit_tests

CC			=	gcc

MV			=	mv -f

%.o:	%.c
		$(CC) $(CFLAGS) $(LIB_FLAGS) $(INCLUDE) -o $@ -c $<

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
		$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(INCLUDE) $(LIB_FLAGS)

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
		$(RM) $(OBJ_MAIN)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(TEST_BINARY)

tclean:
		@find . -type f -name '*.gcda' -exec $(RM) {} \;
		@find . -type f -name '*.gcno' -exec $(RM) {} \;
		$(RM) $(TEST_BINARY)

re:	fclean all

.PHONY:	all clean fclean re
