/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:21:36 by jechekao          #+#    #+#             */
/*   Updated: 2021/11/13 15:46:32 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;
	char			*dst;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = ft_calloc(sizeof(char), size);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(dst + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(dst + i + j) = *(s2 + j);
		j++;
	}
	*(dst + i + j) = '\0';
	return (dst);
}
