/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:43:09 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/08 19:53:53 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_node **list)
{
	t_node	*temp;
	
	if(*list)
	{
		while (*list)
		{
			temp = (*list)->next;
			free(*list);
			*list = NULL;
			*list = temp;
		}
		free(*list);
		*list = NULL;
	}
}

int	find_min(t_node	*list) //find min of a list
{
	int i;
	t_node *temp;
	
	i = list->num;
	temp = list;
	while(temp)
	{
		if(i >= temp->num)
			i = temp->num;
		temp = temp->next;
	}
	return(i);
}

int	find_last(t_node *list) //find last num of the list
{
	t_node *temp;

	temp = list;
	while(temp->next)
		temp = temp->next;
	return(temp->num);
}

void	find_rotate_a(t_node **list, int num) //find number and rotate smartly
{
	
}