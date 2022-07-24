/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:36:32 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/24 16:22:10 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check if the arguments are valid 
#include "push_swap.h"

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
