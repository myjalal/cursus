#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ischar(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
		if (*(set + i++) == c)
			return (1);
	return (0);
}

static char	*trimming(const char *s1, const char *set, size_t *k, size_t i)
{
	size_t	j;
	size_t	len;
	char	*dst;

	len = strlen(s1);
	j = 0;
	while (ischar(*(s1 + len - j - 1), set))
		j++;
	if ((dst = calloc(sizeof(char), len - (j + i) + 1)) == NULL)
		return (NULL);
	while (*k < len - (j + i))
	{
		*(dst + *k) = *(s1 + i + *k);
		*k += 1;
	}
	return (dst);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	k;
	size_t	len;
	char	*dst;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = strlen(s1);
	while (ischar(*(s1 + i), set))
		i++;
	k = 0;
	if (i == len)
		dst = malloc(1);
	else
		dst = trimming(s1, set, &k, i);
	if (dst != NULL)
		*(dst + k) = '\0';
	return (dst);
}

int main(void)
{
	char s1[] = "abc12345ABC6789bbbaacca";
	char set[] = "abc";
	printf("trimmed string is: %s\n", ft_strtrim(s1, set));
}
