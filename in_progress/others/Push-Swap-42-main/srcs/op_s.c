#include "push_swap.h"

/*
** This file has the functions related to the swap operations;
** 'sa' 'sb'
*/
void	s_stk(t_stk **top)
{
	int		i;
	int		j;
	t_stk	*tmp;

	tmp = NULL;
	if ((*top) && (*top)->nxt)
	{
		tmp = *top;
		i = (*top)->num;
		j = (*top)->nxt->num;
		tmp = *top;
		(*top)->num = j;
		tmp = *top;
		(*top)->nxt->num = i;
		(*top) = tmp;
	}
}
