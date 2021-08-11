#include <stdio.h>

int ft_isascii(int c)
{
	if (c >= 0 && c <= 177)
		return (1);
	return(0);
}

int main(void)
{
	int c = 't';
	printf("%d\n",isascii(c));
}

