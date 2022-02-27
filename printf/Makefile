# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 10:44:05 by jechekao          #+#    #+#              #
#    Updated: 2022/02/27 12:51:13 by jechekao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC = ft_printf.c

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) 
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"
fclean: clean
	$(RM) $(NAME)
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"
re: fclean $(NAME)
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"
git:
	git add .
	git commit -m "$m"
	git push origin main