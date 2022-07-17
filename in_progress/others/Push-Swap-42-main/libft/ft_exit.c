#include "libft.h"

void	ft_exit(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	else
		ft_putstr_fd("exit\n", 1);
	exit(err);
}
