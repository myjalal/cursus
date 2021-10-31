/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:57:49 by jechekao          #+#    #+#             */
/*   Updated: 2021/10/31 16:57:52 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	total;
	char			*dest;
	unsigned int	i;

	i = 0;
	total = count * size;
	dest = malloc(total);
	if (dest == NULL)
		return (NULL);
	while (i < total)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
