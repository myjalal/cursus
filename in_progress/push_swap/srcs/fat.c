/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:37:25 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/25 21:16:45 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_atob(t_var *list)
{
	if (list->b && list->b->next && list->b->indx > (list->quarter / 2))
		revers(&list->b);
	one_top_two(&list->a, &list->b);
}

void	push_btoa(t_var *list, int indx, int i)
{
	t_node *temp;
	int		j;

	temp = list->b;
	j = 0;
	while(temp)
	{
		if (temp->indx == indx)
			break;
		j++;
		temp = temp->next; 
	}
	if (j == 0)
		run(3 , &list->a, &list->b);
	else if (j == 1)
		run(23, &list->a, &list->b);
	else
	{
		if (j > (list->len_b)/2); // stopped here
	}
	
	if (i)
		run(i, &list->a, &list->b);
}


void	fat(t_var *list)
{
	t_node *temp;
	int i = 20;
	
	temp = list->a;
	print_list(list->a, list->b);
	while (i)
	{
		if (temp->indx <= list->quarter)
			push_atob(list);
		else
			revers(&list->a);
		i--;
		temp = list->a;
	}
	print_list(list->a, list->b);
	while (list->b)
	{
		ai_rotate_b(list->b, list);
		if (list->index_min >= list->index_max)
			push_btoa(list, list->min, 5);
		else
			push_btoa(list, list->max, 0);
	}
}

	