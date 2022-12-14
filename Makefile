
NAME = pipex

LIBFT = Include/libft/libft.a

LIBFT_PATH = Include/libft/

SRCS_PATH = src/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

SRCS_FILES = main.c pipex.c utils.c inputs.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)






all: 	$(NAME)
	@echo "BOOM 💥💥💥💥💥 $(NAME) Compiled! 💯 $(DEFAULT)"


$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) --silent
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\n$(GREEN)$(NAME) created!$(DEFAULT)💯"





clean:
	@$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean --silent
	@echo "\n$(YELLOW)object files deleted!$(DEFAULT)💯"

fclean:	clean
	@$(RM) $(NAME) $(LIBFT)



re:		fclean all



.PHONY:	all clean libft fclean re



#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
COMMIT = $(shell date "+%d %B %T")

run: 
	@./pipex "notes.txt" "cat" "wc" out.txt

runcmd:
	@./pipex "notes.txt" "/bin/cat" "/usr/bin/wc" out.txt
