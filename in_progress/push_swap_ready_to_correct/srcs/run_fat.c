/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:37:31 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/27 15:30:24 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_run(int op)
{
	if (op == 1)
		write(1, "sa\n", 3);
	else if (op == 2)
		write(1, "sb\n", 3);
	else if (op == 3)
		write(1, "pa\n", 3);
	else if (op == 4)
		write(1, "pb\n", 3);
	else if (op == 5)
		write(1, "ra\n", 3);
	else if (op == 6)
		write(1, "rb\n", 3);
	else if (op == 7)
		write(1, "rra\n", 4);
	else if (op == 8)
		write(1, "rrb\n", 4);
}

void	last_move(int op, t_var *list)
{
	if (list->move != 10)
	{
		print_run(list->move);
		list->move = op;
	}
	else
		list->move = 0;
}

void	run_next(int op, t_var *list)
{
	if (op == 5)
	{
		revers(&list->a);
		last_move(op, list);
	}
	else if (op == 6)
	{
		revers(&list->b);
		last_move(op, list);
	}
	else if (op == 7)
	{
		r_revers(&list->a);
		last_move(op, list);
	}
	else if (op == 8)
	{
		r_revers(&list->b);
		last_move(op, list);
	}
}

void	run(int op, t_var *list)
{
	if (op == 1)
	{
		swap(&list->a);
		last_move(op, list);
	}
	else if (op == 2)
	{
		swap(&list->b);
		last_move(op, list);
	}
	else if (op == 3)
	{
		one_top_two(&list->b, &list->a);
		last_move(op, list);
	}
	else if (op == 4)
	{
		one_top_two(&list->a, &list->b);
		last_move(op, list);
	}
	else
		run_next(op, list);
}

void	run_fat(int op, t_var *list)
{
	if (op > 10)
	{
		run_fat(op / 10, list);
		run_fat(op % 10, list);
	}
	if ((op == 1 && list->move == 2) || (op == 2 && list->move == 1))
	{
		list->move = 10;
		write(1, "ss\n", 3);
		run_fat(op, list);
	}
	else if ((op == 5 && list->move == 6) || (op == 6 && list->move == 5))
	{
		list->move = 10;
		write(1, "rr\n", 3);
		run_fat(op, list);
	}
	else if ((op == 7 && list->move == 8) || (op == 8 && list->move == 7))
	{
		list->move = 10;
		write(1, "rrr\n", 4);
		run_fat(op, list);
	}
	else
		run(op, list);
}
