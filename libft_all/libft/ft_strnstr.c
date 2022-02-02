/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:26:55 by jechekao          #+#    #+#             */
/*   Updated: 2021/11/13 15:44:44 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = -1;
	while (++i < len && *(haystack + i))
	{
		j = -1;
		while ((i + ++j) < len && *(haystack + i + j) == *(needle + j))
			if (!*(needle + j + 1))
				return ((char *)(haystack + i));
	}
	return (NULL);
}
