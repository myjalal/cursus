// check if the arguments are valid 
#include "push_swap.h"

/* (in libft)
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
*/

static int digit_check(char *argv)
{
	if (argv[0] == '-' && !ft_isdigit(argv[1]))
		return (false);
	if (argv[0] == '-' && argv[1] == '\0')
		return (false);
	if (argv[0] != '-' && !ft_isdigit(argv[0]))
		return (false);
	if (argv[0] == '\0')
		return (false);
	return (true);
}

static int is_neg(char *argv, bool *neg, int i)
{
	if (argv[i] == '-')
	{
		*neg = true;
		i++;
	}
	else
		*neg = false;
	return (i);
}

int check_int(char *argv)
{
	int i;
	long number;
	bool neg;
	
	number = 0;
	if (!digit_check(argv))
		return (0);
	while(argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		number = number * 10 + argv[i] - '0';
		if (neg == true && -number < INT_MIN)
			return (0);
		if (neg == false && number > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int check_arg(char **argv)
{
	int i;
	
	i = 1;
	while (i < argc)
	{
		if (check_int(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}


/*
int main(int argc, char **argv)
{
	
	if (!check_arg(argc, argv))
		printf("WARNING! it is not a valid number\n");
	else
		printf("All good\n");
	
	
	//printf("argc is : %d\n", argc);
	return 0;
}
*/