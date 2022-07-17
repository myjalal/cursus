/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:18:17 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/17 17:22:37 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

int	ft_strcmp(const char	*s1, const char	*s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}


void	check_duplic(char **strv)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (strv[i])
	{
		str = ft_strdup(strv[i]);
		j = 0;
		while (strv[j])
		{
			if (i == j)
				j++;
			else if (ft_strcmp(strv[j], str) == 0)
			{
				ft_putstr_fd("Error1\n", 1);
				str_free(&str);
				exit(1);
			}
			else
				j++;
		}
		str_free(&str);
		i++;
	}
}
