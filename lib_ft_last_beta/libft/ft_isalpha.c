#include "libft.h"

int ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*int main(void)
{
	int c = 'a';
	printf("%d\n", isalpha(c));
}*/
