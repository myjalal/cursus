#include <stdio.h>
#include <string.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

unsigned int ft_strlcat(char *restrict dst, const char *restrict src, unsigned int dstsize)
{
	int i;
	int j;
	int dstlen;
	int srclen;
	
	dstlen = ft_strlen (dst);
	srclen = ft_strlen (src);
	j = 0;
	i = ft_strlen (dst);
	
	if (dstsize == 0)
		return (dstlen + srclen);

	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	
	if (src[j] == '\0')
		dst[i] = src[j];
	
	return (dstlen + srclen);
}

int main()
{
	char first[] = "This is ";
	char last[] = "a potentially long string";
	int r;
	int size = 0;
	char buffer[size];

	strcpy(buffer,first);
	r = ft_strlcat(buffer,last,size);

	puts(buffer);
	printf("Value returned: %d\n",r);
	if( r > size )
		puts("String truncated");
	else
		puts("String was fully copied");

	return(0);
}
