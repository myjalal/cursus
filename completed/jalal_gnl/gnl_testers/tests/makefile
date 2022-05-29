# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Updated: 2021/11/28 12:56:28 by jechekao           #+#    #+#              #
#    Updated: 2021/11/28 12:56:33 by jechekao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	get_next_line.c get_next_line_utils.c

BONUS_FILES	=	get_next_line_bonus.c get_next_line_utils_bonus.c

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

all:
	clang $(CFLAGS) -g3 -D BUFFER_SIZE=1 $(FILES) main.c -I get_next_line.h

test:
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 $(FILES) main.c -I get_next_line.h

bonus:
	gcc $(CFLAGS) -D BUFFER_SIZE=42 $(BONUS_FILES) main_bonus.c -I get_next_line_bonus.h

debug:
	gcc -g $(FILES) -I get_next_line.h

object:
	gcc -c $(CFLAGS) get_next_line.c

normi:
	norminette $(FILES) $(BONUS_FILES) get_next_line.h get_next_line_bonus.h

git:
	git add .
	git commit -m "update"
	git push origin main3