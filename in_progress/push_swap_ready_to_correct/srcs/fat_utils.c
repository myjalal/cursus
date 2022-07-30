/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:44:39 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/28 16:00:42 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_last_indx(t_node *list)
{
	t_node	*temp;

	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp->indx);
}

int	find_min_index(t_node	*list)
{
	int		i;
	t_node	*temp;

	i = list->indx;
	temp = list;
	while (temp)
	{
		if (i >= temp->indx)
			i = temp->indx;
		temp = temp->next;
	}
	return (i);
}

int	find_max_index(t_node	*list)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = NULL;
	if (list)
	{
		i = list->indx;
		temp = list;
		while (list)
		{
			if (list->indx >= i)
				i = list->indx;
			list = list->next;
		}
		list = temp;
	}
	return (i);
}

void	ai_rotate_b(t_node *b, t_var *list)
{
	t_node	*temp;
	int		flag;

	temp = b;
	find_min_max_b(list);
	flag = list_len(list->b) % 2;
	while (temp)
	{
		if (list->len_b == -1 && flag == 1)
		{
			list->len_b = 0;
			flag = 0;
		}
		if (temp->indx == list->min)
			list->index_min = list->len_b;
		if (temp->indx == list->max)
			list->index_max = list->len_b;
		list->len_b--;
		temp = temp->next;
	}
	if (list->index_max < 0)
		list->index_max *= -1;
	if (list->index_min < 0)
		list->index_min *= -1;
}

void	ai_pushbtoa(t_var *list)
{
	int	i;

	i = 0;
	if (list->turn == 2)
	{
		i = (list->len / 2) + 1;
		while (find_last_indx(list->a) >= list->ref)
			run_fat(7, list);
	}
	while (list->b)
	{
		ai_rotate_b(list->b, list);
		list->len_b = list_len(list->b);
		if (list->len_b % 2)
			list->len_b++;
		if (list->index_min >= list->index_max)
			push_btoa(list, list->min, 5);
		else
			push_btoa(list, list->max, 0);
	}
	while (list->a->indx >= list->from && list->a->indx <= list->ref)
		run_fat(5, list);
}
