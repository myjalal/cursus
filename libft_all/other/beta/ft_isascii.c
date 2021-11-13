#include "libft.h"

int	ft_isascii(int c)
{
	unsigned int	u;

	u = (unsigned int)c;
	if (u <= 127)
		return (1);
	return (0);
}
