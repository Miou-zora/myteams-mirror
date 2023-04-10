##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

SERVER_FOLDER	=	src/server

CLIENT_FOLDER	=	src/client

MAKE			=	make

all:
		$(MAKE) -C $(SERVER_FOLDER)
		$(MAKE) -C $(CLIENT_FOLDER)

debug:
		$(MAKE) -C $(SERVER_FOLDER) debug
		$(MAKE) -C $(CLIENT_FOLDER) debug

tests_run:
		$(MAKE) -C $(SERVER_FOLDER) tests_run
		$(MAKE) -C $(CLIENT_FOLDER) tests_run

clean:
		$(MAKE) -C $(SERVER_FOLDER) clean
		$(MAKE) -C $(CLIENT_FOLDER) clean

fclean:
		$(MAKE) -C $(SERVER_FOLDER) fclean
		$(MAKE) -C $(CLIENT_FOLDER) fclean

tclean:
		$(MAKE) -C $(SERVER_FOLDER) tclean
		$(MAKE) -C $(CLIENT_FOLDER) tclean

re:	fclean all

.PHONY:	all clean fclean re
