/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:22:40 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/15 21:45:06 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_2(int op, t_node **a, t_node **b)
{
	if (op == 8)
	{
		r_revers(b);
		printf("rrb\n");
	}
	else if (op == 9)
	{
		revers(a);
		revers(b);
		printf("rr\n");
	}
	else if (op == 10)
	{
		r_revers(a);
		r_revers(b);
		printf("rrr\n");
	}
}

void	run_1(int op, t_node **a, t_node **b)
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
		run_1(op, a, b);
}

void	rotate_a(t_var *list) //to revise not sure (normalize_a)
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
			break;
		temp = temp->next;
		indx++;
	}
	//printf("index = %d, num = %d\n",indx, num); 
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
			break;
		temp = temp->next;
		indx++;
	}
	//printf("index = %d, num = %d\n",indx, num); 
	if (list->b && indx < num)
		run(6, &list->a, &list->b);
	else if (list->b)
		run(8, &list->a, &list->b);
}