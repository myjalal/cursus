#include <string.h>
#include <stdio.h>

void *ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char *src;
	
	src = (unsigned char*) s;
	while (n--)
	{
		if (*src == (unsigned char)c)
			return (src);
		src++;
	}
	return (NULL);
}

/*void	test (char *string, int c, int n)
{
	printf("The string is: %s and the char is: %c\n", string, c);
	printf("memchr: %p || ft_memchr: %p \n", memchr(string, c, n), ft_memchr(string, c, n));
	printf("Delta between pointers should be 0: %ld \n\n", memchr(string, c, n) - ft_memchr(string, c, n));
}

int	main (void)
{
	char string[] = "abcdEFG123abcdeFG3251";
	test (string, '\0', 30);
	test (string, 'd', 10);
	test (string, 'd', 3);
}*/
