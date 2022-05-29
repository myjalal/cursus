/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:36:32 by jechekao          #+#    #+#             */
/*   Updated: 2022/05/29 18:35:21 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check if the arguments are valid 
#include "push_swap.h"

static int	digit_check(char *argv)
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

static int	is_neg(char *argv, bool *neg, int i)
{
	if (argv[0] == '-')
	{
		*neg = true;
		i++;
	}
	else
		*neg = false;
	return (i);
}

int	check_int(char *argv)
{
	int		i;
	long	number;
	bool	neg;

	i = -1;
	neg = false;
	number = 0;
	if (!digit_check(argv))
		return (0);
	i = is_neg(argv, &neg, i);

	while (argv[++i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		number = number * 10 + argv[i] - '0';
		if (neg == true && - number < INT_MIN)
			return (2);
		if (neg == false && number > INT_MAX)
			return (3);
	}
	return (1);
}

int	check_arg(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (check_int(argv[i]) == 0)
			error_exit("ERROR: not an int\n", 1);
		else if (check_int(argv[i]) == 2)
			error_exit("OVERFLOW ERROR: less then INT_MIN\n", 1);
		else if (check_int(argv[i]) == 3)
			error_exit("OVERFLOW ERROR: more then INT_MAX\n", 1);
	}
	printf("all good\n");
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