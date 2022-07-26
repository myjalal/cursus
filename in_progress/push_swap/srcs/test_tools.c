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
	printf("______\nA    B\n\n");
}

void	print_indx(t_node *a, t_node *sorted)
{
	const t_node	*temp_a;
	const t_node	*temp_b;

	printf("\nPrinting the list...\n\n");
	temp_a = a;
	temp_b = sorted;
	while (temp_a)
	{
		printf("%d -> %d     %d\n", temp_a->num, temp_a->indx, temp_b->num);
		temp_a = temp_a->next;
		temp_b = temp_b->next;
	}
	printf("_________________\nA   indx   sorted\n\n");
}
