/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larg_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:28:22 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/16 15:54:35 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num_swap(t_node *x, t_node *y)
{
	int	tmp;

	tmp = x->num;
	x->num = y->num;
	y->num = tmp;
}

t_node	*sort_list(t_node *list, t_node *new)
{
	t_node	*base;
	t_node	*tmp;
	t_node	*cmp;

	new = copy_list(list);
	base = new;
	tmp = NULL;
	cmp = NULL;
	while (base->next)
	{
		cmp = base;
		tmp = base->next;
		while (tmp)
		{
			if (cmp->num > tmp->num)
				cmp = tmp;
			tmp = tmp->next;
		}
		num_swap(base, cmp);
		base = base->next;
	}
	return (new);
}

t_node	*copy_list(t_node *head)
{
	t_node	*new;

	if (head == NULL)
		return (NULL);
	else
	{
		new = malloc(sizeof(t_node));
		new->num = head->num;
		new->next = copy_list(head->next);
		return (new);
	}
}

int		ref_check(t_node *list, int	ref)
{
	int i;

	i = 0;
	if (!list)
		return (0);
	while(list && i != 2)
	{
		if (list->num < ref)
			i = 1;
		if (list->num == ref)
			i = 2;
		list = list->next;
	}
	return (i);
}

int	find_max(t_node	*list)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = NULL;
	if (list)
	{
		i = list->num;
		temp = list;
		while (list)
		{
			if (list->num >= i)
				i = list->num;
			list = list->next;
		}
		list = temp;
	}
	return (i);
}