#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return(1);
	return (0);
}

/*int main(void)
{
	int c = 'A';
	printf("%d\n", ft_isalnum(c));
}*/
