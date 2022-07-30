/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:28:04 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/27 17:17:37 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **list)
{
	int	i;
	int	i_indx;
	int	j;
	int	j_indx;

	if ((*list) && (*list)->next)
	{
		i = (*list)->num;
		i_indx = (*list)->indx;
		j = (*list)->next->num;
		j_indx = (*list)->next->indx;
		(*list)->next->num = i;
		(*list)->next->indx = i_indx;
		(*list)->num = j;
		(*list)->indx = j_indx;
	}
}

void	one_top_two(t_node **l_one, t_node **l_two)
{
	t_node	*temp;

	temp = *l_one;
	if ((*l_one)->next == NULL)
		*l_one = NULL;
	else
	{
		*l_one = (*l_one)->next;
		(*l_one)->previous = NULL;
	}
	if (*l_two == NULL)
	{
		temp->next = NULL;
		*l_two = temp;
	}
	else
	{
		temp->next = *l_two;
		(*l_two)->previous = temp;
		*l_two = temp;
	}
}

void	revers(t_node **list)
{
	t_node	*temp;

	temp = *list;
	*list = (*list)->next;
	(*list)->previous = NULL;
	temp->next = NULL;
	while ((*list)->next)
		*list = (*list)->next;
	temp->previous = *list;
	(*list)->next = temp;
	while ((*list)->previous)
		*list = (*list)->previous;
}

void	r_revers(t_node **list)
{
	t_node	*temp;
	int		i;

	i = list_len(*list) - 1;
	temp = *list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *list;
	temp->previous = NULL;
	(*list)->previous = temp;
	while (--i)
		*list = (*list)->next;
	(*list)->next = NULL;
	*list = temp;
}
