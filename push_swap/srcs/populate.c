#include "push_swap.h"

t_var	*list_init(t_var *l)
{
	l = (t_var *)malloc(sizeof(t_var));
	if (!l)
		exit(1);
	l->temp = NULL;
	l->len = 0;
	l->a = NULL;
	l->b = NULL;
	return (l);
}

t_node *list_fill(char **temp, t_var *l, t_node *s)
{
	int	i;

	i = -1;
	while (++i)
	{
		s = malloc(sizeof(t_node));
		if (!s)
			return (NULL);
		//stopped here on the 29 mai 2022

	}
}