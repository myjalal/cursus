#include <stddef.h>
#include <stdio.h>

size_t ft_strlen(const char *c)
{
	int i;
	i = 0;
	
	while (c[i])
		i++;
	return (i);
}

int end_count(char const *s1, char const *set, size_t len)
{
	size_t j;

	j = 0;
	while (set[j])
	{
		if (s1[len] != set[j])
			j++;
		else
		{
			len--;
			j = 0;
		}
	}
	return (len);
}

int main(void)
{
	char s1[] = "abc12345abc6789abc";
	char set[] = "abc";
	printf("number of abc in the start is: %d\n", end_count(s1, set, ft_strlen(s1)-1));
}
