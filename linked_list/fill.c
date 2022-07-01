# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct node
{
	int				num;
	struct node		*next;
	struct node		*previous;
}	t_node;

typedef struct var
{
	char			**temp;
	int				len;
	t_node			*a; //list a
	t_node			*b; //list b
}	t_var;

long long	ps_atoll(const char *str)
{
	int					i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

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

void	add_back(t_node **top, t_node *new)
{
	t_node	*tmp;

	if (*top == NULL)
		*top = new;
	else
	{
		tmp = *top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->previous = tmp;
	}
}

t_node	*fill_list(t_var *l, char **split, t_node *tmp)
{
	int		i;

	i = -1;
	while (split[++i])
	{
		tmp = malloc(sizeof(t_node));
		if (tmp == NULL)
			return (NULL);
		tmp->num = ps_atoll(split[i]);
		tmp->next = NULL;
		tmp->previous = NULL;
		add_back(&l->a, tmp);
		tmp = NULL;
	}
	l->len = i;
	return (l->a);
}


void print_list(t_node *list)
{
	const t_node *temp;
	if (list == NULL)
		printf("\nThe list is empty!!\n\n");
	else
	{
		printf("\n\nPrinting the list...\n\n");
		temp = list;
		while (temp)
		{
			printf("%d\n", temp->num);
			temp = temp->next;
		}
		printf("\n");
	}
}

int	sort_checker(t_node **list, int len)
{
	t_node	*tmp;
	tmp = *list;

	while (tmp && tmp->next)
	{
		if (tmp->num < tmp->next->num)
		{
			tmp = tmp->next;
			len--;
		}
		else
			return (0);
	}
	return (1);
}

void top(t_node **list, t_node *node)
{
	node->previous = NULL;
	node->next = *list;
	if (*list != NULL)
		(*list)->previous = node;
	*list = node;
}

void bottom(t_node **list, t_node *node)
{
	t_node *temp;

	temp = *list;
	if (*list == NULL)
		*list = node;
	else
	{
		while(temp->next)
			temp = temp->next;
		temp->next = node;
		node->previous = temp;
	}
}

int	main(int argc, char **argv)
{
	t_var	*l;
	t_node	*s;
	t_node	*t;

	l = NULL;
	s = NULL;
	
	t = malloc(sizeof(t_node));
	t->num = 100;
	t->next = NULL;
	t->previous = NULL;

	l = list_init(l);
	l->temp = &argv[1];
	l->a = fill_list(l, l->temp, s);
	print_list(l->a);
	sort_checker(&l->a, l->len);
	bottom(&l->a, t);
	print_list(l->a);
	free(l);
	l = NULL;
	return (0);
}
