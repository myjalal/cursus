#include "push_swap.h"

/*
** This file has the operations regardin pushing items between stacks;
** 'pa' 'pb'
*/
void	p_stk(t_stk **a, t_stk **b, t_stk *tmp)
{
	tmp = NULL;
	if (*b == NULL && *a)
	{
		*b = (t_stk *)malloc(sizeof(t_stk));
		(*b)->prv = NULL;
		(*b)->num = (*a)->num;
		(*b)->nxt = NULL;
		(*a) = (*a)->nxt;
		(*a)->prv = NULL;
	}
	else
	{
		if (*a)
		{
			tmp = (t_stk *)malloc(sizeof(t_stk));
			tmp->num = (*a)->num;
			tmp->nxt = NULL;
			tmp->prv = NULL;
			add_front(b, tmp);
			(*a) = (*a)->nxt;
		}
	}
}
