/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:43:30 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/27 14:17:07 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rorate(t_node **a, int min, int len, t_var *list)
{
	int	indx;

	indx = find_indx(*a, min);
	if (len / 2 > indx)
		run_fat(5, list);
	else
		run_fat(7, list);
}

void	ten_num(t_node **a, t_node **b, int len, t_var *list)
{
	int	min;

	while (len > 3)
	{
		min = find_min(*a);
		if ((*a)->next->num == min)
			run_fat(1, list);
		while ((*a)->num != min)
			rorate(a, min, len, list);
		run_fat(4, list);
		len--;
	}
	three_num(a, list);
	while (*b)
	{
		run_fat(3, list);
	}
}

void	three_num(t_node **a, t_var *list)
{
	int	min;
	int	last;

	min = find_min(*a);
	last = find_last(*a);
	if ((*a)->num == min && (*a)->next->num > last)
		run_fat(15, list);
	else if ((*a)->num < (*a)->next->num && min == last)
		run_fat(7, list);
	else if ((*a)->num > (*a)->next->num && min == last)
		run_fat(17, list);
	else if ((*a)->num > last && (*a)->next->num == min)
		run_fat(5, list);
	else if ((*a)->num < last && (*a)->next->num == min)
		run_fat(1, list);
}

void	small(t_node **a, t_node **b, t_var *list)
{
	if (list->len == 2)
		run_fat(1, list);
	if (list->len == 3)
		three_num(a, list);
	if (list->len <= 10)
		ten_num(a, b, list->len, list);
}
