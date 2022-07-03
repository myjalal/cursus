#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
}
node;

int main(void)
{
	node *list = NULL;

	node *n = malloc(sizeof(node));
	if (n == NULL)
		return (0);
	
	n->number = 1;
	n->next = NULL;
	list = n;

	n = malloc(sizeof(node));
	if (n == NULL)
	{
		free(list);
		return (0);
	}
	n->number = 2;
	n->next = NULL;
	list->next = n;
	printf("number 2 is pointing to:  %p\n", n);

	n = malloc(sizeof(node));
	if (n == NULL)
	{
		free(list->next);
		free(list);
		return(0);
	}

	n->number = 3;
	n->next = NULL;
	list->next->next = n;

	node *tmp = list;
	while (tmp != NULL)
	{
		if (tmp->number == 2)
		{
			printf("this is the found pointer %p\n", tmp);
			return (0);
		}
		tmp = tmp->next;
	}
}