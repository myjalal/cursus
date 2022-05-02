#include "push_swap.h"


typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}
node;

typedef struct	v_node
{
	char			*line;
	char			**split;
	char			**av;
	int				ac;
	int				len;
	int				print;
	int				color;
	int				fd;
	node			*a;
	node			*b;
}	v_node;

node *add(int num, node *head)
{
	node *new_node;
	new_node = (node *) malloc(sizeof(node));
	new_node -> data = num;
	new_node -> next = head;
	head = new_node;
	return (head);
}

void print(node *head)
{
	node *corrent_node = head;
	while (corrent_node != NULL)
	{
		printf("%d\n", corrent_node -> data);
		corrent_node = corrent_node -> next;
	}
}

/*
int main(void)
{
	node *head = NULL;
	int i = 1;

	while (i <= 10)
	{
		head = add(i, head);
		i++;
	}

	print(head);
}*/
v_node	*initiate_var(v_node *v)
{
	v = (v_node *)malloc(sizeof(v_node));
	if (v == NULL)
		exit(1);
	v->a = NULL;
	v->b = NULL;
	v->len = 0;
	v->line = NULL;
	v->split = NULL;
	v->print = 0;
	return (v);
}

char **fill(v_node *var, int argc, char **argv)
{
	var -> fd = 1;
	if (argc == 2)
		var -> split = ft_split(argv[1], ' ');
	else
		var -> split = &argv[1];
	return (var -> split);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return 0;

	v_node *var;

	var = initiate_var(var);
	
	var -> split = fill(var, argc, argv);
	check_dup(var -> split);





	int i = 0;
	while (var->split[i])
	{
		printf("%s\n", var->split[i]);
		i++;
	}

	
	/*int i = 0;
	char **str;

	str = ft_split(argv[1], ' ');
	
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}*/
	



	return (0);
}
