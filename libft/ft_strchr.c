/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:21:00 by jechekao          #+#    #+#             */
/*   Updated: 2021/11/12 11:21:00 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*src;

	i = 0;
	src = (char *)(s);
	if (c == '\0')
		return (&src[ft_strlen(src)]);
	while (c > 127)
		c = c - 128;
	while (s[i])
	{
		if (c == src[i])
			return (&src[i]);
		i++;
	}
	return (0);
}
