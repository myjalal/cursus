/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:50:41 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/25 14:28:16 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_linked_list(t_node *list)
{
	t_node		*node;
	t_node		*delete;

	if (list)
	{
		node = list;
		while (node)
		{
			delete = node;
			node = node->next;
			free(delete);
			delete = NULL;
		}
		free(node);
		node = NULL;
	}
}

void		free_all(t_var *list)
{
	if (list)
	{
		if (list->a)
		{
			free_linked_list(list->a);
			list->a = NULL;
		}
		if (list->b)
		{
			free_linked_list(list->b);
			list->b = NULL;
		}	
		if (list->sorted)
		{
			free_linked_list(list->sorted);
			list->sorted = NULL;
		}
		free(list);
		list = NULL;
	}
}

void	error_exit(t_var *list)
{
	write(2, "Error\n", 6);
	free_all(list);
	exit(-1);
}
