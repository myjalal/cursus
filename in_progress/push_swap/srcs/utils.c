/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:43:09 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/25 19:48:48 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node	*list)
{
	int		i;
	t_node	*temp;

	i = list->num;
	temp = list;
	while (temp)
	{
		if (i >= temp->num)
			i = temp->num;
		temp = temp->next;
	}
	return (i);
}

int	find_last(t_node *list)
{
	t_node	*temp;

	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp->num);
}

int	find_indx(t_node *list, int num)
{
	int	indx;

	indx = 1;
	while (list)
	{
		if (list->num <= num)
			return (indx);
		list = list->next;
		indx++;
	}
	return (-1);
}

int	find_num(t_node *list, int indx)
{
	t_node	*temp;

	temp = list;
	while (--indx)
		temp = temp->next;
	return (temp->num);
}

void	find_min_max_b(t_var *list) // new
{
	list->min = find_min(list->b);
	list->max = find_max(list->b);
	list->len_b = (list_len(list->b)/2);
}