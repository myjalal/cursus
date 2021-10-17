#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = -1;
	if (n > 0)
	{
		while ((size_t)++i < n)
		{
			*(unsigned char*)(s + i) = '\0';
		}
	}
}
