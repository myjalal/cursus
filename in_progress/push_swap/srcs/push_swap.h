/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:34:33 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/15 21:24:23 by jechekao         ###   ########.fr       */
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
// check if you are allower to use false and true and bool
# include <stdbool.h>

typedef struct node
{
	int				num;
	int				indx;
	struct node		*next;
	struct node		*previous;
}	t_node;

typedef struct var
{
	char			**temp;
	int				ref;
	int				len;
	int				fd;
	t_node			*a;
	t_node			*b;
	t_node			*sorted;
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
int					sort_checker(t_node **list);

// check size of list
int					list_len(t_node *a);

/*--------populate.c--------*/
// NULL list for initiation
t_var				*list_init(t_var *list);

// Temp argv list,  list, temp node
t_node				*list_filler(char **argv, t_var *list, t_node *temp);

// Check if there is a top node, then either creats one or adds a node
void				add_node(t_node **top, t_node *node);

// will index number from small to big
void				indx_a(t_var *list);

// set rotation ref depending on the len
void				pivote(t_var *list);

/*-------errors.c--------*/

// Prints erros with correct output
int					error_exit(char *error, int err_exit);

/*--------utils.c-----------*/
// Free linked list
void				ft_free(t_node **list);

//find min of a list
int					find_min(t_node	*list);

//find last num of the list
int					find_last(t_node *list);

//find the position of a number in the list
int					find_indx(t_node *list, int num);

// find the number at position indx
int					find_num(t_node *list, int indx);

/*---------move.c-----------*/
// oparations

// SA and SB
void				swap(t_node **list);

//   PA and PB
void				one_top_two(t_node **l_one, t_node **l_two);

// RA and RB
void				revers(t_node **list);

// RRA and RRB
void				r_revers(t_node **list);

/*----------run.c----------*/
// run up to 2 operations at the same time
void				run(int op, t_node **a, t_node **b);

// run the remaining operations
void				run_1(int op, t_node **a, t_node **b);

// run last operations
void				run_2(int op, t_node **a, t_node **b);

// smart rotation of stack A
void				rotate_a(t_var *list);

// smart rotation of stack B
void				rotate_b(t_var *list);

/*--------small_alg.c-------*/
// algo for 10 args or less
void				small(t_node **a, t_node **b, t_var *list);

// sort 3 num or less
void				three_num(t_node **a, t_node **b);

// sort 10 num or less
void				ten_num(t_node **a, t_node **b, int len);

// choose if it ra or rb
void				rorate(t_node **a, int min, int len);

/*--------larg_alg.c-------*/
// algo for more then 10 args
void				larg(t_node **a, t_node **b, t_var *list);

// First sort
void				sort(t_var *list);

// Second sort
void				sort_min(t_var *list);

// Last sort
void				sort_max(t_var *list);

// Find max number of list
int					find_max(t_node	*list);


/*----------larg_utils-------*/
// duplicate list and return new sorted list
t_node				*sort_list(t_node *list, t_node *new);

// return a new duplicated list
t_node				*copy_list(t_node *head);

// swap x->num with y->num
void				num_swap(t_node *x, t_node *y);

// return 0 if list->indx > ref return 1 if list->indx < ref and 2 if list->indx == ref
int					ref_check(t_node *list, int	ref);


/*---------test_tools.c------*/ // !!!!! DELETE
// Print linked list to test
void				print_list(t_node *a, t_node *b);

void				print_indx(t_node *a, t_node *sorted);
/*
void				sort_indx(t_node *list, int len);
*/
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