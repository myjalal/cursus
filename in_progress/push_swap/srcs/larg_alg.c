/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larg_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:15:43 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/10 20:23:36 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	sort_1(t_var *list)
{
	int	i;
	int j;
	
	i = list->len;
	j = (list->len / 4);
	printf("i = %d | j = %d\n", i, j);
	while(i >= j)
	{
		indx_a(list);
		while(ref_check(list->a, list->ref))
		{
			if (list->a->num <= list->ref)
			{
				run(4, &list->a, &list->b);
				i--;
			}
			else
				rotate_a(list);
			print_list(list->a, list->b);
		}
	}
}

void	larg(t_node **a, t_node **b, t_var *list)
{
	print_indx(*a, list->sorted);
	sort_1(list);
	print_list(*a, *b);
	//sort_2(list);
}