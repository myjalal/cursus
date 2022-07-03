/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:43:09 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/02 18:19:09 by jechekao         ###   ########.fr       */
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

