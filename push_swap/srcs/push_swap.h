/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:34:33 by jechekao          #+#    #+#             */
/*   Updated: 2022/05/29 19:35:55 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# include <stdbool.h> // check if you are allower to use false and true and bool

typedef struct node
{
	int				num;
	struct node		*next;
	struct node		*previous;
}	t_node;

typedef struct var
{
	char			**temp;
	int				len;
	t_node			*a;
	t_node			*b;
}	t_var;

/*-------check_dup.c--------*/

//check if there is a duplicate number in args
void				check_duplic(char **argv);
//compare string
int					ft_strcmp(const char	*s1, const char	*s2);

/*-------check_arg.c--------*/

//check if int is negative
//static int is_neg(char *argv, bool *neg, int i);

// check if it's a valid int (INT_MAX and INT_MIN)
int					check_int(char *argv);

// Runs all arg checks and outputs errors
int					check_arg(char **argv);

/*--------populate.c--------*/
//NULL list for initiation
t_var				*list_init(t_var *l);

/*-------errors.c--------*/

// Prints erros with correct output
int					error_exit(char *error, int err_exit);

#endif

/*
- check if there at least 2 argc
- split spaces " "from argv[]
- add argc into temp list
- check if the number are correct valid arg
- check duplicates 
- populate list A
- validate is list A is correctly populated
- if lenth is <= 10 (short sort)
- if lenth is > 10 (long sort)
*/