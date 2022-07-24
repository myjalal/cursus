/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:19:29 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/23 21:26:37 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	**gen_temp(int argc, char **argv, t_var *l)
{
	if (argc == 2)
		l->temp = ft_split(argv[1], ' ');
	else
		l->temp = &argv[1];
	return (0);
}

/*void	push_swap(int argc, char **argv, t_var *list)
{
	t_node	*s;
	
	s = NULL;
	gen_temp(argc, argv, list);
	check_duplic(list->temp);
	check_arg (list->temp, list);
	list_filler(list->temp, list, s);
	ft_free(&s);
	//free_string(list->temp);
	if (list->len == 1)
		exit(1);
	else if (sort_checker(&list->a) == 1)
		exit(1);
	else if (list->len > 10)
		larg(&list->a, &list->b, list);
	else
		small(&list->a, &list->b, list);
	//push_swap_free(list);
}*/

static void	push_swap(t_var *list)
{
	fill_a(list);
}

int	main(int argc, char **argv)
{
	t_var	*l;

	l = NULL;
	if (argc < 2)
		return (1);
	l = list_init(l, argv);
	push_swap(l);
	free_frame(l);
	//free(l);
	//l = NULL;
	return (0);
}
