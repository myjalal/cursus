#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ptr2;
	int		i;

	ptr = (char*)s;
	ptr2 = 0;
	i = 0;
	while (*(ptr + i))
	{
		if (*(ptr + i) == c)
			ptr2 = ptr + i;
		i++;
	}
	if (c == '\0')
		return (ptr + i);
	return (ptr2);
}
