# Folders and Names
NAME		= libft.a
SRCSDIR		= srcs
OBJSDIR		= objs
INCLUDES	= incs

SRCS		= ft_memset.c ft_bzero.c ft_memcpy.c ft_striteri.c ft_memmove.c 	\
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c 		\
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c 		\
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c 	\
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c 		\
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c 		\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 		\
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c 			\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c 			\
			ft_lstmap.c ft_strcmp.c get_next_line.c get_next_line_utils.c		\
			ft_printf.c ft_strfcmp.c

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

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
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
