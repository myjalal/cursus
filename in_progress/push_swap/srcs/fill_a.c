/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:27:03 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/25 13:53:20 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_dup(t_var *list)
{
	t_node		*slow;
	t_node		*fast;

	slow = list->a;
	while (slow)
	{
		fast = slow->next;
		while (fast)
		{
			if (slow->num == fast->num)
				error_exit(list);
			fast = fast->next;
		}
		slow = slow->next;
	}
}

void		creat_a(t_var *list, char *str, int i, int j)
{
	long int	num;
	t_node		*new;

	new = NULL;
	while (str)
	{
		while (*str)
		{
			while (!(j = 0) && *str && *str == ' ')
				str++;
			while (*(str + j) && (*(str + j) == '-' || *(str + j) == '+' ||
						ft_isdigit(*(str + j))))
				j++;
			if (!*str)
				break ;
			num = ft_atoi(str);
			if (num > 2147483647 || num < -2147483648)
				error_exit(list);
			list_filler(list, new, num);
			str += j;
		}
		str = list->argv[++i];
	}
	if (!list->a)
		error_exit(list);
}

void		check_error(t_var *list)
{
	char	*str;
	int		i;

	i = 1;
	str = list->argv[i];
	while (str)
	{
		while (*str)
		{
			if (*str == ' ' || ft_isdigit(*str))
				str++;
			else if (*str == '-' && ft_isdigit(*(str + 1)) &&
						(str == list->argv[i] || *(str - 1) == ' '))
				str++;
			else if (*str == '+' && ft_isdigit(*(str + 1)) &&
						(str == list->argv[i] || *(str - 1) == ' '))
				str++;
			else
				error_exit(list);
		}
		str = list->argv[++i];
	}
}

void			fill_a(t_var *list)
{
	char	*str;
	int		i;
	int		j;

	i = 1;
	j = 0;
	str = list->argv[i];
	check_error(list);
	creat_a(list, str, i, j);
	check_dup(list);
	indx_a(list);
}
