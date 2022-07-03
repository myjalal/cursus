PS_NAME		=	test

CC			=	clang

DIR			=	./
OBJ_DIR		=	obj/

FLAG		=	-c			\
				-Wall		\
				-Wextra		\
				-Werror


RM			=	/bin/rm -f

PS_FILES	=	test.c		\
				swap.c


PS_SRCS		=	$(addprefix $(DIR), $(PS_FILES))
PS_OBJ		=	$(PS_SRCS:$(DIR)%.c=$(OBJ_DIR)%.o)

all			:	$(PS_NAME)	

obj/%.o		:	./%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) -g $(FLAG) $(INCLUDE) $< -o $@

$(LIB)		:	
				@$(MAKE) -C $(LIB_DIR)
				/bin/mv $(LIB_DIR)$(LIB) .

$(PS_NAME)	:	$(PS_OBJ) $(LIB)
				$(CC) -fsanitize=address -o $@ $^

clean		:	
				for dir in $(MODULES); do			\
					@$(MAKE) clean -C $$dir;		\
				done
				@/bin/rm -rf $(OBJ_DIR)

fclean		:	clean
				@$(RM) $(PS_NAME)

re			:	fclean all

.PHONY		:	all clean fclean re