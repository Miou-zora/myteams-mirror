##
## EPITECH PROJECT, 2023
## myteams-mirror
## File description:
## Makefile
##

SERVER_FOLDER	=	src/server

CLIENT_FOLDER	=	src/client

LIB_FOLDER		=	src/lib

MAKE			=	make

all:
		$(MAKE) -C $(LIB_FOLDER)
		$(MAKE) -C $(SERVER_FOLDER)
		$(MAKE) -C $(CLIENT_FOLDER)

debug:
		$(MAKE) -C $(SERVER_FOLDER) debug
		$(MAKE) -C $(CLIENT_FOLDER) debug

tests_run:
		$(MAKE) -C $(SERVER_FOLDER) tests_run
		$(MAKE) -C $(CLIENT_FOLDER) tests_run
clean:
		$(MAKE) -C $(LIB_FOLDER) clean
		$(MAKE) -C $(SERVER_FOLDER) clean
		$(MAKE) -C $(CLIENT_FOLDER) clean

fclean: dclean
		$(MAKE) -C $(LIB_FOLDER) fclean
		$(MAKE) -C $(SERVER_FOLDER) fclean
		$(MAKE) -C $(CLIENT_FOLDER) fclean
		$(RM) -rf doc/html
		$(RM) -rf doc/latex

tclean:
		$(MAKE) -C $(SERVER_FOLDER) tclean
		$(MAKE) -C $(CLIENT_FOLDER) tclean
		@find tests -type f -name '*.gcda' -exec $(RM) {} \;
		@find tests -type f -name '*.gcno' -exec $(RM) {} \;

docu:
		doxygen Doxyfile
		make -C doc/latex

dclean:
		$(RM) -rf doc/html
		$(RM) -rf doc/latex

re:	fclean all

.PHONY:	all clean fclean re
