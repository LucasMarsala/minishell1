#################################NAME###########################################

NAME = minishell1

#################################BULTINS########################################

PATH_BULTINS = ./src/bultins/

SRC_BULTINS = env.c	\
			 				cd.c	\

##################################UTILS#########################################

PATH_UTILS = ./src/utils/

SRC_UTILS = my_strlen.c	\
			 			my_strstr.c	\
						my_strcat.c	\
						my_strcmp.c	\
						my_strdup.c	\
						print_array.c	\
						str_to_word_array.c	\

#################################DESTROY########################################

PATH_DESTROY = ./src/destroy/

SRC_DESTROY = free.c	\

#################################INITIALIZATION#################################

PATH_INITIALIZATION = ./src/initialization/

SRC_INITIALIZATION = main.c	\
										 initialization.c	\

#################################CORE###########################################

PATH_CORE = ./src/core/

SRC_CORE = commands.c	\

#################################SRC############################################

SRC = $(addprefix $(PATH_INITIALIZATION), $(SRC_INITIALIZATION))	\
			$(addprefix $(PATH_CORE), $(SRC_CORE))	\
			$(addprefix $(PATH_UTILS), $(SRC_UTILS))	\
			$(addprefix $(PATH_BULTINS), $(SRC_BULTINS))	\
			$(addprefix $(PATH_DESTROY), $(SRC_DESTROY))	\

OBJ = $(SRC:.c=.o)

#################################COLORS#########################################

GREEN	=	\033[32;1m

CYAN = \033[36m

#################################FLAGS##########################################

WFLAGS = -Wall -Wextra -Werror -Wpedantic -Wuninitialized -Wshadow

CFLAGS = -std=c99 -g -I./include

#################################COMMANDS#######################################

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(WFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	@printf "$(CYAN)[$(NAME)] - All .o files have been deleted\n" $<

fclean: clean
	$(RM) *~ *#
	$(RM) $(PATH_FILES)*~ $(PATH_FILES)*#
	$(RM) $(NAME)
	@printf "$(CYAN)[$(NAME)] - All useless files have been deleted including .o, # and ~ files.\n" $<

re: fclean all
	@printf "$(GREEN)[$(NAME)] - fclean and compilation finished.\n" $<

%.o:	%.c
		@printf "$(GREEN)[$(NAME)] - file -> %-45s\n" $<
		$(CC) $(CFLAGS) -o $@ -c $<
