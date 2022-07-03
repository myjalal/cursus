/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:18:17 by jechekao          #+#    #+#             */
/*   Updated: 2022/05/28 20:19:11 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_duplic(char **argv)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		str = ft_strdup(argv[i]);
		j = 0;
		while (argv[j])
		{
			if (i == j)
				j++;
			else if (ft_strcmp(argv[j], str) == 0)
			{
				ft_putstr_fd("duplicate numbers found\n", 1);
				free(str);
				exit(1);
			}
			else
				j++;
		}
		i++;
	}
	free(str);
}
