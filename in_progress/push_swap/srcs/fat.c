/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:37:25 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/27 18:34:23 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_atob(t_var *list, int i)
{
	if (list->b && list->b->next && list->b->indx > i)
		run_fat(6, list);
	i++;
	run_fat(4, list);
}

void	push_btoa_next(t_var *list, int indx, int j)
{
	if (j > (list->len_b) / 2)
	{
		while (list->b->indx != indx)
			run_fat(8, list);
		run_fat(3, list);
	}
	else
	{
		while (list->b->indx != indx)
			run_fat(6, list);
		run_fat(3, list);
	}
}

void	push_btoa(t_var *list, int indx, int i)
{
	t_node	*temp;
	int		j;

	temp = list->b;
	j = 0;
	while (temp)
	{
		if (temp->indx == indx)
			break ;
		j++;
		temp = temp->next;
	}
	if (j == 0)
		run_fat(3, list);
	else if (j == 1)
		run_fat(23, list);
	else
		push_btoa_next(list, indx, j);
	if (i)
		run_fat(i, list);
}

void	turn_count(t_var *list)
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
		list->len = list->len / 2;
	}
	else if (list->turn == 1)
	{
		list->len = list_len(list->a);
		list->from = ((list->len / 4) * 3) + 1;
		list->ref = (list->len - 1);
		list->len = ((list->len) - (list->from));
	}
}

void	fat(t_var *list)
{
	t_node	*temp;
	int		i;

	turn_count(list);
	i = list->len;
	temp = list->a;
	while (list->turn)
	{
		while (i)
		{
			if (temp->indx >= list->from && temp->indx <= list->ref)
				push_atob(list, (list->ref) / 2);
			else
				run_fat(5, list);
			i--;
			temp = list->a;
		}
		ai_pushbtoa(list);
		list->turn--;
		fat(list);
	}
}
