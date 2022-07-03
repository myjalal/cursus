/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:34:33 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/03 11:29:47 by jechekao         ###   ########.fr       */
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
	char			**temp; // temp argv in strings
	int				len;
	int				fd;
	t_node			*a; //list a
	t_node			*b; //list b
}	t_var;

/*-------check_dup.c--------*/

// Check if there is a duplicate number in args
void				check_duplic(char **argv);
// Compare string
int					ft_strcmp(const char	*s1, const char	*s2);

/*-------check_arg.c--------*/

// Check if int is negative
// Static int is_neg(char *argv, bool *neg, int i);

// Check if it's a valid int (INT_MAX and INT_MIN)
int					check_int(char *argv);

// Runs all arg checks and outputs errors
int					check_arg(char **argv);

// Check if the list is sorted
int					sort_checker(t_node **list, int len);

/*--------populate.c--------*/
// NULL list for initiation
t_var				*list_init(t_var *list);

// Temp argv list,  list, temp node
t_node				*list_filler(char **argv, t_var *list, t_node *temp);

// Check if there is a top node, then either creats one or adds a node
void				add_node(t_node **top, t_node *node);

// Add number to top of the list
void 				top(t_node **list, t_node *node);

// Add number to bottom of the list
void 				bottom(t_node **list, t_node *node);

/*-------errors.c--------*/

// Prints erros with correct output
int					error_exit(char *error, int err_exit);

/*--------utils.c-----------*/
// Free linked list
void				ft_free(t_node **list);

/*---------move.c-----------*/
// oparations

// SA and SB
void	swap(t_node **list);

//   PA and PB
void	one_top_two(t_node **l_one, t_node **l_two);

// RA and RB
void	revers(t_node **list);

// RRA and RRB
void	r_revers(t_node **list);

/*---------test_tools.c------*/ // !!!!! DELETE
// Print linked list to test
void				print_list(t_node *list);



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