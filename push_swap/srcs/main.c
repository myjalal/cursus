/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:19:29 by jechekao          #+#    #+#             */
/*   Updated: 2022/05/29 18:47:50 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//split spaces " " from argv[] and generate a temp list
char	**gen_temp(int argc, char **argv, t_var *l)
{
	if (argc == 2)
		l->temp = ft_split(argv[1], ' ');
	else
		l->temp = &argv[1];
	return (l->temp);
}

//NULL list for initiation
t_var	*list_init(t_var *l)
{
	l = (t_var *)malloc(sizeof(t_var));
	if (!l)
		exit(1);
	l->temp = NULL;
	l->len = 0;
	l->a = NULL;
	l->b = NULL;
	return (l);
}

// push_swap duh...
void	push_swap(int argc, char **argv, t_var *l)
{
	t_node	*s;

	s = NULL;
	l->temp = gen_temp(argc, argv, l);
	check_duplic(l->temp);
	check_arg (l->temp);
}

int	main(int argc, char **argv)
{
	t_var	*l;

	l = NULL;
	if (argc < 2)
		error_exit("No argument found\nPlease try again\n", 1);
	else
	{
		l = list_init(l);
		push_swap(argc, argv, l);
		free(l);
		l = NULL;
		return (0);
	}
	return (0);
}
