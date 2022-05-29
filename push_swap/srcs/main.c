/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:19:29 by jechekao          #+#    #+#             */
/*   Updated: 2022/05/29 19:24:16 by jechekao         ###   ########.fr       */
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

// push_swap duh...
void	push_swap(int argc, char **argv, t_var *l)
{
	t_node	*s;

	s = NULL;
	l->temp = gen_temp(argc, argv, l);
	check_duplic(l->temp);
	check_arg (l->temp);
	l->a = list_fill(l->temp, l, s);
	
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
