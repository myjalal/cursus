/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:43:30 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/08 19:37:06 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sort 5 or less arg
#include "push_swap.h"

void	ten_num(t_node **a, t_node **b, int len)
{
	int min;

	while(len > 3)
	{
		min = find_min(*a);
		if ((*a)->next->num == min)
			run(1, a, b);
		while((*a)->num != min)
			
	}
	
	
}

void	three_num(t_node **a, t_node **b)
{
	int	min;
	int	last;

	min = find_min(*a);
	last = find_last(*a);
	if ((*a)->num == min && (*a)->next->num > last)
		run(15, a, b);
	else if ((*a)->num < (*a)->next->num && min == last)
		run(7, a, b);
	else if ((*a)->num > (*a)->next->num && min == last)
		run(17, a, b);
	else if ((*a)->num > last && (*a)->next->num == min)
		run(5, a, b);
	else if ((*a)->num < last && (*a)->next->num == min)
		run(1, a, b);
}

void	small(t_node **a, t_node **b, t_var *list)
{
	if (list->len == 2)
		run(1, a, b);
	if (list->len == 3)
		three_num(a, b);
}
