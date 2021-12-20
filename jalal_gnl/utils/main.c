#include "../get_next_line.h"
#include <stdio.h>

int main(void)
{
	static char s[] = "hello world \n how are you";

	printf("%d\n", ft_strchr(s, '\n'));
	return (0);
}

