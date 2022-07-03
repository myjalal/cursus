//array to linked list
#include "push_swap.h"


void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ((void) NULL);
	while (*s)
		write(fd, s++, 1);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	 
	 
}
void	arg_to_i(int argc, char **argv, int *n)
{

}



int main(int argc, char **argv)
{
	
}
