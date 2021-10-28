#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t ft_strlen(const char *c)
{
	int i;
	i = 0;
	
	while (c[i])
		i++;
	return (i);
}

int	wordcount(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			j++;
			if (s[i] == '\0' && s[i - 1] == c)
				j--;
		}
	}
	return (j);
}

char **ft_split(char const *s, char c)
{
	int i;
	int j;
	int k;
	char *str;
	char **ptr;
	
	str = (char *) s;
	i = 0;
	j = 0;
	k = 0;//malloc
	ptr = malloc ((wordcount(str, c) + 1) * sizeof (*str));
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c)
			j++;
		ptr[k] = ft_substr(str, i - j, j);
		k++;
		j = 0;
	}
	ptr[k] = (NULL);
	return (&ptr[0]);
}

char *ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char *dst;
	unsigned int i;
	
	if (ft_strlen(s) < start)
	{
		if((dst = malloc(sizeof(char))) == NULL)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		if ((dst = malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		i = 0;
		while (++i - 1 < len)
			*(dst + i - 1) = *(s + start + i - 1);
		*(dst + i - 1) = '\0';
		return (&dst);
	}
}

void	test(char const *s, char c)
{
	char	**ptr;
	int		i;

	i = 0;
	printf("The string is: %s\nThe delimiter is: %c\n", s, c);
	ptr = ft_split (s, c);
	printf("The function returns: \n");
	while (ptr[i])
	{
		printf("%s\n", ptr[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	test ("111I 1love 1111potato11", '1');
	test ("Apples,Oranges,Banana,Mango", ',');
}
