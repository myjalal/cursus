/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:38:54 by jechekao          #+#    #+#             */
/*   Updated: 2022/08/01 17:52:39 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strfcmp(const char	*s1, const char	*s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	size_t			j;

	i = ft_strlen(s1) - n;
	j = ft_strlen(s2) - n;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[j] != '\0'))
	{
		if (str1[i] != str2[j])
			return (str1[i] - str2[j]);
		i++;
		j++;
	}
	return (0);
}
