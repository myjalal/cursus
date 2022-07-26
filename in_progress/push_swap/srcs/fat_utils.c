/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:44:39 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/25 20:44:33 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ai_rotate_b(t_node *b, t_var *list)
{
	t_node	*temp;
	int		flag;

	temp = b;
	find_min_max_b(list);
	flag = (list->len_b) % 2;
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
