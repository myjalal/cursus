/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:28:04 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/09 18:46:17 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SA and SB
void	swap(t_node **list)
{
	int	i;
	int	j;

	if ((*list) && (*list)->next)
	{
		i = (*list)->num;
		j = (*list)->next->num;
		(*list)->next->num = i;
		(*list)->num = j;
	}
}

//   PA and PB
void	one_top_two(t_node **l_one, t_node **l_two)
{
	t_node	*temp;

	if (*l_one && *l_two == NULL)
	{
		temp = malloc(sizeof(t_node));
		temp->num = (*l_one)->num;
		temp->next = NULL;
		temp->previous = NULL;
		*l_two = temp;
		*l_one = (*l_one)->next;
	}
	else
	{
		temp = malloc(sizeof(t_node));
		temp->num = (*l_one)->num;
		temp->previous = NULL;
		temp->next = (*l_two);
		(*l_two) = temp;
		*l_one = (*l_one)->next;
	}
}

// RA and RB
void	revers(t_node **list)
{
	t_node	*temp;
	t_node	*data;

	temp = *list;
	data = malloc(sizeof(t_node));
	data->num = temp->num;
	while (temp->next != NULL)
		temp = temp->next;
	data->previous = temp;
	data->next = NULL;
	temp->next = data;
	*list = (*list)->next;
}

// RRA and RRB
void	r_revers(t_node **list)
{
	t_node	*temp;
	t_node	*data;

	temp = *list;
	data = malloc(sizeof(t_node));
	while (temp->next != NULL)
		temp = temp->next;
	data->num = temp->num;
	temp = temp->previous;
	temp->next = NULL;
	data->next = *list;
	(*list)->previous = data;
	*list = (*list)->previous;
}
