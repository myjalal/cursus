// managing errors
#include "push_swap.h"

int error_exit(char *error, int err_exit)
{
	if (err_exit != 0)
		ft_putstr_fd(error, 2);
	exit(err_exit);
}

