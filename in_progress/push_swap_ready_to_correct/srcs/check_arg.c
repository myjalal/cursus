/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:36:32 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/27 15:25:29 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_var *list)
{
	int		indx;
	int		num;
	t_node	*temp;

	temp = list->a;
	num = (list_len(temp) / 2);
	indx = 1;
	while (temp)
	{
		if (temp->num <= list->ref)
			break ;
		temp = temp->next;
		indx++;
	}
	if (indx < num)
		run_fat(5, list);
	else
		run_fat(7, list);
}

void	rotate_b(t_var *list)
{
	int		indx;
	int		num;
	t_node	*temp;

	temp = list->b;
	num = (list_len(temp) / 2);
	indx = 1;
	while (temp)
	{
		if (temp->num >= list->ref)
			break ;
		temp = temp->next;
		indx++;
	}
	if (list->b && indx < num)
		run_fat(6, list);
	else if (list->b)
		run_fat(8, list);
}

int	sort_checker(t_node **list)
{
	t_node	*tmp;

	tmp = *list;
	if (tmp && !tmp->next)
		return (1);
	while (tmp && tmp->next)
	{
		if (tmp->num < tmp->next->num)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	list_len(t_node *a)
{
	int		len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}
