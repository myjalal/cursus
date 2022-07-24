/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:19:29 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/24 18:46:08 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_var *list)
{	
	if (list->len > 10)
		larg(list);
	else
		small(&list->a, &list->b, list);
	//print_list(list->a, list->b);
}

int	main(int argc, char **argv)
{
	t_var	*l;

	l = NULL;
	if (argc < 2)
		return (1);
	l = list_init(l, argv);
	fill_a(l);
	print_indx(l->a, l->sorted);
	if (sort_checker(&l->a) == 0)
		push_swap(l);
	free_all(l);
	//print_indx(l->a, l->sorted);
	return (0);
}
