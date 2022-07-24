/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:22:40 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/24 16:31:19 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_2(int op, t_node **a, t_node **b)
{
	if (op == 8)
	{
		r_revers(b);
		write(1, "rrb\n", 4);
	}
	else if (op == 9)
	{
		revers(a);
		revers(b);
		write(1, "rr\n", 3);
	}
	else if (op == 10)
	{
		r_revers(a);
		r_revers(b);
		write(1, "rrr\n", 4);
	}
}

void	run_1(int op, t_node **a, t_node **b)
{
	t_node	*temp;

	temp = NULL;
	if (op == 4)
	{
		one_top_two(a, b);
		write(1, "pb\n", 3);
	}
	else if (op == 5)
	{
		revers(a);
		write(1, "ra\n", 3);
	}
	else if (op == 6)
	{
		revers(b);
		write(1, "rb\n", 3);
	}
	else if (op == 7)
	{
		r_revers(a);
		write(1, "rra\n", 4);
	}
	else
		run_2(op, a, b);
}

void	run(int op, t_node **a, t_node **b)
{
	if (op > 10)
	{
		run(op / 10, a, b);
		run(op % 10, a, b);
	}
	if (op == 1)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	else if (op == 2)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	else if (op == 3)
	{
		one_top_two(b, a);
		write(1, "pa\n", 3);
	}
	else
		run_1(op, a, b);
}

void	rotate_a(t_var *list)
{
	int		indx;
	int		num;
	t_node	*temp;

	temp = list->a;
	num = (list_len(temp) / 2);
	indx = 1;
	while (temp)
	{
		if (temp->num <= list->ref)
			break ;
		temp = temp->next;
		indx++;
	}
	if (indx < num)
		run(5, &list->a, &list->b);
	else
		run(7, &list->a, &list->b);
}

void	rotate_b(t_var *list)
{
	int		indx;
	int		num;
	t_node	*temp;

	temp = list->b;
	num = (list_len(temp) / 2);
	indx = 1;
	while (temp)
	{
		if (temp->num >= list->ref)
			break ;
		temp = temp->next;
		indx++;
	}
	if (list->b && indx < num)
		run(6, &list->a, &list->b);
	else if (list->b)
		run(8, &list->a, &list->b);
}
