#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;
	char			*dst;
	
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((dst = ft_calloc(sizeof(char), size))== NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(dst + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(dst + i + j) = *(s2 + j);
		j++;
	}
	*(dst + i + j) = '\0';
	return (dst);
}

/*int main(void)
{
	char s1[] = "hello";
	char s2[] = "world";
	printf("the result is: %s\n", ft_strjoin(s1, s2));
}
