/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:37:25 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/26 18:15:02 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_atob(t_var *list, int i)
{
	if (list->b && list->b->next && list->b->indx > i)
		run(6, &list->a, &list->b);
	run(4, &list->a, &list->b);
}

void	push_btoa(t_var *list, int indx, int i)
{
	t_node *temp;
	int		j;

	temp = list->b;
	j = 0;
	while (temp)
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
		if (j > (list->len_b)/2)
		{
			while (list->b->indx != indx)
				run(8, &list->a, &list->b);
			run(3, &list->a, &list->b);
		}
		else
		{
			while (list->b->indx != indx)
				run(6, &list->a, &list->b);
			run(3, &list->a, &list->b);
		}
	}
	if (i)
		run(i, &list->a, &list->b); //if pushing min
}

void		turn_count(t_var *list) // assigne search
{
	if (list->turn == 4)
	{
		list->from = 0;
		list->ref = list->len / 4;
	}
	else if (list->turn == 3)
	{
		list->from = (list->len / 4) + 1;
		list->ref = list->len / 2;
	}
	else if (list->turn == 2)
	{
		list->from = (list->len / 2) + 1;
		list->ref = (list->len / 4) * 3;
	}
	else if (list->turn == 1)
	{
		list->from = ((list->len / 4) * 3) + 1;
		list->ref = (list->len - 1);
		if (list->len % 2)
			list->len = list->len / 4;
		else
			list->len = (list->len / 4) - 1;
	}
}

void	fat(t_var *list)
{
	t_node *temp;
	int		i;
	
	i = list->len;
	temp = list->a;
	turn_count(list);
	while (list->turn)
	{
		while(i)
		{
			if (temp->indx >= list->from && temp->indx <= list->ref)
				push_atob(list, (list->ref) / 2);
			else
				run(5, &list->a, &list->b);
			i--;
			temp = list->a;
		}
		ai_pushbtoa(list);
		list->turn--;
		fat(list);
	}
}

	