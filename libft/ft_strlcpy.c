#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	string[] = "Hello there, Venus";
	char	buffer[19];
	int		r;

	r = ft_strlcpy (buffer, string, 0);
	printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
}
*/
