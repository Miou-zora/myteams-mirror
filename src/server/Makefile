##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

COMMANDS_FOLDER	=	commands
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

CORE_FOLDER 	=	core
CORE 			=	server_init.c 		\
					create_socket.c 	\
					server_loop.c 		\
					accept_connections.c \
					client_actions.c 	\
					leave_instance.c 		\
					set_actual_instance.c \

CORE 			:=	$(addprefix $(CORE_FOLDER)/, $(CORE))

RESPONSE_FOLDER =	response
RESPONSE 		=	response.c

RESPONSE 		:=	$(addprefix $(RESPONSE_FOLDER)/, $(RESPONSE))

UUID_LIST_FOLDER =	uuid_list
UUID_LIST 		=	add_uuid.c					\
					del_uuid.c					\
					init_list_of_uuids.c			\

UUID_LIST 		:=	$(addprefix $(UUID_LIST_FOLDER)/, $(UUID_LIST))

USER_FOLDER		=	user
USER			=	init_list_of_users.c			\
					add_user.c						\
					add_user_with_uuid.c			\
					del_user.c						\
					del_list_of_users.c				\

USER			:=	$(addprefix $(USER_FOLDER)/, $(USER))

TEAM_FOLDER		=	team
TEAM			=	init_list_of_teams.c			\
					add_team.c						\
					add_team_with_uuid.c			\
					del_team.c						\
					del_list_of_teams.c				\
					add_user_to_team.c				\
					del_user_from_team.c			\

TEAM			:=	$(addprefix $(TEAM_FOLDER)/, $(TEAM))

SRC_FOLDER	=	src
SRC			=	$(COMMANDS)
SRC 		+=	$(CORE)
SRC 		+=	$(RESPONSE)
SRC 		+=	$(USER)
SRC 		+=	$(TEAM)
SRC 		+=	$(UUID_LIST)
SRC 		:=	$(addprefix $(SRC_FOLDER)/, $(SRC))

OBJ			=	$(SRC:.c=.o)

TESTS_USER		=	test_add_user.c				\
					test_add_user_with_uuid.c	\
					test_del_user.c				\
					test_del_list_of_users.c	\

TESTS_USER		:=	$(addprefix $(USER_FOLDER)/, $(TESTS_USER))

TESTS_TEAM_FOLDER	=	team
TESTS_TEAM			=	test_add_team.c				\
						test_add_team_with_uuid.c	\
						test_del_team.c				\
						test_del_list_of_teams.c	\
						test_add_user_to_team.c		\
						test_del_user_from_team.c	\

TESTS_TEAM			:=	$(addprefix $(TESTS_TEAM_FOLDER)/, $(TESTS_TEAM))

TESTS_UUID_LIST_FOLDER	=	uuid_list
TESTS_UUID_LIST			=	test_add_uuid.c				\

TESTS_UUID_LIST			:=	$(addprefix $(TESTS_UUID_LIST_FOLDER)/, $(TESTS_UUID_LIST))

TESTS_FOLDER		=	tests
TESTS				=	$(TESTS_USER)
TESTS				+=	$(TESTS_TEAM)
TESTS				+=	$(TESTS_UUID_LIST)
TESTS				:=	$(addprefix $(TESTS_FOLDER)/, $(TESTS))

TESTS_OBJ	=	$(TESTS:.c=.o)

MAIN		=	main.c

OBJ_MAIN	=	$(MAIN:.c=.o)

NAME		=	../../myteams_server

INCLUDE		=	-I./include -I../lib/include

CFLAGS		=	-Wall -Wextra -Werror -Wshadow

UUID_LIB	=	-luuid

TEST_FLAGS	=	-lcriterion --coverage

LIB_FLAGS	=	-L../lib/ -lmy

TEST_BINARY	=	unit_tests

CC			=	gcc

MV			=	mv -f

%.o:	%.c
		$(CC) $(CFLAGS) $(LIB_FLAGS) $(INCLUDE) -o $@ -c $<

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
		$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(UUID_LIB) $(CFLAGS) $(INCLUDE) \
		$(LIB_FLAGS)

debug:	CFLAGS += -g
debug:	re

tests_run:	$(TESTS_OBJ)
		$(CC) -o $(TEST_BINARY) $(SRC) $(TESTS_OBJ) $(CFLAGS) $(TEST_FLAGS) \
		$(INCLUDE) $(LIB_FLAGS) $(UUID_LIB)
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
