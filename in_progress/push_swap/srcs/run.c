/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:22:40 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/09 19:10:04 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_next(int op, t_node **a, t_node **b)
{
	if (op == 4)
	{
		one_top_two(a, b);
		printf("pb\n");
	}
	else if (op == 5)
	{
		revers(a);
		printf("ra\n");
	}
	else if (op == 6)
	{
		revers(b);
		printf("rb\n");
	}
	else if (op == 7)
	{
		r_revers(a);
		printf("rra\n");
	}
	else if (op == 8)
	{
		r_revers(b);
		printf("rrb\n");
	}
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
		printf("sa\n");
	}
	else if (op == 2)
	{
		swap(b);
		printf("sb\n");
	}
	else if (op == 3)
	{
		one_top_two(b, a);
		printf("pa\n");
	}
	else
		run_next(op, a, b);
}
