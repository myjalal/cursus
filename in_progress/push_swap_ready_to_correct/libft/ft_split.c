/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:20:48 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/17 16:51:17 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (i);
}

static char	*word_dup(const char *s, int x, int y)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((y - x + 1) * sizeof(char));
	while (x < y)
		word[i++] = s[x++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		idx;
	char	**split;

	i = -1;
	j = 0;
	idx = -1;
	split = ft_calloc((word_count(s, c) + 1), sizeof(*split));
	if (!split)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && idx < 0)
			idx = i;
		else if ((s[i] == c || i == ft_strlen(s)) && idx >= 0)
		{
			split[j] = word_dup(s, idx, i);
			j++;
			idx = -1;
		}
	}
	split[j] = NULL;
	return (split);
}
