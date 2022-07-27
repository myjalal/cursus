# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 18:01:38 by jechekao          #+#    #+#              #
#    Updated: 2022/07/27 19:46:21 by jechekao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP =		push_swap

NAME =			$(PUSH_SWAP) $(CHECKER)
LIBFT		=	libft/
LIB			=	libft.a

COMP =			gcc -Wall -Werror -Wextra -I include -I libft/ -c -o

FLAG		=	-c			\
				-Wall		\
				-Wextra		\
				-Werror		\

OBJ_DIR =		obj/
DIR =			srcs/
C_SRC_DIR =		c_srcs/

P_SRC =			main.c			\
				fill_a.c		\
				check_arg.c		\
				errors.c		\
				populate.c		\
				utils.c			\
				test_tools.c	\
				move.c			\
				small.c			\
				large.c			\
				large_utils.c	\
				fat.c			\
				fat_utils.c		\
				run_fat.c

C_SRC =			checker.c

P_OBJ =			$(P_SRC:%.c=%.o)
C_OBJ =			$(C_SRC:%.c=%.o)
OBJ =			$(P_OBJ) $(C_OBJ)

P_SRC_PATH =   	$(P_SRC:%=$(DIR)%)
C_SRC_PATH =   	$(C_SRC:%=$(C_SRC_DIR)%)
SRC_PATH =		$(P_SRC_PATH) $(C_SRC_PATH)

P_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(P_OBJ))
C_OBJ_PATH =	$(addprefix $(OBJ_DIR), $(C_OBJ))
OBJ_PATH =		$(P_OBJ_PATH) $(C_OBJ_PATH)

all:			color do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n\033[32;1m PUSH_SWAP COMPLETE \033[0m \\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):		$(OBJ_PATH)
				@gcc $(P_OBJ_PATH) *.a -o push_swap \
					-I includes -I libft/
				@gcc $(C_OBJ_PATH) *.a -o checker \
					-I includes -I libft/

$(P_OBJ_PATH):	$(P_SRC_PATH)
				@$(MAKE) $(P_OBJ)

$(C_OBJ_PATH):	$(C_SRC_PATH)
				@$(MAKE) $(C_OBJ)

$(C_OBJ):		$(LIB)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(C_SRC_DIR)$(@:%.o=%.c)

$(P_OBJ):		$(LIB)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT)
				@cp $(LIBFT)/$(LIB) .

colour:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			color
				@/bin/rm -rf $(OBJ_DIR) $(LIB)
				@make -C $(LIBFT) clean
				@echo "\\n\033[32;1m Cleaned libft object files \033[0m"

fclean:			clean
				@/bin/rm -f $(PUSH_SWAP) $(CHECKER) $(LIB)
				@make -C $(LIBFT) fclean
				@echo "\\n\033[32;1m Cleaned $(NAME) \033[0m \\n"

re: 			fclean all

.PHONY:			all clean flcean re color
