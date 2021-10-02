#include <stdio.h>
void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;
	char *ft_dst;
	const char *ft_src;
	i = 0;
	ft_dst = dst;
	ft_src = src;
	
	while (i < len)
	{
		ft_dst[i] = ft_src[i];
		i++;
	}
	return (0);
}
int main(void)
{
	char dst[] = "abc";
	const char src[] = "12345";
	int len = 10;
	printf("dst is: %s and src is: %s\n", dst, src);
	ft_memmove(dst, src, len);
	printf("dst is: %s and src is: %s\n", dst, src);
	return (0);
}

