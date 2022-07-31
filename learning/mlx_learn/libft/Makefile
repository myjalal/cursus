# Folders and Names
NAME		= libft.a
SRCSDIR		= srcs
OBJSDIR		= objs
INCLUDES	= incs

SRCS		= ${wildcard srcs/*.c}

# Compiler options
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3

###################################################
# The rest is done by the MakeFile automatically, #
# you should not have to modify it				  #
###################################################

OBJS		= $(SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@printf "\033[0;32m💬 Libft is compiled ! 🍀\033[0m\n"

$(OBJS): $(OBJSDIR)/%.o:%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJSDIR)
	@printf "\033[0;34m💬 Files in '${OBJSDIR}' are deleted ! 👻\033[0m\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "\033[0;31m💬 '${NAME}' is deleted ! 👻\033[0m\n"

re: fclean all

test: all
	./$(NAME)
git:
	git add .
	git commit -m "$m"
	git push origin main

.PHONY: all clean fclean re test
