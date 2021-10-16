#include <stdlib.h>

void *ft_calloc(unsigned int count, unsigned int size)
{
	unsigned int total;
	char *dest;
	unsigned int i;
	
	i = 0;
	total = count * size;
	dest = malloc(total);
	if (mem == NULL)
		RETURN (NULL);
	while (i < total)
	{
		dest[i] = 0;
		i++;
	}
	
	return (dest);
}
