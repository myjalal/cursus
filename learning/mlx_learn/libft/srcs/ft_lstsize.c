/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jechekao < jechekao@student.42quebec.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:54:59 by  jechekao         #+#    #+#             */
/*   Updated: 2021/11/13 12:55:18 by  jechekao        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
