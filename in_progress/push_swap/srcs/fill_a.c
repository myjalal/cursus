/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:27:03 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/23 21:32:26 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long		atoi_push_swap(t_var *list, char *str)
{
	long	num;
	int		i;
	int		len;
	int		sign;

	num = 0;
	i = 0;
	len = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f')
		i++;
	str[i] == '-' ? (sign = -1) : 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		len++;
	}
	len > 10 ? push_swap_error(list) : 0;
	return (num * sign);
}

static void		check_duplicates(t_var *list)
{
	t_stack		*slow;
	t_stack		*fast;

	slow = list->a;
	while (slow != list->a->prev)
	{
		fast = slow->next;
		while (fast != list->a)
		{
			if (slow->num == fast->num)
				push_swap_error(list);
			fast = fast->next;
		}
		slow = slow->next;
	}
}

static void		complete_filling(t_var *list, char *str, int i, int j)
{
	long int	test_int_size;

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
			test_int_size = atoi_push_swap(list, str);
			if (test_int_size > 2147483647 || test_int_size < -2147483648)
				push_swap_error(list);
			stack_add_end(list, 'a', test_int_size);
			str += j;
		}
		str = list->argv[++i];
	}
	if (!list->a)
		push_swap_error(list);
}

static void		error_parser(t_var *list)
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
				push_swap_error(list);
		}
		str = list->argv[++i];
	}
}

void			fill_stack_a(t_var *list)
{
	char	*str;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (ft_strcmp(list->argv[i], "-v") == 0)
	{
		list->argv++;
		list->print_stacks = 1;
	}
	str = list->argv[i];
	error_parser(list);
	complete_filling(list, str, i, j);
	check_duplicates(list);
}
