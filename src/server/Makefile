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
					commands.c		\
					create_team.c	\
					create_channel.c	\
					create_thread.c		\
					create_reply.c		\

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
RESPONSE 		=	add_output.c 				\
					pop_output.c				\
					send_message_every_users.c 	\
					send_message_to_team.c 		\

RESPONSE 		:=	$(addprefix $(RESPONSE_FOLDER)/, $(RESPONSE))

UUID_LIST_FOLDER =	uuid_list
UUID_LIST 		=	add_uuid.c					\
					del_uuid.c					\
					init_list_of_uuids.c			\
					get_uuid.c

UUID_LIST 		:=	$(addprefix $(UUID_LIST_FOLDER)/, $(UUID_LIST))

USER_FOLDER		=	user
USER			=	init_list_of_users.c			\
					add_user.c						\
					add_user_with_uuid.c			\
					del_user.c						\
					del_list_of_users.c				\
					find_user.c 					\
					get_user_by_uuid.c				\

USER			:=	$(addprefix $(USER_FOLDER)/, $(USER))

TEAM_FOLDER		=	team
TEAM			=	init_list_of_teams.c			\
					add_team.c						\
					add_team_with_uuid.c			\
					del_team.c						\
					del_list_of_teams.c				\
					add_user_to_team.c				\
					del_user_from_team.c			\
					get_team_by_name.c				\
					add_channel_to_team.c			\
					get_team_by_uuid.c				\

TEAM			:=	$(addprefix $(TEAM_FOLDER)/, $(TEAM))

CHANNEL_FOLDER	=	channel
CHANNEL			=	init_list_of_channels.c			\
					add_channel.c					\
					add_channel_with_uuid.c			\
					del_channel.c					\
					del_list_of_channels.c			\
					get_channel_by_name.c			\
					add_thread_to_channel.c			\
					del_thread_from_channel.c		\
					get_channel_by_uuid.c			\

CHANNEL			:=	$(addprefix $(CHANNEL_FOLDER)/, $(CHANNEL))

THREAD_FOLDER	=	thread
THREAD			=	init_list_of_threads.c			\
					add_thread.c					\
					add_thread_with_uuid.c			\
					del_thread.c					\
					del_list_of_threads.c			\
					get_thread_by_name.c			\
					get_thread_by_uuid.c			\
					add_comment_to_thread.c			\
					del_comment_from_thread.c		\

THREAD			:=	$(addprefix $(THREAD_FOLDER)/, $(THREAD))

COMMENT_FOLDER	=	comment
COMMENT			=	init_list_of_comments.c			\
					add_comment.c					\
					add_comment_with_uuid.c			\
					del_comment.c					\
					del_list_of_comments.c			\
					get_comment_by_uuid.c			\

COMMENT			:=	$(addprefix $(COMMENT_FOLDER)/, $(COMMENT))

SAVE_FOLDER		=	save
SAVE			=	save_users.c					\
					save_teams.c					\

SAVE			:=	$(addprefix $(SAVE_FOLDER)/, $(SAVE))

LOAD_FOLDER		=	load
LOAD			=	load_users.c					\
					load_teams.c					\

LOAD			:=	$(addprefix $(LOAD_FOLDER)/, $(LOAD))

SRC_FOLDER	=	src
SRC			=	$(COMMANDS)
SRC 		+=	$(CORE)
SRC 		+=	$(RESPONSE)
SRC 		+=	$(USER)
SRC 		+=	$(TEAM)
SRC 		+=	$(UUID_LIST)
SRC 		+=	$(CHANNEL)
SRC 		+=	$(THREAD)
SRC 		+=	$(COMMENT)
SRC 		+=	$(SAVE)
SRC 		+=	$(LOAD)
SRC 		:=	$(addprefix $(SRC_FOLDER)/, $(SRC))

OBJ			=	$(SRC:.c=.o)

TESTS_FOLDER	=	tests

TESTS_USER		=	test_add_user.c				\
					test_add_user_with_uuid.c	\
					test_del_user.c				\
					test_del_list_of_users.c	\

TESTS_USER		:=	$(addprefix $(USER_FOLDER)/, $(TESTS_USER))

TESTS_TEAM			=	test_add_team.c				\
						test_add_team_with_uuid.c	\
						test_del_team.c				\
						test_del_list_of_teams.c	\
						test_add_user_to_team.c		\
						test_del_user_from_team.c	\
						test_add_channel_to_team.c	\

TESTS_TEAM			:=	$(addprefix $(TEAM_FOLDER)/, $(TESTS_TEAM))

TESTS_UUID_LIST		=	test_add_uuid.c
TESTS_UUID_LIST		:=	$(addprefix $(UUID_LIST_FOLDER)/, $(TESTS_UUID_LIST))

TESTS_CHANNEL		=	test_add_channel.c				\
						test_add_channel_with_uuid.c	\
						test_del_channel.c				\
						test_del_list_of_channels.c
TESTS_CHANNEL		:=	$(addprefix $(CHANNEL_FOLDER)/, $(TESTS_CHANNEL))

TESTS_THREAD		=	test_add_thread.c				\
						test_add_thead_with_uuid.c		\
						test_del_thread.c				\
						test_del_list_of_threads.c		\

TESTS_THREAD		:=	$(addprefix $(THREAD_FOLDER)/, $(TESTS_THREAD))

TESTS_COMMENT		=	test_add_comment.c				\
						test_del_comment.c				\
						test_del_list_of_comments.c		\

TESTS_COMMENT		:=	$(addprefix $(COMMENT_FOLDER)/, $(TESTS_COMMENT))

TESTS_FOLDER		=	tests
TESTS				=	$(TESTS_USER)
TESTS				+=	$(TESTS_TEAM)
TESTS				+=	$(TESTS_UUID_LIST)
TESTS				+=	$(TESTS_CHANNEL)
TESTS				+=	$(TESTS_THREAD)
TESTS				+=	$(TESTS_COMMENT)
TESTS				:=	$(addprefix $(TESTS_FOLDER)/, $(TESTS))

TESTS_OBJ	=	$(TESTS:.c=.o)

MAIN		=	main.c

OBJ_MAIN	=	$(MAIN:.c=.o)

NAME		=	../../myteams_server

INCLUDE		=	-I./include -I../lib/include \
-I../network_lib/include -I../../libs/myteams

CFLAGS		=	-Wall -Wextra -Werror -Wshadow

UUID_LIB	=	-luuid

TEST_FLAGS	=	-lcriterion --coverage


LIB_FLAGS	=	-L../lib/ -lmy -L../../libs/myteams/ -lmyteams \
-L../network_lib/ -lnetwork

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
		$(CC) -o $(TEST_BINARY) $(SRC) $(TESTS_OBJ) $(CFLAGS) $(LIB_FLAGS) \
		$(TEST_FLAGS) $(INCLUDE)  $(UUID_LIB)
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
