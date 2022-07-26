/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:19:29 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/26 18:08:42 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_var *list)
{	
	/*if (list->len <= 10)
		small(&list->a, &list->b, list);
	else if (list->len > 10 && list->len <= 100)
		large(list);
	else*/
	//print_list_index(list->a, list->b);
	fat(list);
	//print_list_index(list->a, list->b);
}

int	main(int argc, char **argv)
{
	t_var	*l;

	l = NULL;
	if (argc < 2)
		return (1);
	l = list_init(l, argv);
	fill_a(l);
	//print_list(l->a, l->b);
	if (sort_checker(&l->a) == 0)
		push_swap(l);
	//print_list(l->a, l->b);
	free_all(l);
	return (0);
}
