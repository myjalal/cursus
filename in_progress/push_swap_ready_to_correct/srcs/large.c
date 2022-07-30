/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:15:43 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/27 14:07:52 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_max(t_var *list)
{
	while (list->b)
	{
		list->ref = find_max(list->b);
		while (ref_check(list->b, list->ref) == 2)
		{
			if (list->b->next && list->b->next->num == list->ref)
				run_fat(2, list);
			while (list->b && list->b->num != list->ref)
				rotate_b(list);
			while (list->b && list->b->num == list->ref)
			{
				run_fat(3, list);
				list->ref = find_max(list->b);
			}
		}
	}
}

void	sort_min(t_var *list)
{
	while (!sort_checker(&list->a))
	{
		list->ref = find_min(list->a);
		if (list->a->next && list->a->next->num == list->ref)
			run_fat(1, list);
		while (ref_check(list->a, list->ref))
		{
			if (list->a->num == list->ref)
				run_fat(4, list);
			else
				rotate_a(list);
		}
	}
}

void	sort(t_var *list)
{
	int	i;
	int	j;

	i = list->len;
	j = (list->len / 4);
	while (i >= j)
	{
		indx_a(list);
		while (ref_check(list->a, list->ref))
		{
			if (list->a->num <= list->ref)
			{
				run_fat(4, list);
				i--;
			}
			else
				rotate_a(list);
		}
	}
}

void	large(t_var *list)
{
	sort(list);
	sort_min(list);
	sort_max(list);
}
