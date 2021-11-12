/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:26:55 by jechekao          #+#    #+#             */
/*   Updated: 2021/11/12 11:26:55 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	size_t			i;
	unsigned int	j;
	size_t			p;

	i = 0;
	j = 0;
	p = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			p = i;
			while (haystack[i] == needle[j] && needle [j] && i < len)
			{
				i++;
				j++;
			}
		}
		if (j == ft_strlen((char *)needle))
			return ((char *)haystack + p);
		i = ++p;
		j = 0;
	}
	return (NULL);
}
