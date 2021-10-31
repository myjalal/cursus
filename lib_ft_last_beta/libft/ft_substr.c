#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
		return (dst);
	}
}
//to remove v
/*int main(void)
{
	char *src;
	
	src = "I LOVE POTATO";
	printf("This should output 'LOVE': %p\n", ft_substr(src, 2, 4));
}*/

