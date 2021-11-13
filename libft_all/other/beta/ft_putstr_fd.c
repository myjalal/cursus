#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ((void)NULL);
	while (*s)
		write(fd, s++, 1);
}
