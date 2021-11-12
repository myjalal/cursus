#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	unsigned char	cs;
	int				i;

	ptr = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	cs = (unsigned char)c;
	i = 0;
	while (n-- > 0)
	{
		*(ptr + i) = *(ptr2 + i);
		if (*(ptr2 + i) == cs)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
