NAME = minishell1

GREEN	=	\033[32;1m
CYAN = \033[36m

WFLAGS = -Wall -Wextra -Werror -Wpedantic -Wuninitialized -Wshadow

CFLAGS = -std=c99 -g -I./include

PATH_FILES = ./src/

SRCS = main.c	\
			 env.c	\
			 utils.c	\
			 commands.c	\

SRC = $(addprefix $(PATH_FILES), $(SRCS))

OBJ = $(SRC:.c=.o)

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
