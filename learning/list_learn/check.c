// check if the arguments are valid 

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

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
	printf("im here");
	int i;
	
	i = 0;
	while (argv[i])
	{
		if (check_int(argv[i]) == 0)
			{
				printf("WARNING! There is an invalid number\n");
				return (0);
			}
		i++;
	}
	printf("All good\n");
	return (1);
}

/* =====================================================*/
/* check for duplicates using strdup and strcmp */

void	check_dup(char **argv)
{
	int i;
	int j;
	char *str; //string to compare

	i = 0;
	while (argv[i])
	{
		str = ft_strdup(argv[i]); // change it to ft_strdup !!!!!!!
		j = 0;
		while (argv[j])
		{
			if (j == i)
				j++;
			printf("argv[j] = %s and str = %s\n", argv[j], str);
			if (ft_strcmp(str, argv[j]) == 0) // change it for ft_strcmp !!!!!!!!!
				{
					printf("there is a duplicate\n");
				}
			else
				j++;
		}
		i++;
	}

}