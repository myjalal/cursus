/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:51:16 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/31 17:09:33 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int error(void)
{
	ft_printf("Error fd\n");
	exit(MLX_ERROR);
}
void	map_checker(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd > 0)
		error();
	else
		ft_printf("Found directory\n");
		
	
}