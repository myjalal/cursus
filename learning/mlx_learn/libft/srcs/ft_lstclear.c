/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jechekao < jechekao@student.42quebec.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:54:09 by  jechekao         #+#    #+#             */
/*   Updated: 2021/11/13 12:54:10 by  jechekao        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (lst)
	{
		current = *lst;
		while (current)
		{
			next = current->next;
			ft_lstdelone(current, (del));
			current = next;
		}
		*lst = NULL;
	}
}
