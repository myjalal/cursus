/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  jechekao < jechekao@student.42quebec.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:12:21 by  jechekao         #+#    #+#             */
/*   Updated: 2021/11/13 12:12:22 by  jechekao        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!*alst)
		*alst = new;
	else
	{
		while ((*alst)->next)
			*alst = (*alst)->next;
		(*alst)->next = new;
	}
}
