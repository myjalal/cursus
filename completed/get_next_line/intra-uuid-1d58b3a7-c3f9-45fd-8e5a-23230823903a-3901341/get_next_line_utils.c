/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:48:55 by jechekao          #+#    #+#             */
/*   Updated: 2022/01/30 13:18:45 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *string, int c)
{
	char	*str;

	str = (char *)string;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*join_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}
