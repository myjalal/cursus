#include "push_swap.h"
/*

	PLEASE DELETE BEFORE SUBMITTING
	FOR TEST ONLY

*/

void	print_list(t_node *a, t_node *b)
{
	const t_node	*temp_a;
	const t_node	*temp_b;

	printf("\nPrinting the list...\n\n");
	temp_a = a;
	temp_b = b;
	while (temp_a || temp_b)
	{
		if (temp_a)
		{
			printf("%d    ", temp_a->num);
			temp_a = temp_a->next;
		}
		else if (!temp_a)
			printf("     ");
		if (temp_b)
		{
			printf("%d\n", temp_b->num);
			temp_b = temp_b->next;
		}
		else if (!temp_b)
			printf(" \n");
	}
	printf("______\nA    B\n");
}

/*
int main(int argc, char *argv[])
{
	char **list;
	int i = 0;

	list = NULL;
	if (argc == 2)
		list = ft_split(argv[1], ' ');
	else if (argc > 2)
		list = &argv[1];
	while (list[i])
		{
			printf("number %s\n", list[i]);
			i++;
		}
}*/