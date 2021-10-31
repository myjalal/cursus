#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	
	if (!dst && !src)
		return (0);
	i = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		i = len - 1;
		while (i >= 0 && i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

int main(void)
{
	char dst[] = "abc";
	const char src[] = "12345";
	int len = 8;
	printf("dst is: %s and src is: %s\n", dst, src);
	ft_memmove(dst, src, len);
	printf("dst is: %s and src is: %s\n", dst, src);
	
}
