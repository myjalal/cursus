#include "push_swap.h"
/*

	PLEASE DELETE BEFORE SUBMITTING
	FOR TEST ONLY

*/

void	print_list(t_node *list)
{
	const t_node *temp;
	if (list == NULL)
		printf("\nThe list is empty!!\n\n");
	else
	{
		printf("\nPrinting the list...\n\n");
		temp = list;
		while (temp)
		{
			printf("%d\n", temp->num);
			temp = temp->next;
		}
		printf("\n");
	}
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