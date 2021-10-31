//#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		p;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			p = i;
			while (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
		}
		if (j == strlen((char *)needle)) //fix
			return ((char *)haystack + p);
		i++;
		j = 0;
	}
	return (NULL);
}

int main(void)
{
	char *s1 = "AAAAAAAAAAAAA";
	size_t max = strlen(s1);
	char *i1 = strnstr(s1, s1, max);
	char *i2 = ft_strnstr(s1, s1, max);
	
	printf("ft is: %p , /*str is : %p\n", i2, i1);
}
