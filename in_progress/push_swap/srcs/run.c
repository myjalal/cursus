/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:22:40 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/08 18:35:30 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run(int op, t_node **a, t_node **b)
{
	if (op > 10) //run 2 op
	{
		run(op/10, a, b);
		run(op%10, a, b);
	}
	
	if (op == 1) //sa
	{
		swap(a);
		printf("sa\n");
	}

	else if (op == 2) //sb
	{
		
	}
	
	else if (op == 3) //pa
	{
		
	}

	else if (op == 4) //pb
	{
		
	}

	else if (op == 5) //ra
	{
		revers(a);
		printf("ra\n");
	}

	else if (op == 6) //rb
	{
		
	}
	
	else if (op == 7) //rra
	{
		r_revers(a);
		printf("rra\n");
	}

	else if (op == 8) //rrb
	{
		
	}
}