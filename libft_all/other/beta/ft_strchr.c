#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char*)s;
	i = 0;
	while (*(ptr + i))
	{
		if (*(ptr + i) == c)
			return (ptr + i);
		i++;
	}
	if (c == '\0')
		return (ptr + i);
	return (0);
}
