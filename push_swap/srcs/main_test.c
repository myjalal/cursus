#include "push_swap.h"

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
}