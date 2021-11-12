/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:32:09 by jechekao          #+#    #+#             */
/*   Updated: 2021/11/12 11:32:09 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	start_count(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] != set[j])
			j++;
		else
		{
			i++;
			j = 0;
		}
	}
	return (i);
}

int	end_count(char const *s1, char const *set, size_t len)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (s1[len] != set[j])
			j++;
		else
		{
			len--;
			j = 0;
		}
	}
	return (++len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	len;

	start = start_count (s1, set);
	len = (end_count (s1, set, ft_strlen(s1) - 1) - start);
	if (s1 == NULL)
		return (NULL);
	return (ft_substr(s1, start, len));
}
