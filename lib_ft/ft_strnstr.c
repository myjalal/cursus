#include "libft.h"

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
		if (j == ft_strlen((char *)needle))
			return ((char *)haystack + p);
		i++;
		j = 0;
	}
	return (NULL);
}

/*int main(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "B";
	char *ptr;
	char *ft_ptr;
	 
	ptr = strnstr(largestring, smallstring, 11);
	ft_ptr = ft_strnstr(largestring, smallstring, 11);
	printf("real: %p and mine is: %p\n", ptr, ft_ptr);
}*/
