#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dst;
	
	i = 1;
	while(s[i-1])
		i++;
	dst = malloc(sizeof(*s) * i);
	i = 0;
	if (dst == NULL)
	{
		return (NULL);
	}
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
