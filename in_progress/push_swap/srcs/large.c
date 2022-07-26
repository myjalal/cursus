/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:15:43 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/25 19:49:44 by jechekao         ###   ########.fr       */
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
				run(2, &list->a, &list->b);
			while (list->b && list->b->num != list->ref)
				rotate_b(list);
			while (list->b && list->b->num == list->ref)
			{
				run(3, &list->a, &list->b);
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
			run(1, &list->a, &list->b);
		while (ref_check(list->a, list->ref))
		{
			if (list->a->num == list->ref)
				run(4, &list->a, &list->b);
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
				run(4, &list->a, &list->b);
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
