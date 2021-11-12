/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:29:42 by jechekao          #+#    #+#             */
/*   Updated: 2021/11/12 11:30:00 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*src;

	src = (char *)(s);
	len = ft_strlen(src);
	if (c == '\0')
		return (&src[ft_strlen(src)]);
	while (c > 127)
		c = c - 128;
	while (len >= 0)
	{
		if (c == src[len])
			return (&src[len]);
		len--;
	}
	return (0);
}
