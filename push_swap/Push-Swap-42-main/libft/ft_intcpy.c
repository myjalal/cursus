/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:26:30 by vminomiy          #+#    #+#             */
/*   Updated: 2021/05/03 21:00:20 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intcpy(int *src, int *dst, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}
