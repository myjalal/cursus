# include "test.h"

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

void	add_to_list(t_node **top, t_node *new)
{
	t_node *temp;
	
	if (*top == NULL)
		*top = new;
	else
	{
		temp = *top;
		while (temp ->next)
			temp = temp->next;
		temp->next = new;
		new->previous = temp;
	}
}

void	free_list(t_node **list)
{
	t_node *temp;

	if (*list)
	{
		while(*list)
		{
			temp = (*list)->next;
			free(*list);
			*list = NULL;
			*list = temp;
		}
		free(*list);
		*list = NULL;
	}
}

int	main(void)
{
	t_node	*list_a;
	t_node	*list_b;
	t_node	*temp;

	int 	i;
	int		j;
	
	list_a = NULL;
	list_b = NULL;
	i = 5;
	while(i > 0)
	{
		printf("please enter next number a: ");
		scanf("%d", &j);
		temp = malloc(sizeof(t_node));
		temp->num = j;
		temp->next = NULL;
		temp->previous = NULL;
		add_to_list(&list_a, temp);
		temp = NULL;
		i--;
	}

	i = 5;
	while(i > 0)
	{
		printf("please enter next number b: ");
		scanf("%d", &j);
		temp = malloc(sizeof(t_node));
		temp->num = j;
		temp->next = NULL;
		temp->previous = NULL;
		add_to_list(&list_b, temp);
		temp = NULL;
		i--;
	}
	

	printf("\nlist a:\n");
	print_list(list_a);
	printf("\nlist a:\n");
	print_list(list_b);
	printf("\nRunning SA function");
	revers(&list_a);
	r_revers(&list_b);
	one_top_two(&list_a, &list_b);
	printf("\nRe-printing list a...\n");
	print_list(list_a);
	printf("\nRe-printing list b:\n");
	print_list(list_b);
	printf("\nList printed...\n");
	return (0); 
}